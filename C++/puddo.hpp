/** 853355 AED1
 * @author Davi Ferreira Puddo
*/

#include <iostream>    // para entradas e saidas
#include <fstream>     // para arquivos
#include <sstream>     // para conversoes
#include <string>      // para cadeias de caracteres

#include <cstdio>      // para entradas e saida
#include <cstdlib>     // para a biblioteca padrao
#include <cstring>     // para cadeias de caracteres

#include <stddef.h>    // para definicoes basicas
#include <stdarg.h>    // para tratar argumentos
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo


void println (const char* const text)
{
    printf ("%s\n", text);
}

void pause (const char* const text)
{
    println (text);
    getchar ();
}