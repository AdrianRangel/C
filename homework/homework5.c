/*Hola este es mi buscaminas espero que te guste,
si usaras gdb online unicamente copia todo el codigo
no olvides seleccionar el lenguaje en c, presiona el boton run
te pedira digitar la fila (que son las letras) das enter
y te pedira digitar la columna (que son los numeros)
Suerte y diviertete con mi buscaminas!!*/

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define mina_encontrada 1
#define espacio_ya_descubierto 2
#define ningun_error 3
#define columnas 10
#define filas 10
#define espacio_vacio '.'
#define espacio_descubierto ' '
#define mina 'x'
#define cantidad_minas 5
#define DEBUG 0


int obtenerMinasCercanas(int fila, int columna, char tablero[filas][columnas]) { //obtiene el numero de minas cercana a la coordenada
  int conteo = 0, filaInicio, filaFin, columnaInicio, columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= filas) {
    filaFin = filas - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    columnaInicio = 0;
  } else {
    columnaInicio = columna - 1;
  }
  if (columna + 1 >= columnas) {
    columnaFin = columnas - 1;
  } else {
    columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = columnaInicio; l <= columnaFin; l++) {
      if (tablero[m][l] == mina) {
        conteo++;
      }
    }
  }
  return conteo;
}


int aleatorioEnRango(int minimo, int maximo) { //da un numero aleatorio entre minimo y maximo
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void iniciarTablero(char tablero[filas][columnas]) { //pone espacios sin descubrir en el tablero
  int l;
  for (l = 0; l < filas; l++) {
    int m;
    for (m = 0; m < columnas; m++) {
      tablero[l][m] = espacio_vacio;
    }
  }
}


void colocarMina(int fila, int columna, char tablero[filas][columnas]) { //coloca minas en una coordenada especifica
  tablero[fila][columna] = mina;
}


void colocarMinasAleatoriamente(char tablero[filas][columnas]) { //coloca minas de forma aleatoria
  int l;
  for (l = 0; l < cantidad_minas; l++) {
    int fila = aleatorioEnRango(0, filas - 1);
    int columna = aleatorioEnRango(0, columnas - 1);
    colocarMina(fila, columna, tablero);
  }
}

void imprimirSeparadorEncabezado() {
  int m;
  for (m = 0; m <= columnas; m++) {
    printf("----");
    if (m + 2 == columnas) {
      printf("-");
    }
  }
  printf("\n");
}

void imprimirSeparadorFilas() {
  int m;
  for (m = 0; m <= columnas; m++) {
    printf("----");
    if (m == columnas) {
      printf("-");
    }
  }
  printf("\n");
}

void imprimirEncabezado() {
  imprimirSeparadorEncabezado();
  printf("|   ");
  int l;
  for (l = 0; l < columnas; l++) {
    printf("| %d ", l + 1);
    if (l + 1 == columnas) {
      printf("|");
    }
  }
  printf("\n");
}

char enteroACaracter(int numero) { //cambia a un int por un char
  return numero + '0';
}

void imprimirTablero(char tablero[filas][columnas], int deberiaMostrarMinas) {
  imprimirEncabezado();
  imprimirSeparadorEncabezado();
  char letra = 'A';
  int l;
  for (l = 0; l < filas; l++) {
    int m;

    printf("| %c ", letra); //imprime la letra de la fila
    letra++;
    for (m = 0; m < columnas; m++) {

      char verdaderaLetra = espacio_vacio; //no se le muestra al usuario si hay una mina
      char letraActual = tablero[l][m];
      if (letraActual == mina) {
        verdaderaLetra = espacio_vacio;
      } else if (letraActual == espacio_descubierto) {

        int minasCercanas = obtenerMinasCercanas(l, m, tablero); //si abre la casilla, entonces mostramos la minas cercanas
        verdaderaLetra = enteroACaracter(minasCercanas);
      }

      if (letraActual == mina && (DEBUG || deberiaMostrarMinas)) { //si tenemos DEBUG en 1, deberia mostrar las minas en caso de que pierda o gane
        verdaderaLetra = mina;
      }
      printf("| %c ", verdaderaLetra);
      if (m + 1 == columnas) {
        printf("|");
      }
    }
    printf("\n");
    imprimirSeparadorFilas();
  }
}


int abrirCasilla(char filaLetra, int columna, char tablero[filas][columnas]) { //inica el tablero con fila y columna

  filaLetra = toupper(filaLetra); //convierte a mayuscula

  columna--; //se resta uno porque se usa la columna como indice

  int fila = filaLetra - 'A'; //convertimos la letra a indice
  assert(columna < columnas && columna >= 0);
  assert(fila < filas && fila >= 0);
  if (tablero[fila][columna] == mina) {
    return mina_encontrada;
  }
  if (tablero[fila][columna] == espacio_descubierto) {
    return espacio_ya_descubierto;
  }

  tablero[fila][columna] = espacio_descubierto; //colocamos el espacio descubierto
  return ningun_error;
}


int noHayCasillasSinAbrir(char tablero[filas][columnas]) { //indicamos que el usuario gano
  int l;
  for (l = 0; l < filas; l++) {
    int m;
    for (m = 0; m < columnas; m++) {
      char actual = tablero[l][m];
      if (actual == espacio_vacio) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  printf("       BUSCAMINAS\n");
  char tablero[filas][columnas];
  int deberiaMostrarMinas = 0;

  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);

  while (1) { //ciclio infinito que se rompe si ganas o pierdes
    imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf ("\n");
    printf("Digite la fila: ");
    scanf(" %c", &fila);
    printf("Digite la columna: ");
    scanf("%d", &columna);
    printf("\n");
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("Ganaste!!\n");
      deberiaMostrarMinas = 1;
    } else if (status == espacio_ya_descubierto) {
      printf("Ya has abierto esta casilla!!\n");
    } else if (status == mina_encontrada) {
      printf("\n");
      printf("Perdiste!!\n");
      deberiaMostrarMinas = 1;
    }
  }
  return 0;
}
