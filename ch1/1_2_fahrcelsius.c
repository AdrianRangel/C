#include <stdio.h>
/*imprime la tabla Fahrenheit-Celsius
    for fahr=0,20,...,300, version de punto flotante*/

int main(){

        printf("Fahrenheit and Celsius Table\n");

        float fahr, celsius;
        int lower, upper, step;

        #define lower 0       //limitesuperior de la tabla de temperaturas//
        #define upper 300     //limite superior//
        #define step 20       //tamaño del incremento//

        fahr = lower;
        printf("F\tC\n--------------\n");
        while(fahr <= upper)

        {

            celsius = 5 * (fahr-32) / 9;
            printf("%3.0f %6.1f\n", fahr, celsius);
            fahr = fahr + step;
        }
}
