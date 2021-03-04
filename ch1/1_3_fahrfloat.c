#include <stdio.h>
/*imprime la tabla Fahrenheit-Celsius
    for fahr=0,20,...,300, version de punto flotante*/

int main(){

        printf("Fahrenheit and Celsius Table\n");

        float fahr, celsius;
        int lower, upper, step;

        lower = 0;       //limite superior de la tabla de temperaturas//
        upper = 300;     //limite superior//
        step =  20;       //tamaño del incremento//

        fahr = lower;
        while(fahr <= upper)

        {

            celsius = 5 * (fahr-32) / 9;
            printf("%3.0f %6.1f\n", fahr, celsius);
            fahr = fahr + step;
        }
}
