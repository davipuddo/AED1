//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


//Limpar Tela
void Clear(void){system("cls");}

//Acoes
int main(void)
{
    //Variavel do lado do quadrado x
    double S = 0;

    //Apresentacao e fornecimento dos dados
    Clear();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Forneca o lado de um quadrado x qualquer: ");
    scanf ("%lf", &S);
    getchar();

    //Calculo
    S = pow((3*S),2);

    //Resultado
    Clear();
    printf("%s%.4lf\n", "O lado de um quadrado de lado 3 vezes maior que x e: ", S);

    //Fim
    printf("%s\n", "Aperte <ENTER> para sair.");
    getchar();
    return(0);
}

