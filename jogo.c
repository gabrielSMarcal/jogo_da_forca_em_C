#include <stdio.h>
#include <string.h>
char palavrasecreta[20];
char chutes [26];
int tentativas = 0;

void intro() {
    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n\n");
}

void chute(char chutes[26]) {
    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int chutou(char letra){
    int achou = 0;

    for(int j=0; j<tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
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
    sprintf(palavrasecreta, "MELANCIA");
}

int main () {
    //Letras & Palavras
    //VAR
    int acertou = 0;
    int enforcou = 0;



    palavraselecionada();
    intro();
    
    do {
        //O jogo

        desenhaforca();
        chute(chutes);
        
    } while(!acertou && !enforcou );
    
    
    return 0;
}