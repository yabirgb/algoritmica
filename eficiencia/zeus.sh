#!/bin/bash

rm -r bin/*
rm -r plots/*
rm -r fit_data/*
rm -r output/*

make sort
./auto_test.sh 
./plot.sh 0
