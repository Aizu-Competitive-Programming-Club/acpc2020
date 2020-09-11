#! /bin/bash
#find . -wholename "rime-out/tests"

input(){
    find . -wholename "./in" | while read inpath; do
        judgedata_path="./judgedata/"
        inputfiles=`ls $inpath | grep ".in$"`
        cnt=1
        for i in $inputfiles
        do
	    #echo "cp" $inpath"/"$i $judgedata_path"/in"$cnt".txt"
            echo $cnt $i
            echo $cnt $i | cat >> $judgedata_path"/"case_mapping.txt
	    cp $inpath"/"$i $judgedata_path"/in"$cnt".txt"
	    cnt=$(($cnt + 1))
        done
        cnt=$(($cnt - 1))
        echo $cnt | cat > $judgedata_path"/"case.txt
        #echo $cnt
    done
}

output(){
    find . -wholename "./out" | while read outpath; do
	judgedata_path="./judgedata/"
	outputfiles=`ls $outpath | grep ".out$"`
	cnt=1
	for i in $outputfiles
	do
	    #echo $outpath"/"$i $judgedata_path"/out"$cnt".txt"
	    cp $outpath"/"$i $judgedata_path"/out"$cnt".txt"
	    cnt=$(($cnt+1))
	done
	#echo $cnt
    done
}

build(){
    judgedata_path="./judgedata/"
    cp ../common/testlib.h $judgedata_path
    cp ../common/build.sh $judgedata_path
    cp checker.cpp $judgedata_path
    cp params.h $judgedata_path
}

rm -r judgedata
mkdir judgedata
input
output
build
