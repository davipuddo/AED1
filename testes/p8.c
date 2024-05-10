//853355_AED1

#include "io.h"

int main (void)
{

    //Variaveis
    int x = 0,
        y = 0,
        z = 0;

    //Apresentacao
    clrscr  ();
    println ("853355_AED1");
    println ("Descobrir o quadrante de um angulo x");
    println ("Se este for maior do que 360 ou menor do que -360, fornecer o numero de voltas e em qual sentido");

    //Fornecimento de dados
    println ("Forneca o valor de um angulo: ");
    scanf   ("%d", &x);
    getchar ();

    //Calculo
      //Se o valor inicial for positivo 
    if (x >= 0)
     {
        y = (x/90) + 1;
     }
      //Se o valor inicial for negativo 
    else                 
     {
        y = (x/-90) + 1;
        x = x * -1;
     }
      //Verificar a quantidade de voltas
    if (y > 4)
     {
        z = x/360;
        y = 4;
     }

    //Resultados
    clrscr();
    printf ("%s%d\n", "O angulo fornecido pertence ao quadrante: ", y);
    if (z > 0)
     {
        printf ("O mesmo dando %d volta(s) no sentido horario.\n", z);
        printf ("faltando %d grau(s) para completar uma volta.\n", 360 - (x%360));
     }

     if (z < 0)
     {
         z = z * -1;
        printf ("faltando %d grau(s) para completar uma volta.\n", 360 - (x%360));
        printf ("O mesmo dando %d voltas no sentido anti-horario.\n", z);
     }

    println("");        //Limpar tela
    pause ("Aperte <ENTER> para sair.");
    return(0);
}