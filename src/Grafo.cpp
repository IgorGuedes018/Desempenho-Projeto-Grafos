#include "../include/Grafo.h"


Grafo::Grafo(){

}

/**
 * @brief Insere um nó no grafo.
 * @param idNo Identificador único do nó.
 * @param x Coordenada x do nó.
 * @param y Coordenada y do nó.
 * @return Ponteiro para o nó recém-inserido.
 */
No *Grafo::insereNo(int idNo, float x, float y){

    No *novoNo = new No(idNo, x, y);

    if(this->raiz == nullptr){
        this->raiz = novoNo;
        this->ultimoNo = this->raiz;
        return this->raiz;
    }

    this->ultimoNo->setProxNo(novoNo);
    this->ultimoNo = novoNo;

    return this->ultimoNo;
}

/**
 * @brief Função para imprimir os nós do grafo.
 */
void Grafo::imprimeGrafo(){
    No *no = this->raiz;
    while(no != nullptr){
        cout<< no->getIdNo() << " " << no->getDemanda() << " " <<no->getDeposito() << endl;
        no = no->getProxNo();
    }
}

/**
 * @brief Busca um nó no grafo pelo ID.
 * @param idNo O ID do nó a ser buscado.
 * @return Um ponteiro para o nó encontrado ou nullptr se não for encontrado.
 */
No* Grafo::buscaNo(int idNo){
    No *no = this->raiz;

    while(no != nullptr){
        if(no->getIdNo() == idNo){
            return no;
        }
        no = no->getProxNo();
    } 

    return nullptr;

}