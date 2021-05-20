#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void crearNota();
void verificarNota();
void modificarNota();
void eliminarNota();

int opcion;

main() {
	
	do {
	
		system("cls");
	
		printf("\t\t**************************\n");
		printf("\t\t**Welcome to the schedule**\n");
		printf("\t\t**************************\n");
	
		printf("\n\n");
	
		printf("Menu\n\n");
		printf("1. Add note\n");
		printf("2. Verify note\n");
		printf("3. Modify a note\n");
		printf("4. Delete note\n");
		printf("5. Exit\n\n\n");
		
		printf("Option: ");
		scanf("%d", &opcion);
		
		system("cls");
		
		switch(opcion) {
			case 1: crearNota();
				break;
			case 2: verificarNota();
				break;
			case 3: modificarNota();
				break;
			case 4: eliminarNota();
				break;
			default: opcion = 5;
				break;
		}
		
	} while(opcion <= 4 && opcion >= 1);
	
	system("cls");
	
	printf("\t\t*************************************\n");
	printf("\t\t******Thanks for use my program******\n");
	printf("\t\t*************************************\n\n\n");
	
	return 0;
}

void crearNota() {
	
	char nombreFinal[50], segundoString[5] = ".txt", nombreNota[10];

	printf("\t\t***********************\n");
	printf("\t\t***Create a new note***\n");
	printf("\t\t***********************\n\n\n");	
	
	printf("-To create a new note you need to put the date following the example below:\n");
	printf("\n\t\t\t 21 05 2021\n\n");
	printf("-Firt add the day, month and year in this order.\n\n\n\n\n");
	
	printf("Type the name of the note: ");
	fflush(stdin);
	fgets(nombreNota, 12, stdin);
	
	strcpy(nombreFinal, nombreNota);
	strcat(nombreFinal, segundoString);
	
	int i = 0;
	for(i = 0; i < 15; i++) {
		if (i <= 9) {
			nombreFinal[i] = nombreNota[i];
		} else {
			nombreFinal[i] = segundoString[i - 10];
		}
	}
	
	FILE *nuevoArchivo;
	nuevoArchivo = fopen(nombreFinal, "w");
	
	if(nuevoArchivo==NULL){
		printf("Error creating note");
		exit(1);
	} else {
		
		char mesChar[2], diaChar[2];
		int mesInt, diaInt;
		
		i = 0;
		while(nombreNota[i] != '\0') {
			
			if(i == 3 || i == 4) {
				mesChar[i - 3] = nombreNota[i];
				mesInt = atoi(mesChar);
			}
			
			i++;
		}
		
		i = 0;
		while(nombreNota[i] != '\0') {
			
			if(i == 0 || i == 1) {
				diaChar[i] = nombreNota[i];
				diaInt = atoi(diaChar);
			}
			
			i++;
		}
		
		if(mesInt == 3 && diaInt >= 20 || mesInt == 4 || mesInt == 5 || mesInt == 6 && diaInt <= 20) {
			printf("Your note corresponds to the spring season.");
		} else if(mesInt == 6 && diaInt >= 21 || mesInt == 7 || mesInt == 8 || mesInt == 9 && diaInt <= 21) {
			printf("Your note corresponds to the summer season.");
		} else if(mesInt == 9 && diaInt >= 22 || mesInt == 10 || mesInt == 11 || mesInt == 12 && diaInt <= 20) {
			printf("Your note corresponds to the fall season.");
		} else if(mesInt == 12 && diaInt >= 21 || mesInt == 1 || mesInt == 2 || mesInt == 3 && diaInt <= 19) {
			printf("Your note corresponds to the winter season.");
		}
		
		printf("\nYour note has been saved successfully.");
	}
	
	printf("\n\n");
	system("pause");
}

void verificarNota() {
	
	char escrito[150];
	char sumaStrings[50], segundoString[5] = ".txt", nombreArchivo[10];
	
	printf("\t\t*****************************************\n");
	printf("\t\t**********Consult a saved note***********\n");
	printf("\t\t*****************************************\n\n\n");	
	
	printf("-For the consultation of the note you have to enter the date following the example below:\n");
	printf("\n\t\t\t 21 05 2021\n\n");
	printf("-Firt add the day, month and year in this order.\n\n\n\n\n");
	
	printf("Type the date of the note you want to consult: ");
	fflush(stdin);
	fgets(nombreArchivo, 12, stdin);
	
	strcpy(sumaStrings, nombreArchivo);
	strcat(sumaStrings, segundoString);
	
	int i = 0;
	for(i = 0; i < 15; i++) {
		if (i <= 9) {
			sumaStrings[i] = nombreArchivo[i];
		} else {
			sumaStrings[i] = segundoString[i - 10];
		}
	}
	
	FILE *busquedaArchivo;
	busquedaArchivo = fopen(sumaStrings, "r");
	
	if(busquedaArchivo == NULL) {
		printf("There is no note with that name.");
	} else {
		printf("\n");
		while(!feof(busquedaArchivo)) {
		fgets(escrito, 150, busquedaArchivo);
		puts(escrito);
	}
	}
	
	fclose(busquedaArchivo);
	
	printf("\n\n");
	system("pause");
}

void modificarNota() {
	
	char sumaStrings[50], segundoString[5] = ".txt", nombreArchivo[10];
	
	printf("\t\t********************************\n");
	printf("\t\t****Adding content to a note****\n");
	printf("\t\t********************************\n\n\n");	
	
	printf("-To add content to a note you have to enter the date following the example below:\n");
	printf("\n\t\t\t 21 05 2021\n\n");
	printf("-Firt add the day, month and year in this order.\n\n\n\n\n");
	
	printf("Type the date of the note you want to modify: ");
	fflush(stdin);
	fgets(nombreArchivo, 12, stdin);
	
	strcpy(sumaStrings, nombreArchivo);
	strcat(sumaStrings, segundoString);
	
	int i = 0;
	for(i = 0; i < 15; i++) {
		if (i <= 9) {
			sumaStrings[i] = nombreArchivo[i];
		} else {
			sumaStrings[i] = segundoString[i - 10];
		}
	}
	
	FILE *nombreNota;
	nombreNota = fopen(sumaStrings, "rt");
	
	if(nombreNota == NULL) {
		printf("\nA note with that name was not found..");
	} else {
		
		char textoNota[150];
		FILE *punteroParaEscritura;
		punteroParaEscritura = fopen(sumaStrings, "a");
		
		printf("\nWrite what you want to add to your note: ");
		fflush(stdin);
		fgets(textoNota, 150, stdin);
			
		fprintf(punteroParaEscritura, textoNota);
		fprintf(punteroParaEscritura, "\n");
			
		printf("\n\nChanges have been made to your note correctly.");
	}
	
	fflush(nombreNota);
	fclose(nombreNota);
	
	printf("\n\n");
	system("pause");
}

void eliminarNota() {
	
	char sumaStrings[50], segundoString[5] = ".txt", nombreArchivo[10];
	
	printf("\t\t****************************************\n");
	printf("\t\t**********Delete a saved note***********\n");
	printf("\t\t****************************************\n\n\n");	
	
	printf("-To delete a note you have to enter the date following the example below:\n");
	printf("\n\t\t\t 21 05 2021\n\n");
	printf("-Firt add the day, month and year in this order.\n\n\n\n\n");
	
	printf("Type the date of the note you want to delete: ");
	fflush(stdin);
	fgets(nombreArchivo, 12, stdin);
	
	strcpy(sumaStrings, nombreArchivo);
	strcat(sumaStrings, segundoString);
	
	int i = 0;
	for(i = 0; i < 15; i++) {
		if (i <= 9) {
			sumaStrings[i] = nombreArchivo[i];
		} else {
			sumaStrings[i] = segundoString[i - 10];
		}
	}
		
	remove(sumaStrings);
	
	printf("Your note has been successfully removed.");
	
	printf("\n\n");
	system("pause");
}
