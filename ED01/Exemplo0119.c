//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main (void)
{

    #define M_PI 3.14159265358979323846         // Valor de PI

    //Variavel
    double R = 0.0,         //Raio do circulo X
           A = 0.0;         //Area do simicirculo
    
    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular a area de um semicirculo com um sexto do raio de um circulo X.");
    printf("\n");

    //Fornecimento de dados
    printf("%s\n", "Forneca o raio de um circulo X: ");
    scanf ("%lf", &R);
    getchar();

    //Verificacao do resultado
    if (R <= 0)
    {
        clrscr();
        printf("%s\n", "O raio fornecido e invalido.");
        goto Fim;
    }

    //Calculos
    R = R/6;
    A = (M_PI * ( pow(R,2) ))/2;


    //Resultados
    clrscr();
    printf("%s\n", "A area de um semicirculo com um sexto do raio do circulo X e igual a: ");
    printf("%s%lf\n", "Area: ", A);

    //Fim
    Fim:
    printf("\n");
    printf("%s\n", "Aperte <ENTER> para sair");
    getchar();
    return(0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/01/2024  (ERRO)   Primeiro Teste
    0.2     03/01/2024  (OK)     Correcao do codigo: [#define M_PI] // [#define M_PI 3.14159265358979323846]

*/