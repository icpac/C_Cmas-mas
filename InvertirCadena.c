/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINEA 100
#define PRUEBA 1

char* lineas = "Hola mundo \n Como has estado \n jala bien \0";
int POS;


/* Vamos a usar la misma cadena para alojar la inversa. */
void invertir (char *cad)
{
    /*Hello world\n*/
    /*\ndlrow olleH*/
    int posLen = 0;
    int posIzq = 0;
    int tmp;

    while (cad[posLen] != '\0')
        posLen++;
    --posLen;

    for (; posLen > posIzq; --posLen, ++posIzq)
    {
        tmp = cad[posIzq];
        cad[posIzq] = cad[posLen];
        cad[posLen] = tmp;
    }
}

int leeCaracter(int opc)
{
    if (opc == PRUEBA)
    {
        if (lineas[POS] != '\0')
            return lineas[POS++];
        return EOF;
    }
    else
        return getchar();
}

int leeLinea(char* linea)
{
    int c;
    int pos = 0;

    while ((c = leeCaracter(/*PRUEBA*/2)) != EOF && c != '\n')
    {
        linea[pos++] = c;
    }
    linea[pos] = '\0';

    return pos;
}

int main()
{
    char linea [MAX_LINEA];

    POS = 0;
    while (leeLinea(linea))
    {
        invertir(linea);
        printf("%s\n", linea);
    }

    return 0;
}
