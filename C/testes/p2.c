//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void Clear (){system("cls");}

int main(void)
{
    const char SENHA[5] = "1234";

    char S[10];

    Clear();
    printf("%s\n", "853355_AED1");
    Sleep(1000);
    Clear();

    printf("%s\n", "Digite a senha:");
    scanf ("%s",S);
    getchar();
    if (strcmp(S,SENHA)==0)
    {
        Clear();
        printf("\nSenha Correta: %s\n",S);
    } else {
        Clear();
        printf("\nSenha Errada: %s\n",S);
    }

    printf("%s\n", "Aperte <ENTER> para sair.");
    getchar();
    Clear();
    return(0);
}