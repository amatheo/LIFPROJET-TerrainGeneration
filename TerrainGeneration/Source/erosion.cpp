#include "erosion.h"
#include <math.h>
using namespace std;
Terrain Erosion::ErodeTerrain(int numIteration, Terrain terrain, ErosionParameter parameter)
{
	srand(time(NULL));
	////////Initialize Brushweight
	vector<vector<int>> erosionBrushIndices = vector<vector<int>>(terrain.ni * terrain.nj);
	vector<vector<float>> erosionBrushWeights = vector<vector<float>>(terrain.ni * terrain.nj);

	vector<int> xOffsets = vector<int>(parameter.erosionRadius * parameter.erosionRadius * 4);//Cause 4 point on one tile
	vector<int> yOffsets = vector<int>(parameter.erosionRadius * parameter.erosionRadius * 4);//Cause 4 point on one tile
	vector<float> weights = vector<float>(parameter.erosionRadius * parameter.erosionRadius * 4);

	float weightSum = 0;
	int addIndex = 0;

	for (int i = 0; i < erosionBrushIndices.size(); i++)
	{
		//Because we build from top to bottom
		int centreX = i / terrain.nj;
		int centreY = i % terrain.nj;

		if (centreY <= parameter.erosionRadius || centreY >= terrain.nj - parameter.erosionRadius || centreX <= parameter.erosionRadius + 1 || centreX >= terrain.ni - parameter.erosionRadius) {
			weightSum = 0;
			addIndex = 0;
			for (int y = -parameter.erosionRadius; y <= parameter.erosionRadius; y++) {
				for (int x = -parameter.erosionRadius; x <= parameter.erosionRadius; x++) {
					float sqrDst = x * x + y * y;
					if (sqrDst < parameter.erosionRadius * parameter.erosionRadius) {
						int coordX = centreX + x;
						int coordY = centreY + y;

						if (coordX >= 0 && coordX < terrain.ni && coordY >= 0 && coordY < terrain.nj) {
							float weight = 1 - sqrt(sqrDst) / parameter.erosionRadius;
							weightSum += weight;
							weights[addIndex] = weight;
							xOffsets[addIndex] = x;
							yOffsets[addIndex] = y;
							addIndex++;
						}
					}
				}
			}
		}

		int numEntries = addIndex;
		erosionBrushIndices[i] = vector<int>(numEntries);
		erosionBrushWeights[i] = vector<float>(numEntries);

		for (int j = 0; j < numEntries; j++) {
			erosionBrushIndices[i][j] = (yOffsets[j] + centreY) * terrain.nj + xOffsets[j] + centreX;
			erosionBrushWeights[i][j] = weights[j] / weightSum;
		}
	}

	
	//////Apply Droplet
	for (int iteration= 0; iteration < numIteration; iteration++)
	{
		float posX = float_rand(0.0f, terrain.ni - 1);
		float posY = float_rand(0.0f, terrain.nj - 1);
		cout << "PosX: " << posX << endl;
		cout << "PosY: " << posY << endl;
		float dirX = 0;
		float dirY = 0;

		float speed = parameter.initialSpeed;
		float water = parameter.initialWaterVolume;
		float sediment = 0;


		for (int lifetime = 0; lifetime < parameter.maxDropletLifetime; lifetime++) {
			int nodeX = (int)posX;
			int nodeY = (int)posY;

			cout << "NodeX before moving: " << nodeX << endl;
			cout << "NodeY before moving: " << nodeY << endl;

			int dropletIndex = terrain.getIndex(nodeX, nodeY);

			// Calculate droplet's offset inside the cell (0,0) = at NW node, (1,1) = at SE node
			float cellOffsetX = posX - nodeX;
			float cellOffsetY = posY - nodeY;

			Vector gradient = terrain.gradient(posX, posY);
			cout << "Gradient X : " << gradient[0] << " Gradient Y : " << gradient[1] << " Gradient Z : " << gradient[2] << endl;
			float baseHeight = terrain.getHeight(nodeX, nodeY);

			dirX = (dirX * parameter.inertia - gradient[0] * (1 - parameter.inertia));
			dirY = (dirY * parameter.inertia - gradient[1] * (1 - parameter.inertia));

			cout << "DirX: " << dirX << endl;
			cout << "DirY: " << dirY << endl;

			float len = sqrt(dirX * dirX + dirY * dirY);
			if (len != 0) {
				dirX /= len;
				dirY /= len;
			}
			posX += dirX;
			posY += dirY;

			// Stop simulating droplet if it's not moving or has flowed over edge of map
			if ((dirX == 0 && dirY == 0) || posX < 0 || posX >= terrain.ni - 1 || posY < 0 || posY >= terrain.nj - 1) {
				break;
			}

			nodeX = (int)posX;
			nodeY = (int)posY;
			cout << "NodeX after moving: " << nodeX << endl;
			cout << "NodeY after moving: " << nodeY << endl;

			float newHeight = terrain.getHeight(nodeX, nodeY);
			float deltaHeight = newHeight - baseHeight;

			// Calculate the droplet's sediment capacity (higher when moving fast down a slope and contains lots of water)
			float sedimentCapacity = max(-deltaHeight * speed * water * parameter.sedimentCapacityFactor, parameter.minSedimentCapacity);

			if (sediment > sedimentCapacity || deltaHeight > 0) {
				float amountToDeposit = (deltaHeight > 0) ? min(deltaHeight, sediment) : (sediment - sedimentCapacity) * parameter.depositSpeed;
				sediment -= amountToDeposit;

				float sedimentNW = amountToDeposit * (1 - cellOffsetX) * (1 - cellOffsetY);
				terrain.addHeight(nodeX, nodeY, sedimentNW);

				float sedimentNE = amountToDeposit * cellOffsetX * (1 - cellOffsetY);
				terrain.addHeight(nodeX + 1, nodeY, sedimentNE);

				float sedimentSW = amountToDeposit * (1 - cellOffsetX) * cellOffsetY;
				terrain.addHeight(nodeX, nodeY+1, sedimentSW);

				float sedimentSE = amountToDeposit * cellOffsetX * cellOffsetY;
				terrain.addHeight(nodeX+1, nodeY+1, sedimentSE);
				
			}
			else
			{
				// Erode a fraction of the droplet's current carry capacity.
				// Clamp the erosion to the change in height so that it doesn't dig a hole in the terrain behind the droplet
				float amountToErode = min((sedimentCapacity - sediment) * parameter.erodeSpeed, -deltaHeight);
				
				// Use erosion brush to erode from all nodes inside the droplet's erosion radius
				for (int brushPointIndex = 0; brushPointIndex < erosionBrushIndices[dropletIndex].size(); brushPointIndex++) {
					int nodeIndex = erosionBrushIndices[dropletIndex][brushPointIndex];

					float weighedErodeAmount = amountToErode * erosionBrushWeights[dropletIndex][brushPointIndex];
					float deltaSediment = (terrain.getHeight(nodeIndex) < weighedErodeAmount) ? terrain.getHeight(nodeIndex) : weighedErodeAmount;
					terrain.addHeight(nodeIndex, -deltaSediment);
					sediment += deltaSediment;
				}
			}

			// Update droplet's speed and water content
			speed = sqrt(speed * speed + deltaHeight * 4); //For is used as an abstract multiplier, can make it a parameter
			water *= (1 - parameter.evaporateSpeed);
		}
	}
	cout << "";
	return terrain;
}

float Erosion::float_rand(float min, float max)
{
	// this  function assumes max > min, you may want 
	// more robust error checking for a non-debug build
	assert(max > min);
	float random = ((float)rand()) / (float)RAND_MAX;

	// generate (in your case) a float between 0 and (4.5-.78)
	// then add .78, giving you a float between .78 and 4.5
	float range = max - min;
	return (random * range) + min;
}
