#ifndef PROBLEMA_H
#define PROBLEMA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "Grafo.h"

using namespace std;
class Grafo;

class Problema {
private:
    
    int numCaminhoes;
    int solucaoOtima;
    int dimensao;
    int capacidadeCaminhao;
    vector<vector <float>> matrizDistancia;
    Grafo *g = nullptr;

public:
    
    Problema(string arquivo);
    ~Problema();

    void calculaMatrizDitancia();
    float calcularDistanciaEuclidiana(float x1, float y1, float x2, float y2);
    void insereArestas();
    void auxLer(string nomeArquivo);

    int getNumCaminhoes(){return numCaminhoes;};
    int getSolucaoOtima(){return solucaoOtima;};
    int getDimensao(){return dimensao;};
    int getCapacidadeCaminhao(){return capacidadeCaminhao;};
    vector<vector <float>> getMatrizDistancia(){return matrizDistancia;};
    Grafo *getGrafo(){return g;};
    
};

#endif // PROBLEMA_H