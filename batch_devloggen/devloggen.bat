@echo off

:: Edit the offsets as needed to suit your system time.
set logdate=%date:~9,4%%date:~6,2%%date:~3,2%
set datetext=%date:~9,4%-%date:~6,2%-%date:~3,2%

echo Development Log > devlog_%logdate%.txt
echo %datetext% >> devlog_%logdate%.txt
echo =============== >> devlog_%logdate%.txt
