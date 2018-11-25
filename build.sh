#!/bin/bash

#----------------------AWK Code Generator------------------------
cd src/codegen

awk -v pass=h  -f object.awk object.txt >  ../include/object.h
awk -v pass=c1 -f object.awk object.txt >  ../src/object.c
awk -v pass=c2 -f object.awk object.txt >> ../src/object.c

cd ../..
#----------------------------------------------------------------

# build
cmake . && make

# clean project
make clean-all
