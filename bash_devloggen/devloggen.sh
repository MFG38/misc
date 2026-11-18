#!/usr/bin/env bash
LOGDATE=$(date +%F)
FILEDATE=$(date +%Y%m%d)

if [ $# -eq 1 ]; then
    TARPATH=$1
else
    TARPATH=$(pwd)
fi

echo Development Log >> $TARPATH/devlog_$FILEDATE.txt
echo "$LOGDATE" >> $TARPATH/devlog_$FILEDATE.txt
echo --------------- >> $TARPATH/devlog_$FILEDATE.txt
