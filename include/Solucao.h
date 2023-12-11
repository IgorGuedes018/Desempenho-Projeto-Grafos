#ifndef SOLUCAO_H
#define SOLUCAO_H
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <random>
//#include "Aresta.h"
#include "Problema.h"
#include "Valida.h"
#include "No.h"

using namespace std;
class Problema;
class No;
//class Aresta;

class Solucao {
private:
    
    //vector<Aresta> resultado;
    Problema *p;
    float comparacao;
    float custoTotal = 0;
    vector<vector<int>> resultado;

public:
    
    Solucao(Problema *p);
    ~Solucao();

    vector<vector<int>> guloso();
    vector<vector<int>> getResultado(){return resultado;};
    float getComparacao(){return comparacao;};
    float getCustoTotal(){return custoTotal;};
    vector<vector<int>> gulosoAdptativo(float alfa, int numIter);
    vector<vector<int>> gulosoReativo(vector<float> alfas, int numIter, int bloco);
    
};

#endif // SOLUCAO_H