#!/usr/bin/bash

# Modify these two variables as needed to fit your own
# directory structure.
IWADDIR="./iwads/"
PWADDIR="./pwads/"

LAUNCHCMD="dsda-doom"

read -p "Enter IWAD to load: " IWAD
read -p "Enter PWAD(s) to load or leave blank: " PWADS
read -p "Enter complevel: " COMPLVL
read -p "Enter extra arguments if needed: " EXTRAARGS

if [[ $IWAD ]]; then
    LAUNCHCMD+=" -iwad ${IWADDIR}${IWAD}.WAD"
fi

if [[ $PWADS ]]; then
    LAUNCHCMD+=" -file ${PWADDIR}${PWADS}"
fi

if [[ $COMPLVL ]]; then
    LAUNCHCMD+=" -complevel $COMPLVL"
fi

if [[ $EXTRAARGS ]]; then
    LAUNCHCMD+=" $EXTRAARGS"
fi

echo "Final command: $LAUNCHCMD"
read -p "Are you ready to rip and tear? [y/N] " CONFIRM

if [ $CONFIRM == 'y' ]; then
    exec $LAUNCHCMD
fi

