#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct da tatuagem
typedef struct tatuagens Tatuagens;

// Struct nó da lista encadeada
typedef struct no No;

// Função para contar e alocar memória para as tatuagens do TXT
Tatuagens *contaTattoo(int *qtd);

// Função para verificar se a lista encadeada está vazia
int verifica_vazio(No *l);

// Função para inserir elementos na lista encadeada
No *Insere_elementos(No *primeiro_no, int id, Tatuagens *aux);

// Função para coleta de dados das tatuagens
void coletaTattoo(Tatuagens *tattoo, int qtdC);

// Função para imprimir os dados das tatuagens
void imprime_dados(Tatuagens *tattoos, int qtd);

// Insere uma nova tatuagem no arquivo de texto
void inserirTatuagem(int *numdeTatuagem);

// Função para remover tatuagem da lista encadeada
void remove_elemento(No **primeiro, int identificacao);

// Função para imprimir uma lista encadeada
void lst_Imprime(No* primeiro);
