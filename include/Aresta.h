#ifndef ARESTA_H
#define ARESTA_H
#include <iostream>
#include "No.h"

using namespace std;
class No;

class Aresta {
private:
    float distancia;
    int idNoDestino;
    int idNoOrigem;

    Aresta* proxAresta = nullptr;

public: 
    Aresta(int idNoDestino, int idNoOrigem, float distancia);
    ~Aresta();

    float getDistancia(){return distancia;};
    int getIdNoDestino(){return idNoDestino;};
    int getIdNoOrigem(){return idNoOrigem;};
    Aresta *getProxAresta(){return proxAresta;};

    void setProxAresta();
    
};

#endif // ARESTA_H