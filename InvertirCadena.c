/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINEA 1000
#define PRUEBA 1

char* Lineas = "Hola mundo \n Como has estado \n Jala muy bien\t que pasa\0";

/* Invierte la cadena recibida */
void invertir(char* cad)
{
    /*
    Hola mundo\0
    o        H\0
    od      oH\o
    */
    int posLen = 0;
    int posIzq = 0;
    int tmp;

    while (cad[posLen] != '\0')
        ++posLen;
    --posLen;

    for (; posLen > posIzq; --posLen, ++posIzq)
    {
        tmp = cad[posIzq];
        cad[posIzq] = cad[posLen];
        cad[posLen] = tmp;
    }
}

/* Regresa el caracter leido */
int leeCaracter(int opc, int *POS)
{
    if (opc == PRUEBA)
    {
        if (Lineas[*POS] != '\0')
            return Lineas[(*POS)++];
        return EOF;
    }

    return getchar();
}

/* regresa la longitud de la linea leida */
int leeLinea(char* linea, int *POS)
{
    /*
    leeCaracter
    linea[pos] = c
    EOF \n
    */
    int c;
    int pos = 0;

    while ((c = leeCaracter(PRUEBA, POS)) != EOF && c != '\n')
    {
        linea[pos++] = c;
    }
    linea[pos] = '\0';

    return pos;
}

int main()
{
    int POS = 0;
    char linea[MAX_LINEA];

    while (leeLinea(linea, &POS))
    {
        invertir(linea);
        printf("%s\n", linea);
    }
    return 0;
}
