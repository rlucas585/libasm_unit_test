#!/bin/bash
DEFAULT="\e[39m"
BLACK="\e[30m"
RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
MAGENTA="\e[35m"
CYAN="\e[36m"

if [ "$#" -ge 2 ]
then
	printf $RED"Please supply between 0 and 1 argument\n\n"
	printf $DEFAULT"test - test mandatory functions with criterion tests\n"
	printf $DEFAULT"bonus - test mandatory + bonus functions with "\
"criterion tests\n"
	printf $DEFAULT"nocrit - test mandatory functions (use if criterion"\
" is not installed)\n"
	exit
fi
if [ "$1" == "test" ] || [ "$#" == 0 ]
then
	if [ -e "libasm.a" ]
	then
		make test
	else
		printf $RED"Please make sure libasm.a is in the current directory\n"
	fi
fi
if [ "$1" == "bonus" ]
then
	if [ -e "libasm_bonus.a" ]
	then
		make bonustest
	else
		printf $RED"Please make sure libasm_bonus.a is in the "\
"current directory\n"
	fi
fi
if [ "$1" == "nocrit" ]
then
	if [ -e "libasm.a" ]
	then
		make nocrit
	else
		printf $RED"Please make sure libasm.a is in the current directory\n"
	fi
fi