#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../TAD_Tatuagens/tatuagem.h"

// Struct do cliente
struct cliente;

// Função para contagem e alocação de memória de clientes
struct cliente *contaClientes(int *qtd);

// Função para coleta de informações de cada cliente
void coletaClientes(struct cliente *clientes, int qtd);

//Função para mostrar dados de clientes com o seu índice
void mostrarDados(struct cliente *Cliente, int qtdClientes);

// Função auxiliar para a função ordena/qsort
int comp(const void *a, const void *b);

// Função que ordena os nomes em ordem alfabética
void ordenaNome(struct cliente *Cliente, int qtdClientes);

// Função para escrever os dados ordenados
void escreverOrd(struct cliente *clientes, int qtdClientes);

// Função para adicionar um cliente
void adicionaCliente(int *q);

// Função para remover um cliente do vetor e do arquivo de texto
void removeCliente(struct cliente *clientes, int *qtdClientes, int ind);

// Função que mostra o menu para edições do dado de um cliente
void menuEdit(int id, struct cliente *Cedit, Tatuagens *Tedit, int *qtdT, int *qtdC);

