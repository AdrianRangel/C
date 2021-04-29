/*Para ejecutar este programa necesitas copiar el contenido del archivo tree.h
si usas online gbd en el archivo main pegaras este programa y crearas otro con el nombre
de tree.h y ejecutas el archivo main.c*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

int option;
int add;




int main(){
    printf("What do you want to do?\n");
    printf("1. Add user\n2. Delete user\n3. View users\n");
    scanf("%i", &option);
    switch (option){
        case 1:printf("Insert Username and Password: ");
                scanf("%s");
                printf("User created!");
               break;
        case 2:printf("Insert Username and Password: ");
               scanf("%s");
               printf("User deleted!");
               break;
        case 3:printf("%s");
    }

}
