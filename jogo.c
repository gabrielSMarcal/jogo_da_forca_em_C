#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"


//Variáveis Globais
char palavrasecreta[20];
char chutes [26];
int chutesdados = 0;

void intro() {

    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n\n");
}

void chute() {
   
    char chute;

    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca() {

    for(int i=0; i<strlen(palavrasecreta); i++) {

        int retornoachou = chutou(palavrasecreta[i]);
        if(retornoachou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");
}

void palavraselecionada() {

    FILE* f;

    //Abre o arquivo e o deixano modo leitura
    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados não localizado\n\n");
        exit(1);
    }

    //Lê a primeira linha e retorna a primeira que informa quantas palavrão são
    int qtdepalavras;
    fscanf(f, "%d", &qtdepalavras);
    
    //Puxa de maneira randomica as linhas com uma das palavras
    srand(time(0));
    int aleatorio = rand() % qtdepalavras;

    for (int i=0; i<=aleatorio; i++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int enforcou() {

    int erros = 0;

    for (int i=0; i<chutesdados; i++){
        int existe = 0;

        for (int j=0; j<strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros >= 5;
}

int ganhou() {

    for(int i=0; i<strlen(palavrasecreta); i++){
        if(!chutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;
}

int chutou(char letra) {

    int achou = 0;

    for(int j=0; j<chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

int main () {
    //Funções iniciais
    palavraselecionada();
    intro();
    
    do {
        //O jogo
        desenhaforca();
        chute();
        
    } while(!ganhou() && !enforcou());
    
    
    return 0;
}