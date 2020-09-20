#!/bin/bash
BASE_DIR=$(cd $(dirname $0)/..; pwd)
$BASE_DIR/generate.py info.toml --only-html --htmldir $BASE_DIR/html

PROBLEM=$(basename $PWD)
cat $BASE_DIR/common/header.html $BASE_DIR/html/$PROBLEM.html > $BASE_DIR/html/$PROBLEM.view.html
