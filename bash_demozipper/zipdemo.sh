#!/usr/bin/env bash

DOANOTHER="y"

while [ "$DOANOTHER" == "y" ]
do
    read -p "Name of target zip: " TARFILE
    7za a -tzip $TARFILE.zip $TARFILE.lmp $TARFILE.txt

    read -p "Zip another file? [y/N]" DOANOTHER
done
