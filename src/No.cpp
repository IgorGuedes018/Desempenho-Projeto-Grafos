#include "../include/No.h"

/**
 * @brief Construtor da classe No.
 * @param id Identificador único do nó.
 * @param x Coordenada x do nó.
 * @param y Coordenada y do nó.
 */
No::No(int id, float x, float y){
    this->idNo = id;
    this->x = x;
    this->y = y;
}

/**
 * @brief Define o próximo nó na lista.
 * @param no Ponteiro para o próximo nó.
 */
void No::setProxNo(No *no){
    this->proxNo = no;
}

/**
 * @brief Define a demanda associada ao nó.
 * @param demanda Valor da demanda.
 */
void No::setDemanda(int demanda){
    this->demanda = demanda;
}

/**
 * @brief Marca o nó como um depósito.
 */
void No::setDeposito(){
    this->deposito = true;
}

/**
 * @brief Define se o nó foi visitado.
 * @param visitado Valor booleano indicando se o nó foi visitado.
 */
void No::setVisitado(bool visitado){
    this->visitado = visitado;
}