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
           y = 0.0,             //Segundo  valor
           z = 0.0;             //Terceiro valor

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Ler tres valores e dizer se o primeiro esta entre os dois ultimos, quando esses forem diferentes entre si. ");
    println ("");               //Pular uma linha

    //Fornecimento de dados
    println ("Forneca um valor: ");
    scanf   ("%lf", &x);
    getchar ();
        
    println ("Forneca um outro valor: ");
    scanf   ("%lf", &y);
    getchar ();

    println ("Forneca um terceiro valor: ");
    scanf   ("%lf", &z);
    getchar ();

    //Resultados
    if (y != z)                 //Se o segundo valor for diferente do terceiro
      {
        if ((y > x && z < x) || (z > x && y < x))
         {
                clrscr  ();
                println ("O primeiro valor fornecido esta entre os dois ultimos. ");
          }
        else
          {
                clrscr  ();
                println ("O primeiro valor fornecido nao esta entre os dois ultimos. ");
          }
      }
    else                        //Se o segundo valor for igual ao terceiro
      {
        clrscr  ();
        println ("Os ultimos valores digitados sao invalidos. ");
      }
    
    //Fim
    println ("");
    pause   ("Aperte <ENTER> para sair. ");
    return  (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/07/2024  (ERRO)   Primeiro Teste
    0.2     03/07/2024  (OK)     Correcao da leitura dos valores e da declaracao "se, entao"
    
*/