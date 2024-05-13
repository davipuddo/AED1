//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Colocar na tela uma sequencia de caracteres e pular um linha
void println (char *text)
{
    printf   ("%s\n", text);
}

//Colocar na tela uma sequencia de caracteres, pular um linha e esperar <ENTER>
void pause (char *text)
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
    int  x  = 0;             //Valor inicial

    bool i1 = false,         //Primeiro intervalo
         i2 = false;         //Segundo  intervalo

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Dados os intervalos [10:30] e (25:50)");
    println ("Dizer se um valor inteiro pertence a intersecao ou a apenas um deles. ");
    println ("");            //Pular uma linha

    //Fornecimento de dados
    println ("Forneca um valor x: ");
    scanf   ("%d", &x);
    getchar ();

    //Simplificacao dos dados
    if (10 < x && x < 30)
      {
        i1 = true;
      }
    if (25 <= x && x <= 50)
      {
        i2 = true;
      }

    //Resultado
    if      ((i1) && (i2))      //Se o valor inicial pertecer a ambos os intervalos
      {
        println ("");
        println ("O valor fornecido pertence a ambos os intervalos. ");
      }
    else if ((i1) && !(i2))      //Se o valor inicial pertecer apenas ao primeiro intervalo
      {
        println ("");
        println ("O valor fornecido pertence apenas ao intervalo [10:30]. ");
      }
    else if (!(i1) && (i2))      //Se o valor inicial pertecer apenas ao segundo intervalo
      {
        println ("");
        println ("O valor fornecido pertence apenas ao intervalo (25:50). ");
      }
    else                         //Se o valor inicial nao pertecer a nenhum dos intervalos
      {
        println ("");
        println ("O valor fornecido nao pertence a nenhum dos intervalos fornecidos. ");
      }

    //Fim
    println ("");
    pause   ("Aperte <ENTER> para sair.");
    return  (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/06/2024  (OK)   Primeiro Teste
    0.2     03/06/2024  (OK)   Implementacao da biblioteca: "<stdbool.h>"
    
*/