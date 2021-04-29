/*To run this program you nedd to copy the program tree.h and this program
if you use gbd online add the new file with the name tree.h and then run main.c*/
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
                scanf("%s", add);
               break;
        case 2:printf("Insert Username and Password: ");
               scanf("%s");
               break;
        case 3:printf("%s");
    }

}
