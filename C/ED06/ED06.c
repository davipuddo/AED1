//853355_AED1

#include "io.h"

// Receber um valor inteiro [n] e mostrar [n] multiplos de 6 em ordem crescente
void Multiplos_6C (int n, int x)
{
  if (n > 0)                          // Repetir a recursao [n] vezes
    {
      x = x + 6;
      IO_printf    ("%d\n", x);       // Mostar o resultado
      Multiplos_6C (n-1, x);          // Recursao
    }
}

// Receber um valor inteiro [n] e mostrar [n] multiplos de 6 em orderm decrescente
void Multiplos_6D (int n, int x)
{
  if (n > 0)                          // Repetir a recursao [n] vezes
    {
      x = x + 6;
      Multiplos_6D (n-1, x);          // Recursao
      IO_printf    ("%d\n", x);       // Mostar o resultado
    }
}

// Receber um valor inteiro [n] e mostrar [n] inversos dos multiplos de 6 em orderm crescente, comecando em 1
void In_Multiplos_6_C1 (int n, int x)
{
  if (n > 0)                          // Repetir a recursao [n] vezes
    {
      if (x == 0)
        {
          n--;                        // Reduzir [n] por 1, para a adicao de um caso especial
          IO_println ("1/1");         // Mostar caso especial
        }
      x = x + 6;
      IO_printf    ("1/%d\n", x);     // Mostar o resultado
      In_Multiplos_6_C1 (n-1, x);     // Recursao
    }
}

// Receber um valor inteiro [n] e mostrar [n] inversos dos multiplos de 6 em orderm decrescente, terminando em 1
void In_Multiplos_6_T1 (int n, int x)
{
  if (n > 0)                          // Repetir a recursao [n] vezes
    {
      x = n * 6;
      IO_printf    ("1/%d\n", x);     // Mostar o resultado
      In_Multiplos_6_T1 (n-1, x);     // Recursao
    }
  else
    {
      IO_println ("1/1");             // Mostar caso especial
    }
}

// Calcular a soma de [n] valores gerados pela adicao dos primeiros valores pares positivos ao valor 6
int Soma_Pares_6 (int n, int i, int x, int total)
{
  if (i < n)                                    // Repetir a recursao [n] vezes
    {
      x = x + (i*2);                            // Calcular pares positivos
      total = total + x;                        // Somar tudo
      return Soma_Pares_6 (n, i+1, x, total);   // Recursao
    }
  else
    {
      return (total+6);                         // Resultado final
    }
}

// Calcular soma de [n] inversos dos primeiros valores pares positivos multiplos do valor 6. 
double In_Soma_Pares_6 (int n,int i, double x, double total)
{
  if (i <= n)                          // Repetir a recursao [n] vezes
    {
      x = x + 6;
      total = total + (1/x);
      IO_printf    ("%lf\n", x);            // Mostar o resultado
      return In_Soma_Pares_6 (n, i+1, x, total);     // Recursao
    }
  else
    {
      return (total);                     // Retornar valor final
    }
}

// Ler uma cadeia de caracteres e mostrar cada simbolo separadamente, um por linha
void Simbolo_Cadeia (const char *cadeia, int i)
{
  int TamCad = strlen(cadeia);                  // Tamanho da cadeia de caracteres
  if (i <= TamCad)                              // Repetir Recursao para todos os caracteres
    {
      IO_printf ("%c\n", cadeia[i]);            // Mostar caractere
      Simbolo_Cadeia(cadeia, i+1);              // Recursao
    }
}

// Retornar digitos pares a partir de uma cadeia de caracteres
char *Digitos_Pares_Cadeia (const char *cadeia, int i, int y, char *resultado)
{
  int TamCad = strlen(cadeia);                                  // Tamanho da cadeia de caracteres
  if (i == 0)
    {
      resultado = (char*)malloc(TamCad+2);                      // Alocar [resultado] na memoria
    }

  if (i <= TamCad)                                              // Ler cada caractere individualmente
    {
      if (cadeia[i] >= '0' && cadeia[i] <= '9')                 // Testar se o caractere e um digito
        {
          if (cadeia[i] % 2 == 0)                               // Testar se o caractere e par
            {
              resultado[y] = cadeia[i];                         // Salvar o caractere em [ resultado[y] ]
              y++;
            }
        }
      return Digitos_Pares_Cadeia (cadeia, i+1, y, resultado);  // Recursao
    }
  else
    {
      resultado[y] = '\0';                                      // Finalizar [resultado]
      return (resultado);                                       // Resultado da funcao
    }
}

// Retornar letras maiusculas menores do que 'L' a partir de uma cadeia de caracteres
char *Letras_Maiusculas_Menor_L (const char *cadeia, int i, int y, char *resultado)
{
  int TamCad = strlen(cadeia);                      // Tamanho da cadeia de caracteres
  if (i == 0)
    {
      resultado = (char*)malloc(TamCad+1);          // Alocar [resultado] na memoria
    }

  if (i < TamCad)
    {
      if (cadeia[i] >= 'A' && cadeia[i] < 'L')
      {
        resultado[y] = cadeia[i];
        y++;
      }
      return Letras_Maiusculas_Menor_L (cadeia, i+1, y, resultado);
    }
  else
    {
      resultado[y] = '\0';                        // Terminar a string [resultado]
      return (resultado);                         // Resultado da funcao
    }
}

int Par_Fibonacci (int n)
{
  int termo = 0;
  if (n == 1 || n == 2)
    {
      termo = 1;
    }
  else if (n > 1)
    {
      termo = Par_Fibonacci(n-1) + Par_Fibonacci(n-2);
    }
  return (termo);
}


void ED0601 (void)
{
  // Identificacao de dados
  int n = 0;                        // Quantidade de valores a serem mostrados

  // Apresentacao
  IO_println ("ED0601");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essas quantidades ");
  IO_println ("em valores multiplos de 6 em ordem crescente. ");
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
    
  // Mostrar dados
  Multiplos_6C (n, 0);              // Chamar procedimento [Multiplos_6C]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0602 (void)
{
  // Identificacao de dados
  int n = 0;                        // Quantidade de valores a serem mostrados

  // Apresentacao
  IO_println ("ED0601");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essas quantidades ");
  IO_println ("em valores multiplos de 6 em ordem decrescente. ");
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

  // Mostrar dados
  Multiplos_6D (n, 0);              // Chamar procedimento [Multiplos_6D]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0603 (void)
{
  // Identificacao de dados
  int n = 0;                        // Quantidade de valores a serem mostrados

  // Apresentacao
  IO_println ("ED0603");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essa quantidade em valores ");
  IO_println ("da sequencia dos inversos dos multiplos de 6, comecando em 1. ");
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

  // Mostrar dados
  In_Multiplos_6_C1 (n, 0);         // Chamar procedimento [In_Multiplos_6_C1]

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0604 (void)
{
  // Identificacao de dados
  int n = 0;                        // Quantidade de valores a serem mostrados

  // Apresentacao
  IO_println ("ED0603");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e chamar um procedimento recursivo para mostrar essa quantidade em valores ");
  IO_println ("da sequencia dos inversos dos multiplos de 6, terminando em 1. ");
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

  // Mostrar dados
  In_Multiplos_6_T1 (n, 0);         // Chamar procedimento [In_Multiplos_6_T1]
  
  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0605 (void)
{
  // Identificacao de dados
  int n = 0;                        // Quantidade de valores a serem mostrados

  // Apresentacao
  IO_println ("ED0605");
  IO_println ("");                  // Pular uma linha
  IO_println ("Calcular a soma de valres gerados pela adicao dos primeiros valores positivos ao valor 6. ");
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

  // Mostrar dados
  IO_printf ("Total = %d\n", Soma_Pares_6  (n, 1, 6, 0));    // Mostar resultado da funcao

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0606 (void)
{
  // Identificacao de dados
  int    n = 0;                        // Quantidade de valores a serem mostrados

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


  // Mostrar dados
  IO_printf  ("Total = %lf\n", In_Soma_Pares_6 (n, 1, 0.0, 0.0));  // Mostar resultado da funcao
  
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
  Simbolo_Cadeia (cadeia, 0);       // Chamar Procedimento [Simbolo_Cadeia]

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
  IO_printf ("%s\n", Digitos_Pares_Cadeia(cadeia, 0, 0, 0));      // Chamar funcao [Digitos_Pares_Cadeia]

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
  IO_printf ("%s\n", Letras_Maiusculas_Menor_L(cadeia, 0, 0, 0) ); // Chamar funcao [Letras_Maiusculas_Menor_L]

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
  IO_println ("ED0610 (Incompleto)");
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
  IO_printf("Termo = %d\n",Par_Fibonacci(n));  // Charmar funcao [Par_Fibonacci]

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
    0.7         04/01/24    (OK)       Implementacao do Exercicio ED0607
    0.71        04/01/24    (ERRO)     Implementacao do Exercicio ED0608
    0.8         04/01/24    (OK)       Correcao do algoritimo do Exercicio ED0608
    0.9         04/01/24    (OK)       Implementacao do Exercicio ED0609
    0.91        04/01/24    (ERRO)     Implementacao do Exercicio ED0610
*/