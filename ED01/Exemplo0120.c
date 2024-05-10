//853355_AED1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main(void)
{

    #define M_PI 3.14159265358979323846         //Valor de PI

    //Variveis
    double R = 0.0,         //Raio do circulo X
           V = 0.0;         //Volume
    
    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular o volume de uma esfera com tres quartos do raio de uma esfera X.");
    printf("\n");

    //Fornecimento de dados
    printf("%s\n", "Forneca o raio de uma esfera X: ");
    scanf ("%lf", &R);
    getchar();

    //Verificacao do resultado
    if (R <= 0)
    {
        clrscr();
        printf("%s\n", "O raio fornecido e invalido");
        goto Fim;
    }

    //Calculos
    R = R * 0.75;
    R = pow(R,3);
    V = (4 * M_PI * R)/3;

    //Resultado
    clrscr();
    printf("%s\n", "O volume de uma esfera com 3 quartos do raio da esfera X e igual a: ");
    printf("%s%lf\n", "Volume: ", V);

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
    0.2     03/01/2024  (OK)     Correcao do calculo

*/