#ifndef NO_H
#define NO_H
#include <iostream>
#include "Aresta.h"

using namespace std;
class Aresta;

class No {
private:
    int idNo;
    int demanda;
    bool deposito = false;
    bool visitado = false;
    float x;
    float y;
    No *proxNo = nullptr;
    Aresta *primeiraAresta = nullptr;
    Aresta *ultimaAresta = nullptr;

public:

    No(int idNo, float x, float y);
    ~No();

    int getIdNo(){return idNo;};
    int getDemanda(){return demanda;};
    int getDeposito(){return deposito;};
    bool getVisitado(){return visitado;};
    void setVisitado(bool visitado);
    float getX(){return x;};
    float getY(){return y;};
    No * getProxNo(){return proxNo;};
    Aresta * getPrimeiraAresta(){return primeiraAresta;}
    Aresta * getUltimaAresta(){return ultimaAresta;}

    void setProxNo(No *no);
    void setDemanda(int demanda);
    void setDeposito();
    Aresta * insertAresta(int destino, float peso);
};

#endif // NO_H