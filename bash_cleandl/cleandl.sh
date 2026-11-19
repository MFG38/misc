#!/usr/bin/env bash

echo Cleaning Downloads folder...
cd $HOME/Downloads/

if [ "$(ls -A $PWD)" ]; then
	rm -r *
	echo Folder cleaned.
else
	echo Nothing to delete!
fi
