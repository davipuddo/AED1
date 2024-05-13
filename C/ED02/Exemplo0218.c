//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Colocar na tela uma sequencia de caracteres e pular um linha
void println (char *text)
{
    printf   ("%s\n", text);
}

//Colocar na tela uma sequencia de caracteres, pular um linha e esperar <ENTER>
void pause  (char *text)
{
    printf  ("%s\n", text);
    getchar ();
}

//Limpar a tela
void clrscr (void) 
{
    system ("cls");
}

int main (void)
{

    //Variaveis
    double x = 0.0,             //Primeiro valor
           y = 0.0;             //Segundo  valor

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Ler dois valores e descobrir se o segundo e menor, igual ou maior do que um terco do primeiro. ");
    println ("");            //Pular uma linha

    //Fornecimento de dados
    println ("Forneca um valor x: ");
    scanf   ("%lf", &x);
    getchar ();

    clrscr  ();
    println ("Forneca um valor y: ");
    scanf   ("%lf", &y);
    getchar ();

    //Calculos
    x = x/3.0;

    //Resultado
    if (y < x)
      {
        clrscr  ();
        println ("O segundo valor e menor do que um terco do primeiro. ");
      }
    else if (y == x )
      {
        clrscr  ();
        println ("O segundo valor e igual a um terco do primeiro. ");
      }
    else if (y > x)
      {
        clrscr  ();
        println ("O segundo valor e maior do que um terco do primeiro. ");
      }

    //Fim
    println ("");
    pause   ("Aperte <ENTER> para sair.");
    return  (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/06/2024  (OK)   Primeiro Teste
    
*/