#include "cliente.h"
#include "../TAD_Tatuagens/tatuagem.h"

int main(void)
{
    int qtdClientes = 0;
    int qtdTattoos = 0;
    int op, id;

    struct cliente *Clientes = contaClientes(&qtdClientes);
    Tatuagens *tattoos = contaTattoo(&qtdTattoos);
    coletaClientes(Clientes, qtdClientes);
    ordenaNome(Clientes, qtdClientes);
    escreverOrd(Clientes, qtdClientes);
    coletaTattoo(tattoos, qtdTattoos);
    do
    {
        coletaTattoo(tattoos, qtdTattoos);

        printf("-----Menu-----\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Remover cliente\n");
        printf("3 - Realizar tatuagem\n");
        printf("4 - Remover tatuagem\n");                 // faltando
        printf("5 - Editar informacao do cliente\n");
        printf("6 - Buscar cliente por nome\n");          // Criar, Artur
        printf("7 - Listar clientes e suas tatuagens\n"); // Criar, Artur
        printf("8 - Sair\n");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            adicionaCliente(&qtdClientes);
            coletaClientes(Clientes, qtdClientes);
            ordenaNome(Clientes, qtdClientes);
            escreverOrd(Clientes, qtdClientes);
            break;
        case 2:
            mostrarDados(Clientes, qtdClientes);
            printf("Qual cliente deseja remover?\n");
            scanf(" %d", &id);
            removeCliente(Clientes, &qtdClientes, id);
            coletaClientes(Clientes, qtdClientes);
            ordenaNome(Clientes, qtdClientes);
            escreverOrd(Clientes, qtdClientes);
            break;
        case 3:
            inserirTatuagem(&qtdTattoos);
            break;
        case 4:
    // Faltando
    printf("Digite o ID da tatuagem que deseja remover: ");
    scanf("%d", &id);
    removeTatuagemPorId(tattoos, &qtdTattoos, id);
            break;
        case 5:
            mostrarDados(Clientes, qtdClientes);
            printf("Digite o ID do cliente: \n");
            scanf(" %d", &id);
            menuEdit(id, Clientes, tattoos, &qtdTattoos, &qtdClientes);

            break;
        case 6:
            // a criar
            break;
        case 7:
            // a criar
            break;
        case 8:
            printf("Obrigado!\n"); // liberar memoria? (Examinar funcionamento do código aqui)
            break;
        default:
            printf("Digite uma opcao valida!\n");
            break;
        }

    } while (op != 8);

    return 0;
}