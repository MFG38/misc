#!/usr/bin/env bash

echo Name of target zip:
read TARFILE
7za a -tzip ${TARFILE}.zip ${TARFILE}.lmp ${TARFILE}.txt
