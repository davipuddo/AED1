
#include <stdio.h>
#include <stdlib.h>

int main ( )
{
 int X = 0,
     N = 0,
     CONTADOR = 0;

    printf ( "EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
    printf ( "\nFORNECER O NUMERO DE VEZES (N) :");
    scanf("%d", &N);
    getchar();
    for ( CONTADOR = 1; CONTADOR <= N; CONTADOR++)
    {
        printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
        scanf  ( "%d", &X );
        getchar( );
        printf ( "\nO VALOR DIGITADO FOI : %d", X );
    }

    printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
    getchar( );
    return ( EXIT_SUCCESS );
} 