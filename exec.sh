#g++ -g main.cpp ./src/*.cpp -o ./main && ./main A-n34-k5.txt 1 0.37 10 arquivoSaida.txt

#!/bin/bash


    g++ -g main.cpp ./src/*.cpp -o ./main && ./main instancias/A-n34-k5.txt 1 0.37  arquivoSaida.txt


for value in 10 100 1000; do
    for file in instancias/*
    do
        g++ -g main.cpp ./src/*.cpp -o ./main && ./main "$file" 1 0.37 "$value" arquivoSaida.txt
    done
done



