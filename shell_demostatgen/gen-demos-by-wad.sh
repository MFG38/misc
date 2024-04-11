#!/usr/bin/env bash

BASEDIR=$(pwd)
GENFILE="demos-by-wad.txt"

if [ -f $GENFILE ]; then
    echo "Regenerating $GENFILE..."
    rm $GENFILE
    touch $GENFILE
else
    echo "Generating $GENFILE..."
    touch $GENFILE
fi

for dir in */; do
    cd $dir
    WADNAME=$(printf '%-20s' "$(pwd | awk -F / '{print $NF}')")
    DEMOCOUNT=$(find -iname '*.lmp*' | wc -l)

    echo "$WADNAME $DEMOCOUNT" >> $BASEDIR/$GENFILE
    cd $BASEDIR
done
