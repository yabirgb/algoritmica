#/bin/bash

files=(burbuja insercion seleccion mergesort quicksort heapsort)
cuadraticos=(burbuja insercion seleccion)
logaritmos=(mergesort quicksort heapsort)
plots="plots"
data="output"
level=$1

#Plot data with dots

for file in "${files[@]}"
do
    
gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia ${file} -O${level}"   
        set term png
        set output "${plots}/${file}_O${level}_points.png"
        plot "${data}/${file}_O${level}.dat" notitle
EOF
done


#Plot data with lines

for file in "${files[@]}"
do
    
gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia ${file} -O${level}"   
        set term png
        set output "${plots}/${file}_O${level}_lines.png"
        plot "${data}/${file}_O${level}.dat" notitle with lines
EOF
done

#Fit data

for file in "${cuadraticos[@]}"
do
    
gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia híbrida ${file} -O${level}"   
        set term png
        set output "${plots}/${file}_O${level}_fit.png"
	set fit logfile 'fit_data/${file}_O${level}_fit.log'
	f(x) = a*x**2 + b*x + c
        fit f(x) "${data}/${file}_O${level}.dat" via a,b,c
	plot "${data}/${file}_O${level}.dat", f(x)
EOF
done

for file in "${logaritmos[@]}"
do
    
gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia híbrida ${file} -O${1}"   
        set term png
        set output "${plots}/${file}_O${level}_O${1}_fit.png"
	set fit logfile 'fit_data/${file}_${1}_fit.log'
	f(x) = a*log(x+b) + c
        fit f(x) "${data}/${file}_O${level}.dat" via a,b,c
	plot "${data}/${file}_O${level}.dat", f(x)
EOF
done
