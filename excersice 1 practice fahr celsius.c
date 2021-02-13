#include <stdio.h>
/* Print the table of Fahrenheit-Celsius
    for fahr=0,20,...,300, put a name on the top of table*/

int main(){


        printf("Fahrenheit and Celsius Table\n");

        int fahr, celsius;
        int lower, upper, step;

        lower = 0;       //limitesuperior de la tabla de temperaturas//
        upper = 300;     //limite superior//
        step = 20;       //tamaño del incremento//

        fahr = lower;
        while(fahr <= upper)

        {

            celsius = 5 * (fahr-32) / 9;
            printf("%3d\t %6d\n", fahr, celsius);
            fahr = fahr + step;
        }
}
