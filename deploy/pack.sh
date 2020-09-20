#!/bin/bash

BASE_DIR=$(cd $(dirname $0)/..; pwd)

cd $BASE_DIR
rm -r pack
mkdir pack
mkdir pack/data
mkdir pack/html

DATA_DIR=$BASE_DIR/pack/data
HTML_DIR=$BASE_DIR/pack/html

if [ $# -ne 1 ]; then
  echo specify start index 1>&2
  exit 1
fi

index=$1

judgedata_path="./judgedata"

find $BASE_DIR -name "info.toml" | sort | while read inpath; do
    PROB_DIR=$(dirname $inpath);
    PROB_NAME=$(basename $PROB_DIR);
    cd $PROB_DIR
    echo $PROB_NAME $index
    mv $judgedata_path $DATA_DIR/$index
    mv $BASE_DIR/html/$PROB_NAME.html $HTML_DIR/$index.html
    index=$(($index+1))
done
