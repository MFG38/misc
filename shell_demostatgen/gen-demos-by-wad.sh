#!/usr/bin/env bash

BASEDIR=$(pwd)
GENFILE="demos-by-wad.txt"

if [ -f $GENFILE ]; then
    echo "Deleting previous TXT..."
    rm $GENFILE
    touch $GENFILE
else
    echo "Creating TXT..."
    touch $GENFILE
fi

for dir in */; do
    cd $dir
    WADNAME=$(printf '%-20s' "$(pwd | awk -F / '{print $NF}')")
    DEMOCOUNT=$(find -iname '*.lmp*' | wc -l)

    echo "$WADNAME $DEMOCOUNT" >> $BASEDIR/$GENFILE
    cd $BASEDIR
done
