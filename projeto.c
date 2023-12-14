#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#define TAM 20

struct registro_funcionario

{
    char nome[200];
    int turno;
    char cargo[200];
    int idade;
    float salario;
    char turnoEscolhido[100];
};

void funcionario(struct registro_funcionario *funcionarios, int quantidadeFuncionarios)
{

    printf("Nome do funcionário:\n");
    gets(funcionarios[quantidadeFuncionarios].nome);

    printf("\n1- Matutino\n");
    printf("2- Vespertino\n");
    printf("3- Noturno\n");
    printf("Turno do funcionário:\n");
    scanf("%d", &funcionarios[quantidadeFuncionarios].turno);

    fflush(stdin);

    switch (funcionarios[quantidadeFuncionarios].turno)
    {
    case 1:
        printf("Turno escolhido: Matutino\n\n");
        strcpy(funcionarios[quantidadeFuncionarios].turnoEscolhido, "Matutino");
        break;
    case 2:
        printf("Turno escolhido: Vespertino\n\n");
        strcpy(funcionarios[quantidadeFuncionarios].turnoEscolhido, "Vespertino");
        break;
    case 3:
        printf("Turno escolhido: Noturno\n\n");
        strcpy(funcionarios[quantidadeFuncionarios].turnoEscolhido, "Noturno");
        break;
    }

    fflush(stdin);
    printf("Cargo do funcionário:\n");
    gets(funcionarios[quantidadeFuncionarios].cargo);

    printf("Idade do funcionário:\n");
    scanf("%d", &funcionarios[quantidadeFuncionarios].idade);

    printf("Salário do funcionário:\n");
    scanf("%f", &funcionarios[quantidadeFuncionarios].salario);
}

void amostrarFicha(struct registro_funcionario *funcionarios, char *funcionarioEscolhido)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(funcionarios[i].nome, funcionarioEscolhido) == 0)
        {
            printf("Nome: %s\n", funcionarioEscolhido);
            printf("Turno: %s\n", funcionarios[i].turnoEscolhido);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Idade: %d\n", funcionarios[i].idade);
            printf("Salário: R$%.2f\n", funcionarios[i].salario);
            getchar();
        }
    }
}

void formapagamento(struct registro_funcionario *funcionarios, char *funcionarioEscolhido, int quantidadeFuncionarios)
{
    int i;
    int pagamento;
    printf("1 - Boleto\n");
    printf("2 - Pix\n");
    printf("Qual forma de pagamento do salário do funcionário?\n");
    scanf("%d", &pagamento);

    for (i = 0; i < quantidadeFuncionarios; i++)
    {
    if (strcmp(funcionarios[i].nome, funcionarioEscolhido) == 0)
    {
        if (pagamento == 1)
        {
            printf("Imprimindo Boleto...");
                printf("Nome: %s\n", funcionarioEscolhido);
                printf("Cargo: %s\n", funcionarios[quantidadeFuncionarios].cargo);
                printf("Salário: R$%.2f\n", funcionarios[quantidadeFuncionarios].salario);

            printf("Impressão concluída!");
        }
        else if (pagamento == 2)
        {
            printf("Gerando código pix...\n\n");
            sleep(2);

            printf("045521123%s20%d.gov.br\n", funcionarioEscolhido, funcionarios[i].idade);

            printf("Código gerado !");
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct registro_funcionario funcionarios[TAM];

    char funcionarioEscolhido[200];

    int opcao, quantidadeFuncionarios;

    do
    {
        fflush(stdin);
        system("cls || clear");
        printf("_____________________________________\n");
        printf("|1 - Registrar funcionario          |\n");
        printf("|2 - Amostrar a ficha do funcionario|\n");
        printf("|3 - Formas de pagamento            |\n");
        printf("|4 - Mudar turno do funcionario     |\n");
        printf("|5 - Sair e Fechar o programa       |\n\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        system("cls || clear");

        fflush(stdin);

        switch (opcao)
        {
        case 1:
            funcionario(funcionarios, quantidadeFuncionarios);
            quantidadeFuncionarios++;
            break;
        case 2:
            fflush(stdin);
            printf("Digite qual o funcionário: ");
            gets(funcionarioEscolhido);
            system("cls || clear");
            amostrarFicha(funcionarios, funcionarioEscolhido);
            break;
        case 3:
            fflush(stdin);
            printf("Digite qual o funcionário deseja para forma de pagamento: ");
            gets(funcionarioEscolhido);
            system("cls || clear");
            formapagamento(funcionarios, funcionarioEscolhido, quantidadeFuncionarios);
            break;
        case 4:

            break;
        case 5:
            printf("Fechando o programa...");
            sleep(3);
            break;

        default:
            break;
        }

    } while (opcao != 5);

    return 0;
}