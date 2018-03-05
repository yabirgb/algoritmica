

from itertools import repeat
#This part of the code is to get the data from files and store it in a hash table

algs = ("burbuja", "heapsort", "insercion", "mergesort", "quicksort", "seleccion", "floyd", "hanoi")

mensajes = {
    "burbuja": "ordenación usando el algoritmo de burbuja",
    "heapsort": "ordenación usando el algoritmo heapsort",
    "insercion": "ordenación usando el algoritmo de insercción",
    "mergesort": "ordenación usando el algoritmo mergesort",
    "quicksort": "ordenación usando el algoritmo quicksort",
    "seleccion": "ordenación usando el algoritmo de selección",
    "floyd": "algoritmo para calculo de costo floyd",
    "hanoi": "calculo de los movimientos en las torres de hanoi"
}


def tablas(optimizacion):
    data = {}
    optimization = 0

    for alg in algs:
        name = "output/{}_O{}.dat".format(alg, optimization)
        data[alg] = []
        with open(name, "r") as f:
            for line in f:
                #This is because i forgot to forma data well in one file
                info = line.replace("\n","").split('\t')
                info = [x for x in info if x != ""]
                data[alg].append(info[1])

    #print(data)
    
    #Now that we got the data, we create the latex table
    
    output_files = (("report/tables/ordenacionC{}.tex", "Tamaño Burbuja Insercción Selección",0 , 1000, "burbuja", "insercion", "seleccion"),
                    ("report/tables/ordenacionL{}.tex", "Tamaño Mergesort Quicksort Heapesort",0 , 1000, "mergesort", "quicksort", "heapsort"),
                    ("report/tables/floyd{}.tex", "Tamaño Floyd",25 , 35, "floyd"),
                    ("report/tables/hanoi{}.tex", "Tamaño Hanoi",5 , 31, "hanoi"),)
    for pick in output_files:
        header = """\\begin{tabular}[H]{|llll|}
\\hline\n"""
    
        footer = """
\\end{tabular}"""

        body = ""
            
        output, titles, start, increment, *sources = pick

        #Create a line for each size
        lines = zip(*[data[x] for x in sources])

        #Add headers
        for title in titles.split(" ")[:-1]:
            body += "\\textbf{{{}}} & ".format(title)

        body += "\\textbf{{{}}} \\\\ \hline\n".format(titles.split(" ")[-1])

    
        #We try to abstract the format
        size = start
        for line in lines:
            body += "{} & ".format(size) 
            for measure in line[:-1]:
                body += "{} & ".format(measure)

            body += "{} \\\\ \hline\n".format(line[-1])

            size+= increment
        result = header + body + footer


        with open(output.format(optimizacion), "w") as f:
            f.write(result)

def stripe(alg, version, linea, lineb):

    with open("fit_data/{}_O{}_fit.log".format(alg, version), "r") as f:
        data = ""
        for i, line in enumerate(f):
            if i >= linea and i <= lineb:
                data += line
                
        return data
def images(version):

    lines = 182

    for alg in algs:

        text="""
\\begin{{figure}}[H]%
    \centering
    \subfloat[Nube de puntos]{{\includegraphics[width=0.5\\textwidth]{{../plots/{}_O{}_points.png}}}}%
    \subfloat[Función continua]{{\includegraphics[width=0.5\\textwidth]{{../plots/{}_O{}_lines.png}}}}%
    \caption{{Resultados experimentales representados mediante una nube de puntos y la linea que los une}}%
    \centering
    \subfloat{{\includegraphics[width=0.6\\textwidth]{{../plots/{}_O{}_fit.png}}}}%
    \caption{{Ajuste para: {}}}%
\end{{figure}}

\\begin{{verbatim}}
{}
\end{{verbatim}}
"""

        rep = repeat([alg, version],3)
        usar = []

        for pair in rep:
            usar += pair

        usar.append(mensajes[alg])
        if alg == "hanoi":
            usar.append(stripe(alg, version, 357, 361))
        elif alg == "floyd":
            usar.append(stripe(alg, version, 401, 407))
        else:
            usar.append(stripe(alg, version, lines , lines +6))
        

        with open("report/images/{}_{}_images.tex".format(alg, version), "w") as f:
            f.write(text.format(*usar))

tablas(0)
tablas(1)
tablas(2)
images(0)
