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
    printf("%s\n", "Calcular area de um retangulo seis vezes maior do que um retangulo X.");
    printf("\n");

    //Fornecimento de dados

      //Base
    printf("%s\n", "Forneca a base de um retangulo X: ");
    scanf ("%lf", &B);
    getchar();

      //Altura
    printf("\n");
    printf("%s\n", "Forneca a altura do mesmo retangulo X: ");
    scanf ("%lf", &H);
    getchar();

    //Verificacao do resultado
    if (B <= 0 || H <= 0)
    {
        clrscr();
        printf("%s\n", "Um dos valores digitados e invalido.");
        goto Fim;
    }

    //Calculo
    A = ( (B*H)*6 );

    //Resultado
    clrscr();
    printf("%s\n", "A area de um retangulo seis vezes maior do que o retangulo X e igual a: ");
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

    0.1     03/01/2024  (OK)     Primeiro Teste
    0.2     03/01/2024  (OK)     Correcoes ortograficas e organizacao do codigo
    0.3     03/01/2024  (OK)     Correcoes ortograficas
    0.4     03/01/2024  (OK)     Otimizacao do codigo: [double variavel = 0;] // [... = 0.0;]
    0.6     03/01/2024  (OK)     Otimizacao do codigo: [Calculo --> Verificao do resultado] // [Verificao do resultado --> Calculo]
*/