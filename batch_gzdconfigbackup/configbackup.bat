@echo off

echo GZDoom Config File Backup Utility
echo by Santtu "MFG38" Pesonen, 2021
echo ---------------------------------
echo Type 'backup' or 'b' to create a backup of an existing config file.
echo Type 'restore' or 'r' to restore a config from a backup.
echo.
set /p OPERATION="Which operation do you wish to perform? " % = %

if (%OPERATION%) == (backup) (goto OpBackup)
if (%OPERATION%) == (b) (goto OpBackup)

if (%OPERATION%) == (restore) (goto OpRestore)
if (%OPERATION%) == (r) (goto OpRestore)

:OpBackup
set /p INFILE="Enter name of input file: " % = %
set /p OUTFILE="Enter name of output file: " % = %
copy %INFILE%.ini %OUTFILE%.ini
goto OpFinish

:OpRestore
set /p INFILE="Enter name of input file: " % = %
copy %INFILE%.ini gzdoom-%USERNAME%.ini
goto OpFinish

:OpFinish
pause >nul
