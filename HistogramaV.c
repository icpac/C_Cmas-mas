/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANO_MAXIMOA_PALABRA 50
#define PRUEBA 1
int POS;

int LeeCaracter(int opc)
{
    char *cadena = "4444: 55555\t22, 1, 7777777; 88888888 \t 1010101010 1 4444 7777777 22 22 333\0";
    /*
    1 2
    2 3
    3 1
    4 2
    5 1
    6 0
    7 2
    8 1
    9 0
    10 1
    */

    if (opc == PRUEBA)
        return cadena[POS++];

    return getchar();
}

int EsBlanco(int c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == ',' || c == ';' || c == ':';
}

/* Regresa la longitud de la palabra leida */
int palabras()
{
    int longitud = 0;
    int c;

    /* Texto, de pureba         otra palabra*/
    while ((c = LeeCaracter(PRUEBA)) != EOF && c != '\0')
    {
        if (!EsBlanco(c))
            ++longitud;
        else if (longitud > 0)
            break;
    }
    return longitud;
}


/*
 4 |
 3 |            *
 2 |   *        *        *
 1 |   *  *     *     *  *
 -------------------------
       1  2  3  4  5  6  7
*/

void muestraHistograma(int *longitudes)
{
    /* Encontrar el tamaño maximo leido */
    int longMax = 0;
    int ejeX = 0;
    int c, d;

    /* Conocer amplitudes en el eje x y y*/
    for (c = 0; c < TAMANO_MAXIMOA_PALABRA; ++c)
    {
        if (longitudes[c] > 0)
        {
            if (longitudes[c] > longMax)
                longMax = longitudes[c];
            ejeX = c;
        }
    }

    /*Imprimimos el primer cuadrante */
    for (c = longMax + 1; c > 0; --c)
    {
        printf("%d |", c);
        for (d = 0; d < ejeX +1; ++d)
        {
            if (longitudes[d] >= c)
                printf("*");

            printf("\t");
        }
        printf("\n");
    }

    /* Imprimir el eje X */
    printf("  |");
    for (c = 0; c < ejeX*8; ++c)
        printf("-");
    printf("\n");

    /* Imprime las unidades en el eje X*/
    for (c = 1; c < ejeX+1; ++c)
        printf("\t%d", c);

    printf("\n");
}


int main()
{
    /*
    Leer texto, identificar las palabras
    contar su tamaño
    Guardar ese tamaño
    Mostrarlo de forma vertical
    */

    int longitudes[TAMANO_MAXIMOA_PALABRA];
    int c;
    int longitud;

    /* inicializar el arreblo */
    for (c = 0; c < TAMANO_MAXIMOA_PALABRA; ++c)
        longitudes[c] = 0;

    /* Leer el texto, mientras haya */
    while ((longitud = palabras()) > 0)
    {
        if (longitud < TAMANO_MAXIMOA_PALABRA)
            longitudes[longitud] += 1;
    }

    /* Mostrar el histograma */
    muestraHistograma(longitudes);

    return 0;
}
