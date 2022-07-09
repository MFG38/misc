#!/bin/sh
LOGDATE=$(date +%F)
FILEDATE=$(date +%Y%m%d)

echo Development Log >> devlog_"$FILEDATE".txt
echo "$LOGDATE" >> devlog_"$FILEDATE".txt
echo --------------- >> devlog_"$FILEDATE".txt
