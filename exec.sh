#g++ -g main.cpp ./src/*.cpp -o ./main && ./main A-n34-k5.txt 1 0.37 10 arquivoSaida.txt

#!/bin/bash


#g++ -g main.cpp ./src/*.cpp -o ./main && ./main instancias/A-n34-k5.txt 1 0.37  arquivoSaida.txt

for alfa in 0.05 0.10 0.15 0.30 0.50; do
    for file in instancias/*
    do
        g++ -g main.cpp ./src/*.cpp -o ./main && ./main "$file" 2 "$alfa" 3000 ""$alfa"AlgoritmoGulosoAdaptativoDesempenho.txt"
    done
done





