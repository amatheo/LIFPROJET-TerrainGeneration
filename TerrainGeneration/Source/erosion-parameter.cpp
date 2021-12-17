#include "erosion-parameter.h"

/*!
* \brief constructor
*/
ErosionParameter::ErosionParameter()
{
	//Default Value
	this->erosionRadius = 3;
	this->inertia = 0.05f;
	this->sedimentCapacityFactor = 4.0f;
	this->minSedimentCapacity = 0.01f;
	this->erodeSpeed = 0.3f;
	this->depositSpeed = 0.3f;
	this->evaporateSpeed = 0.01f;
	this->maxDropletLifetime = 30;
	this->initialSpeed = 1.0f;
	this->initialWaterVolume = 1.0f;
}

/*!
* \brief destructor
*/
ErosionParameter::~ErosionParameter()
{
}