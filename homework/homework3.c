#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i;
    char digitos[20];

    printf("Digite una Cadena de Numeros: ");gets(digitos);

    if(digitos[0] == '[' || digitos[0] == '(' || digitos[0] == '"'){
        for(i = 0; i < strlen(digitos); i++){
            printf("%c",digitos[i]);
        }
       }
    else{
        for(i = 0; i < strlen(digitos); i++){
            digitos[i] = 'X';
     }
        for(i = 0;i<strlen(digitos); i++){
            printf("%c",digitos[i]);
     }
    }
    printf("\n");
    system("pause");
    return 0;
}
