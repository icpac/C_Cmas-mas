/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com

Cuenta los caracteres: blanco, tabulador, nueva línea
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Programa que lee cuantos caracteres blanco, tabulador y nueva linea */
    /* ' '  '\t'  '\n' */
    /* getchar() */
    int nl = 0;
    int tb = 0, bl = 0;
    int c;

    /* Leas hasta que ya no quiera EOF */
    while ((c = getchar()) != EOF) /* Lee caracter */
    {
        if (c == ' ')
            bl = bl + 1;
        else if (c == '\t')
            tb++;
        else if (c == '\n')
            ++nl;
    }

    printf("Hay blancos: %d, tabuladores: %d y nueva linea %d\n",
           bl, tb, nl);
    return 0;
}
