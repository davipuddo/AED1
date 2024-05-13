//853355_AED1

#include <stdio.h>
#include <stdlib.h>

//Limpar tela
void clrscr(void) {system("cls");}

//Acoes
int main()
{

    //Variavel
    double X = 0.0;         //lado do quadrado X

    //Apresentacao
    clrscr();
    printf("%s\n", "853355_AED1");
    printf("%s\n", "Calcular a area de um quadrado de lado tres vezes maior do que um quadrado X.");
    printf("\n");

    //Fornecimento de dados
    printf("%s\n", "Forneca o lado de um quadrado X qualquer: ");
    scanf ("%lf", &X);
    getchar();

    //Verificao do resultado
    if (X <= 0)
    {
        clrscr();
        printf("%s\n", "O valor de X digitado e invalido.");
        goto Fim;
    }

    //Calculo
    X = X * 3;
    X = X * X;

    //Resultado
    clrscr();
    printf("%s\n", "A area de um quadrado de lado 3 vezes maior do que o quadrado X e igual a: ");
    printf("%s%.4lf\n", "Area:", X);

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
    0.2     03/01/2024  (OK)     Adicao da verificacao de resultado
    0.3     03/01/2024  (OK)     Correcoes ortograficas e organizacao do codigo
    0.4     03/01/2024  (OK)     Remocao da biblioteca math.h
    0.5     03/01/2024  (OK)     Organizacao do codigo
    0.6     03/01/2024  (OK)     Otimizacao do codigo: [double variavel = 0;] // [... = 0.0;]
    0.7     03/01/2024  (OK)     Otimizacao do codigo: [Calculo --> Verificao do resultado] // [Verificao do resultado --> Calculo]

*/