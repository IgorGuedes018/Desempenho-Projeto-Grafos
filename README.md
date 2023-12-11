# Como Executar

Para executar este código, siga os passos abaixo:

1. **Compilação do código:** Utilize o seguinte comando para compilar o código-fonte:

    ```
    g++ -g main.cpp ./src/*.cpp -o ./main
    ```

2. **Execução do programa:** Após a compilação bem-sucedida, execute o programa com o seguinte comando:

    ```
    ./main {ArquivoDeEntrada} {AlgoritmoDeSuaEscolha} {Alfa (Se Adaptativo ou Reativo)} {NúmeroDeInterações (Se Adaptativo ou Reativo)} {arquivoSaida}
    ```

    **Ops.: É necessário passar os parâmetros alfa e número de interações mesmo nos algoritimos que não necessitam deles(basta mandar 0)**

## Lista de algoritmos disponíveis:

- **1 => Guloso**
- **2 => Guloso Randomizado Adaptativo**
- **3 => Guloso Randomizado Adaptativo Reativo**

Outra forma de rodar o programa é inserir o comando desejado no arquivo `exec.sh` e executar o arquivo usando `./exec.sh` (no Linux, talvez seja necessário permissão de execução usando `chmod`).

Lembre-se de substituir `{ArquivoDeEntrada}`, `{AlgoritmoDeSuaEscolha}`, `{Alfa}`, `{NúmeroDeInterações}` e `{arquivoSaida}` pelos valores correspondentes que você deseja utilizar.

# Especificação da Atividade Avaliativa

## Trabalho Prático em Grupo - Etapa 2

### Objetivo
Estender o Tipo Abstrato de Dados (TAD) ou classe desenvolvidos no Trabalho 1 para representar grafos conforme definido pelo problema escolhido pelo grupo.

### Algoritmos a serem implementados
- Algoritmo guloso
- Algoritmo guloso randomizado adaptativo
- Algoritmo guloso randomizado adaptativo reativo

#### Observações
- O arquivo de entrada seguirá o formato definido pelo benchmark específico do problema escolhido.
- Deve ser apresentado um arquivo de texto descrevendo como o programa deve ser executado em linha de comando, especificando o algoritmo a ser executado, os parâmetros (número de iterações, semente de randomização, etc.) e o arquivo de saída.
- Devido à natureza estocástica dos algoritmos, é recomendado buscar orientação do professor para a análise adequada dos resultados.
- O design de experimento foi detalhado em sala, e cada grupo deve gerenciar o tempo para garantir a entrega dentro do prazo.

### Entrega
- Um relatório em formato LaTex deve ser enviado via Classroom. O relatório deve informar as decisões de projeto e implementação, fundamentadas nas dificuldades enfrentadas, referentes à parte 2 da implementação, além de exemplos das saídas do programa para as funcionalidades solicitadas. O relatório não deve ultrapassar 15 páginas, sem listagens de código fonte e com pseudocódigo numerado.

## Seminário
### Objetivo
Avaliar o uso de algoritmos gulosos e estocásticos em problemas NP-Completo modelados em Grafos através da apresentação de seminário.

### Apresentação
- Descrição do problema
- Algoritmos implementados
- Análise de resultados em comparação com trabalhos correlatos da literatura
- Conclusões

Obs: A estrutura do seminário deve seguir elementos similares à estrutura do relatório do trabalho prático.

## Perguntas Frequentes
- Mudanças na composição do grupo devem ser informadas imediatamente após a postagem da especificação no Classroom.
- O projeto pode ter mais de um arquivo fonte (c, cc, cpp e h).
- A avaliação individual considera interação com o professor, envolvimento nas decisões de projeto, participação na apresentação do seminário e feedback dos colegas na autoavaliação do grupo.

## Distribuição de Pontos
- Relatório: 5 pontos
- Funcionalidade e corretude:
  - Guloso: 4 pontos
  - Guloso Randomizado: 6 pontos
  - Guloso Randomizado Reativo: 10 pontos

## Questões sobre Bugs
- Desconto na nota dependerá da gravidade do bug. Menor desconto se o bug for informado no relatório. Nota zero se o código não compilar.

Tenham todos um bom trabalho!
Prof. Stênio
