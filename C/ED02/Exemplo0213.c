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
    
    //Varivel
    int x = 0;

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Dizer se um valor inteiro pertence ao intervalo aberto (35:65). ");
    println ("");            //Pular uma linha

    //Fornecimento de dados
    println ("Forneca um valor x: ");
    scanf   ("%d", &x);
    getchar ();

    //Resultado
    if (35 < x && x < 65)
      {
        println ("");        //Pular uma linha
        println ("O valor fornecido pertence ao intervalo aberto (35:65). ");
      }
    else
     {
        println ("");        //Pular uma linha
        println ("O valor fornecido nao pertence ao intervalo aberto (35:65). ");
     }

    //Fim
    println ("");            //Pular uma linha
    pause   ("Aperte <ENTER> para sair.");
    return  (0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/06/2024  (OK)   Primeiro Teste
    0.2     03/06/2024  (OK)   Organizacao do codigo
    
*/