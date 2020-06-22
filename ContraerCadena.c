/*
 _autor_    Tlacaelel Icpac
 _correo_  tlacaelel.icpac@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

void contraer(char s1[], char s2[])
{
    int i;
    int j;
    int m;
    int k;

    /* Recorremos los caracteres de la
       primer cadena */
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {
                for(m = k = i; s1[k] != '\0'; ++k)
                    if (s1[k] != s2[j])
                        s1[m++] = s1[k];
                s1[m] = '\0';
            }
        }
    }
}

int main()
{
    char s1[] = "b";
    char s2[] = "a";
    char s3[] = "ninguna";
    char s4[] = "let";
    char s5[] = "varias letras";
    char s6[] = "repetidas juuuntas";
    char s7[] = "repeeetiiidas juuuntaiis";

    contraer(s7, "ieu");
    printf("\n Resultado: %s", s7);
    return 0;
}
