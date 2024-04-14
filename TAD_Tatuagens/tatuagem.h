#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct da tatuagem com redefinição. */
typedef struct tatuagens Tatuagens;

/* Struct nó da lista encadeada com redefinição. */
typedef struct no No;

/* Struct auxiliar para ler dados armazenados. */
struct leitura;

/* Função para contar a quantidade de linhas e alocar memória para as tatuagens do aruivo texto. */
Tatuagens *contaEalocaTatuagens(int *qtd);

/* Função para verificar se a lista encadeada está vazia. */
int verificaVazio(No *l);

/* Função para inserir elementos na lista encadeada. */
No *insereElementosNaLista(No *primeiro_no, int id, Tatuagens *aux);

/* Função para coleta de dados das tatuagens. */
void coletaDadosTatuagens(Tatuagens *tattoo, int qtdC);

/* Função para imprimir os dados das tatuagens */
void imprimeDadosTatuagens(Tatuagens *tattoos, int qtd);

/* Função que insere uma nova tatuagem realocando espaço. */
void realizarTatuagem(int *numdeTatuagem, Tatuagens **novaTatuagem);

/* Função para remover tatuagem da lista encadeada com o id especificado. */
void removeTatuagemDaLista(No **primeiro, int identificacao, struct leitura *aux, int idc, int qtdC, const char *nome);

/* Função que remove as tatuagens registradas do cliente. */
void removeTatuagensRegistradas(struct leitura *aux, int *qtdLeitura, char *nomeCliente);

/* Função para imprimir uma lista encadeada. */
void lstImprime(No *primeiro);

/* Função para carregar as tatuagens do cliente para sua lista encadeada. */
No *carregaTatuagensNaLista(No *primeiro_no, int id, Tatuagens *tattoo, int qtdTattoos);

/* Função que coleta os dados das tatuagens que cada cliente tem registrada. */
void lerLista(struct leitura *lendo, int qtdL);

/* Função para atualizar o arquivo de texto com as informações modificadas durante a execução do programa */
void reescreveLista(struct leitura *escreve, int qtdL);

/* Função que aloca memória para a struct chamada 'leitura'. */
struct leitura *alocaLista(int *qtd, int Qtdc);

/* Função para realocar memória e aumentar o tamanho da lista. */
void realocaLista(struct leitura **novaLista, int *n);

/* Função que verifica se o cliente excedeu a quantidade de tatuagens e grava uma nova tatuagem. */
int verificaInsere(struct leitura *grava, int idT, char *nome);

/* Função que remove a tatuagem do arquivo texto. */
void removeTatuagemPorId(Tatuagens *tatuagens, int *qtdTatuagens, struct leitura *aux, int id, int qtdL);
