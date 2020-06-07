/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

void saltaCaracter(FILE* h, FILE *hN, int* c1, int *c2)
{
    if (*c1 == '\\')
    {
        fputc(*c1, hN);
        *c1 = fgetc(h);
    }
    fputc(*c1, hN);
    *c1 = fgetc(h);
    fputc(*c1, hN);
    *c2 = fgetc(h);
}

void saltaComentario(FILE* h, int* c1, int *c2)
{
    *c1 = fgetc(h);
    while (*c1 != EOF)
    {
        *c2 = fgetc(h);
        if (*c2 != EOF && *c1 == '*' && *c2 == '/')
        {
            *c2 = fgetc(h);
            return;
        }
        *c1 = *c2;
    }
    *c2 = EOF;
}

void saltaComilla(FILE *h, FILE *hN, int *c1, int* c2)
{
    int secuencia = 0;

    while (*c1 != EOF)
    {
        *c2 = fgetc(h);
        if (*c1 == '"' && !secuencia)
        {
            fputc(*c1, hN);
            return;
        }
        secuencia = *c1 == '\\' && *c2 == '"';

        fputc(*c1, hN);
        *c1 = *c2;
    }
}

int esCaracter(int c1)
{
    return c1 == '\'';
}

int esComilla(int c1)
{
    return c1 == '"';
}

int esComentario(int c1, int c2)
{
    return c1 == '/' && c2 == '*';
}

/* Abrir un archivo de lectura
   Crear un archivo
   Archivo es una entrada secuencia de caracteres, EOF */
int main()
{
    FILE* h = fopen("prueba.c", "r+");

    if (h != NULL)
    {
        FILE* hN = fopen("sincomen.c", "w");

        if (hN != NULL)
        {
            int c1, c2;

            c1 = fgetc(h);
            while (c1 != EOF)
            {
                c2 = fgetc(h);
                if (c2 == EOF)
                {
                    fputc(c1, hN);
                    c1 = EOF;
                }
                else
                {
                    if (!esComentario(c1, c2))
                    {
                        fputc(c1, hN);
                        if (esComilla(c1))
                        {
                            c1 = c2;
                            saltaComilla(h, hN, &c1, &c2);
                        }
                        if (esCaracter(c1))
                        {
                            c1 = c2;
                            saltaCaracter(h, hN, &c1, &c2);
                        }
                    }
                    else
                        saltaComentario(h, &c1, &c2);
                }
                c1 = c2;
            }

            fclose(hN);
        }
        fclose(h);
    }
    return 0;
}
