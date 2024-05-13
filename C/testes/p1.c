//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void Clear (){system("cls");}

char  X = '0';

//acoes
int main (void)
    {

        //inicio
        Clear();
        printf("%s\n", "853355_AED1");
        Sleep(1000);
        Clear();

    do {
            printf("%s\n", "Digite um dos simbolos: >, <, =, +, -");
            scanf ("%c",&X);
            getchar();


            switch(X)
            {
                case '>': Clear();
                          printf("%s\n", "Foi digitado o sinal de maior");
                          printf("%s\n", "Aperte <S> para sair");
                break;
                case '<': Clear();
                          printf("%s\n", "Foi digitado o sinal de menor");
                          printf("%s\n", "Aperte <S> para sair");
                break;
                case '=': Clear();
                          printf("%s\n", "Foi digitado o sinal de igual");
                          printf("%s\n", "Aperte <S> para sair");
                break;
                case '+': Clear();
                          printf("%s\n", "Foi digitado o sinal de mais" );
                          printf("%s\n", "Aperte <S> para sair");
                break;
                case '-': Clear();
                          printf("%s\n", "Foi digitado o sinal de menos");
                          printf("%s\n", "Aperte <S> para sair");
                break;
                default:  Clear();
                          printf("%s\n", "Foi digitado um outro sinal"  );
                          printf("%s\n", "Aperte <S> para sair");
            }
        } while (X != 'S');

        // Fim
        printf("%s\n", "Aperte <ENTER> para sair.");
        getchar();
        return(0);
    }