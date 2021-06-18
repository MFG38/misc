@echo off

:: Edit the offsets as needed to suit your system time.
set logdate=%date:~6,4%%date:~3,2%%date:~0,2%
set datetext=%date:~6,4%-%date:~3,2%-%date:~0,2%

echo Development Log > devlog_%logdate%.txt
echo %datetext% >> devlog_%logdate%.txt
echo =============== >> devlog_%logdate%.txt
