#!/bin/bash

BASE_DIR=$(cd $(dirname $0)/..; pwd)
judgedata_path="./judgedata/"

input(){
    find . -wholename "./in" | while read inpath; do
        inputfiles=`ls $inpath | grep ".in$"`
        cnt=1
        for i in $inputfiles
        do
            echo $cnt $i
            echo $cnt $i | cat >> $judgedata_path"/"case_mapping.txt
	    cp $inpath"/"$i $judgedata_path"/in"$cnt".txt"
	    cnt=$(($cnt + 1))
        done
        cnt=$(($cnt - 1))
        echo $cnt | cat > $judgedata_path"/"case.txt
    done
}

output(){
    find . -wholename "./out" | while read outpath; do
	outputfiles=`ls $outpath | grep ".out$"`
	cnt=1
	for i in $outputfiles
	do
	    cp $outpath"/"$i $judgedata_path"/out"$cnt".txt"
	    cnt=$(($cnt+1))
	done
    done
}

build(){
    cp $BASE_DIR/common/testlib.h $judgedata_path
    cp $BASE_DIR/deploy/build.sh $judgedata_path
    cp checker.cpp $judgedata_path
    cp params.h $judgedata_path
}

rm -r judgedata
mkdir judgedata
input
output
build
