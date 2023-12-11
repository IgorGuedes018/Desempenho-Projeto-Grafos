#include "../include/Solucao.h"

/**
 * @brief Construtor da classe Solucao.
 * @param p Ponteiro para o objeto da classe Problema associado à solução.
 */
Solucao::Solucao(Problema *p)
{
    this->p = p;
}

/**
 * @brief Estrutura que representa uma rota no sistema.
 *
 * Uma rota é definida por uma sequência de nós e sua capacidade atual.
 */
struct Rota
{
    vector<int> nos;
    int capacidadeAtual;
};

/**
 * @brief Gera um número aleatório dentro de um intervalo [min, max].
 * @param min Valor mínimo do intervalo.
 * @param max Valor máximo do intervalo.
 * @return Número aleatório gerado.
 */
int randomRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}

/**
 * @brief Implementação do algoritmo guloso para resolver um problema de roteirização.
 * @return Uma matriz representando as rotas calculadas pelo algoritmo.
 */
vector<vector<int>> Solucao::guloso()
{
    int numCaminhoes = p->getNumCaminhoes();
    int capacidadeCaminhao = p->getCapacidadeCaminhao();
    Grafo *grafo = p->getGrafo();
    vector<vector<float>> matrizDistancia = p->getMatrizDistancia();

    vector<Rota> rotas(numCaminhoes);

    No *deposito = grafo->getRaiz();
    deposito->setVisitado(true);

    for (int i = 0; i < numCaminhoes; i++)
    {
        rotas[i].nos.push_back(deposito->getIdNo());
        rotas[i].capacidadeAtual = capacidadeCaminhao;
    }

    for (int i = 0; i < numCaminhoes; i++)
    {
        No *noAtual = deposito;

        float custoDaRota = 0;
        while (true)
        {
            float menorDistancia = numeric_limits<float>::max();
            int proxNo = -1;

            for (int j = 1; j <= p->getDimensao(); j++)
            {
                
                    No *possivelProximoNo = grafo->buscaNo(j);
                    if (!possivelProximoNo->getVisitado() && matrizDistancia[noAtual->getIdNo() - 1][possivelProximoNo->getIdNo() - 1] < menorDistancia &&
                        possivelProximoNo->getDemanda() <= rotas[i].capacidadeAtual)
                    {
                        menorDistancia = matrizDistancia[noAtual->getIdNo() - 1][possivelProximoNo->getIdNo() - 1];
                        proxNo = possivelProximoNo->getIdNo();
                    }
                
            }

            if (proxNo == -1)
            {
                rotas[i].nos.push_back(deposito->getIdNo());
                custoDaRota += matrizDistancia[noAtual->getIdNo() - 1][0];
                break;
            }

            custoDaRota += menorDistancia;
            No *proximoNo = grafo->buscaNo(proxNo);
            proximoNo->setVisitado(true);
            rotas[i].nos.push_back(proximoNo->getIdNo());
            rotas[i].capacidadeAtual -= proximoNo->getDemanda();
            noAtual = proximoNo;
        }

        rotas[i].nos.push_back(rotas[i].capacidadeAtual);
        rotas[i].nos.push_back(custoDaRota);
        this->custoTotal += custoDaRota;
    }

    vector<vector<int>> resultado;
    for (const auto &rota : rotas)
    {
        resultado.push_back(rota.nos);
    }

    No *n = p->getGrafo()->getRaiz();

    while (n != nullptr)
    {
        if (n->getVisitado() == false)
        {
            cout << "Solução invalida, nó " << n->getIdNo() << " não visistado!" << endl;
        }
        n = n->getProxNo();
    }

    this->resultado = resultado;

    return this->resultado;
}

/**
 * @brief Executa o algoritmo de construção de rotas guloso adaptativo.
 * @param alfa Parâmetro de controle da probabilidade de escolha do melhor candidato (0 <= alfa <= 1).
 * @param numIter Número de iterações do algoritmo.
 * @return Uma solução de rotas gerada pelo algoritmo.
 */
vector<vector<int>> Solucao::gulosoAdptativo(float alfa, int numIter)
{
    vector<vector<int>> solBest;
    float custoBest = numeric_limits<float>::max();

    int numCaminhoes = p->getNumCaminhoes();
    int capacidadeCaminhao = p->getCapacidadeCaminhao();
    vector<vector<float>> matrizDistancia = p->getMatrizDistancia();
    Grafo *grafo = p->getGrafo();

    for (int i = 0; i < numIter; ++i)
    {
        vector<int> clientesRestantes;
        for (int j = 2; j <= p->getDimensao(); ++j)
        {
            clientesRestantes.push_back(j);
        }

        vector<vector<int>> rotas;

        for (int caminhao = 0; caminhao < numCaminhoes; ++caminhao)
        {
            float capacidadeAtual = capacidadeCaminhao;
            vector<int> rota;
        
            int atual = 1;
            rota.push_back(1);

            while (!clientesRestantes.empty())
            {
                vector<pair<float, int>> candidatosViaveis;
                for (int cliente : clientesRestantes)
                {
                    if (capacidadeAtual - grafo->buscaNo(cliente)->getDemanda() >= 0)
                    {
                        candidatosViaveis.push_back(make_pair(matrizDistancia[cliente - 1][rota[rota.size() - 1] - 1], cliente));
                    }
                }

                if (!candidatosViaveis.empty())
                {
                    sort(candidatosViaveis.begin(), candidatosViaveis.end(),
                         [](const auto &a, const auto &b)
                         {
                             return a.first < b.first;
                         });

                    int k = randomRange(0, alfa * (candidatosViaveis.size() - 1));

                    int escolha = candidatosViaveis[k].second;

                    rota.push_back(escolha);

                    atual = escolha;
                    capacidadeAtual -= grafo->buscaNo(escolha)->getDemanda();

                    clientesRestantes.erase(find(clientesRestantes.begin(), clientesRestantes.end(), escolha));
                }
                else
                {
                    break;
                }
            }

            rota.push_back(1);
            rota.push_back(capacidadeAtual);
            rotas.push_back(rota);
        }

        float custoTotal = 0;
        for (auto &rota : rotas)
        {
            float custoRota = 0;
            for (size_t i = 1; i < rota.size() - 1; ++i)
            {
                custoRota += matrizDistancia[rota[i - 1] - 1][rota[i] - 1];
            }
            rota.push_back(custoRota);
            custoTotal += custoRota;
        }

        Valida *v = new Valida(rotas, this->p);

        bool valido = v->validar();

        if (custoTotal < custoBest && valido)
        {
            solBest = rotas;
            custoBest = custoTotal;
            this->custoTotal = custoBest;
        }
    }

    return solBest;
}

/**
 * @brief Executa o algoritmo de construção gulosa reativa.
 * 
 * @param alfas Vetor de parâmetros alfa para ajuste das probabilidades.
 * @param numIter Número total de iterações do algoritmo.
 * @param bloco Número de iterações entre as atualizações das probabilidades.
 * @return Vetor representando a melhor solução encontrada.
 */
vector<vector<int>> Solucao::gulosoReativo(vector<float> alfas, int numIter, int bloco) {
    vector<float> probabilidades(alfas.size(), 1.0 / alfas.size()); // Inicialização das probabilidades

    float melhorSolucao = numeric_limits<float>::max();
    int indiceMelhorAlfa = 0; 
    vector<vector<int>> melhorSolucaoEncontrada;
    
    vector<float> medias(alfas.size(), 0);
    vector<int> contandorMedia(alfas.size(), 0);

    for (int iteracao = 1; iteracao <= numIter; ++iteracao) {

        if (iteracao % bloco == 0) {
            float somatorio = 0.0;
            for (int j = 0; j < alfas.size(); ++j) {
                float qj = pow((melhorSolucao / (medias[j] / contandorMedia[j])), alfas[j]);
                somatorio += qj;
            }

            for (int i = 0; i < probabilidades.size(); ++i) {
                float qi = pow((melhorSolucao / (medias[i] / contandorMedia[i])), alfas[i]);
                probabilidades[i] = qi / somatorio;
            }
        }

     
        float randomValue = static_cast<float>(rand()) / RAND_MAX;
        float acumulado = 0.0;
        int indiceEscolhido = 0;

        for (int i = 0; i < probabilidades.size(); ++i) {
            acumulado += probabilidades[i] * 100; 
            if (randomValue <= acumulado) {
                indiceEscolhido = i;
                break;
            }
        }

        float alfaEscolhido = alfas[indiceEscolhido];
        vector<int> clientesRestantes; 

      
        for (int j = 2; j <= p->getDimensao(); ++j)
        {
            clientesRestantes.push_back(j);
        }

        vector<vector<int>> rotas;

        for (int caminhao = 0; caminhao < p->getNumCaminhoes(); ++caminhao)
        {
            float capacidadeAtual = p->getCapacidadeCaminhao();
            vector<int> rota;
            int custoDaRota = 0;
            int atual = 1; 
            rota.push_back(1);

            while (!clientesRestantes.empty())
            {
                vector<pair<float, int>> candidatosViaveis; 
                for (int cliente : clientesRestantes)
                {
                    if (capacidadeAtual - p->getGrafo()->buscaNo(cliente)->getDemanda() >= 0)
                    {
                        candidatosViaveis.push_back(make_pair(p->getMatrizDistancia()[cliente - 1][rota[rota.size() - 1] - 1], cliente));
                    }
                }

                if (!candidatosViaveis.empty())
                {
                    sort(candidatosViaveis.begin(), candidatosViaveis.end(),
                              [](const auto &a, const auto &b)
                              {
                                  return a.first < b.first;
                              });

                    int k = randomRange(0, alfaEscolhido * (candidatosViaveis.size() - 1));

                    int escolha = candidatosViaveis[k].second;

                    rota.push_back(escolha);

                    atual = escolha;
                    capacidadeAtual -= p->getGrafo()->buscaNo(escolha)->getDemanda();

                    clientesRestantes.erase(find(clientesRestantes.begin(), clientesRestantes.end(), escolha));
                }
                else
                {
                    break; 
                }
            }

            rota.push_back(1);
            rota.push_back(capacidadeAtual);
            rotas.push_back(rota);
        }

        float custoTotal = 0;
        for (auto &rota : rotas)
        {
            float custoRota = 0;
            for (size_t i = 1; i < rota.size() - 1; ++i)
            {
                custoRota += p->getMatrizDistancia()[rota[i - 1] - 1][rota[i] - 1];
            }
            rota.push_back(custoRota);
            custoTotal += custoRota;
        }

        Valida *v = new Valida(rotas, this->p);

        bool valido = v->validar();

        if (custoTotal < melhorSolucao && valido)
        {
            melhorSolucaoEncontrada = rotas;
            melhorSolucao = custoTotal;
            indiceMelhorAlfa = indiceEscolhido;
            this->custoTotal = melhorSolucao;
        }
       

        medias[indiceEscolhido] = (medias[indiceEscolhido] + custoTotal);
        contandorMedia[indiceEscolhido] += 1;
       
        
    }

    return melhorSolucaoEncontrada;
}

