#  Gerenciamento do Estúdio de Tatuagem
- O projeto é um sistema na Linguagem C para gerencamento de um estúdio de tatuagem. Com manipulação dos dados dos Clientes e Tatuagens.

## Desenvolvedores
>   [Artur Carvalho Gama](https://github.com/Arturzip)

>  [José Kayque Lima Lopes](https://github.com/KayqueLopes99)


# Tabela de Conteúdo
1. [Gerenciamento do Estúdio de Tatuagem](#gerenciamento-do-estúdio-de-tatuagem)
2. [Desenvolvedores](#desenvolvedores)
3. [Introdução](#introdução)
4. [Problemática](#problemática)
5. [Requisitos atendidos](#requisitos-atendidos)
6. [Desenvolvimento](#desenvolvimento)
7. [Implementação da (TAD) Tatuagens](#implementação-da-tad-tatuagens)
8. [Implementação da (TAD) Clientes](#implementação-da-tad-clientes)
9. [Compilação](#compilação)
10. [Conclusão e motivação](#conclusão-e-motivação)


## Introdução
- O Gerenciamento de um Estúdio de tatuagem é um método eficiente de conduzir um sistema operacional sem problemas e qualificar o atendimento a todos os clientes. Deste modo, administramos cada funcionalidade para o usuário realizar sua tatuagem e realizar seu cadastramento em nosso sistema. Isso se torna fundamental, diante aos constantes avanços tecnologicos e o crescente adequação de todas as industrias as Tecnologias.

- Nesse projeto, o sistema do Estudio de tatuagens foi estruturado com lista encadeada, para percorer e alterar dados caso necessário.

- As funções manipulam a lista encadeada para adicionar, remover, e editar os dados. Desta forma, A lista encadeada permite um gerenciamento eficiente das tatuagens e dos clientes cadastrados, pois novas tatuagens podem ser adicionadas no início, no meio ou no fim da lista, assim como os dados do usuário e tatuagens e clientes existentes podem ser removidos sem muitas complexidades.

- Além disso, algumas funcionalidades qualificam nosso sistema como a impressão do histórico de tatuagens feitas do cliente, a escolha do cliente na questão do estilo e cor da tatuagem e principalmente a adequação ou mudança da tatuagem.

- Uma lista encadeada consiste em uma sequência de nós. Cada nó contém dois campos: um para armazenar os dados e outro para armazenar a referência ao próximo nó na lista. Assim, de forma mais dinâmica podemos gerenciar os dados, com accesso de cada nó ou implementação dos nós.

- Portanto, o uso da lista encadeada se torna eficiente para lidar com dados que têm um número variável de elementos. Isso é especialmente relevante considerando que é um sistema que nossos futuros clientes irão acessar.

## Problemática
- O sistema de gerenciamento do estúdio de tatuagens, implementado em Linguagem C, tem como objetivo proporcionar um atendimento ao cliente de qualidade, simplificando e gerenciando as operações para o funcionamento eficiente do nosso estúdio. 

- Nosso sistema contém as funcionalidades como adicionar, excluir, buscar e editar as tatuagens e os dados do cliente e listar todo o histórico de tatuagens feitas. 

- Com este sistema, esperamos melhorar a gestão de todos os usuários do estúdio de tatuagens.


## Requisitos atendidos
#### *Atributos do campo Clientes*
 > Nome

 > Email 

 >lista de tatuagens feitas.

#### *Atributos do campo Tatuagens*
> Identificação

> Estilo

> Cores 

> Preço

#### *MENU*

>  Adicionar cliente.

>  Remover cliente.

>  Realizar tatuagem.

>  Remover tatuagem.

>  Editar informação de cliente.

>  Buscar cliente por nome.

>  listar clientes e suas tatuagens.

>  Sair.

-  A cada execução do programa, os dados são carregados(armazenados em um arquivo texto).
- Cada cliente cadastrado é inserido em ordem alfabética.
- Cada nova tatuagem cadastrada é inserida em ordem de identificação.
- O arquivo texto é atualizado na adição e remoção.

## Desenvolvimento
- O sistema é composto por dois Tipos Abstratos de Dados (TADs), dois arquivos de cabeçalho e três arquivos de texto. Estes são designados para tatuagens e clientes, e os arquivos são para dados registrados.
- A organização em pastas melhora a qualidade da organização do sistema.
- A lista encadeada usada, com diferentes funcionalidades em cada função, foi tratada.
- Vários comandos estudados por nós, os contribuidores, foram implementados no sistema.
- No código do nosso sistema foi implementado inúmeras tratativas para qualificar o nosso estúdio de tatuagem.

## Implementação da (TAD) Tatuagens
- Neste tipo estruturado se encontra parte do gerenciamento mais focado nas tatuagens.
## Tipos estruturados
### struct tatuagens:
- Armazena as informações de uma tatuagem individual, incluindo seu identificador, estilo, cores e preço.

```` c 
struct tatuagens
{
    int identificacao;
    char estilo[150];
    char cores[150];
    float preco;
};
````

### struct no: 
- Cria uma lista encadeada de tatuagens. Com sua criação, cada nó na lista contém uma tatuagem e um ponteiro para o próximo nó.

```` c
struct no
{
    Tatuagens tatuagem;
    No *prox;
};
````

### struct leitura:
- Armazena informações sobre um cliente e suas tatuagens. Incluindo o nome do cliente, o número de tatuagens que o cliente possui e um array de IDs de tatuagens, permitindo que mantenha o registro das tatuagens vinculadas ao cliente.

``` c 
struct leitura
{
    char cliente[250];
    int numerodeT;
    int idsT[10];
};
```
## Funções
### Função contaEalocaTatuagens:
```c 
Tatuagens *contaEalocaTatuagens(int *qtd);
```
- Está função Conta o número de linhas (tatuagens), no arquivo texto e aloca memória para armazenar essas tatuagens. 

- A função então aloca memória suficiente para armazenar todas as tatuagens e retorna um ponteiro para o bloco de memória alocado.

### Função verifica_vazio:
````c 
int verifica_vazio(No *l);
````
- Está função verifica se a lista encadeada está vazia, recebendo o primeiro nó.

### Função insereElementosNaLista:
````c 
No *insereElementosNaLista(No *primeiro_no, int id, Tatuagens *aux);
````
- Está função insere uma nova tatuagem na frente de uma lista encadeada de tatuagens. Com a criação de um novo nó e copia os detalhes da tatuagem do array aux para este novo nó. 

### Função coletaDadosTatuagens:
```` c 
void coletaDadosTatuagens(Tatuagens *tattoo, int qtdC);
 ````
- Função: Leitura dos dados das tatuagens de um arquivo de texto e armazena esses dados em um array de estruturas Tatuagens até que todos os dados das tatuagens tenham sido lidos do arquivo.

- Temos a modificação do array tattoo para conter os dados das tatuagens lidos do arquivo.

### Função escreveTattoos:
````c 
void escreveTattoos(Tatuagens *tattoos, int qtdT);
````
- Função: Escreve os dados das tatuagens de um array de estruturas Tatuagens para um arquivo de texto.

### Função imprimeDadosTatuagens:
````c
void imprimeDadosTatuagens(Tatuagens *tattoos, int qtd);
````
- Função: Esta função imprime os detalhes de todas as tatuagens em um array de estruturas Tatuagens.

- Logo percorre o array tattoos e para cada tatuagem ela imprime seu identificador, estilo, preço e cores.

### Função realizarTatuagem:
````c
void realizarTatuagem(int *numdeTatuagem, Tatuagens **novaTatuagem);
````
- Função: Realoca memória para o array de tatuagens para colocar a nova tatuagem. Em seguida, solicita ao usuário que insira os detalhes da nova tatuagem (estilo, cores e preço). Assim, a função atribui um identificador a nova tatuagem e incrementa o contador de tatuagens.

- Modifica o array novaTatuagem para incluir a nova tatuagem e atualiza o valor de numdeTatuagem.

### Função removeTatuagemPorId:
````c
void removeTatuagemPorId(Tatuagens *tatuagens, int *qtdTatuagens, struct leitura *aux, int id, int qtdL);
````
- Função: Encontra a tatuagem com o ID especificado no array de tatuagens. Se a tatuagem for encontrada, ela é removida do array e todas as tatuagens em subposições são deslocadas para preencher o espaço.

- Atualizamos o número total de tatuagens e verificamos se a tatuagem removida está na lista de tatuagens de qualquer cliente. Se estiver, a tatuagem é removida da lista do cliente.

- Assim, removemos uma tatuagem de um array de tatuagens e atualiza as informações do cliente relacionadas a essa tatuagem.

### Função removeTatuagemDaLista: 
````c
void removeTatuagemDaLista(No **primeiro, int identificacao, struct leitura *aux, int idc, int qtdC, const char *nome);
````
- Função: Verifica se a tatuagem com o ID está na lista de tatuagens de qualquer cliente. Se estiver, a tatuagem é removida da lista do cliente.

- Procura a tatuagem com o ID especificado na lista encadeada de tatuagens para remover.

- Portanto, ela remove uma tatuagem da lista encadeada de tatuagens e atualiza as informações do cliente relacionadas a essa tatuagem.

### Função removeTatuagensRegistradas:
````c
void removeTatuagensRegistradas(struct leitura *aux, int *qtdLeitura, char *nomeCliente);
````
- Função: Percorre a estrutura de dados leitura com *aux procurando pelo nomeCliente. Quando o encontra, remove todas as tatuagens registradas desse cliente e atualiza a estrutura de dados com *aux e a quantidade total de tatuagens registradas qtdLeitura.

- Assim, ela remove todas as tatuagens registradas de um cliente específico em uma estrutura de dados. 

### Função lst_Imprime:
````c
void lst_Imprime(No *primeiro);
````
- Função: Percorre a lista ligada começando pelo nó primeiro. Para cada nó na lista, ela imprimirá as informações da tatuagem associada ao nó.

### Função carregaTatuagensNaLista:
````c
No *carregaTatuagensNaLista(No *primeiro_no, int id, Tatuagens *tattoo, int qtdTattoos);
````
- Função: Percorre as tatuagens procurando por uma tatuagem com um id específico. Quando encontra a tatuagem, cria um novo nó, copia as informações da tatuagem para o novo nó e adiciona o novo nó no início da lista ligada, o qual será adiconada a algum cliente.
- Assim, a função é permite a adição eficiente de uma tatuagem específica a uma lista ligada de tatuagens.

### Função alocaLista:
````c
struct leitura *alocaLista(int *qtdL, int qtdC);
````
- Função: Aloca memória para uma lista de leituras de tatuagens de tamanho qtdC. Deste modo, ela inicializa o número de tatuagens e os IDs das tatuagens para  criar uma lista de leituras de tatuagens com um tamanho específico e inicializar os valores. Assim, cada estrutura da lista formada representa um cliente e suas tatuagens.

### Função realocaLista:
````c
void realocaLista(struct leitura **novaLista, int *n);
````
- Função: Realoca memória para a lista de leituras de tatuagens novaLista, aumentando o tamanho da lista em um. 
Assim, permitindo o crescimento da lista de leituras modificando os dados se possível.

### Função lerLista:
````c
void lerLista(struct leitura *lendo, int qtdL);
````
- Função: Usada para ler as informações das tatuagens de um arquivo e preencher uma lista de leituras de tatuagens.

### Função reescreveLista:
````c
void reescreveLista(struct leitura *escreve, int qtdL);
````
- Função : Escrever as informações das tatuagens de uma lista de leituras de tatuagens em um arquivo. Assim no arquivo estará o nome do cliente e a quantidade de tatuagens feitas.
### Função verificaInsere:
````c
int verificaInsere(struct leitura *grava, int idT, char *nome);
````
- Função: Verificar se uma tatuagem com um ID específico pode ser inserida para um cliente específico em uma lista de leituras de tatuagens. 


## Implementação da (TAD) Clientes
- Neste tipo estruturado se encontra o complemento do gerenciamento do estúdio de tatuagens associada aos nossos futuros clientes.
## Tipos estruturado
### Struct cliente
```c
struct cliente
{
    char nome[250];
    char email[250];
    No *lista_de_tatuagens;
};
```
- A estrutura cliente é uma estrutura de dados em C que armazena informações sobre um cliente. Ela contém nome, email e lista_de_tatuagens que é usado para criar a lista encadeada para armazenar uma lista de tatuagens que o cliente possui.

- A estrutura armazenar e organizar informações sobre um cliente em um formato estruturado e facilmente acessível. Ela pode ser usada em várias funções para realizar operações.

## Funções
### Função contaClientes: 
````c 
struct cliente *contaClientes(int *qtd);
````
- Esta função lê um arquivo de texto que contém dados dos clientes, linha por linha incrementando a variável tamanho para cada linha lida. Depois, a função aloca memória para um array de estruturas cliente com base no valor de tamanho. Assim, a função atualiza o valor de qtd para tamanho e retorna o ponteiro para o array de clientes.

### Função coletaClientes:
````c
void coletaClientes(struct cliente *clientes, int qtdC);
````
- A função lê o nome e o email de cada cliente do arquivo e armazena esses valores nos campos do array apropriados da estrutura cliente.


### Função mostrarDados: 
```` c
void mostrarDados(struct cliente *Cliente, int qtdClientes); 
````
- A função percorre o array de estruturas cliente e imprime o nome e o email de cada cliente.

### Função comp:
````c
int comp(const void *a, const void *b);
````
- Esta é uma função de comparação de nomes com strcmp usada para ordenar o array de estruturas cliente.

### Função ordenaNome: 
```c
void ordenaNome(struct cliente *Cliente, int qtdClientes);
```
- Esta função usa a função qsort para ordenar o array de estruturas cliente em ordem alfabética pelo nome do cliente.

### Função escreverOrd: 
```c 
void escreverOrd(struct cliente *clientes, int qtdClientes);
```
- Esta função escreve os dados dos clientes em um arquivo em ordem alfabética pelo nome do cliente. 

### Função adicionaCliente:
````c
void adicionaCliente(int *q, int *lista, struct cliente **clienteNovo, struct leitura **novaLista);
````
-  Esta função adiciona um novo cliente ao array de estruturas cliente. A função primeiro realoca memória para o cliente, na lista posteriomente e solicita que insira o nome e o email do novo cliente. Assim, o número de tatuagens feitas por ele.
### Função removeCliente: 
```c
void removeCliente(struct leitura *aux, struct cliente *clientes, int *qtdClientes, int ind, int *qtdLeitura);
```
- Esta função remove um cliente do array de estruturas cliente. A função primeiro validao indice, chama remove todas as tatuagens registradas para o cliente e move todos os clientes após o cliente removido uma posição para cima no array.

### Função menuEdit:
```c
void menuEdit(struct leitura *aux, int id, struct cliente *Cedit, Tatuagens *Tedit, int *qtdT, int *qtdC);
```
- Está função é um menu de edição que permite ao usuário editar os detalhes de um cliente específico. 

###  Função coletarLista: 
```c
void coletarLista(struct cliente *cliente, Tatuagens *tattoo, int Qtdc, int Qtdt);
```
- Esta função lê um arquivo que contém uma lista de tatuagens para cada cliente e armazena essas tatuagens na estrutura cliente.

### Função validaEmail: 
```c
int validaEmail(char *email);
```
- Esta função verifica se um email é válido. 

### Função validaNome:
```c
int validaNome(char *nome);
```
- Esta função verifica se um nome é válido. 

### Função buscaBinariaNome: 
```c
void buscaBinariaNome(struct cliente *clientes, int qtdClientes);
```
- Esta função realiza uma busca binária no array de estruturas cliente para encontrar um cliente com um nome específico.

### Função listarClientesEsuasTattoos:
```c
void listarClientesEsuasTattoos(struct cliente *cliente, int qtdC);
```
-  Esta função percorre o array de estruturas cliente e imprime os detalhes de cada cliente, incluindo o nome, o email e a lista de tatuagens.

### Função lerOpcao:
```c 
int lerOpcao();
```
- Escolhida para fazer o tratamento de todo menu e submenu para ler a opção do usuário e validar a entrada.

## Compilação 
- Recomendamos:
> O uso do terminal intergrado.

> Os comando adequados para [GCC](https://gcc.gnu.org/).

## Conclusão e motivação
- Portanto, a utilização de listas encadeadas em nosso estúdio de tatuagem oferece diferentes vantagens e em especial quando se trata de gerenciar dados dinamicamente.

- Em `Tatuagens.c`, a lista encadeada é usada para gerenciar as tatuagens disponíveis e as informações dos clientes. Isso favorece o própio usuário na modificação de seus dados registrados e até mesmo o nosso própio catálogo que se torna flexível e podendo ser facilmente expandido ou modificado. Desta forma, diante a este mundo tecnologico o nosso estúdio se torna ideal pelas multiplas relações com os clientes, pois proporciana uma forma interativa e simplificada com a  lista encadeada.

- Em `Clientes.c`,  gerenciamos as informações de clientes do estúdio de tatuagem e suas tatuagens correspondentes. Isso permite novamente um gerenciamento dinâmico, usando listas encadeadas, ordenamos, validamos os dados e pricipalmente organizamos cada arquivo texto que armazena todos as informações necessárias para registro que pode ser facilmente modificado conforme necessário.

- Assim, nosso projeto com o uso eficiente de listas encadeadas e estruturas de dados na linguagem c, visa proporcionar um gerenciamento dinâmico e eficaz das informações dos clientes e suas tatuagens, de forma online, prática e condicionada a ajudar cada cidadão com interesse em fazer uma tatuagem. 

- Atualização, Implementação e Facilidade definem nosso código.