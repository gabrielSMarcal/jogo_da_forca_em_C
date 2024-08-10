#include <stdio.h>
#include <string.h>

void intro() {
    printf("*********************\n");
    printf("*   Jogo da Forca   *\n");
    printf("*********************\n\n");
}

void chute(char c [26], int t) {
    char chute;
    scanf(" %c", &chute);

    c[t] = chute;
}

int main () {
    
    //Letras & Palavras
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes [26];
    int tentativas = 0;

    intro();
    
    do {
        //O jogo

        for(int i=0; i<strlen(palavrasecreta); i++) {

            int achou = 0;

            for(int j=0; j<tentativas; j++) {
                if(chutes[j] == palavrasecreta[i]) {
                    achou = 1;
                    break;
                }
            }
            
            if(achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        chute(chutes, tentativas);
        tentativas++;
        
    } while(!acertou && !enforcou );
    
    
    return 0;
}