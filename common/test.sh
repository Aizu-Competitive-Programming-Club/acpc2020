#!/bin/bash
BASE_DIR=$(cd $(dirname $0)/..; pwd)
$BASE_DIR/generate.py info.toml --dev --htmldir $BASE_DIR/html
