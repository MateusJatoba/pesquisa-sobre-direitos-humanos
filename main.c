#include <stdio.h>
#include <windows.h>
#include "biblioteca.h"
#define N  4000


int main(){
    entrvistado p;
    int escolha;
    // int continua = 0;

    printf("Seja Bem-Vindo a nossa pesquisa relacionada a formas de violacao dos direitos humanos\n");
    Sleep(N);

    while (escolha != 5 || escolha > 0 || escolha < 6)
    {
        system("cls");
        printf("       Menu\n");
        printf("------------------------\n");
        printf("Digite uma opcao a sua escolha\n\n[1] - Responder a pesquisa\n[2] - Listar dados dos respondentes\n[3] - Listar dados individuais\n[4] - Listar estatistica\n[5] - Encerrar programa\n");

        scanf("%d" , &escolha);
        /* code */
        switch (escolha)
        {

        case 1:

            entrevista(&p , "praticas.txt");
            system("pause");
            break;
        
        case 2:
            listar_participantes("praticas.txt");
            system("pause");
            break;
        case 3: 
            imprimir_participante("praticas.txt");
            system("pause");
            break;
        case 4:
            totalizacao_violacoes("praticas.txt");
            system("pause");
            break;

        case 5:
            printf("Fim...");
            Sleep(N);
            return 0;
            break;

        default:
            printf("Opcao indisponivel. Encerrando o programa imediatamente...");
            Sleep(N);
            return 0;
            break;
        }

    }
    


}