@echo off

set /p DIR="Enter path of directory to clean up: " % = %
for %%f in (%DIR%) do (
	echo Cleaning directory %%f
	del %%f
)
