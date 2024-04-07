#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct cliente
{
    char nome[250];
    char email[250];
    No *lista_de_tatuagens;
};

struct cliente *contaClientes(int *qtd)
{
    int tamanho = 0;
    char linha[101];

    FILE *arquivo;
    arquivo = fopen("../Dados/DadosClientes.txt", "r");

    if (arquivo == NULL)
    {
        printf("Problema na abertura do arquivo.\n");
        exit(1);
    }

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

    if (dados == NULL)
    {
        printf("Problema na abertura do arquivo!\n");
        return;
    }

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
        printf("Problema ao abrir o arquivo\n");
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

void adicionaCliente(int *q, int *lista, struct cliente **clienteNovo, struct leitura **novaLista)
{
    *clienteNovo = realloc(*clienteNovo, ((*q) + 1) * sizeof(struct cliente));
    if (*clienteNovo == NULL)
    {
        printf("Problema na realocacao.\n");
        exit(1);
    }
    do
    {
        printf("Digite o nome: \n");
        scanf(" %[^\n]", (*clienteNovo)[*q].nome);
    } while (!validaNome((*clienteNovo)[*q].nome));

    do
    {
        printf("Digite o e-mail: \n");
        scanf(" %[^\n]", (*clienteNovo)[*q].email);

    } while (!validaEmail((*clienteNovo)[*q].email));
    (*q)++;

    FILE *arquivo;
    arquivo = fopen("../Dados/ListaTatuagens.txt", "a");

    if (arquivo == NULL)
    {
        printf("Problema ao abrir o arquivo\n");
        return;
    }

    realocaLista(novaLista, lista);
    fprintf(arquivo, "%s\t%d\n", (*clienteNovo)[*q - 1].nome, 0);
    fclose(arquivo);
}

void removeCliente(struct leitura *aux, struct cliente *clientes, int *qtdClientes, int ind, int *qtdLeitura)
{
    int i;

    if (ind < 0 || ind >= *qtdClientes)
    {
        printf("Cliente inexistente.\n");
        return;
    }

    removeTatuagensRegistradas(aux, qtdLeitura, clientes[ind].nome);

    for (i = ind; i < *qtdClientes - 1; i++)
    {
        strcpy(clientes[i].nome, clientes[i + 1].nome);
        strcpy(clientes[i].email, clientes[i + 1].email);
    }

    (*qtdClientes)--;
    clientes[ind].lista_de_tatuagens == NULL;

    FILE *arquivo;
    arquivo = fopen("../Dados/DadosClientes.txt", "w");

    if (arquivo == NULL)
    {
        printf("Problema na abertura do arquivo.\n");
        return;
    }

    for (i = 0; i < *qtdClientes; i++)
    {
        fprintf(arquivo, "%s\t%s\n", clientes[i].nome, clientes[i].email);
    }

    fclose(arquivo);

    printf("!!!! O cliente foi deletado !!!!\n");
}

void menuEdit(struct leitura *aux, int id, struct cliente *Cedit, Tatuagens *Tedit, int *qtdT, int *qtdC)
{
    int op, opb, ida, idb, controle;
    getchar();
    printf("-_-_ AREA DE EDICAO _-_-\n");
    printf("1 - Editar nome do cliente\n");
    printf("2 - Editar email do cliente\n");
    printf("3 - Editar tatuagens do cliente\n");
    if ((scanf(" %d", &op)) != 1)
    {
        printf("Permitido apenas numeros\n");
        while (getchar() != '\n')
            ;
    }
    else
    {
        switch (op)
        {
        case 1:

            do
            {
                printf("Digite o novo nome do cliente: \n");
                scanf(" %[^\n]", Cedit[id].nome);
            } while (!validaNome(Cedit[id].nome));

            printf("Dado alterado!\n");
            ordenaNome(Cedit, *qtdC);
            escreverOrd(Cedit, *qtdC);
            break;

        case 2:

            do
            {
                printf("Digite o novo email do cliente: \n");
                scanf(" %[^\n]", Cedit[id].email);
            } while (!validaEmail(Cedit[id].email));
            printf("Dado alterado!\n");
            escreverOrd(Cedit, *qtdC);
            break;

        case 3:

            printf("1 - Adicionar uma tatuagem ao cliente.\n");
            printf("2 - Remover uma tatuagem do cliente.\n");
            ;
            if ((scanf(" %d", &opb)) != 1)
            {
                printf("Permitido apenas numeros\n");
                while (getchar() != '\n')
                    ;
            }
            else
            {
                do
                {

                    if (opb == 1)
                    {
                        imprimeDadosTatuagens(Tedit, *qtdT);
                        printf("Digite o ID da tatuagem que deseja inserir na lista do cliente: \n");
                        if ((scanf(" %d", &ida)) != 1)
                        {
                            printf("Permitido apenas numeros\n");
                            while (getchar() != '\n')
                                ;
                        }

                        if (ida >= *qtdT + 1 || ida < 0)
                        {
                            printf("ID invalido.\n");
                            return;
                        }

                        controle = verificaInsere(aux, ida, Cedit[id].nome);

                        if (controle != 1)
                        {
                            Cedit[id].lista_de_tatuagens = carregaTatuagensNaLista(Cedit[id].lista_de_tatuagens, ida, Tedit, *qtdT);
                        }

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

                        if ((scanf(" %d", &idb)) != 1)
                        {
                            printf("Permitido apenas numeros\n");
                            while (getchar() != '\n')
                                ;
                        }
                        removeTatuagemDaLista(&Cedit[id].lista_de_tatuagens, idb, aux, id, *qtdC, Cedit[id].nome);

                        opb = 3;
                    }

                    else
                    {
                        printf("Opcao invalida! \n");
                    }

                } while (opb != 3);
            }
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}

void coletarLista(struct cliente *cliente, Tatuagens *tattoo, int Qtdc, int Qtdt)
{
    int i, j, qtdl;
    char nome[200];

    FILE *arquivo;
    arquivo = fopen("../Dados/ListaTatuagens.txt", "r");
    for (j = 0; j < Qtdc; j++)
    {
        fscanf(arquivo, "%[^\t]\t%d\t", nome, &qtdl);
        for (i = 0; i < Qtdc; i++)
        {
            if (strcmp(cliente[i].nome, nome) == 0)
            {
                No *primeiro = NULL;
                int j;

                for (j = 0; j < qtdl; j++)
                {
                    int id;
                    if (fscanf(arquivo, "%d", &id) == 1)
                    {
                        primeiro = carregaTatuagensNaLista(primeiro, id, tattoo, Qtdt);
                    }
                    else
                    {
                        printf("Problema de leitura de tatuagem no cliente %s\n", nome);
                        break;
                    }
                }
                cliente[i].lista_de_tatuagens = primeiro;
            }
        }
        fscanf(arquivo, "\n");
    }
    fclose(arquivo);
}

int validaEmail(char *email)
{
    if (strstr(email, "@") == NULL)
    {
        printf("O e-mail deve conter @.\n");
        return 0;
    }

    if (strstr(email, ".") == NULL)
    {
        printf("O e-mail deve conter um ponto (.)\n");
        return 0;
    }

    if (strstr(email, "hotmail.com") == NULL && strstr(email, "gmail.com") == NULL)
    {
        printf("O e-mail deve conter hotmail.com ou gmail.com.\n");
        return 0;
    }

    return 1;
}

int validaNome(char *nome)
{
    int i;

    for (i = 0; nome[i]; i++)
    {
        if ((nome[i] < 'A' || nome[i] > 'Z') && (nome[i] < 'a' || nome[i] > 'z') && nome[i] != ' ')
        {
            printf("O nome deve conter apenas letras.\n");
            return 0;
        }
    }

    if (nome[0] < 'A' || nome[0] > 'Z')
    {
        printf("A primeira letra do nome deve ser maiuscula.\n");
        return 0;
    }

    return 1;
}
void buscaBinariaNome(struct cliente *clientes, int qtdClientes)
{
    char nomeDesejado[200];
    int encontrado = 0;
    int min = 0;
    int max = qtdClientes - 1;
    int meio;

    printf("Digite o nome desejado: \n");
    scanf(" %[^\n]", nomeDesejado);

    while (min <= max)
    {
        meio = (min + max) / 2;

        int comparacao = strcmp(clientes[meio].nome, nomeDesejado);
        if (comparacao == 0)
        {
            printf("================================\n");
            printf("Nome: %s\n", clientes[meio].nome);
            printf("Endereco: %s \n", clientes[meio].email);
            printf("Tatuagens do cliente: \n");

            if (clientes[meio].lista_de_tatuagens == NULL)
            {
                printf("O cliente nao possui tatuagens!\n");
                return;
            }

            lst_Imprime(clientes[meio].lista_de_tatuagens);
            printf("================================\n");

            encontrado = 1;
            break;
        }
        else if (comparacao < 0)
        {
            min = meio + 1;
        }
        else
        {
            max = meio - 1;
        }
    }

    if (!encontrado)
    {
        printf("Cliente nao encontrado.\n");
    }
}

void listarClientesEsuasTattoos(struct cliente *cliente, int qtdC)
{
    int i;
    for (i = 0; i < qtdC; i++)
    {
        printf("Nome: %s\n", cliente[i].nome);
        printf("Email: %s\n", cliente[i].email);

        if (cliente[i].lista_de_tatuagens == NULL)
        {
            printf("O cliente nao possui tatuagens!\n");
            printf("-------------------------\n");
        }
        else
        {
            printf("Tatuagens: \n");
            lst_Imprime(cliente[i].lista_de_tatuagens);
            printf("-------------------------\n");
        }
    }
}