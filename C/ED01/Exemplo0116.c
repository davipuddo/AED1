//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main(void)
{

    //Variaveis
    double X = 0.0,         //Lado do triangulo X
           H = 0.0,         //Altura
           A = 0.0,         //Area
           P = 0.0;         //Perimetro

    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular altura, area e perimetro de um triangulo equilatero com o triplo do lado de um triangulo X do mesmo tipo.");
    printf("\n");

    //Fornecimento de dados
    printf("%s\n", "Forneca o lado de um triangulo equilatero X: ");
    scanf ("%lf", &X);
    getchar();

    //Verificacao do resultado
    if (X <= 0)
    {
        clrscr();
        printf("%s\n", "O valor digitado e invalido.");
        goto Fim;
    }

    //Calculos
    X = X * 3;
    H = (sqrt(3) * X) / 2;
    A = (X * H) / 2;
    P = X * 3;

    //Resultados
    clrscr();
    printf("%s\n", "A altura, area e perimetro de um triangulo equilatero com o triplo do lado do triangulo X do mesmo tipo e igual a: ");
    printf("%s%.4lf\n", "Altura: ", H);
    printf("%s%.4lf\n", "Area: ", A);
    printf("%s%.4lf\n", "Perimetro: ", P);

    //Fim
    Fim:
    printf("\n");
    printf("Aperte <ENTER> para sair");
    getchar();
    return(0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/01/2024  (Erro)   Primeiro Teste
    0.2     03/01/2024  (Ok)     Correcao do calculo: [ A = X * H ] // [ A = (X * H) / 2 ]
    0.3     03/01/2024  (OK)     Otimizacao do codigo: [Calculo --> Verificao do resultado] // [Verificao do resultado --> Calculo]

*/