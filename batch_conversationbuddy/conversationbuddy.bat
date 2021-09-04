@echo off

echo Say something, will ya?

:Loop
set /p MESSAGE="" % = %
echo %MESSAGE%
goto Loop
