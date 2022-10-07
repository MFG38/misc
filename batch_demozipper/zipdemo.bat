@echo off

set /p FILE="Name of target zip: " % = %
:: Modify the line below as needed if your path to 7za.exe is different.
_tools\7za a -tzip %FILE%.zip %FILE%.lmp %FILE%.txt
pause >nul
