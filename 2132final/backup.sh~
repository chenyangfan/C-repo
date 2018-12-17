#!/bin/bash
#
if [ ! -d $1 ]; then
  echo Source directory does not exist
  exit 1
elif [ ! -d $2 ]; then
  echo Destination directory does not exist
  exit 1
fi

for filename in `ls $1` 
do
  if [ -f $1/$filename ]; then
    if [ ! -e $2/$filename ]; then 
      cp $1/$filename $2/$filename
      echo $filename
    fi
  fi
done

