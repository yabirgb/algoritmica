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
    echo "touch ${out}/${filen}_O${VERSION}.dat"
    while [ $i -le $total ]
    do
          echo -ne "$i"'\r'
	  ./${BIN}/${filen}_O${VERSION} $i >> ${out}/${filen}_O${VERSION}.dat
	  i=$((i + 1000))
    done
done

#Test hanoi

echo "Working on hanoi"

i=5
while [ $i -le 31 ]
do
    echo -ne "$i"'\r'
    ./${BIN}/hanoi_O${VERSION} $i >> ${out}/hanoi_O${VERSION}.dat
    i=$((i + 1))
done

#Test floyd
echo "Working on floyd"
i=25
while [ $i -le 910 ]
do
    echo -ne "$i"'\r'
    ./${BIN}/floyd_O${VERSION} $i >> ${out}/floyd_O${VERSION}.dat
    i=$((i + 35))
done
