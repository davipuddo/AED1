//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main()
{

    //Variaveis
    double X = 0.0,       //Lado do quadrado X
           A = 0.0,       //Area
           P = 0.0;       //Perimetro

    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular a area e o perimetro de um quadrado duas vezes menor do que um quadrado X.");
    printf("\n");

    //Fornecimento de dados
    printf("%s\n", "Forneca o lado de um quadrado X qualquer: ");
    scanf ("%lf", &X);
    getchar();

    //Verificao dos resultados
    if (X <= 0)
    {
        clrscr();
        printf("%s\n", "O valor de X digitado e invalido.");
        goto Fim;
    }

    //Calculos
    X = X / 2;
    P = X * 4;
    A = X * X;

    //Resultados
    clrscr();
    printf("%s\n", "A area e perimetro de um quadrado de lado 2 vezes menor do que o quadrado X e igual a: ");
    printf("%s%.4lf\n", "Area: ", A);
    printf("%s%.4lf\n", "Perimetro: ", P);
    

    //Fim
    Fim:
    printf("\n");
    printf("%s\n", "Aperte <ENTER> para sair.");
    getchar();
    return(0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/01/2024  (OK)     Primeiro Teste
    0.2     03/01/2024  (OK)     Correcoes ortograficas e organizacao do codigo
    0.3     03/01/2024  (OK)     Remocao da biblioteca math.h
    0.4     03/01/2024  (OK)     Correcoes ortograficas
    0.5     03/01/2024  (OK)     Otimizacao do codigo: [double variavel = 0;] // [... = 0.0;]
    0.6     03/01/2024  (OK)     Otimizacao do codigo: [Calculo --> Verificao do resultado] // [Verificao do resultado --> Calculo]

*/