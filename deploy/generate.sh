#!/bin/bash

BASE_DIR=$(cd $(dirname $0)/..; pwd)

find $BASE_DIR -name "info.toml" | sort | while read inpath; do
    PROB_DIR=$(dirname $inpath);
    cd $PROB_DIR
    echo $PWD
    ../common/htmlgen.sh
    ../deploy/special.sh
done
