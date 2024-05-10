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
    int x1 = 0,           //Primeiro valor
        x2 = 0,           //Indicador de paridade do primeiro valor
        y1 = 0,           //Segundo  valor
        y2 = 0;           //Indicador de paridade do Segundo  valor

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Ler dois numeros inteiros e dizer se o primeiro e par e negativo, e o segundo e impar e positivo");
    println ("");           //Pular uma linha

    //Fornecimento de dados
    clrscr  ();
    println ("Forneca um valor x: ");
    scanf   ("%d", &x1);
    getchar ();

    clrscr  ();
    println ("Forneca um valor y: ");
    scanf   ("%d", &y1);
    getchar ();

    //Calculos
    x2 = x1 % 2;            //Resto da divisao entre x e 2
    y2 = y1 % 2;            //Resto da divisao entre y e 2

    //Resultados
    if (x2 == 0)            //Se x for par
      {
        clrscr  ();
        printf ("%s", "O primeiro numero e par e ");
      }
    else                    //Se x for impar
      {
        clrscr  ();
        printf ("%s", "O primeiro numero e impar e ");
      }
    if (x1 < 0)             //Se x for negativo
      {
        printf ("%s", "negativo, ");
      }
    else                    //Se x for positivo
      {
        printf ("%s", "positivo, ");
      }
    if (y2 == 0)            //Se y for par
      {
        printf ("%s", "o segundo numero e par e ");
      }
    else                    //Se x for impar
      {
        printf ("%s", "o segundo numero e impar e ");
      }
    if (y1 < 0)             //Se y fo negativo
      {
        printf ("%s", "negativo. \n");
      }
    else                    //Se y for positivo
      {
        printf ("%s", "positivo. \n");
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