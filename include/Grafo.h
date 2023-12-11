#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include "No.h"
#include "Aresta.h"

using namespace std;
class No;

class Grafo {
private:
    
    No *raiz = nullptr;
    No *ultimoNo = nullptr;
    int ordem;

public:
    Grafo();
    ~Grafo();

    No *insereNo(int idNo, float x, float y);
    No *buscaNo(int idNo);
    No* getRaiz(){return raiz;};
    void imprimeGrafo();

};

#endif // GRAFO_H