/* Carlos Javier L�pez Cruz
javier1604@gmail.com
     *
    * *
   *   *
  *     *
  *******
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Dibujos varios !\n");
    printf("Un tri�ngulo:  \n\n");

    int i = 0;
    int j = 0;

    /* Renglones */
    for (i = 1; i < 10; i++)
    {
        /* de mas a menos espacios */
        for (j = 1; j < 10-i; ++j)
            printf(" ");
        printf("*");
        /* de menos a mas espacio */
        for (j = 1; j < 2*i; ++j)
            printf(" ");
        printf("*");

        printf("\n");
    }
    /* la base del tri�ngulo */
    for (i = 1; i < 20; i++)
        printf("*");
    return 0;
}
