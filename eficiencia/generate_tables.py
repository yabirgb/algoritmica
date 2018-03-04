#This part of the code is to get the data from files and store it in a hash table

algs = ("burbuja", "heapsort", "insercion", "mergesort", "quicksort", "seleccion")


data = {}
optimization = 0

for alg in algs:
    name = "output/{}_O{}.dat".format(alg, optimization)
    data[alg] = []
    with open(name, "r") as f:
        for line in f:
            #This is because i forgot to forma data well in one file
            info = line.replace(" ","\t").replace("\n","").split('\t')
            info = [x for x in info if x != ""]
            data[alg].append(info[1])

#print(data)

#Now that we got the data, we create the latex table

output_files = [("report/tables/ordenacion.tex", "burbuja", "insercion", "seleccion")]

header = """\\begin{center}
  \\begin{tabular}{ l  l  l }
    \hline\n"""

footer = """    \hline
  \end{tabular}
\end{center}"""

body = ""

for pick in output_files:

    output, *sources = pick

    #Create a line for each size
    lines = zip(*[data[x] for x in sources])

    #We try to abstract the format
    for line in lines:
        for measure in line[:-1]:
            body += "{} & ".format(measure)

        body += "{} \\\\ \hline\n".format(line[-1])

    result = header + body + footer


    with open(output, "w") as f:
        f.write(result)

    


