#!/bin/bash

rm -r bin/*
rm -r plots/*
rm -r fit_data/*
rm -r output/*

make
./auto_test.sh 0
./plot.sh 0
python3 generate_tables.py
cd report
pdflatex main.tex
