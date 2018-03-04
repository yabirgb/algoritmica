#!/bin/bash
i=1000
BIN="bin/"
out="output"
safe=false

#array=${ls -d $BIN}
VERSION=$1
total=25000
files=(burbuja insercion seleccion mergesort quicksort heapsort)

for filen in "${files[@]}"
do
    echo "Working on $filen"
    i=0

    #Clear or not the files before saving data
    if [ "safe" = true ]; then
	echo "" > ${out}/${filen}_O${VERSION}.dat
    else
	echo "" >> ${out}/${filen}_O${VERSION}.dat
    fi
    
    while [ $i -le $total ]
    do
          echo -ne "$i"'\r'
	  ./${BIN}/${filen}_O${VERSION} $i >> ${out}/${filen}_O${VERSION}.dat
	  i=$((i + 1000))
    done
done
