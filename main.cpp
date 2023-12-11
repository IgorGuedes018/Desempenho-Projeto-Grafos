#include <iostream>
#include "./include/Problema.h"
#include "./include/Solucao.h"
#include "./include/Valida.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    
    if(argc != 6){
        cout << "ERRO: quantidade de parametros invalidos";
        return 0;
    }

    // declaracoes de entrada
    string arquivo_entrada = argv[1];
    int algoritmo = stoi(argv[2]);
    float alfa = stof(argv[3]);
    int numInteracoes = stoi(argv[4]);
    string saida = argv[5];
    string result;
    
    // ARQUIVO SAIDA
    ofstream arquivo_saida(saida, std::ios::app);
    if (!(arquivo_saida.is_open()))
    {
        cout << "Erro ao abrir o arquivo de saída." << endl;
        return 0;
    }
    
    cout << "===================================================================================================================================================================================" << endl;

    // declaracoes do algoritmo
    Problema *p = new Problema("instancias/" + arquivo_entrada);
    Solucao *s = new Solucao(p);
    vector<vector<int>> rotas;

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
        vector<float> alfas = {0.1, 0.7, 0.5, 0.8, 0.3};
        rotas = s->gulosoReativo(alfas, numInteracoes, static_cast<int>(numInteracoes * 0.10));
    }
    else
    {
        cout << "Algum valor de entrada esta invalido";
        return 0;
    }

    result = "========================================================== Instancia " + arquivo_entrada + " ===============================================================================================\n";
    Valida *v = new Valida(rotas, p);

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
    result += "Custo Total: " + to_string(s->getCustoTotal()) + "\n";
    result += "Solucao Otimo: " + to_string(p->getSolucaoOtima()) + "\n";

    //porcentagem diferenca
    double porcentagemAcimaOtimo = ((s->getCustoTotal() - p->getSolucaoOtima()) / p->getSolucaoOtima()) * 100;
    result += "Valor acima da Solucao Otima: " + to_string(s->getCustoTotal() - p->getSolucaoOtima()) + " que tem porcentagem: " + to_string(porcentagemAcimaOtimo) + "% \n";

    //validacao
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
    cout << "String escrita no arquivo com sucesso." << endl;

    return 0;
}