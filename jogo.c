#include <stdio.h>
#include <string.h>

void intro() {
    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n\n");
}

void chute(char chutes[26], int* tentativas) {
    char chute;
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int chutou(char letra, char chutes[26], int tentativas){
    int achou = 0;

    for(int j=0; j<tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca(char palavrasecreta[20], char chutes[26], int tentativas) {
    for(int i=0; i<strlen(palavrasecreta); i++) {

        int retornoachou = chutou(palavrasecreta[i], chutes, tentativas);

        if(retornoachou) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void palavraselecionada(char palavrasecreta[20]) {
    sprintf(palavrasecreta, "MELANCIA");
}

int main () {
    //Letras & Palavras
    char palavrasecreta[20];
    char chutes [26];
    int tentativas = 0;
    int acertou = 0;
    int enforcou = 0;



    palavraselecionada(palavrasecreta);
    intro();
    
    do {
        //O jogo

        desenhaforca(palavrasecreta, chutes, tentativas);
        chute(chutes, &tentativas);
        
    } while(!acertou && !enforcou );
    
    
    return 0;
}