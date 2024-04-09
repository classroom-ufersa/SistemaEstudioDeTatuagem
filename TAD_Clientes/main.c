#include "cliente.h"
#include "../TAD_Tatuagens/tatuagem.h"

int main(void)
{
    int qtdClientes = 0;
    int qtdTattoos = 0;
    int qtdLista = 0;
    int op, id, i;

    struct cliente *clientes = contaClientes(&qtdClientes);
    struct leitura *dados = alocaLista(&qtdLista, qtdClientes);
    Tatuagens *tattoos = contaEalocaTatuagens(&qtdTattoos);

    lerLista(dados, qtdLista);
    coletaClientes(clientes, qtdClientes);
    ordenaNome(clientes, qtdClientes);
    escreverOrd(clientes, qtdClientes);
    coletaDadosTatuagens(tattoos, qtdTattoos);

    for (i = 0; i < qtdClientes; i++)
    {
        coletarLista(clientes, tattoos, qtdClientes, qtdTattoos);
    }

    do
    {

        printf("-----Menu-----\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Remover cliente\n");
        printf("3 - Realizar tatuagem\n");
        printf("4 - Remover tatuagem\n");
        printf("5 - Editar informacao do cliente\n");
        printf("6 - Buscar cliente por nome\n");
        printf("7 - Listar clientes e suas tatuagens\n");
        printf("8 - Sair\n");
        
         op = lerOpcao(); 
        if(op == -1) {
            continue; 
        }

            switch (op)
            {
            case 1:
                adicionaCliente(&qtdClientes, &qtdLista, &clientes, &dados);
                lerLista(dados, qtdLista);

                break;

            case 2:
                mostrarDados(clientes, qtdClientes);
                printf("Qual cliente deseja remover?\n");
                if ((scanf(" %d", &id)) != 1)
                {
                    printf("Permitido apenas numeros\n");
                    while (getchar() != '\n')
                        ;
                }
                removeCliente(dados, clientes, &qtdClientes, id, &qtdLista);
                break;

            case 3:
                realizarTatuagem(&qtdTattoos, &tattoos);
                break;

            case 4:
                imprimeDadosTatuagens(tattoos, qtdTattoos);
                printf("\nAtencao! Remover uma tatuagem tambem removera dos clientes que a possuem.\n");
                printf("Digite o ID da tatuagem que deseja remover: ");
                if ((scanf(" %d", &id)) != 1)
                {
                    printf("Permitido apenas numeros\n");
                    while (getchar() != '\n')
                        ;
                }
                removeTatuagemPorId(tattoos, &qtdTattoos, dados, id, qtdLista);
                break;

            case 5:
                mostrarDados(clientes, qtdClientes);
                printf("Digite o ID do cliente: \n");
                while ((scanf(" %d", &id)) != 1 || id < 0 || id >= qtdClientes)
                {
                    printf("Insira um ID de cliente válido:\n");
                    while (getchar() != '\n')
                        ;
                }
                menuEdit(dados, id, clientes, tattoos, &qtdTattoos, &qtdClientes);
                break;

            case 6:
                buscaBinariaNome(clientes, qtdClientes);
                break;

            case 7:
                listarClientesEsuasTattoos(clientes, qtdClientes);
                break;

            case 8:
                printf("Obrigado!\n");
                reescreveLista(dados, qtdLista);
                ordenaNome(clientes, qtdClientes);
                escreverOrd(clientes, qtdClientes);
                escreveTattoos(tattoos, qtdTattoos);
                free(clientes);
                free(tattoos);
                free(dados);
                break;

            default:
                printf("Digite uma opcao valida!\n");
                break;
            
        }
    } while (op != 8);
    return 0;
}