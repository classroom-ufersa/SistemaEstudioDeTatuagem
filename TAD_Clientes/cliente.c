#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct cliente
{
    char nome[200];
    char email[250];
    No *lista_de_tatuagens;
};

struct cliente *contaClientes(int *qtd)
{
    int tamanho = 0;
    char linha[101];
    FILE *arquivo;

    arquivo = fopen("../Dados/DadosClientes.txt", "r");

    while (fscanf(arquivo, "%[^\n]\n", linha) != EOF)
    {
        tamanho++;
    }

    fclose(arquivo);

    struct cliente *clientes = malloc(tamanho * sizeof(struct cliente));

    *qtd = tamanho;

    return clientes;
}

int comp(const void *a, const void *b)
{
    return strcmp(((struct cliente *)a)->nome, ((struct cliente *)b)->nome);
}

void ordenaNome(struct cliente *Cliente, int qtdClientes)
{
    qsort(Cliente, qtdClientes, sizeof(struct cliente), comp);
}

void coletaClientes(struct cliente *clientes, int qtdC)
{
    int i = 0;

    FILE *dados;
    dados = fopen("../Dados/DadosClientes.txt", "r");

    while (i < qtdC)
    {
        fscanf(dados, "%[^\t]\t%[^\n]\n", clientes[i].nome, clientes[i].email);
        i++;
    }

    fclose(dados);
}

void escreverOrd(struct cliente *clientes, int qtdClientes)
{
    int i;
    FILE *arquivo;
    arquivo = fopen("../Dados/DadosClientes.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (i = 0; i < qtdClientes; i++)
    {
        fprintf(arquivo, "%s\t%s\n", clientes[i].nome, clientes[i].email);
    }

    fclose(arquivo);
}

void mostrarDados(struct cliente *Cliente, int qtdClientes)
{
    int j;
    for (j = 0; j < qtdClientes; j++)
    {
        printf("| %d |Nome: %s, E-mail: %s\n", j, Cliente[j].nome, Cliente[j].email);
    }
}

void adicionaCliente(int *q)
{
    // Obrigatoriamente, o primeiro digito do nome deve ser maiusculo, implementar mais tarde
    struct cliente Aux;
    FILE *arquivo;
    arquivo = fopen("../Dados/DadosClientes.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("Digite o nome do cliente: \n");
    scanf(" %[^\n]", Aux.nome);
    printf("Digite o e-mail: \n");
    scanf(" %[^\n]", Aux.email);

    fprintf(arquivo, "%s\t%s\n", Aux.nome, Aux.email);
    fclose(arquivo);

    (*q)++;
}

void removeCliente(struct cliente *clientes, int *qtdClientes, int ind)
{
    int i;
    if (ind < 0 || ind >= *qtdClientes)
    {
        printf("Cliente inexistente.\n");
        return;
    }

    for (i = ind; i < *qtdClientes - 1; i++)
    {
        strcpy(clientes[i].nome, clientes[i + 1].nome);
        strcpy(clientes[i].email, clientes[i + 1].email);
        clientes[i].lista_de_tatuagens = clientes[i + 1].lista_de_tatuagens;
    }
    (*qtdClientes)--;

    FILE *arquivo;
    arquivo = fopen("../Dados/DadosClientes.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (i = 0; i < *qtdClientes; i++)
    {
        fprintf(arquivo, "%s\t%s\n", clientes[i].nome, clientes[i].email);
    }

    fclose(arquivo);

    printf("!!!! O cliente foi deletado !!!!\n");
}

void menuEdit(int id, struct cliente *Cedit, Tatuagens *Tedit, int *qtdT, int *qtdC)
{
    int op, opb, ida, idb;

    printf("-_-_ AREA DE EDICAO _-_-\n");
    printf("1 - Editar nome do cliente\n");
    printf("2 - Editar email do cliente\n");
    printf("3 - Editar tatuagens do cliente\n");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:

        printf("Digite o novo nome do cliente: \n");
        scanf(" %[^\n]", Cedit[id].nome);
        printf("Dado alterado!\n");
        ordenaNome(Cedit, *qtdC);
        escreverOrd(Cedit, *qtdC);

        break;

    case 2:

        printf("Digite o novo email do cliente: \n");
        scanf(" %[^\n]", Cedit[id].email);
        printf("Dado alterado!\n");
        escreverOrd(Cedit, *qtdC);

        break;

    case 3:

        printf("1 - Adicionar uma tatuagem ao cliente.\n");
        printf("2 - Remover uma tatuagem do cliente.\n");
        scanf(" %d", &opb);

        do
        {

            if (opb == 1)
            {
                imprime_dados(Tedit, *qtdT);
                printf("Digite o ID da tatuagem que deseja inserir na lista do cliente: \n");
                scanf(" %d", &ida);
                Cedit[id].lista_de_tatuagens = NULL;
                Cedit[id].lista_de_tatuagens = Insere_elementos(Cedit[id].lista_de_tatuagens, ida, Tedit);
                opb = 3;
            }

            else if (opb == 2)
            {
                if (verifica_vazio(Cedit[id].lista_de_tatuagens))
                {
                    printf("O cliente nao possui tatuagens!\n");
                    opb = 3;
                    return;
                }
                lst_Imprime(Cedit[id].lista_de_tatuagens);
                printf("Digite o ID da tatuagem que deseja remover: \n");
                scanf(" %d", &idb);
                remove_elemento(&Cedit[id].lista_de_tatuagens, idb);
                opb = 3;
            }

            else
            {
                printf("Opcao invalida! \n");
            }

        } while (opb != 3);

        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}