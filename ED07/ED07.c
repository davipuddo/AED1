//853355_AED1

#include "io.h"

// Ler e mostrar valores inteiros de um arquivo
void IntReadFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  int x = 0;
  int y = 1;

  printf ("\n%s- \n", fileName);
  fscanf (arquivo, "%d", &x);
  while (!feof (arquivo))
  {
    IO_printf ("%d: %d\n", y, x);
    fscanf    (arquivo, "%d", &x);
    y++;
  }
  fclose (arquivo);
}

// Ler e mostrar valores reais de um arquivo
void DoubleReadFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  double x = 0.0;
  int    y = 1;

  printf ("\n%s : \n", fileName);
  fscanf (arquivo, "%lf", &x);
  while (!feof (arquivo) )
  {
    IO_printf ("%d: %lf\n", y, x);
    fscanf    (arquivo, "%lf", &x);
    y++;
  }
  fclose (arquivo);
}

// Ler e mostrar caraceteres em um arquivo
void StrReadFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  char  x = '0';
  int   y = 1;

  printf ("\n%s : \n", fileName);
  fscanf (arquivo, "%c", &x);
  while (!feof(arquivo))
  { 
    IO_printf ("%d: %c\n", y, x);
    fscanf    (arquivo, "%c", &x);
    y++;
  }
  fclose (arquivo);
}

// Ler um arquivo e retornar uma cadeia de caracteres
char *StrReturnTextFile (char *fileName)
{
  FILE *arquivo   = fopen(fileName, "rt");
  char *resultado = (char*)malloc(81);
  char  x = '0';
  int   y = 0;

  fscanf (arquivo, "%c", &x);
  while (!feof(arquivo))
  {
    resultado[y] = x;
    fscanf (arquivo, "%c", &x);
    y++;
  }
  resultado[y] = '\0';
  fclose (arquivo);
  return (resultado);
}

// Escrever uma cadeia de caracteres em um arquivo
void StrWriteFile (char *fileName, char *str)
{
  FILE *arquivo = fopen (fileName, "wt");
  int   TamStr  = strlen(str)-1;
  int   i = 0;

  while ( i <= TamStr )
  {
    if (str[i] != '\n')
    {
      fprintf (arquivo, "%c", str[i]);
    }
    i++;
  }
  fclose (arquivo);
}

// Ler caracteres em um arquivo e retornar valores dentro do intervalo [x:y]
char *StrReturnFileInterval (char *fileName, char x, char y)
{
  FILE *arquivo = fopen (fileName, "rt");
  char *str = (char*)malloc(81);
  char  z = '0';
  int   i = 0;

  fscanf (arquivo, "%c", &z);
  while (!feof(arquivo))
  {
    if (z >= x && z <= y)
    {
      str[i] = z;
      i++;
    }
  fscanf (arquivo, "%c", &z);  
  }
  fclose (arquivo);
  str[i] = '\0';
  return (str);
}

/*
// Ler caracteres em um arquivo e retornar letras maiusculas
char *StrReturnUpperFile (char *fileName)
{
  FILE *arquivo = fopen(fileName, "rt");
  char *str = (char*)malloc(81); 
  char  x = '0';
  int   y = 0;
  
  fscanf (arquivo, "%c", &x);
  while (!feof(arquivo) )
  {
    if (x >= 'A' && x <= 'Z')
    {
      str[y] = x;
      y++;
    }
    fscanf  (arquivo, "%c", &x);
  }
  fclose (arquivo);
  str[y] = '\0';
  return (str);
}
*/

/*
// Ler caracteres em um arquivo e retornar digitos maiores do que 5
char *StrReadFileMaiorIgual5 (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  char *str = (char*)malloc(80);
  char x = '0';
  int  y = 0;

  fscanf (arquivo, "%c", &x);
  while (!feof(arquivo))
  {
    if (x >= '5' && x <= '9')
    {
      str[y] = x;
      y++;
    }
    fscanf (arquivo, "%c", &x);
  }
  fclose (arquivo);
  str[y] = '\0';
  return (str);
}
*/

// Somar [x] a [n] valores de [File1] e salvar em [File2]
void DoubleSomaFile (char *File1, char *File2, int n, int x)
{
  FILE  *dados = fopen (File1, "rt");
  FILE  *resultado = fopen (File2, "wt");
  double valor = 0.0;

  fscanf (dados, "%lf", &valor);
  while (!feof(dados) && n > 0)
  {
    fprintf (resultado, "%lf\n", (valor+x));
    fscanf  (dados, "%lf", &valor);
    n--;
  }
  fclose (dados);
  fclose (resultado);
}

// Retornar o [n] termo par da sequencia de Fibonacci
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

void IntWriteParFibonacciFile (char *fileName, int n)
{
  FILE *arquivo = fopen (fileName, "wt");

  for (int i = 1; i <= n; i++)
  {
    fprintf (arquivo, "%d\n", Par_Fibonacci(i));
  }
  fclose (arquivo);
}

void ED0701 (void)
{
  // Identificacao de dados
  FILE *arquivo = NULL;
  arquivo = fopen ("DADOS1.TXT", "wt");
  int n = 0;

  // Apresentacao
  IO_println ("ED0701");
  IO_println ("");                  // Pular uma linha
  IO_println ("Ler um valor inteiro e gravar essa quantidade em multiplos de 4, pares, em ordem crescente, comecando em 4");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_printf ("Forneca um valor inteiro: ");
  IO_scanf  ("%d", &n);
  getchar   ();
  
  // Gravar dados no arquivo
  for (int i = 1; i <= n; i++)
  {
    fprintf (arquivo, "%d\n", (4*i) );
  }
  fclose (arquivo);

  // Mostrar dados
  IntReadFile ("DADOS1.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0702 (void)
{
  // Identificacao de dados
  FILE *arquivo = NULL;
  arquivo = fopen ("DADOS2.TXT", "wt");
  int n = 0;

  // Apresentacao
  IO_println ("ED0702");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e gravar essa quantidade em multiplos de 5, impares, em ordem decrescente, ");
  IO_println ("encerrando em 25");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_printf ("Forneca um valor inteiro: ");
  IO_scanf  ("%d", &n);
  getchar   ();

  int w = n;                        // Salvar valor [n] 
  while (w > 0) 
  {
    int i = ( 2*(w-1) ) + 5;
    if ( i % 2 != 0)
    {
      fprintf (arquivo, "%d\n", (5*i));
    }
    w--;  
  }

  fclose (arquivo);

  // Mostrar dados
  IntReadFile ("DADOS2.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0703 (void)
{
  // Identificacao de dados
  FILE *arquivo = NULL;
  arquivo = fopen ("DADOS3.TXT", "wt");
  int n = 0;

  // Apresentacao
  IO_println ("ED0703");
  IO_println ("");                  // Pular uma linha
  IO_println ("Ler um valor inteiro e gravar essa quantidade em valores da sequencia 1,5,25,125,625");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_printf ("Forneca um valor inteiro: ");
  IO_scanf  ("%d", &n);
  getchar   ();

  for (int i = 0; i < n; i++)
  {
    fprintf (arquivo, "%lf\n", pow(5,i));
  }
  fclose (arquivo);

  // Mostrar dados
  DoubleReadFile ("DADOS3.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0704 (void)
{
  // Identificacao de dados
  FILE *arquivo = NULL;
  arquivo = fopen ("DADOS4.TXT", "wt");
  int n = 0;

  // Apresentacao
  IO_println ("ED0704");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e gravar essa quantidade em valores decrescentes da sequencia: 1/625, 1/125, ");
  IO_println ("1/25, 1/5");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  if (n == 0)
  {
    IO_printf ("Forneca um valor inteiro: ");
    IO_scanf  ("%d", &n);
    getchar   ();
  }
  
  for (int i = n-1; i >= 0; i--)
  {
    fprintf (arquivo, "%lf\n", ( 1.0/pow(5,i) ) );
  }
  fclose (arquivo);

  // Mostrar dados
  DoubleReadFile ("DADOS4.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0705 (void)
{
  // Identificacao de dados
  FILE *arquivo = NULL;
  arquivo = fopen ("DADOS5.TXT", "wt");
  int    n = 0;
  double x = 0.0;

  // Apresentacao
  IO_println ("ED0705");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro [n] e outro valor real [x], gravar essa quantidade [n] em valores ");
  IO_println ("reais da sequencia: 1, 1/x3, 1/x5, 1/x7");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_printf ("Forneca um valor inteiro: ");
  IO_scanf  ("%d", &n);
  getchar   ();

  IO_printf ("Forneca um valor real: ");
  IO_scanf  ("%lf", &x);
  getchar   ();

  int w = 0;
  for (int i = 0; i < n; i++)
  {
    if (i > 0)
    {
      w = (i * 2) + 1;
    }
    fprintf (arquivo, "%lf\n", (1.0/pow(x,w)) );
  }
  fclose (arquivo);

  // Mostrar dados
  DoubleReadFile ("DADOS5.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0706 (void)
{
  // Identificacao de dados
  int    n = 0;
  double soma  = 0.0;

  // Apresentacao
  IO_println ("ED0706");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro para representar certa quantidade de valores a serem somados dentre ");
  IO_println ("os primeiros gravados no ED0705");
  IO_println ("");                  // Pular uma linha
  
  // Abrir ED0705
  IO_println ("Aperte <ENTER> para abrir ED0705");
  getchar    ();
  ED0705     ();
  IO_println ("ED0706\n");

  // Ler dados
  IO_printf ("Forneca um valor inteiro para definir quantos valores serao somados: ");
  IO_scanf  ("%d", &n);
  getchar   ();

  // Ler dados
  IO_printf ("Forneca um valor real para definir o valor da soma: ");
  IO_scanf  ("%lf", &soma);
  getchar   ();

  // Gravar dados
  DoubleSomaFile ("DADOS5.TXT", "RESULTADO06.TXT", n, soma);

  // Mostrar dados
  DoubleReadFile ("RESULTADO06.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0707 (void)
{
  // Identificacao de dados
  int    n     = 0;
  double valor = 0.0;
  double total = 0.0;

  // Apresentacao
  IO_println ("ED0707");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "ler um valor inteiro, e ate essa quantidade, um valor por vez, ");
  IO_println ("calcular a soma dos inversos das potencias do ED0704.");
  IO_println ("");                  // Pular uma linha

  // Abrir ED0704
  IO_println ("Aperte <ENTER> para abrir ED0704");
  getchar    ();
  ED0704     ();
  IO_println ("ED0707\n");

  // Ler dados
  IO_printf ("Forneca um valor inteiro: ");
  IO_scanf  ("%d", &n);
  getchar   ();

  // Arquivo ED0704
  FILE *fED04 = NULL;
  fED04 = fopen ("DADOS4.TXT", "rt");
  
  fscanf (fED04, "%lf", &valor);
  while (!feof(fED04) && n > 0)
  {
    total = total + valor;                      // somar valores
    fscanf (fED04,"%lf", &valor);
    n = n - 1;
  }
  fclose (fED04);

  // Gravar dados
  FILE *resultado = NULL;
  resultado = fopen ("RESULTADO07.TXT", "wt");
  fprintf (resultado, "%lf\n", total);
  fclose  (resultado);

  // Mostrar dados
  DoubleReadFile ("RESULTADO07.TXT");
  
  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0708 (void)
{
  // Identificacao de dados
  int n = 0;

  // Apresentacao
  IO_println ("ED0708");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Ler um valor inteiro e ate atingir essa quantidade, um valor por vez, ");
  IO_println ("gravar os primeiros termos pares da serie de Fibonacci, gravar resultado em um arquivo. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_printf ("Forneca um valor inteiro: ");
  IO_scanf  ("%d", &n);
  getchar   ();
  
  // Gravar dados 
  IntWriteParFibonacciFile ("DADOS8.TXT", n);

  // Mostrar dados
  IntReadFile ("DADOS8.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0709 (void)
{
  // Identificacao de dados
  char str [80];

  // Apresentacao
  IO_println ("ED0709");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Calcular a quantidade de letras maiusculas em uma cadeia de caracteres de um ");
  IO_printf  ("arquivo texto. Gravar o resultado em outro arquivo. ");
  IO_println ("");                  // Pular uma linha
  
  // Ler cadeia
  IO_println ("Forneca uma cadeia de caracteres: ");
  fgets      (str, 80, stdin);

  // Gravar cadeia em "DADOS9.TXT"
  StrWriteFile ("DADOS9.TXT", str);

  // Ler cadeia do arquivo "DADOS9.TXT" e gravar resultado em "RESULTADO09.TXT"
  StrWriteFile ("RESULTADO09.TXT", StrReturnFileInterval("DADOS9.TXT", 'A', 'Z'));

  // Mostrar dados
  StrReadFile ("RESULTADO09.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void ED0710 (void)
{
  // Identificacao de dados
  char str [80];

  // Apresentacao
  IO_println ("ED0710");
  IO_println ("");                  // Pular uma linha
  IO_printf  ("%s", "Contar digitos maiores dou iguais a 5 em uma cadeia " );
  IO_println ("de caracteres. Gravar resultado em outro arquivo. \n");
  IO_println ("");                  // Pular uma linha
  
  // Ler dados
  IO_println ("Forneca uma cadeia de caracteres: ");
  fgets      (str, 80, stdin);

  // Gravar dados
  StrWriteFile ("DADOS10.TXT", str);

  // Ler cadeia
  StrWriteFile ("RESULTADO10.TXT", StrReturnFileInterval("DADOS10.TXT", '5', '9'));

  // Mostrar dados
  StrReadFile ("RESULTADO10.TXT");

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void T_01 (void)
{
  char str [80];
  IO_println ("Forneca uma cadeia de caracters: ");
  fgets      (str, 80, stdin);

  StrWriteFile ("TESTE01.TXT", str);

  StrReadFile ("TESTE01.TXT");

  IO_printf  ("%s", StrReturnTextFile("TESTE01.TXT"));
  IO_println ("Aperte <ENTER> para sair. ");
  getchar    ();
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
      IO_println ("ED07 - v0.9 - 00/00/00" );
      IO_println ("853355_AED1 - Davi Puddo");
      IO_println ("");              // Pular uma linha

      // Mostrar opcoes
      IO_println ("Exercicios: ");
      IO_println ("");              // Pular uma linha
      IO_println ("0  - sair");
      IO_println ("1  - ED0701   2 - ED0702");
      IO_println ("3  - ED0703   4 - ED0704");
      IO_println ("5  - ED0705   6 - ED0706");
      IO_println ("7  - ED0707   8 - ED0708");
      IO_println ("9  - ED0709  10 - ED0X10");
      IO_println ("11 - T_01    ");
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
          case 1:  ED0701();
            break;
          case 2:  ED0702();
            break;
          case 3:  ED0703();
            break;
          case 4:  ED0704();
            break;
          case 5:  ED0705();
            break;
          case 6:  ED0706();
            break;
          case 7:  ED0707();
            break;
          case 8:  ED0708();
            break;
          case 9:  ED0709();
            break;
          case 10: ED0710();
            break;
          case 11: T_01  ();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED0X e seus metodos

*/