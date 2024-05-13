//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Colocar na tela uma sequencia de caracteres e pular um linha
void println (char *text)
{
    printf   ("%s\n", text);
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

//Acoes
int main (void)
{
    
    //Variavel
    int x = 0;

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Descobrir se um valor x e par ou impar");
    println ("");       //Pular uma limha

    //Fornecimento de dados
    println ("Forneca um valor x: ");
    scanf   ("%d", &x);
    getchar ( );

    //Calculos
    x = x % 2;      //Resto da divisao entre x e 2

    //Resultado
    if (x == 0)
     {
        clrscr  ();
        println ("O numero fornecido e par.");
     } 
    else
     {
        clrscr  ();
        println ("O numero fornecido e impar.");
     }

    //Fim
    pause  ("Aperte <ENTER> para sair.");
    return (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/04/2024  (OK)   Primeiro Teste
    0.2     03/04/2024  (OK)   Organizacao do codigo

*/