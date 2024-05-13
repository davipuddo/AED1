//853355_AED1

#include "io.h"

// Mostrar [n] multiplos de 6 em ordem crescente 
void Multiplos_6 (int n)                        
{
    for (int i = 1; i <= n; i++ )           // Repetir ate que [i] chegue ao valor de [n]
      {
        IO_printf ("n%d = %d\n", i, i*6);   // Mostrar valor de [i] vezes 6
      }
}

// Mostrar [n] multiplos de 3 e 5 em ordem crescente 
void Multiplos_3_5 (int n)                      
{
    for (int i = 1; i <= n; i++ )           // Repetir ate que [i] chegue ao valor de [n]
      {
        IO_printf ("n%d = %d\n", i, i*15);  // Mostrar valor de [i] vezes 15
      }
}    

// Mostrar [n] potencias de 4 em ordem decrescente 
void Potencia_4 (int n)                      
{
    for (int i = n; i > 0; i-- )                     // Repetir ate que [i] chegue a 1
      {
        IO_printf ("n%d = %d\n", i, (int)pow(4,i));  // Mostrar valor de 4 elevado a [i]
      }
}
    
// Mostrar [n] multiplos de 7 nos denominadores em ordem crescente 
void In_Multiplos_7 (int n)                      
{
    for (int i = 1; i <= n; i++ )            // Repetir ate que [i] chegue a [n]
      {
        IO_printf ("n%d = 1/%d\n", i, i*7);  // Mostrar valor de [i] no denominador vezes 7
      }
}               

// Mostrar [n] potencias de [x] nos denominadores em ordem crescente
void In_Potencia_X (int n, double x)                      
{
    for (int i = 1; i <= n; i++ )                      // Repetir ate que [i] chegue a [n]
      {
        IO_printf ("n%d = 1/%d\n", i, (int)pow(x,i));  // Mostrar valor de [x] elevado a [i] no denominador
      }
}  

// Calcular soma dos primeiros valores positivos, comecando em 3, multiplos de [x] e nao multiplos de [y] 
void Soma_Multiplos_x_Nao_y (int n, int x, int y)
{
    int resultado = 0;                          // Resultado do procedimento

    for (int i = 1; i <= n; i++ )
      {
        if ( ( i * x ) % y != 0)                // Se o proximo resultado nao for multiplo de [y]
          {
            IO_printf ("+ %d\n", (i*x));        // Mostrar valores a serem somados
            resultado = resultado + ( i * x );  // Somar
          }
        else                                    // Se o ([i] * [x]) for um numero multiplo de [y]
          {    
            n++;                                // Ler mais um valor
          }
      }

      IO_printf ("total = %d", resultado);      // Mostrar resultado
    }

// Calcular soma dos inversos dos primeiros valores positivos, comecando em 3, multiplos de [x] e nao multiplos de [y] 
void Soma_In_Multiplos_x_Nao_y (int n, int x, int y)
{
    double resultado = 0.0;                                   // Resultado do procedimento

    for (int i = 1; i <= n; i++)                              // Repitir ate que [i] chegue a [n]
      {
        if ( (i * x) % y != 0)                                // Se o proximo resultado nao for multiplo de [y]
          {
            IO_printf ("1/%d\n", (i*x));                      // Mostrar valores a serem somados
            resultado = resultado + ( 1 / (double)(i * x) );  // Somar
          }
        else                                                  // Se o ([i] * [x]) for um numero multiplo de [y]
          {
            n++;                                              // Ler mais um valor
          }
      }

    IO_printf ("total = %lf", resultado);                     // Mostrar resultado
}

// Calcular soma dos da adicao dos primeiros numeros naturais
void Soma_Naturais_x (int n, int x)
{
    int soma  = x,                // Valor inicial / anterior
        total = 0;                // Resultado da soma

    for (int i = 0; i < n; i++)   // Repitir ate que [i] chegue a [n-1]
      {
        soma = soma + i;          // Somar valor anterior com o proximo numero natural
        total = total + soma;     // Somar tudo
      }

    IO_printf ("total = %d\n", total);  // Mostrar resultado
}

// Calcular soma da adicao do quadrado dos numeros naturais
void Soma_Quadrado_Naturais_x (int n, int x)
{
    int soma = 0;                      // Valor inicial

    for (int i = 0; i < n; i++)        // Repitir ate que [i] chegue a [n]
      {
        soma = soma + pow( (x+i), 2);  // Somar valor inicial com o quadrado do proximo numero natural, e depois somar tudo
      }

    IO_printf ("soma = %d\n", soma);   // Mostrar resultado
}

// Calcular soma do inverso das adicoes dos numeros naturais terminando no valor [x]
void Soma_In_Naturais_x (int n, int x)
{
    int soma = x;                       // Valor inicial
    
    double resultado = 0.0;             // Resultado da procedimento

    for (int i = 0; i < n; i++)         // Repitir ate que [i] chegue a [n]
      {
        soma = soma + i;                // Chegar ao ultimo valor
      }
    for (int i = n-1; i > 0; i--)       // Repetir ate que [i] chegue a 0
      {
        IO_printf ("1/%d\n", soma);                 // Mostar cada numero a ser somado
        resultado = resultado + (1 / (double)soma); // Calcular a soma dos inversos
        soma = soma - i;                            // Reduzir ate o valor inicial
      }
    
    IO_printf ("1/%d\n", soma);                 // Mostar cada numero a ser somado
    resultado = resultado + (1 / (double)soma); // Calcular a soma dos inversos
    IO_printf ("Resultado = %lf\n", resultado); // Mostrar resultado
}
void ED0501 (void)
{
    // Identificacao de dados
    int n = 0;                        // Valor inteiro a ser lido

    // Apresentacao
    IO_println ("ED0501");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma quantidade inteira e com um procedimento mostrar essa quantidade em valores multiplos de 6. ");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    IO_println ("Forneca um valor inteiro: ");
    IO_scanf   ("%d", &n);            // Ler dado
    getchar    ();     

    // Mostrar dados
    Multiplos_6(n);                   // Chamar procedimento [Multiplos_6]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0502 (void)
{
    // Identificacao de dados
    int n = 0;                        // Valor inteiro a ser lido

    // Apresentacao
    IO_println ("ED0502");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma quantidade inteira e com um procedimento mostrar essa quantidade em valores multiplos de 3 e de 5. ");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    IO_println ("Forneca um valor inteiro: ");
    IO_scanf   ("%d", &n);            // Ler dado
    getchar    ();

    // Mostrar dados
    Multiplos_3_5 (n);                // Chamar procedimento [multiplos_3_5]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0503 (void)
{
    // Identificacao de dados
    int n = 0;                        // Valor inteiro a ser lido

    // Apresentacao
    IO_println ("ED0503");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma quantidade inteira e com um procedimento mostrar essa quantidade em valores multiplos de 4 em ordem decrescente. ");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    IO_println ("Forneca um valor inteiro: ");
    IO_scanf   ("%d", &n);            // Ler dado
    getchar    ();

    // Mostrar dados
    Potencia_4 (n);                   // Chamar procedimento [Potencia_4]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0504 (void)
{
    // Identificacao de dados
    int n = 0;                        // Valor inteiro a ser lido
    
    // Apresentacao
    IO_println ("ED0504");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma quantidade inteira e com um procedimento mostrar essa quantidade em valores crescentes nos denominadores multiplos de 7");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    IO_println ("Forneca um valor inteiro: ");
    IO_scanf   ("%d", &n);            // Ler dado
    getchar    ();

    // Mostrar dados
    In_Multiplos_7 (n);               // Chamar procedimento [In_Multiplos_7]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0505 (void)
{
    // Identificacao de dados
    int n = 0;                        // Valor inteiro a ser lido
    double x = 0.0;                   // Valor real a ser lido

    // Apresentacao
    IO_println ("ED0505");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler um valor real, ler um valor inteiro e com um procedimento mostar essa quantidade ");
    IO_println ("em valores pares crescentes nos denominadores da sequencia 1 1/x^2 1/x^4 1/x^8");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
      // Inteiro
    IO_println ("Forneca um valor inteiro: ");
    IO_scanf   ("%d", &n);            // Ler dado
    getchar    ();

      // Real
    IO_println ("Forneca um valor real: ");
    IO_scanf   ("%lf", &x);            // Ler dado
    getchar    ();

    // Mostrar dados
    In_Potencia_X (n, x);             // Chamar procedimento [In_Potencia_X]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0506 (void)
{
    // Identificacao de dados
    int n = 0,                        // Quantidade
        x = 0,                        // Multiplos
        y = 0;                        // Nao multiplos

    // Apresentacao
    IO_println ("ED0506");
    IO_println ("");                  // Pular uma linha
    IO_println ("Calcular a soma dos primeiros valores positivos, comecando no valor [x], multiplos de [x] e nao multiplos de [y]");
    IO_println ("");                  // Pular uma linha
    
        // Ler dados
    do 
      {
        // Quantidade
        IO_println ("Forneca um valor inteiro para definir a quantidade valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();

        // Verificar dados
        if (n < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (n < 0); // Repetir

    do
      {
        // Multiplos
        IO_println ("Forneca um valor inteiro para definir [x]: ");
        IO_scanf   ("%d", &x);
        getchar    ();

        // Verificar dados
        if (x < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (x < 0); // Repetir

    do
      {
        // Nao multiplos
        IO_println ("Forneca um valor inteiro para definir [y]: ");
        IO_scanf   ("%d", &y);
        getchar    ();

        // Verificar dados
        if (y < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (y < 0); // Repetir

    // Mostrar dados
    Soma_Multiplos_x_Nao_y (n, x, y);     // Chamar procedimento [Soma_Multiplos_3_Nao_5]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0507 (void)
{
    // Identificacao de dados
    int n = 0,                        // Quantidade    
        x = 0,                        // Multiplos
        y = 0;                        // Nao multiplos

    // Apresentacao
    IO_println ("ED0507");
    IO_println ("");                  // Pular uma linha
    IO_println ("Calcular a soma dos inversos (1/x) dos primeiros valores positivos, comecando no valor [x], multiplos de [x]");
    IO_println ("e nao multiplos de [y]");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    do 
      {
        // Quantidade
        IO_println ("Forneca um valor inteiro para definir a quantidade valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();

        // Verificar dados
        if (n < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (n < 0); // Repetir

    do
      {
        // Multiplos
        IO_println ("Forneca um valor inteiro para definir [x]: ");
        IO_scanf   ("%d", &x);
        getchar    ();

        // Verificar dados
        if (x < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (x < 0); // Repetir

    do
      {
        // Nao multiplos
        IO_println ("Forneca um valor inteiro para definir [y]: ");
        IO_scanf   ("%d", &y);
        getchar    ();

        // Verificar dados
        if (y < 0)
          { 
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (y < 0); // Repetir

    // Mostrar dados
    Soma_In_Multiplos_x_Nao_y (n, x, y);        // Chamar procedimento [Soma_In_Multiplos_x_Nao_y]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0508 (void)
{
    // Identificacao de dados
    int n = 0,                        // Quantidade    
        x = 0;                        // Valor inicial

    // Apresentacao
    IO_println ("ED0508");
    IO_println ("");                  // Pular uma linha
    IO_println ("Calcular a soma da adicao dos primeiros numeros naturais comecando no valor [x]");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    do 
      {
        // Quantidade
        IO_println ("Forneca um valor inteiro para definir a quantidade valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();

        // Verificar dados
        if (n < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (n < 0); // Repetir

    do
      {
        // Multiplos
        IO_println ("Forneca um valor inteiro para definir [x]: ");
        IO_scanf   ("%d", &x);
        getchar    ();

        // Verificar dados
        if (x < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (x < 0); // Repetir

    // Mostrar dados
    Soma_Naturais_x (n, x);       // Charmar procedimento [Soma_Naturais_x]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0509 (void)
{
    // Identificacao de dados
    int n = 0,                        // Quantidade    
        x = 0;                        // Valor inicial

    // Apresentacao
    IO_println ("ED0508");
    IO_println ("");                  // Pular uma linha
    IO_println ("Calcular a soma da adicao das potencias dos primeiros numeros naturais comecando no valor [x]");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    do 
      {
        // Quantidade
        IO_println ("Forneca um valor inteiro para definir a quantidade valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();

        // Verificar dados
        if (n < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (n < 0); // Repetir

    do
      {
        // Multiplos
        IO_println ("Forneca um valor inteiro para definir [x]: ");
        IO_scanf   ("%d", &x);
        getchar    ();

        // Verificar dados
        if (x < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (x < 0); // Repetir

    // Mostrar dados
    Soma_Quadrado_Naturais_x (n, x);       // Charmar procedimento [Soma_Quadrado_Naturais_x]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0510 (void)
{
    // Identificacao de dados
    int n = 0,                        // Quantidade    
        x = 0;                        // Valor inicial

    // Apresentacao
    IO_println ("ED0510");
    IO_println ("");                  // Pular uma linha
    IO_println ("Clacular a soma dos inversos (1/x) das adicoes de numeros naturais terminando no valor [x] ");
    IO_println ("");                  // Pular uma linha
    
    // Ler dados
    do 
      {
        // Quantidade
        IO_println ("Forneca um valor inteiro para definir a quantidade valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();

        // Verificar dados
        if (n < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (n < 0); // Repetir

    do
      {
        // Multiplos
        IO_println ("Forneca um valor inteiro para definir [x]: ");
        IO_scanf   ("%d", &x);
        getchar    ();

        // Verificar dados
        if (x < 0)
          {
            // Mensagem de erro
            IO_println ("O valor fornecido deve ser maior do que 0");
          }

      } while (x < 0); // Repetir

    // Mostrar dados
    Soma_In_Naturais_x (n, x);        // Charmar procedimento [Soma_In_Naturais_x]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para continuar. ");
}

int main (void)
{

    // Definir dado
    int opcao = 0;

    // Repetir
    do
      {

        // Identificacao
        IO_println ("");              // Pular uma linha
        IO_println ("ED05 - v1.0 - 03/27/24" );
        IO_println ("853355_AED1 - Davi Puddo");
        IO_println ("");              // Pular uma linha

        // Mostrar opcoes
        IO_println ("Exercicios: ");
        IO_println ("");              // Pular uma linha
        IO_println ("0 - sair");
        IO_println ("1 - ED0501   2 - ED0502");
        IO_println ("3 - ED0503   4 - ED0504");
        IO_println ("5 - ED0505   6 - ED0506");
        IO_println ("7 - ED0507   8 - ED0508");
        IO_println ("9 - ED0509  10 - ED0510");
        IO_println ("");              // Pular uma linha

        // Ler opcao
        IO_println ("Escolha um exercicio: ");
        IO_scanf   ("%d", &opcao);
        getchar    ();

        // Escolher opcao
        switch (opcao)
          {
            case 0:
              break;
            case 1:  ED0501();
              break;
            case 2:  ED0502();
              break;
            case 3:  ED0503();
              break;
            case 4:  ED0504();
              break;
            case 5:  ED0505();
              break;
            case 6:  ED0506();
              break;
            case 7:  ED0507();
              break;
            case 8:  ED0508();
              break;
            case 9:  ED0509();
              break;
            case 10: ED0510();
              break;
            default: 
                IO_println ("");                // Pular uma linha
                IO_println ("A opcao escolhida e invalida. ");
                IO_println ("");                // Pular uma linha
              break;

          }

      } while (opcao != 0);

      // Fim
      IO_pause ("Aperte <ENTER> para sair. ");
      return (0);
}

/*
    Versao      Data        Teste      Modificacoes
    0.0         03/27/24    (OK)       Criacao do arquivo ED05 e seus metodos
    0.1         03/27/24    (OK)       Implementacao do Exercicio ED0501
    0.2         03/27/24    (OK)       Implementacao do Exercicio ED0502
    0.3         03/27/24    (OK)       Implementacao do Exercicio ED0503
    0.4         03/27/24    (OK)       Implementacao do Exercicio ED0504
    0.5         03/27/24    (OK)       Implementacao do Exercicio ED0505
    0.61        03/27/24    (ERRO)     Implementacao do Exercicio ED0506
    0.62        03/27/24    (OK)       Mudanca no algoritimo do procedimento [Soma_Multiplos_x_Nao_y]   
    0.71        03/27/24    (ERRO)     Implementacao do Exercicio ED0507
    0.72        03/27/24    (OK)       Adicao do typecast (double) no denominador da divisao
    0.8         03/27/24    (OK)       Implementacao do Exercicio ED0508
    0.9         03/27/24    (OK)       Implementacao do Exercicio ED0509
    1.0         03/27/24    (OK)       Implementacao do Exercicio ED0510

*/