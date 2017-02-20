#!/bin/bash
# $1 = Problem Name
P=$1
TLE='1s'
point=0
ntest=0
for (( t = 0; ; ++t )); do
	if [ ! -f $t.in ]; then
		break
	fi
	echo -en "\r\033[K\t$P: Judging test $t..."
	let 'ntest=ntest+1'
	judgement="Judgement failed"
	cp $t.in $P.inp
	if (timeout $TLE ./$P.exec 2> /dev/null); then
		g++ -o checker.exec checker.cpp
		if (./checker.exec $t.in $P.out); then
			let 'point=point+1';
			judgement="Correct"
		else
			judgement="Wrong answer"
		fi
		rm checker.exec
	elif [ $? -ne 124 ]; then
		judgement="Runtime error"
	else
		judgement="Time limit exceeded"
	fi
	echo -e "\t\tTest $t: $judgement" >> ../../result/detail.txt
done
rm -rf $P.exec output.txt $P.*
echo $(python -c 'print '$point'.0/'$ntest'*100') > result.txt 
