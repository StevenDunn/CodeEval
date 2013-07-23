#!/bin/bash
# Email Validation solution in Bash for CodeEval.com by Steven A. Dunn
function validateEmail 
{
	if [[ $line =~ ^\" ]]
	then
		if
			[[ $line =~ ^\"([^\"]*)\"+@[A-Z0-9._]+\.([A-Z]{2}|com|org|net|edu|gov|mil|biz|info|mobi|name|aero|asia|jobs|museum)$ ]] ;
			then
				echo "true"
			else
				echo "false"
		fi
	else
		if [[ $line =~ ^[A-Z0-9._+%-]+@[A-Z0-9._]+\.([A-Z]{2}|com|org|net|edu|gov|mil|biz|info|mobi|name|aero|asia|jobs|museum)$ ]] ;
		then
			echo "true"
		else
			echo "false"
		fi	
	fi
}

shopt -s nocasematch
while read line
do
	validateEmail $line
done < $1

