//853355_AED1

#include <stdio.h>
#include <stdlib.h>

// Acoes
int main (void)
{
    // Identificar dados
    int nchar = 0,
        tam   = 10,
        x     = 0;

    char palavra [tam];

    // Inicio
    printf ("%s\n", "Ler uma cadeia de caracteres. ");

    //Entrada de dados
    printf ("%s\n", "Forneca uma palavra");
    do
      {
        x = getchar();
        if ( nchar < tam )
          {
            palavra[nchar++] = x;
            palavra[nchar] = '\0';
          }

      } while (x != '\n' && x != EOF);

    // Mostrar dados
    printf ("[%s]\n", palavra);

    // Teste de vazamento
    char teste [80] = "Teste";
    printf ("[%s]\n", teste);
    
    // Fim
    printf  ("%s\n", "Aperte <ENTER> para sair. ");
    getchar ( );
    return  (0);
}