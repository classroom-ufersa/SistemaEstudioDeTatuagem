#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../TAD_Tatuagens/tatuagem.h"

/* Struct do cliente com redefinição. */
struct cliente;

/* Função para contagem e alocação de memória de clientes. */
struct cliente *contaClientes(int *qtd);

/* Função para coleta de informações de cada cliente e seus dados referentes. */
void coletaClientes(struct cliente *clientes, int qtd);

/* Função para mostrar dados de clientes com o sua identificação.*/
void mostrarDados(struct cliente *Cliente, int qtdClientes);

/* Função auxiliar para a função ordena/qsort um algoritmo de ordenação. */
int comp(const void *a, const void *b);

/* Função que ordena os nomes em ordem alfabética. */
void ordenaNome(struct cliente *Cliente, int qtdClientes);

/* Função para escrever os dados ordenados. */
void escreverOrd(struct cliente *clientes, int qtdClientes);

/* Função para adicionar um cliente. */
void adicionaCliente(int *q, int *lista, struct cliente **clienteNovo, struct leitura **novaLista);

/* Função para remover um cliente do vetor e do arquivo de texto, segundo sua identificação. */
void removeCliente(struct leitura *aux, struct cliente *clientes, int *qtdClientes, int ind, int *qtdLeitura);

/* Função que mostra o menu para edições do dado de um cliente. */
void menuEdit(struct leitura *aux, int id, struct cliente *Cedit, Tatuagens *Tedit, int *qtdT, int *qtdC);

/* Função que coleta os dados das tatuagens dos cliente e chama a função "Insere_elementos_por_id" para adicioná-los. */
void coletarLista(struct cliente *cliente, Tatuagens *tattoo, int Qtdc, int Qtdt);

/* Função que reescreve as tatuagens no arquivo tetxo.*/
void escreveTattoos(Tatuagens *tattoos, int qtdT);

/* Função para verificação no email e validação. */
int validaEmail(char *email);

/* Função de verificação do nome e validação. */
int validaNome(char *nome);

/* Função para busca binaria por nome de um cliente. */
void buscaBinariaNome(struct cliente *clientes, int qtdClientes);

/* Função para listar todos os clientes e suas tatuagens. */
void listarClientesEsuasTattoos(struct cliente *cliente, int qtdC);

/* Função tratativa para entrada no menu. */
int lerOpcao();