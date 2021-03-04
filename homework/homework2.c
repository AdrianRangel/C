#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void binario(int n);

int main(){
    int numero[10] = {29,17,13,23,11,7,2,3,5,19};
    int i = 0,j = 0,aux;
    do{

        binario(numero[i]);
        i++;
    }while(i != 10);
    system("cls");

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(numero[j]>numero[j+1]){
                aux = numero[j];
                numero[j] = numero[j+1];
                numero[j+1] = aux;
            }

        }
    }

    printf("Orden de menor a mayor\n");

    for(i=0;i<10;i++){
        printf("\nLa posicion %i: %i",i+1,numero[i]);printf("\n");
        binario(numero[i]);
    }


    printf("\n");
    getch();
    system("pause");
    return 0;
}

void binario(int n){
    if(n>1) binario(n/2);

    printf("%i",n%2);

}
