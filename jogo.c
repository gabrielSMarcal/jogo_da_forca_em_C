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

void adicionapalavra() {

    char quer;

    printf("Deseja incluir uma palavra no jogo? (S/N)\n");
    scanf(" %c", &quer);

    if (quer == 'S') {

        char novapalavra [20];
        printf("Qual a nova Palavra?\n");
        scanf("%s", novapalavra);

        FILE* f;

        //Abre o arquivo para leitura e edição
        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados não localizado\n\n");
            exit(1);
        }

        //Determina que a primeira linha, que é uma int de número de palavras, precisará ser adicionada +1 na condição de 'S'
        int qt;
        fscanf(f, "%d", &qt);
        qt++;

        //Define o ponteiro para ser apontado no bit 0 para aplicar a lógica acima
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qt);

        //Define agora o ponteiro para o final do arquivo, que será a útilma linha vazia, e escreva a nova palavra no arquivo txt
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
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

    adicionapalavra();
    
    return 0;
}