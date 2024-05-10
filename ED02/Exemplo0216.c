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

//Acoes
int main (void)
{

    //Variveis
    int x = 0,           //Primeiro valor
        y = 0;           //Segundo  valor

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Ler dois numeros inteiros e dizer se o primeiro e impar e o segundo e par");
    println ("");        //Pular uma linha

    //Fornecimento de dados
    clrscr  ();
    println ("Forneca um valor x: ");
    scanf   ("%d", &x);
    getchar ();

    clrscr  ();
    println ("Forneca um valor y: ");
    scanf   ("%d", &y);
    getchar ();

    //Calculos
    x = x % 2;           //Resto da divisao entre x e 2
    y = y % 2;           //Resto da divisao entre y e 2

    //Resultados
    if      (x != 0 && y == 0)         //Se x for impar e y for par
      {
        clrscr  ();
        println ("O primeiro numero e impar e o segundo numero e par. ");
      }
    else if (x == 0 && y == 0)        //Se ambos forem pares
      {
        clrscr  ();
        println ("O primeiro numero e o segundo numeros sao pares. ");
      }
    else if (x != 0 && y != 0)        //Se ambos forem impares
      {
        clrscr  ();
        println ("O primeiro numero e o segundo numeros sao impares. ");
      }
    else                               //Se x for par e y for impar
      {
        clrscr  ();
        println ("O primeiro numero e par e o segundo numero e impar. ");
      }

    //Fim
    println("");
    pause  ("Aperte <ENTER> para sair.");
    return (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/06/2024  (OK)   Primeiro Teste
    
*/