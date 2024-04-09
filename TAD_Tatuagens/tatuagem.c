#include "tatuagem.h"

struct tatuagens
{
    int identificacao;
    char estilo[150];
    char cores[150];
    float preco;
};

struct no
{
    Tatuagens tatuagem;
    No *prox;
};

struct leitura
{
    char cliente[250];
    int numerodeT;
    int idsT[10];
};

Tatuagens *contaEalocaTatuagens(int *qtd)
{
    int tamanho = 0;
    char linha[101];

    FILE *arquivo;
    arquivo = fopen("../Dados/DadosTattoos.txt", "r");

    while (fscanf(arquivo, "%[^\n]\n", linha) != EOF)
    {
        tamanho++;
    }

    fclose(arquivo);

    Tatuagens *tattoos = malloc(tamanho * sizeof(Tatuagens));

    *qtd = tamanho;
    return tattoos;
}

int verificaVazio(No *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

No *insereElementosNaLista(No *primeiroNo, int id, Tatuagens *aux)
{
    int i;

    No *novo = (No *)malloc(sizeof(No));

    strcpy(novo->tatuagem.cores, aux[id].cores);
    strcpy(novo->tatuagem.estilo, aux[id].estilo);

    novo->tatuagem.identificacao = aux[id].identificacao;
    novo->tatuagem.preco = aux[id].preco;
    novo->prox = primeiroNo;

    return novo;
}

void coletaDadosTatuagens(Tatuagens *tattoo, int qtdC)
{
    int i = 0;

    FILE *dados;
    dados = fopen("../Dados/DadosTattoos.txt", "r");

    while (i < qtdC)
    {
        fscanf(dados, "%d\t%[^\t]\t%f\t%[^\n]", &tattoo[i].identificacao, tattoo[i].estilo, &tattoo[i].preco, tattoo[i].cores);
        i++;
    }

    fclose(dados);
}

void escreveTattoos(Tatuagens *tattoos, int qtdT)
{
    int i;

    FILE *arquivo;
    arquivo = fopen("../Dados/DadosTattoos.txt", "w");

    for (i = 0; i < qtdT; i++)
    {
        fprintf(arquivo, "%d\t%s\t%.2f\t%s\n", tattoos[i].identificacao, tattoos[i].estilo, tattoos[i].preco, tattoos[i].cores);
    }

    fclose(arquivo);
}

void imprimeDadosTatuagens(Tatuagens *tattoos, int qtd)
{
    int j;

    for (j = 0; j < qtd; j++)
    {
        printf("| %d | Estilo: %s, Preco: %.2f, Cores: %s\n", tattoos[j].identificacao, tattoos[j].estilo, tattoos[j].preco, tattoos[j].cores);
    }
}

void realizarTatuagem(int *numdeTatuagem, Tatuagens **novaTatuagem)
{
    int resultado;

    *novaTatuagem = realloc(*novaTatuagem, ((*numdeTatuagem) + 1) * sizeof(Tatuagens));
    if (*novaTatuagem == NULL)
    {
        printf("Problema na realocacao.\n");
        return;
    }

    getchar();
    printf("Digite o estilo: \n");
    scanf(" %[^\n]", (*novaTatuagem)[*numdeTatuagem].estilo);
    printf("Digite a cor: \n");
    scanf(" %[^\n]", (*novaTatuagem)[*numdeTatuagem].cores);

    do
    {
        printf("Digite o preco: \n");
        resultado = scanf(" %f", &(*novaTatuagem)[*numdeTatuagem].preco);
        while (getchar() != '\n')
            ;
        if (resultado == 0)
        {
            printf("Por favor, insira um numero valido para o preco.\n");
        }
    } while (resultado == 0);

    (*novaTatuagem)[*numdeTatuagem].identificacao = *numdeTatuagem + 1;
    (*numdeTatuagem)++;
}

void removeTatuagemPorId(Tatuagens *tatuagens, int *qtdTatuagens, struct leitura *aux, int id, int qtdL)
{
    int i, j;

    int posicaoRemover = -1;
    for (i = 0; i < *qtdTatuagens; i++)
    {
        if (tatuagens[i].identificacao == id)
        {
            posicaoRemover = i;
            printf("ID removido com sucesso\n");
            break;
        }
    }

    if (posicaoRemover == -1)
    {
        printf("ID nao encontrado.\n", id);
        return;
    }

    for (i = posicaoRemover; i < *qtdTatuagens - 1; i++)
    {
        tatuagens[i] = tatuagens[i + 1];
    }
    (*qtdTatuagens)--;

    for (i = 0; i < qtdL; i++)
    {
        for (j = 0; j < aux[i].numerodeT; j++)
        {
            if (aux[i].idsT[j] == id)
            {
                aux[i].idsT[j] = 0;
                aux[i].numerodeT--;
                break;
            }
        }
    }

    for (i = 0; i < *qtdTatuagens; i++)
    {
        if (tatuagens[i].identificacao > id)
        {
            tatuagens[i].identificacao--;
        }
    }
}

void removeTatuagemDaLista(No **primeiro, int identificacao, struct leitura *aux, int idc, int qtdC, const char *nome)
{
    int i, j;

    No *atual = *primeiro;
    No *anterior = NULL;
    for (j = 0; j < qtdC; j++)
    {
        for (i = 0; i < 10; i++)
        {
            if (strcmp(aux[j].cliente, nome) == 0)
            {
                if (aux[j].idsT[i] == identificacao)
                {
                    aux[j].idsT[i] = 0;
                    aux[j].numerodeT = aux[j].numerodeT - 1;
                    return;
                }
            }
        }
    }

    while (atual != NULL && atual->tatuagem.identificacao != identificacao)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Id nao encontrado na lista.\n");
        return;
    }

    if (anterior == NULL)
    {
        *primeiro = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
}

void removeTatuagensRegistradas(struct leitura *aux, int *qtdLeitura, char *nomeCliente)
{
    int i, j, k;

    for (i = 0; i < *qtdLeitura; i++)
    {
        if (strcmp(aux[i].cliente, nomeCliente) == 0)
        {

            for (j = i; j < *qtdLeitura - 1; j++)
            {
                strcpy(aux[j].cliente, aux[j + 1].cliente);
                aux[j].numerodeT = aux[j + 1].numerodeT;

                for (k = 0; k < aux[j].numerodeT; k++)
                {
                    aux[j].idsT[k] = aux[j + 1].idsT[k];
                }
            }

            (*qtdLeitura)--;
            break;
        }
    }
}

void lstImprime(No *primeiro)
{
    No *aux;

    for (aux = primeiro; aux != NULL; aux = aux->prox)
    {
        printf("ID: %d \n Estilo: %s \n Preco: %.2f \n Cor: %s \n", aux->tatuagem.identificacao, aux->tatuagem.estilo, aux->tatuagem.preco, aux->tatuagem.cores);
        printf("-----------------------\n");
    }
}

No *carregaTatuagensNaLista(No *primeiroNo, int id, Tatuagens *tattoo, int qtdTattoos)
{
    int i;

    for (i = 0; i < qtdTattoos; i++)
    {
        if (tattoo[i].identificacao == id)
        {
            No *novo = (No *)malloc(sizeof(No));

            if (novo == NULL)
            {
                printf("Falha na alocacao.\n");
                return primeiroNo;
            }

            strcpy(novo->tatuagem.cores, tattoo[i].cores);
            strcpy(novo->tatuagem.estilo, tattoo[i].estilo);

            novo->tatuagem.identificacao = tattoo[i].identificacao;
            novo->tatuagem.preco = tattoo[i].preco;
            novo->prox = primeiroNo;

            return novo;
        }
    }
    printf("ID da tatuagem nao encontrado.\n");

    return primeiroNo;
}

struct leitura *alocaLista(int *qtdL, int qtdC)
{
    int i, j;
    int tamanho = qtdC;
    struct leitura *ler = malloc(tamanho * sizeof(struct leitura));
    if (ler == NULL)
    {
        printf("Problema na alocacao\n");
        exit(1);
    }

    for (i = 0; i < tamanho; i++)
    {
        ler[i].numerodeT = 0;
        for (j = 0; j < 10; j++)
        {
            ler[i].idsT[j] = 0;
        }
    }

    *qtdL = tamanho;

    return ler;
}

void realocaLista(struct leitura **novaLista, int *n)
{
    *novaLista = realloc(*novaLista, ((*n) + 1) * sizeof(struct leitura));
    if (*novaLista == NULL)
    {
        printf("Problema na realocacao.\n");
        return;
    }
    (*n)++;
}

void lerLista(struct leitura *lendo, int qtdL)
{
    int i, j;

    FILE *dados;
    dados = fopen("../Dados/ListaTatuagens.txt", "r");
    if (dados == NULL)
    {
        printf("Problema na abertura do arquivo!\n");
        return;
    }

    for (i = 0; i < qtdL; i++)
    {
        fscanf(dados, "%[^\t]\t%d\t", lendo[i].cliente, &lendo[i].numerodeT);
        for (j = 0; j < lendo[i].numerodeT; j++)
        {
            fscanf(dados, "%d ", &lendo[i].idsT[j]);
        }
    }

    fclose(dados);
}

void reescreveLista(struct leitura *escreve, int qtdL)
{
    int i, j;
    FILE *arquivo;
    arquivo = fopen("../Dados/ListaTatuagens.txt", "w");
    if (arquivo == NULL)
    {
        printf("Problema na abertura do arquivo!\n");
        return;
    }
    for (i = 0; i < qtdL; i++)
    {
        fprintf(arquivo, "%s\t%d\t", escreve[i].cliente, escreve[i].numerodeT);
        for (j = 0; j < escreve[i].numerodeT; j++)
        {
            fprintf(arquivo, "%d ", escreve[i].idsT[j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

int verificaInsere(struct leitura *grava, int idT, char *nome)
{
    int i, j;
    int encontrado = 0;

    for (i = 0; i < 10; i++)
    {
        if (strcmp(grava[i].cliente, nome) == 0)
        {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Cliente nao encontrado.\n");
        return 1;
    }

    if (grava[i].numerodeT == 10)
    {
        printf("O cliente %s nao tem mais espaço para tatuagens!\n", nome);
        return 1;
    }

    for (j = 0; j < 10; j++)
    {
        if (grava[i].idsT[j] == 0)
        {

            strcpy(grava[i].cliente, nome);
            grava[i].idsT[j] = idT;
            grava[i].numerodeT++;
            break;
        }
    }
}