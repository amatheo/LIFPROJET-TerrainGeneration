cls

:: x64 Debug
XCOPY /Y "%QTDIR64%\bin\Qt5Cored.dll"	 					"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\Qt5Guid.dll" 						"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\Qt5Widgetsd.dll" 					"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\Qt5Opengld.dll" 					"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\Qt5PrintSupportd.dll" 				"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\icudt53.dll" 						"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\icuin53.dll" 						"..\bin\x64\Debug\" 
XCOPY /Y "%QTDIR64%\bin\icuuc53.dll" 						"..\bin\x64\Debug\" 
	
XCOPY /Y "%PLATFORMDIR%\LibGL\x64\bin\glew32.dll" 			"..\bin\x64\Debug\" 

:: x64 Release
XCOPY /Y "%QTDIR64%\bin\Qt5Core.dll"	 					"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\Qt5Gui.dll" 						"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\Qt5Widgets.dll" 					"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\Qt5Opengl.dll" 						"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\Qt5PrintSupport.dll" 				"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\icudt53.dll" 						"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\icuin53.dll" 						"..\bin\x64\Release\" 
XCOPY /Y "%QTDIR64%\bin\icuuc53.dll" 						"..\bin\x64\Release\" 
	
XCOPY /Y "%PLATFORMDIR%\LibGL\x64\bin\glew32.dll" 			"..\bin\x64\Release\" 