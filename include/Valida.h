#ifndef VALIDA_H
#define VALIDA_H
#include <iostream>
#include <vector>
#include "Solucao.h"
#include "Problema.h"


using namespace std;
class Problema;
class Solucao;

class Valida {
private:
    
    
    vector<vector<int>> resultado;
    Problema *p;
    bool resultadoValidacao;
    bool atendeuTodos = false;
    bool unicoEmRota = false;


public:
    
    Valida(vector<vector<int>> resultao, Problema *p);
    ~Valida();

    bool validar();
    bool validarTodosPresente();
    bool validarUnicoDeRota();
    bool getAtendeuTodos(){return atendeuTodos;};
    bool getUnicoEmRota(){return unicoEmRota;};
    
};

#endif // VALIDA_H