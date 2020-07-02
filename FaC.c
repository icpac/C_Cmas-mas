/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

void Conversion(int inf, int sup, int pas)
{
    int fahr;
    for(fahr = inf; abs(fahr - sup) > abs(pas/2); fahr = fahr + pas)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)* (fahr-32));
    printf("%3d %6.1f\n", fahr, (5.0/9.0)* (fahr-32));
}

int main()
{
    printf("La tabla de forma ascendente:\n");
    Conversion(0, 300, 20);
    printf("\nLa tabla de forma descendente:\n");
    Conversion(300, 0, -20);
    return 0;
}
