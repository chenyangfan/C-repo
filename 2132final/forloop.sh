#!/bin/bash
for file in *.txt
do
  sort $file > $file.sorted
done
