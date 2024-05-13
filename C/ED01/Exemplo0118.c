//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main(void)
{

    //Variveis
    double C = 0.0,         //Comprimento
           L = 0.0,         //Largura
           A = 0.0,         //Altura
           V = 0.0;         //Volume

    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular o volume de um paralelepipedo com um oitavo das medidas de um paralelepipedo X.");
    printf("\n");

    //Fornecimento de dados
      //Comprimento
    printf("%s\n", "Forneca o comprimento de um paralelepipedo X: ");
    scanf ("%lf", &C);
    getchar();

      //Largura
    printf("%s\n", "Forneca a largura de um paralelepipedo X: ");
    scanf ("%lf", &L);
    getchar();

      //Altura
    printf("%s\n", "Forneca a altura de um paralelepipedo X: ");
    scanf ("%lf", &A);
    getchar();

    //Verificacao do resultado
    if (C <= 0 || L <= 0 || A <= 0)
    {
        clrscr();
        printf("%s\n", "Um dos dados fornecidos e invalido.");
        goto Fim;
    }

    //Calculos
    C = C/8;
    L = L/8;
    A = A/8;
    V = C * L * A;

    //Resultados
    clrscr();
    printf("%s\n", "O volume de um paralelepipedo com um oitavo das medidas do paralelepipedo X e igual a: ");
    printf("%lf", V);

    //Fim
    Fim:
    printf("\n");
    printf("%s\n", "Aperte <ENTER> para sair");
    getchar();
    return(0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/01/2024  (OK)     Primeiro Teste

*/