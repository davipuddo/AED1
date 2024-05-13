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
    int x = 0,
        y = 0,
        z = 0;

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Descobrir se um numero x e impar e menor do que -25, ou par e maior que 25.");
    println ("");       //Pular uma linha

    //Fornecimento de dados
    println ("Forneca um valor x: ");
    scanf   ("%d", &x);
    getchar ();

    //Calculos
    y = x % 2;          //Resto da divisao entre x e 2
    z = x - 25;

    //Resultados
    if (y == 0)
     {
        if (z > 0)
         {
            clrscr  ();
            println ("O valor digitado e par e maior do que 25.");
         }
        else
         {
            clrscr  ();
            println ("O valor digitado e par, mas nao e maior do que 25.");
         }
     }
    else
     {
        if (z > (-50))
         {
            clrscr  ();
            println ("O valor digitado e impar e maior do que -25.");   
         }
        else if (z == (-50))
         {
            clrscr  ();
            println ("O valor digitado e par e igual a -25.");
         }
        else
         {
            clrscr  ();
            println ("O valor digitado e impar, mas menor do que -25.");
         }
     }
    
    //Fim
    println ("");       //Pular uma linha
    pause   ("Aperte <ENTER> para sair.");
    return  (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/04/2024  (OK)   Primeiro Teste
    0.2     03/04/2024  (OK)   Resultado se x for igual a -25
    
*/