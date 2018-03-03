#/bin/bash

FILE="burbuja"

gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia ${FILE} -O0"   
        set term png
        set output "graficas/${FILE}_points.png"
        plot "salida/${FILE}_O0.dat" notitle
EOF
