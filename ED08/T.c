
#include "io.h"

int main (void)
{
    // Identificacao de dados
    int *x = NULL;
    x = malloc(1 * sizeof(int));
    if (x) {*x = 10;}

    // Ler dados
  
    // Mostrar dados
    IO_printf ("%d\n", *x);
    IO_printf ("%d\n", *(x));

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
    return (0);
}