#!/bin/bash

day=`date | cut -f1 -d" "`

case "$day" in
    Mon|Wed|Fri)
	echo 2132 lectures
	;;
    Tue|Thu)
	echo no 2132 lectures
	;;
    Sat|Sun)
	echo No lectures
	;;
esac
