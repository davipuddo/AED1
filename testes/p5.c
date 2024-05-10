//853355_AED1

#include <stdio.h>
#include <stdlib.h>

int X = 0;


void P1 (void)
{
    printf("\n");
    printf("\nChamado o procedimento P1 %d vez(es)", X);
    printf("\n");
}

int main (void)
{
    for (X = 1; X <= 5; X++)
        P1();
    
    printf("\n");
    printf("%s\n", "Presione <ENTER> para sair.");
    getchar();
    system("cls");
    return(0);
}