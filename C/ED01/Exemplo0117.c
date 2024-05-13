//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main(void)
{

    //Variavel
    double X = 0.0;         //Lado do Cubo X

    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular volume de um cubo com cinco vezes o lado de um cubo X.");
    printf("\n");

    //Fornecimento de dados
    printf("%s\n", "Forneca o lado de um cubo X: ");
    scanf ("%lf", &X);
    getchar();

    //Verificacao do resultado
    if (X <= 0)
    {
        clrscr();
        printf("%s\n", "O valor de X e invalido.");
        goto Fim;
    }

    //Calculo
    X = X * 5;
    X = X * X * X;

    //Resultado
    clrscr();
    printf("%s\n", "O volume de um cubo com cinco vezes o lado do cubo X e igual a: ");
    printf("%s%.4lf\n", "Volume: ", X);

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