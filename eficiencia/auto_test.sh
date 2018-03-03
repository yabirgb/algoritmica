#!/bin/bash
i=500
BIN="bin/"

#array=${ls -d $BIN}
VERSION=0
total = 25000
arr=(burbuja insercion seleccion mergesort quicksort heapsort)

for filen in "${arr[@]}"
do
    echo "Working on $filen"
    i=0
    echo "" > salida_$filen.dat
    while [ $i -le 25000 ]
    do
          echo -ne "$i"'\r'
	  ./${BIN}/${filen}_O${VERSION} $i >> salida/${filen}_O${VERSION}.dat
	  i=$((i + 500))
    done
done
