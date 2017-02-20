#!/bin/bash

#-------------------------------------Introduction-----------------------------------------------------#
echo -e "\t\t\t*******************************"
echo -e "\t\t\t*      Offline Judge 1.5      *"
echo -e	"\t\t\t*        Khanh Do Ngoc        *"
echo -e "\t\t\t*******************************"
#------------------------------------------------------------------------------------------------------#

declare PosArgument=0
#-------------------------------------Load Contestants-------------------------------------------------#
declare contestant
let 'PosArgument=PosArgument+1'
nc=${!PosArgument}
if [ "$nc" == "all" ]; then
	cd contestant
	for D in *; do
		if [ -d $D ]; then
			contestant=(${contestant[@]} $D)
		fi
	done
	cd ..
else
	for (( i = 0; i < nc; ++i )); do
		let 'PosArgument=PosArgument+1'
		if [ -d contestant/${!PosArgument} ]; then
			contestant=(${contestant[@]} ${!PosArgument})
		fi
	done
fi
#------------------------------------------------------------------------------------------------------#

#-------------------------------------Load Problems----------------------------------------------------#
declare problem
let 'PosArgument=PosArgument+1'
np=${!PosArgument}
if [ "$np" == "all" ]; then
	cd material
	for D in *; do
		if [ -d $D ]; then
			problem=(${problem[@]} $D)
		fi
	done
	cd ..
else
	for (( i = 0; i < np; ++i )); do
		let 'PosArgument=PosArgument+1'
		if [ -d material/${!PosArgument} ]; then
			problem=(${problem[@]} ${!PosArgument})
		fi
	done
fi
#------------------------------------------------------------------------------------------------------#

echo Contestants: ${contestant[@]}						#	Print contestants' name
echo Problems: ${problem[@]}							#	Print problems' name

#------------------------------------Judging-----------------------------------------------------------#
# Creating result Directory
if [ ! -d result ]; then
	mkdir result
fi
rm -rf result/*

# Judge for each contestant
for C in ${contestant[@]}; do
    echo $C
	echo $C >> result/result.txt
	echo $C >> result/detail.txt
	expression='0'
	for P in ${problem[@]}; do
		echo -e "\t$P" >> result/detail.txt
        point="Judgement failed"
		if [ -f contestant/$C/$P.cpp ]; then
			echo -en "\r\033[K\t$P: Compiling..."
			g++ -static -fno-optimize-sibling-calls -fno-strict-aliasing -lm -s -x c++ -O2 -o $P.exec contestant/$C/$P.cpp > /dev/null 2> /dev/null
            if [ $? -ne 0 ]; then
                point="Compile error"
                rm $P.exec > /dev/null 2> /dev/null
            else
                cd material/$P
                mv ../../$P.exec .
                chmod a+x run.sh
				./run.sh $P 2> /dev/null
				point=$(cat result.txt)
				expression+='+'
				expression+=$point
				rm result.txt
                cd ../..
            fi
        else
            point="File not found"
		fi
        echo -e "\t$P: $point" >> result/result.txt
        echo -e "\t\tPoint: $point\n" >> result/detail.txt
        echo -e "\r\033[K\t$P: $point"
	done
	res=$(python -c 'print '$expression)
	echo -e "\tTotal: $res\n" >> result/detail.txt
	echo -e "\tTotal: $res\n" >> result/result.txt
    echo -e "\tTotal: $res"
done
#------------------------------------------------------------------------------------------------------#
