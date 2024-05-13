//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main(void)
{

    //Variaveis
    double B = 0.0,       //Base
           H = 0.0,       //Altura
           A = 0.0;       //Area

    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular a area de um triangulo com o dobro da altura de um triangulo X.");
    printf("\n");

    //Fornecimento de dados

      //Base
    printf("%s\n", "Forneca a base de um triangulo X: ");
    scanf ("%lf", &B);
    getchar();

      //Altura
    printf("\n");
    printf("%s\n", "Forneca a altura do mesmo triangulo X: ");
    scanf ("%lf", &H);
    getchar();

    //Verificacao do resultado
    if (B <= 0 || H <= 0)
    {
        clrscr();
        printf("%s\n", "Um dos valores fornecidos e invalido.");
        goto Fim;
    }

    //Calculo
    A = B * H;      // = (B * (H * 2)) / 2

    //Resultados
    clrscr();
    printf("%s\n", "A area de um triangulo com o dobro da altura do triangulo X e igual a: ");
    printf("%s%.4lf\n", "Area: ", A);

    //Fim
    Fim:
    printf("\n");
    printf("%s\n", "Aperte <ENTER> para sair.");
    getchar();
    return(0);
}

/*

    VERSAO     DATA     TESTE    MODIFICACAO

    0.1     03/01/2024  (Erro)  Primeiro Teste
    0.2     03/01/2024  (OK)    Correcao do Erro: [ printf("%s%.4lf\n", A) ]
    0.3     03/01/2024  (OK)    Otimizacao do calculo
    0.4     03/01/2024  (OK)    Otimizacao do codigo: [double variavel = 0;] // [... = 0.0;]
    0.5     03/01/2024  (OK)    Otimizacao do codigo: [Calculo --> Verificao do resultado] // [Verificao do resultado --> Calculo]

*/