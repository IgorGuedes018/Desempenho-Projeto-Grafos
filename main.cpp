#include <iostream>
#include "./include/Problema.h"
#include "./include/Solucao.h"
#include "./include/Valida.h"
#include <string>
#include <chrono>

using namespace std;

int renameInstance(string entrada)
{

    if (entrada == "instancias/A-n34-k5.txt")
    {
        return 1;
    }
    if (entrada == "instancias/A-n48-k7.txt")
    {
        return 2;
    }
    if (entrada == "instancias/B-n34-k5.txt")
    {
        return 3;
    }
    if (entrada == "instancias/B-n50-k8.txt")
    {
        return 4;
    }
    if (entrada == "instancias/Golden_1.txt")
    {
        return 5;
    }
    if (entrada == "instancias/Golden_17.txt")
    {
        return 6;
    }
    if (entrada == "instancias/M-n101-k10.txt")
    {
        return 7;
    }
    if (entrada == "instancias/M-n151-k12.txt")
    {
        return 8;
    }
    if (entrada == "instancias/X-n101-k25.txt")
    {
        return 9;
    }
    if (entrada == "instancias/X-n280-k17.txt")
    {
        return 10;
    }
    return 0;
}

int main(int argc, char *argv[])
{

    if (argc != 6)
    {
        cout << "ERRO: quantidade de parametros invalidos";
        return 0;
    }

    // declaracoes de entrada
    string arquivo_entrada = argv[1];
    int algoritmo = stoi(argv[2]);
    float alfa = stof(argv[3]);
    int numInteracoes = stoi(argv[4]);
    string saida = argv[5];
    // string saida = "AlgoritmoGulosoReativoDesempenho.txt";
    string result;

    // ARQUIVO SAIDA
    ofstream arquivo_saida(saida, std::ios::app);
    if (!(arquivo_saida.is_open()))
    {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return 0;
    }

    int instance = renameInstance(arquivo_entrada);

    cout << "===================================================================================================================================================================================" << endl;

    // declaracoes do algoritmo
    Problema *p = new Problema(arquivo_entrada);
    Solucao *s = new Solucao(p);
    vector<vector<int>> rotas;

    auto start_time = chrono::high_resolution_clock::now();

    // ALGORITMO:
    vector<float> alfas = {0.1, 0.7, 0.5, 0.8, 0.3};
    rotas = s->gulosoReativo(alfas, numInteracoes, static_cast<int>(numInteracoes * 0.10));

    auto end_time = chrono::high_resolution_clock::now();

    // calculo
    auto duration = chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count();

    double durationInSeconds = static_cast<double>(duration); // Convertendo de milissegundos para segundos

    /*
    if (algoritmo == 1)
    {
        rotas = s->guloso();
    }
    else if (algoritmo == 2 && alfa != 0)
    {
        rotas = s->gulosoAdptativo(alfa, numInteracoes);
    }
    else if (algoritmo == 3 && numInteracoes != 0)
    {

    }
    else
    {
        cout << "Algum valor de entrada esta invalido";
        return 0;
    }
    */

    result = "========================================================== " + arquivo_entrada + " (" + to_string(instance) + ")" + " Alfa: " + to_string(alfa) + " ===============================================================================================\n";
    Valida *v = new Valida(rotas, p);

    /*
    for (size_t i = 0; i < rotas.size(); ++i)
    {
        result += "Rota " + to_string(i + 1) + ": ";
        for (size_t j = 0; j < rotas[i].size(); ++j)
        {
            if (j == rotas[i].size() - 2)
            {
                result += "Capacidade sobrando: ";
            }
            else if (j == rotas[i].size() - 1)
            {
                result += "Custo da rota: ";
            }

            result += to_string(rotas[i][j]) + " ";
        }
        result += "\n";
    }
    */
    result += "Custo Total: " + to_string(s->getCustoTotal()) + "\n";
    result += "Solucao Otimo: " + to_string(p->getSolucaoOtima()) + "\n";

    // porcentagem diferenca
    double porcentagemAcimaOtimo = ((s->getCustoTotal() - p->getSolucaoOtima()) / p->getSolucaoOtima()) * 100;
    result += "Valor acima da Solucao Otima: " + to_string(s->getCustoTotal() - p->getSolucaoOtima()) + " que tem porcentagem: " + to_string(porcentagemAcimaOtimo) + "% \n";
    result += "Tempo de duracao do Algoritmo Guloso Reativo: " + to_string(durationInSeconds) + " milissegundos \n";

    // validacao
    if (!v->validar())
    {
        if (!v->getAtendeuTodos())
        {
            result += "A solução não atendeu todos os clientes! \n";
        }
        if (!v->getUnicoEmRota())
        {
            result += "Os nós não são únicos nas rotas!\n";
        }
    }

    // ARQUIVO DE SAIDA
    arquivo_saida << result << std::endl;
    arquivo_saida.close();
    cout << "String escrita no arquivo com sucesso. (" << instance << ") " << alfa << endl;

    return 0;
}