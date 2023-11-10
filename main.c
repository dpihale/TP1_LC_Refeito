#include "arquivo.h"
#include <go32.h>
#include <stdio.h>
#include <sys/farptr.h>
#include <string.h>
#include <stdio.h>
int menu()
{
    int opcao;
    system("cls");
    printf("|            = MENU =            |\n");
    printf("| 1. Imprimir um Caratere        |\n");
    printf("| 2. Imprimir uma String         |\n");
    printf("| 3. Imprimir um Numero          |\n");
    printf("| 4. Desenhar um Frame           |\n");
    printf("| 0. Sair                        |\n");
    printf("| Escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao < 1 && opcao > 5)
    {
        system("cls");
        printf("\nA opcao escolhida eh invalida. Escolha outra opcao.\n");
        opcao = menu();
    }
    return opcao;
}
int main()
{
    int x, y;
    char letra;
    char str[100];
    do
    {
        int opcao = menu();
        switch (opcao)
        {
        case 1:

            printf("escolha a posicao x: ");
            scanf("%d", &x);
            printf("escolha a posicao y: ");
            scanf("%d", &y);
            printf("informe um caracter: ");
            letra  = getchar();
            scanf(" %c",&letra);
            system("cls");
            printCharAt(letra, x, y, 0x41);
            getchar();
            getchar();
            break;
        case 2:
             printf("escolha a posicao x: ");
            scanf("%d", &x);
            printf("escolha a posicao y: ");
            scanf("%d", &y);
            printf("informe uma string: ");
            letra  = getchar();
            fgets(str, 100, stdin);
            system("cls");
            printStringAt(str, x, y, 0x41);
            getchar();
            getchar();
        case 4:
            system("cls");
            drawFrame("dj", 0x41,0,0,20,20 );
            getchar();
            getchar();
        default:
            printf("invalido");
        }
    } while (1);
}