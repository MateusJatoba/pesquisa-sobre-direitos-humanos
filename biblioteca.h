#ifndef LISTASE_H
#define LISTASE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[30];
    int idade;
    char genero[30];
    char violencia[4];
    char escravidao[4];
    char tortura[4];
    char repressao[4];

} entrvistado;


void entrevista(entrvistado *e , char f[]){
    FILE *file = fopen(f , "a");
    // char respostas[4][4];

    system("cls");
    printf("Insira seu nome: ");
    scanf("%s" , e->nome);
    printf("\n\n");
    printf("Insira sua idade: ");
    scanf("%d" , &e->idade);
    printf("\n\n");
    printf("Insira seu genero: ");
    scanf("%s" , e->genero);
    printf("\n");

    system("cls");

    printf("Pesquisa sobre violacao dos Direitos Humanos\n");
    printf("------------------------------------------");
    printf("\n\nAs respostas a seguir devem ser respondidas com: [sim] - Sim, [nao] - Nao\n\n");
    printf("Sofreu algum ato de violencia: ");
    scanf("%s" , e->violencia);

    printf("\n\n");

    printf("Trabalhou em condicoes analogas a escravidao: ");
    scanf("%s" , e->escravidao);

    printf("\n\n");

    printf("Sofreu tortura (psicologica ou fisica): ");
    scanf("%s" , e->tortura);

    printf("\n\n");
    
    printf("Sofreu algum tipo de repressao (expressao , religiosa, social e etc): ");
    scanf("%s" , e->repressao);

    if (file)
    {
        fprintf(file , "Nome: %s\nIdade: %d\nGenero: %s\nSofreu algum ato de violencia: %s\nTrabalhou em condicoes analogas a escravidao: %s\nSofreu tortura (psicologica ou fisica): %s\nSofreu algum tipo de repressao (expressao , religiosa, social e etc): %s\n----------------------------------------------------------------------------------------\n" , e->nome , e->idade , e->genero , e->violencia , e->escravidao , e->tortura , e->repressao); // com essa funcao eu printo no arquivo 
        
        fclose(file);
    }

    else{
        printf("Erro ao abrir o arquivo");
    }



}

void listar_participantes(char f[]){
    FILE *file = fopen(f,"r");
    char linha[100]; // declara uma string para guardar a linha
    system("cls");
    if(file == NULL){
        printf("Falha ao abrir o arquivo");
    }
    else{
        while (fgets(linha, sizeof(linha), file) != NULL) { // ate nao achar mais caracter
            printf("%s\n", linha);
        }
        fclose(file);
    }
}



int imprimir_participante(char f[]) {
    FILE *file = fopen(f, "r");
    char texto[100];
    char linha[100];
    char nome[20];

    char nome_busca[20];
    printf("Insira o nome que deseja buscar: ");
    scanf("%s" , nome_busca);

    if (file == NULL) {
        perror("Falha ao abrir o arquivo");
        return 0;
    }

    while (fscanf(file, "%s %s", texto, nome)) { // salva o nome do usuario
        if (strcmp(nome, nome_busca) == 0) { // compara com o nome fornecido pelo usuario
            system("cls");

            printf("%s %s" , texto , nome);

            for (int i = 0; i < 7; i++) // quantidade de dados para imprimir
            {
                fgets(linha, sizeof(linha), file);
                printf("%s\n", linha);

            }    
            

            return 1;
        }
    
    }

    printf("Participante não encontrado: %s\n", nome_busca);
    fclose(file);
    return 0;
}




void totalizacao_violacoes(char f[]) {
    FILE *file = fopen(f, "r");
    char linha[100];
    int total_geral = 0;
    int total_violencia = 0;
    int total_escravidao = 0;
    int total_tortura = 0;
    int total_repressao = 0;
    int total_genero_masculino = 0;
    int total_genero_feminino = 0;
    int total_menores_18 = 0;
    int total_maiores_igual_18 = 0;

    if (file == NULL) {
        perror("Falha ao abrir o arquivo");
        return;
    }

    while (fgets(linha, sizeof(linha), file) != NULL) { //primeiro while abrange o total de violacoes, genero e catwgorias de violacao
        if (strstr(linha, "Genero: masculino") != NULL) {
            for (int i = 0; i < 4; i++) {
                fgets(linha, sizeof(linha), file);

                if (strstr(linha, "Sofreu algum ato de violencia: sim") != NULL) {
                    total_geral++;
                    total_violencia++;
                    total_genero_masculino++;
                } else if (strstr(linha, "Trabalhou em condicoes analogas a escravidao: sim") != NULL) {
                    total_geral++;
                    total_escravidao++;
                    total_genero_masculino++;
                } else if (strstr(linha, "Sofreu tortura (psicologica ou fisica): sim") != NULL) {
                    total_geral++;
                    total_tortura++;
                    total_genero_masculino++;
                } else if (strstr(linha, "Sofreu algum tipo de repressao (expressao , religiosa, social e etc): sim") != NULL) {
                    total_geral++;
                    total_repressao++;
                    total_genero_masculino++;
                }
            }
        } else if (strstr(linha, "Genero: feminino") != NULL) {
            for (int i = 0; i < 4; i++) {
                fgets(linha, sizeof(linha), file);

                if (strstr(linha, "Sofreu algum ato de violencia: sim") != NULL) {
                    total_geral++;
                    total_violencia++;
                    total_genero_feminino++;
                } else if (strstr(linha, "Trabalhou em condicoes analogas a escravidao: sim") != NULL) {
                    total_geral++;
                    total_escravidao++;
                    total_genero_feminino++;
                } else if (strstr(linha, "Sofreu tortura (psicologica ou fisica): sim") != NULL) {
                    total_geral++;
                    total_tortura++;
                    total_genero_feminino++;
                } else if (strstr(linha, "Sofreu algum tipo de repressao (expressao , religiosa, social e etc): sim") != NULL) {
                    total_geral++;
                    total_repressao++;
                    total_genero_feminino++;
                }
            }
        }

    }



    rewind(file);



    while (fgets(linha, sizeof(linha), file) != NULL) { // segundo while abrange a idade
        if (strstr(linha, "Idade: ") != NULL) {
            int idade = 0;
            sscanf(linha, "Idade: %d", &idade);

            if (idade >= 18) {
                for (int i = 0; i < 5; i++) {
                    fgets(linha, sizeof(linha), file);
                    if (strstr(linha, "Sofreu algum ato de violencia: sim") != NULL) {
                        total_maiores_igual_18++;
                    } else if (strstr(linha, "Trabalhou em condicoes analogas a escravidao: sim") != NULL) {
                        total_maiores_igual_18++;
                    } else if (strstr(linha, "Sofreu tortura (psicologica ou fisica): sim") != NULL) {
                        total_maiores_igual_18++;
                    } else if (strstr(linha, "Sofreu algum tipo de repressao (expressao , religiosa, social e etc): sim") != NULL) {
                        total_maiores_igual_18++;
                    }
                }
            } 
            
            else {
                for (int i = 0; i < 5; i++) {
                    fgets(linha, sizeof(linha), file);
                    if (strstr(linha, "Sofreu algum ato de violencia: sim") != NULL) {
                        total_menores_18++;
                    } else if (strstr(linha, "Trabalhou em condicoes analogas a escravidao: sim") != NULL) {
                        total_menores_18++;
                    } else if (strstr(linha, "Sofreu tortura (psicologica ou fisica): sim") != NULL) {
                        total_menores_18++;
                    } else if (strstr(linha, "Sofreu algum tipo de repressao (expressao , religiosa, social e etc): sim") != NULL) {
                        total_menores_18++;
                    }
                }
            }
        }
    }

    printf("\n\nTotal violacoes gerais: %d\n\n", total_geral);
    printf("Total de violencia: %d\n\n", total_violencia);
    printf("Total de escravidao: %d\n\n", total_escravidao);
    printf("Total de tortura: %d\n\n", total_tortura);
    printf("Total de repressao: %d\n\n", total_repressao);
    printf("Total de violacoes por genero masculino: %d\n\n", total_genero_masculino);
    printf("Total de violacoes por genero feminino: %d\n\n", total_genero_feminino);
    printf("Total de violacoes para menores de 18 anos: %d\n\n", total_menores_18);
    printf("Total de violacoes para maiores ou iguais a 18 anos: %d\n\n", total_maiores_igual_18);

    fclose(file);
}





#endif
