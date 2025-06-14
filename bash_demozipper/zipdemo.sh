#!/usr/bin/env bash

read -p "Name of target zip: " TARFILE
7za a -tzip ${TARFILE}.zip ${TARFILE}.lmp ${TARFILE}.txt
