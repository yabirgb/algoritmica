ALG="comparacion"
plots="plots"


#gnuplot <<- EOF
#        set xlabel "Tamaño del vector"
#        set ylabel "Tiempo (seg)"
#        set title "Comparativa de los algoritmos -O2"   
#       set terminal pngcairo size 1280,720 enhanced font 'Arial,10'
#        set output "${plots}/$1$2.png"
#        plot "data/$1$2.out" using 1:2 smooth unique title "Algoritmo divide y vencerás", "data/$1$2.out" using 1:3 smooth unique title "Lectura lineal"
#EOF

gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Comparativa de los algoritmos -O2"   
       	set terminal pngcairo size 1280,720 enhanced font 'Arial,12'
        set output "${plots}/copia_4.png"
	set key left top
        plot "data/copia_4.out" using 1:2 smooth unique title "Algoritmo divide y vencerás" linecolor rgb 'blue' lw 3, "data/copia_4.out" using 1:3 smooth unique title "Lectura lineal" linecolor rgb 'red' lw 3
EOF


gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia híbrida del algoritmo divide y vencerás"   
        set terminal pngcairo size 1280,720 enhanced font 'Arial,10'
        set output "${plots}/hibrida2.png"
	f(x) = b*log(x+c)+a
        fit f(x) "data/copia_4.out" using 1:2 via a,b,c
	plot "data/copia_4.out" using 1:2 lt rgb '#009999' lw 1.5, f(x) linecolor rgb '#ff3300' lw 3
EOF

gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Eficiencia híbrida del algoritmo divide y vencerás"   
        set terminal pngcairo size 1280,720 enhanced font 'Arial,10'
        set output "${plots}/hibrida_lineal.png"
	f(x) = b*x+a
        fit f(x) "data/copia_4.out" using 1:2 via a,b
	plot "data/copia_4.out" using 1:2 lt rgb '#009999' lw 1.5, f(x) linecolor rgb '#ff3300' lw 3
EOF

gnuplot <<- EOF
        set xlabel "Tamaño del vector"
        set ylabel "Tiempo (seg)"
        set title "Comparativa de los algoritmos -O2"   
       set terminal pngcairo size 1280,720 enhanced font 'Arial,10'
        set output "${plots}/segundoDyV.png"
        plot "data/dyv_1.out" using 1:3 smooth unique title "Segunda implementación" linecolor rgb 'blue', "data/dyv_1.out"  using 1:2 smooth unique title "Primera implementación" linecolor rgb 'red'
EOF


