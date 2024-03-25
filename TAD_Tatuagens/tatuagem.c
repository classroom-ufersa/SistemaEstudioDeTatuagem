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

Tatuagens *contaTattoo(int *qtd)
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

int verifica_vazio(No *l)
{
    if (l == NULL)
        return 1;
    else
        return 0;
}

No *Insere_elementos(No *primeiro_no, int id, Tatuagens *aux)
{
    No *novo = (No *)malloc(sizeof(No));

    strcpy(novo->tatuagem.cores, aux[id].cores);
    strcpy(novo->tatuagem.estilo, aux[id].estilo);

    novo->tatuagem.identificacao = aux[id].identificacao;
    novo->tatuagem.preco = aux[id].preco;
    novo->prox = primeiro_no;

    return novo;
}

void coletaTattoo(Tatuagens *tattoo, int qtdC)
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

void imprime_dados(Tatuagens *tattoos, int qtd)
{

    int j;
    for (j = 0; j < qtd; j++)
    {
        printf("| %d | Estilo: %s, Preco: %.2f, Cores: %s\n", j, tattoos[j].estilo, tattoos[j].preco, tattoos[j].cores);
    }
}

void inserirTatuagem(int *numdeTatuagem)
{
    FILE *arquivo;
    Tatuagens aux;

    arquivo = fopen("../Dados/DadosTattoos.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    getchar();
    printf("Digite o estilo: \n");
    scanf(" %[^\n]", aux.estilo);
    printf("Digite a cor: \n");
    scanf(" %[^\n]", aux.cores);
    printf("Digite o preco: \n");
    scanf(" %f", &aux.preco);
    getchar();

    (*numdeTatuagem)++;
    aux.identificacao = *numdeTatuagem;

    fprintf(arquivo, "%d\t%s\t%.2f\t%s\n", aux.identificacao, aux.estilo, aux.preco, aux.cores);
    fclose(arquivo);
}

void remove_elemento(No **primeiro, int identificacao) {
    No *atual = *primeiro;
    No *anterior = NULL;

    while (atual != NULL && atual->tatuagem.identificacao != identificacao) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Elemento com identificacao %d nao encontrado na lista.\n", identificacao);
        return;
    }

    if (anterior == NULL) {
        *primeiro = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}


void lst_Imprime(No *primeiro)
{
    No *aux;
    for (aux = primeiro; aux != NULL; aux = aux->prox)
    {
        printf("ID: %d \n Estilo: %s \n Preco: %.2f \n Cor: %s \n", aux->tatuagem.identificacao, aux->tatuagem.estilo, aux->tatuagem.preco, aux->tatuagem.cores);
        printf("-----------------------\n");
    }
}