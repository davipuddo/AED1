//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Colocar na tela uma sequencia de caracteres e pular um linha
void println (char *text)
{
    printf ("%s\n", text);
}

//Colocar na tela uma sequencia de caracteres, pular um linha e esperar <ENTER>
void pause (char *text)
{
    printf ("%s\n", text);
    getchar();
}

//Limpar a tela
void clrscr (void) 
{
    system("cls");
}

//Apresentacao
void apresentacao (char *text)
{
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", text);
    printf("\n");
}
