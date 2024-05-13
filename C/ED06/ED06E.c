//853355_AED1

#include "io.h"

// Receber um valor inteiro [n] e mostrar [n] multiplos de 6 em orderm crescente
void Multiplos_XC (int n, int x)
{
  for (int i = 1; i <= n; i++)        // Sequencia de numeros naturais ate [n]
    {
      IO_printf ("%d\n", i*x);        // Multiplicar numero natural por [x] e mostar o resultado
    }
}

// Receber um valor inteiro [n] e mostrar [n] multiplos de [x] em orderm decrescente
void Multiplos_XD (int n, int x)
{
  for (int i = n; i > 0; i--)         // Sequencia de numeros naturais ate [n] em ordem decrescente
    {
      IO_printf ("%d\n", i*x);        // Multiplicar numero natural por [x] e mostar o resultado
    }
}

// Receber um valor inteiro [n] e mostrar [n] inversos dos multiplos de [x] em orderm crescente, comecando em 1
void In_Multiplos_X_C1 (int n, int x)
{
  n--;                                // Reduzir [n] por 1, para a adicao de um caso especial  
  IO_println ("1/1");                 // Mostar caso especial

  for (int i = 1; i <= n; i++)        // Sequencia de numeros naturais ate [n]
  {
    IO_printf ("1/%d\n", i*x);        // Multiplicar numero natural por [x] e mostar o resultado
  }
}

// Receber um valor inteiro [n] e mostrar [n] inversos dos multiplos de [x] em orderm decrescente, terminando em 1
void In_Multiplos_X_T1 (int n, int x)
{
  n--;                                // Reduzir [n] por 1, para a adicao de um caso especial  

  for (int i = n; i > 0; i--)         // Sequencia de numeros naturais ate [n] em ordem decrescente
  {
    IO_printf ("1/%d\n", i*x);        // Multiplicar numero natural por [x] e mostar o resultado
  }

  IO_println ("1/1");                 // Mostar caso especial
}

// Calcular a soma de [n] valores gerados pela adicao dos primeiros valores pares positivos ao valor [x]
int Soma_Pares_X (int n, int x)
{
  int soma  = x,                      // Valor inicial / anterior
      total = 0;                      // Resultado total da soma  

  for (int i = 0; i < n; i++)         // Sequencia de numeros naturais ate [n-1] em ordem crescente
    {
      soma  = soma  + (i*2);          // Somar [n] numeros pares a [x]
      total = total + soma ;          // Somar tudo
    //  IO_printf ("+%d\n", soma);    // Mostar valores somados
    }

  return (total);                     // Retornar valor final
}

// Calcular soma de [n] inversos dos primeiros valores pares positivos multiplos do valor [x]. 
double In_Soma_Pares_X (int n, int x)
{
  double total = 0;                   // Resultado total da soma 

  for (int i = 1; i <= n; i++)        // Sequencia de numeros naturais ate [n] em ordem crescente
    {
      total = total + ( 1/(double)(i * x) );    // Somar 
    // IO_printf ("+ 1/%lf\n", soma);           // Mostar valores somados
    }
  return (total);                     // Retornar valor final
}

// Ler uma cadeia de caracteres e mostrar cada simbolo separadamente, um por linha
void Simbolo_Cadeia (char *cadeia)
{
  int TamCad = strlen(cadeia);              // Tamanho da cadeia de caracteres
  
  for (int i = 0; i <= TamCad; i++)         // Ler cada caracter individualmente
    {
      IO_printf ("%c\n", cadeia[i]);        // Mostar caractere
    }
}

// Retornar digitos pares a partir de uma cadeia de caracteres
char* Digitos_Pares_Cadeia (const char *cadeia)
{
  int TamCad = strlen(cadeia);                  // Tamanho da cadeia de caracteres
  char* resultado = (char*)malloc(TamCad+1);    // Alocar [resultado] na memoria
  int y = 0;                                    // Posicao do caractere em [resultado]

  for (int i = 0; i <= TamCad; i++)             // Ler cada caractere individualmente
    {
      if (cadeia[i] >= '0' && cadeia[i] <= '9') // Testar se o caractere e um digito
        {
          if (cadeia[i] % 2 == 0)               // Testar se o caractere e par
            {
              resultado[y] = cadeia[i];         // Salvar valor em [resultado]
              y++;                              // Ir para o proximo caractere
            }
        }
    }
    
  resultado[y] = '\0';                          // Terminar a string [resultado]
  
  return (resultado);                           // Resultado da funcao
}

// Retornar letras maiusculas menores do que 'L' a partir de uma cadeia de caracteres
char *Letras_Maiusculas_Menor_L (const char *cadeia)
{
  int TamCad = strlen(cadeia);                  // Tamanho da cadeia de caracteres
  char* resultado = (char*)malloc(TamCad+1);    // Alocar [resultado] na memoria
  int y = 0;                                    // Posicao do caractere em [resultado]

  for (int i = 0; i <= TamCad; i++)             // Ler cada caractere individualmente
    {
      if (cadeia[i] < 'L' && cadeia[i] >= 'A')  // Testar se o caractere e uma letra maiuscula menor do que 'L'
        {
          resultado[y] = cadeia[i];             // Salvar valor em [resultado]
          y++;                                  // Ir para o proximo caractere
        }
    }

    resultado[y] = '\0';                        // Terminar a string [resultado]

    return (resultado);                         // Resultado da funcao
}

int Par_Fibonacci (int n)
{
  int x    = 1,                       // Valor 1
      y    = 0,                       // Valor 2
      z    = 0;                       // Termo final
  for (int i = 0; i < n; i++)         // Ler [n] sequencias da serie fibonacci
    {
      // Calcular Fibonacci
      z = x + y;
      y = x;
      x = z;
      if (z % 2 != 0)                 // Se [z] for um numero par
        {
          n++;                        // Pular para a proxima sequencia
        }
    }
  return (z);                         // Resultado da funcao
}

void ED0601 (void)
{
  // Identificacao de dados
  int n = 0,                        // Quantidade de valores a serem mostrados
      x = 0;                        // Multiplos

  // Apresentacao
  IO_println ("ED0601");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essas quantidades ");
  IO_println ("em valores multiplos de [x] em ordem crescente. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
    // Quantidade
    do                              // Repetir ate que [n] tenha um valor valido
      {
        IO_println ("Forneca um valor inteiro para definir a quantidade de valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();
        if (n <= 0)
          {
            IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
          }
      } while (n <= 0);             // Verificar dados

    // Multiplos
    do                              // Repetir ate que [n] tenha um valor valido
    {
      IO_println ("Forneca um valor inteiro para definir [x]: ");
      IO_scanf   ("%d", &x);
      getchar    ();
      if (x <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
        }
    } while (x <= 0);               // Verificar dados
    
  // Mostrar dados
  Multiplos_XC (n, x);              // Chamar procedimento [Multiplos_XC]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0602 (void)
{
  // Identificacao de dados
  int n = 0,                        // Quantidade de valores a serem mostrados
      x = 0;                        // Multiplos

  // Apresentacao
  IO_println ("ED0601");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essas quantidades ");
  IO_println ("em valores multiplos de [x] em ordem decrescente. ");
  IO_println ("");                  // Pular uma linha
    

  // Ler dados
    // Quantidade
    do                              // Repetir ate que [n] tenha um valor valido
      {
        IO_println ("Forneca um valor inteiro para definir a quantidade de valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();
        if (n <= 0)
          {
            IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
          }
      } while (n <= 0);             // Verificar dados

    // Multiplos
    do                              // Repetir ate que [n] tenha um valor valido
    {
      IO_println ("Forneca um valor inteiro para definir [x]: ");
      IO_scanf   ("%d", &x);
      getchar    ();
      if (x <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
        }
    } while (x <= 0);               // Verificar dados
      
  // Mostrar dados
  Multiplos_XD (n,x);               // Chamar procedimento [Multiplos_XD]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0603 (void)
{
  // Identificacao de dados
  int n = 0,                        // Quantidade de valores a serem mostrados
      x = 0;                        // Multiplos

  // Apresentacao
  IO_println ("ED0603");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essa quantidade em valores ");
  IO_println ("da sequencia dos inversos dos multiplos de [x], comecando em 1. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
    // Quantidade
    do                              // Repetir ate que [n] tenha um valor valido
      {
        IO_println ("Forneca um valor inteiro para definir a quantidade de valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();
        if (n <= 0)
          {
            IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
          }
      } while (n <= 0);             // Verificar dados

    // Multiplos
    do                              // Repetir ate que [n] tenha um valor valido
    {
      IO_println ("Forneca um valor inteiro para definir [x]: ");
      IO_scanf   ("%d", &x);
      getchar    ();
      if (x <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
        }
    } while (x <= 0);               // Verificar dados

  // Mostrar dados
  In_Multiplos_X_C1 (n, x);         // Chamar procedimento [In_Multiplos_X_C1]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0604 (void)
{
  // Identificacao de dados
  int n = 0,                        // Quantidade de valores a serem mostrados
      x = 0;                        // Multiplos

  // Apresentacao
  IO_println ("ED0603");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essa quantidade em valores ");
  IO_println ("da sequencia dos inversos dos multiplos de [x], terminando em 1. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
    // Quantidade
    do                              // Repetir ate que [n] tenha um valor valido
      {
        IO_println ("Forneca um valor inteiro para definir a quantidade de valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();
        if (n <= 0)
          {
            IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
          }
      } while (n <= 0);             // Verificar dados

    // Multiplos
    do                              // Repetir ate que [n] tenha um valor valido
    {
      IO_println ("Forneca um valor inteiro para definir [x]: ");
      IO_scanf   ("%d", &x);
      getchar    ();
      if (x <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
        }
    } while (x <= 0);               // Verificar dados

  // Mostrar dados
  In_Multiplos_X_T1 (n, x);         // Chamar procedimento [In_Multiplos_X_T1]
  
  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0605 (void)
{
  // Identificacao de dados
  int n = 0,                        // Quantidade de valores a serem mostrados
      x = 0,                        // Multiplos
      r = 0;                        // Resultado

  // Apresentacao
  IO_println ("ED0605");
  IO_println ("");                  // Pular uma linha
  IO_println ("Calcular a soma de valres gerados pela adicao dos primeiros valores positivos ao valor [x]. ");
  IO_println ("");                  // Pular uma linha
  
 // Ler dados
    // Quantidade
    do                              // Repetir ate que [n] tenha um valor valido
      {
        IO_println ("Forneca um valor inteiro para definir a quantidade de valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();
        if (n <= 0)
          {
            IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
          }
      } while (n <= 0);             // Verificar dados

    // Multiplos
    do                              // Repetir ate que [n] tenha um valor valido
    {
      IO_println ("Forneca um valor inteiro para definir [x]: ");
      IO_scanf   ("%d", &x);
      getchar    ();
      if (x <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
        }
    } while (x <= 0);               // Verificar dados

  // Mostrar dados
  r = Soma_Pares_X  (n, x);         // Chamar funcao [Soma_Pares_X]
  IO_printf ("Total = %d\n", r);    // Mostar resultado da funcao

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0606 (void)
{
  // Identificacao de dados
  int    n = 0,                        // Quantidade de valores a serem mostrados
         x = 0;                        // Multiplos
  double r = 0;                        // Resultado

  // Apresentacao
  IO_println ("ED0606");
  IO_println ("");                  // Pular uma linha
  IO_println ("Calcular soma dos inversos (1/x) dos primeiros valores pares positivos multiplos do valor [x]. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
    // Quantidade
    do                              // Repetir ate que [n] tenha um valor valido
      {
        IO_println ("Forneca um valor inteiro para definir a quantidade de valores a serem mostrados: ");
        IO_scanf   ("%d", &n);
        getchar    ();
        if (n <= 0)
          {
            IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
          }
      } while (n <= 0);             // Verificar dados

    // Multiplos
    do                              // Repetir ate que [n] tenha um valor valido
    {
      IO_println ("Forneca um valor inteiro para definir [x]: ");
      IO_scanf   ("%d", &x);
      getchar    ();
      if (x <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero inteiro maior do que zero. ");
        }
    } while (x <= 0);               // Verificar dados

  // Mostrar dados
  r = In_Soma_Pares_X (n, x);       // Chamar funcao [In_Soma_Pares_X]
  IO_printf  ("Total = %lf\n", r);  // Mostar resultado da funcao
  
  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0607 (void)
{
  // Identificacao de dados
  char cadeia [80];                 // Cadeia de caracteres a ser lida

  // Apresentacao
  IO_println ("ED0607");
  IO_println ("");                  // Pular uma linha
  IO_println ("Ler uma cadeia de caracteres e chamar um Funcao recursivo para mostrar cada simbolo separadamente, um por linha. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_println ("Forneca uma cadeia de caracteres: ");
  fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

  // Mostrar dados
  Simbolo_Cadeia (cadeia);          // Chamar Funcao [Simbolo_Cadeia]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0608 (void)
{
  // Identificacao de dados
  char cadeia [80];                 // Cadeia de caracteres a ser lida

  // Apresentacao
  IO_println ("ED0608");
  IO_println ("");                  // Pular uma linha
  IO_println ("Contar os digitos com valores pares em uma cadeia de caracteres. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_println ("Forneca uma cadeia de caracteres: ");
  fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

  // Mostrar dados
  IO_printf ("%s\n", Digitos_Pares_Cadeia(cadeia) );      // Chamar funcao [Digitos_Pares_Cadeia]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0609 (void)
{
  // Identificacao de dados
  char cadeia [80];                 // Cadeia de caracteres a ser lida

  // Apresentacao
  IO_println ("ED0609");
  IO_println ("");                  // Pular uma linha
  IO_println ("Calcular a quantidade de letras maiusculas menores do que 'L' em uma cadeia de caracteres. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_println ("Forneca uma cadeia de caracteres: ");
  fgets      (cadeia, 80, stdin);   // Ler dados

  // Mostrar dados
  IO_printf ("%s\n", Letras_Maiusculas_Menor_L(cadeia) ); // Chamar funcao [Letras_Maiusculas_Menor_L]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0610 (void)
{
  // Identificacao de dados
  int n = 0;                        // Quantidade de valores a serem mostrados

  // Apresentacao
  IO_println ("ED0610");
  IO_println ("");                  // Pular uma linha
  IO_println ("Calcular certo termo par da serie de Fibonacci comecando em 1. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  do
    {
      IO_println ("Forneca um valor inteiro: ");
      IO_scanf   ("%d", &n);
      getchar    ();

      if (n <= 0)
        {
          IO_println ("O valor fornecido deve ser um numero maior do que zero. ");
        }

    } while (n <= 0);               // Verificar dados

  // Mostrar dados
  IO_printf("Termo = %d\n", Par_Fibonacci(n));  // Charmar funcao [Par_Fibonacci]

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
      IO_println ("ED06 - v1.0 - 04/01/24" );
      IO_println ("853355_AED1 - Davi Puddo");
      IO_println ("");              // Pular uma linha

      // Mostrar opcoes
      IO_println ("Exercicios: ");
      IO_println ("");              // Pular uma linha
      IO_println ("0 - sair");
      IO_println ("1 - ED0601   2 - ED0602");
      IO_println ("3 - ED0603   4 - ED0604");
      IO_println ("5 - ED0605   6 - ED0606");
      IO_println ("7 - ED0607   8 - ED0608");
      IO_println ("9 - ED0609  10 - ED0610");
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
          case 1:  ED0601();
            break;
          case 2:  ED0602();
            break;
          case 3:  ED0603();
            break;
          case 4:  ED0604();
            break;
          case 5:  ED0605();
            break;
          case 6:  ED0606();
            break;
          case 7:  ED0607();
            break;
          case 8:  ED0608();
            break;
          case 9:  ED0609();
            break;
          case 10: ED0610();
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
    0.0         04/01/24    (OK)       Criacao do arquivo ED06 e seus metodos
    0.1         04/01/24    (OK)       Implementacao do Exercicio ED0601
    0.2         04/01/24    (OK)       Implementacao do Exercicio ED0602
    0.3         04/01/24    (OK)       Implementacao do Exercicio ED0603
    0.4         04/01/24    (OK)       Implementacao do Exercicio ED0604
    0.5         04/01/24    (OK)       Implementacao do Exercicio ED0605
    0.6         04/01/24    (OK)       Implementacao do Exercicio ED0606
    0.6.1       04/01/24    (OK)       Mudanca das funcoes e procedimentos para aceitarem um valor [x] como parametro
    0.7         04/01/24    (OK)       Implementacao do Exercicio ED0607
    0.8         04/01/24    (OK)       Implementacao do Exercicio ED0608
    0.9         04/01/24    (OK)       Implementacao do Exercicio ED0609
    1.0         04/01/24    (OK)       Implementacao do Exercicio ED0610
*/