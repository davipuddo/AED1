//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void Clear(void) {system("cls");}

//Acoes
int main ()
{
    double a = 0,
           b = 0,
           c = 0,
           x1 = 0,
           x2 = 0,
           delta = 0;

    //Fornecer Dados
    Clear();
    printf("%s\n", "853355_AED1");
    Sleep(1000);

    Clear();
    printf("%s\n", "Forneca a: ");
    scanf ("%lf", &a);
    getchar();

    Clear();
    printf("%s\n", "Forneca b: ");
    scanf ("%lf", &b);
    getchar();

    Clear();
    printf("%s\n", "Forneca c: ");
    scanf ("%lf", &c);
    getchar();

    Clear();

    //Calculos e resultado
    delta = pow(b,2) - 4*a*c;

    if (delta < 0)
    {
        printf("%s\n", "Valores invalidos.\n");

    } else { if (delta == 0)

      {
         x1 = -b / (a*2);
         printf("%s%lf\n", "A equacao possui uma raiz real: ",x1);

      } else {

         x1 = (-b + sqrt(delta)) / (a*2);
         x2 = (-b - sqrt(delta)) / (a*2);

         printf("A equacao possui duas raizes reais: \n r1 = %lf\n r2 = %lf\n"
         ,x1
         ,x2);
      }

    }

    //Fim
    printf("%s\n", "Aperte <ENTER> para sair.");
    getchar();
    Clear();
    return(0);
}
