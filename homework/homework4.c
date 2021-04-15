#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void Datos_Usuario();
void Calculadora(char Name[]);
//void Asignacion_Variable();
int Suma(int,int);
//int Resta();

int num1,num2;
char Nombre[30];

int main(){
    Datos_Usuario();
    Calculadora(Nombre);

    getch();
    return 0;
}
void Datos_Usuario(){
    printf("Digite el Nombre de Usuario:");gets(Nombre);
}
void Calculadora(char Nombre[]){
    system("cls");
    int Opcion;
    char Continuacion[10],Variable1[1],Variable2[1],specialf[2];
    do{
        printf("\t\t\t\t\t--CALCULADORA DE TIPO ENTERO--\n");
        printf("Nombre del Usuario:%s\n",Nombre);
        printf("Que desea Hacer: \n1.Sumar.\n2.Restar.\n3.Multiplicar.\n4.Dividir.\n5.Resto.\n6.El Cuadrado de un Numero.\n7.La Raiz de un Numero.\n8.Salir del Programa 'EOF'.\nSu Opcion:");
        scanf("%i",&Opcion);
        fflush(stdin);

        //Asignacion_Variable();

    printf("Digite la Variable 1:");gets(Variable1);
    printf("=");scanf("%i",&num1);
    fflush(stdin);
    printf("Digite la Variable 2:");gets(Variable2);
    printf("=");scanf("%i",&num2);



    if(strcmp((strupr(Variable2),strupr(Variable1))==0){
        printf("Digite el Comando especial: ':=' para forzar ambas variables.\nSi Deseas volver al Menu Digite cualquier Caracter:");
        fflush(stdin);
        gets(specialf);
        if(strcmp(specialf,":=")==0){
            printf("Excelente.\n");
            getch();
        }
        else{
            main();
        }
    }
        switch(Opcion){
            case 1:printf("La Suma es:%i\n",Suma(num1,num2));
            system("pause");
            getch();
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            default:break;
        }



        /while(Continuacion){

        }/
        system("cls");

    }while(Continuacion == 'EOF');
}
int Suma(int N1,int N2){
    int Suma = 0;
    Suma = N1 + N2;
    return Suma;
}
