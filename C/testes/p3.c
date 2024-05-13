//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void Clear(){system("cls");}

int main (void)
{
    //Inicio
    Clear();
    printf("%s\n", "853355_AED1");
    Sleep(1000);

    //Acoes
    double V = 0,
           D = 0,
           T = 0;
    
    printf("%s\n", "Forneca uma distancia qualquer em metros: ");
    scanf ("%lf",&D);
    getchar();
    printf("%s\n", "Forneca um tempo para percorer dada distancia em segundos: ");
    scanf ("%lf",&T);
    getchar();

    V = D/T;

    Clear();
    printf("%lf%s\n", V ,"m/s");

    //Fim
    printf("%s\n", "Aperte <ENTER> para sair.");
    getchar();
    return(0);
}