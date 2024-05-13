/**
 *  @author Davi Puddo
*/

#include <stdio.h>     // para entradas e saidas
#include <stddef.h>    // para definicoes basicas
#include <stdlib.h>    // para a biblioteca padrao
#include <string.h>    // para cadeias de caracteres
#include <stdarg.h>    // para tratar argumentos
#include <stdbool.h>   // para definicoes logicas
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo
#include <wchar.h>     // para 16-bit characters
#include <iso646.h>    // para and, or, xor, not alternatives

/** Mostrar uma cadeia de caracteres e pular uma linha
 *  @param Texto
*/
void println (const char * const text)
{
    printf ("%s\n", text);
}

/** Pausar o programa ate que aperte enter
 *  @param Texto
*/
void pause (const char * const text)
{
  printf  ("%s\n", text);
  getchar ();
}

/** Ler um valor inteiro do teclado
 *  @param Texto
 *  @returns Valor lido
*/ 
int ReadInt (const char * const text)
{
  int x = 0;
  printf  ("%s\n", text);
  scanf   ("%d", &x);
  getchar ( );
  println (""); // Pular uma linha
  return  (x);
}

/** Ler um valor real do teclado
 *  @param Texto
 *  @returns Valor lido
*/ 
double ReadDouble (const char * const text)
{
  double x = 0.0;
  printf  ("%s\n", text);
  scanf   ("%lf", &x);
  getchar ( );
  return  (x);
}

/** Ler um caractere do teclado
 *  @param Texto
 *  @returns Caractere lido
*/ 
char ReadChar (const char * const text)
{
  char x = '0';
  printf  ("%s\n", text);
  scanf   ("%c", &x);
  getchar ( );
  return  (x);
}

/** Ler uma cadeia de caracteres do teclado
 *  @param Texto
 *  @param Tamanho da cadeia de caracteres
 *  @returns Cadeia de caracteres
*/ 
char *ReadString (const char *const text, int tamanho)
{
  char *str = (char*)malloc(tamanho);
  if (str == NULL)
  {
    println ("Falha na alocacao da memoria. ");
    return  (NULL);
  }
  else
  {
    printf ("%s\n", text);
    fgets  (str, tamanho, stdin);
  }
  for (int i = 0; i < tamanho; i++)
  {
    if (str[i] == '\n')
    {
      str[i] = '\0';
    }
  }
  return (str);
}

/** Ler [n] valores inteiros e guarda-los em um array
 *  @param Tamanho inicial do array / Ponto de retorno do tamanho final do array
 *  @param Valor inteiro para determinar a condicao de parada
 *  @returns Array de numeros inteiros
*/
int *ReadInts (int *tamanho, int s)
{
  *tamanho = 10;
  int i = 0;
  int *resultado = (int*)malloc(*tamanho*sizeof(int));

  do
  {
    printf  ("Forneca valores inteiros: ");
    scanf   ("%d", &resultado[i]);
    getchar ();
    
    i++;

    // Realocar memoria
    if (i >= *tamanho)
    {
      *tamanho += 10;
      resultado = (int*)realloc(resultado, (*tamanho)*sizeof(int) );
    }
  } while (resultado[i-1] != (s));

  *tamanho = i-1;
  return (resultado);
}

/** Ler [n] valores reais e guarda-los em um array
 *  @param Tamanho inicial do array / Ponto de retorno do tamanho final do array
 *  @param Valor inteiro para determinar a condicao de parada
 *  @returns Array de numeros reais
*/
double *ReadDoubles (int *tamanho, int s)
{
  *tamanho = 10;
  int i = 0;
  double *resultado = (double*)malloc(*tamanho*sizeof(double));

  do
  {
    printf  ("Forneca valores reais: ");
    scanf   ("%lf", &resultado[i]);
    getchar ();

    i++;

    if (i >= *tamanho)
    {
      *tamanho += 10;
      resultado = (double*)realloc(resultado, (*tamanho)*sizeof(int));
    }
  } while (resultado [i-1] != s);
  *tamanho = i-1;
  return (resultado);
}

/** Calcular a potencia [n] de um numero [x]
 *  @param Base
 *  @param Expoente
 *  @returns Potencia de [x]
*/
int Pow (int x, int n)
{
  int y = x;
  n -= 1;
  if (n < 0)
  {
    n = 0;
  }
  for (int i = 0; i < n; i++)
  {
    x *= y;
  }
  return (x);
}

/** Inverter dois valores inteiros
 *  @param Valor 1
 *  @param Valor 2
*/
void IntInvertValues (int *x, int *y)
{
  int t1 = *x;
  int t2 = *y;
  *x = t2;
  *y = t1;
}

/** Inverter dois valores reais
 *  @param Valor 1
 *  @param Valor 2
*/
void DoubleInvertValues (double *x, double *y)
{
  double t1 = *x;
  double t2 = *y;
  *x = t2;
  *y = t1;
}

/** Retornar um valor pseudo-aleatorio dentro de um intervalo
 *  @param Intervalo inferior
 *  @param Intervalo superior
 *  @param Quantidade de valores a serem gerados / Tamanho do array 
 *  @returns Valor pseudo-aleatorio
*/
int *IntArrayRandInterval (int inferior, int superior, int tamanho)
{
  srand(time(NULL));
  int *array = (int*)malloc(tamanho*sizeof(int));
  int i = 0;

  array[i] = tamanho;
  i++;
  for (i = 0; i < tamanho; i++)
  {
    array[i] = (rand() % (inferior-superior+1)) + inferior;
  }
  return (array);
}

/** Ler e mostrar valores inteiros de um arquivo
 *  @param Nome do arquivo
*/
void IntPrintFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  int x = 0;
  int y = 1;

  printf ("\n%s- \n", fileName);
  fscanf (arquivo, "%d", &x);
  while (!feof (arquivo))
  {
    printf ("%2d: %d\n", y, x);
    fscanf    (arquivo, "%d", &x);
    y++;
  }
  fclose (arquivo);
}

/** Ler um arquivo e retornar uma cadeia de caracteres
 *  @param Nome do arquivo
*/
char *StrTextFile (char *fileName)
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

/** Ler caracteres em um arquivo e retornar valores dentro do intervalo [x:y]
 *  @param Nome do arquivo
 *  @param x intervalo 1
 *  @param y intervalo 2
 *  @returns Caracteres lidos
*/
char *StrFileInterval (char *fileName, char x, char y)
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

/** Escrever uma cadeia de caracteres em um arquivo
 *  @param Nome do arquivo
 *  @param Cadeia_de_caracteres
*/
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

/** Escrever valores inteiros de um array em um arquivo
 *  @param Nome do arquivo
 *  @param Tamanho do array
 *  @param Array
*/
void IntWriteArrayFile (char *fileName, int tamanho, int *array)
{
  FILE *arquivo = fopen(fileName, "wt");
  
  fprintf (arquivo, "%d\n", tamanho);
  for (int i = 0; i < tamanho; i++)
  {
    fprintf (arquivo, "%d\n", array[i]);
  }
  fclose (arquivo);
}

/** Retornar um array de valores inteiros de um arquivo
 *  @param Nome do arquivo
 *  @param Valor qualquer (Ponto de retorno do tamanho do array)
 *  @returns Array
*/
int *IntArrayFile (char *fileName, int *tamanho)
{
  FILE *arquivo = fopen (fileName, "rt");

  fscanf (arquivo, "%d", &(*tamanho));
  int *array = (int*)malloc(*tamanho*sizeof(int));

  if (array == NULL)
  {
    printf ("Nao foi possivel retornar a memoria. \n");
    return (NULL);
  }
  else
  {
    int i = 0;
    while (!feof(arquivo) && i < *tamanho)
    {
      fscanf(arquivo, "%d", &array[i]);
      i = i + 1;
    }
    fclose (arquivo);
  }
  return (array);
}

/** Retornar valores positivos de um array
 *  @param Array
 *  @param Tamanho do array
*/
int *IntArrayPositive (int *array, int *tamanho)
{
  int *resultado = (int*)malloc(*tamanho*sizeof(int));
  int y = 0;
  for (int i = 0; i < *tamanho; i++)
  {
    if (array[i] > 0)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  *tamanho = y;
  return (resultado);
}

/** Pedir [n] valores para fazer um array
 *  @param Tamanho do array
 *  @returns Array
*/
int *IntWriteArray (int tamanho)
{
  int *array = (int*)malloc(tamanho*sizeof(int));

  for (int i = 0; i < tamanho; i++)
  {
    printf  ("Forneca [%d] valores inteiros para o arranjo: ", tamanho-i);
    scanf   ("%d", &array[i]);
    getchar ();
  }
  println (""); // Pular uma linha
  return (array);
}

double *DoubleWriteArray (int tamanho)
{
  double *array = (double*)malloc(tamanho*sizeof(double));

  for (int i = 0; i < tamanho; i++)
  {
    printf  ("Forneca [%d] valores reais para o arranjo: ", tamanho-i);
    scanf   ("%lf", &array[i]);
    getchar ();
  }
  println ("");
  return  (array);
}

/** Ler e mostrar valores de um array inteiro
 *  @param Array
 *  @param Quantidade de valores a serem lidos
*/
void IntPrintArray (int *array, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf ("\n%2d: %d\n", i+1, array[i]);
    }
}

/** Ler e mostrar valores de um array real
 *  @param Array
 *  @param Quantidade de valores a serem lidos
*/
void DoublePrintArray (double *array, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf ("\n%2d: %lf\n", i+1, array[i]);
  }
}

/** Retornar valores inteiros, multiplos de [ x ], de um array
 *  @param Array
 *  @param Tamanho do array
 *  @param Numero(inteiro) para definir o multiplo
 *  @returns Array de muliplos de [ x ]
*/
int *IntMultipleArray (int *array, int *tamanho, int x)
{
  int *resultado = (int*)malloc(*tamanho * sizeof(int));
  int y = 0;
  for (int i = 0; i < *tamanho; i++)
  {
    if (array[i] % x == 0)
    {
      resultado[y] = array[i];
      y++;
    }    
  }
  if (y == 0)
  {
    resultado[y] = 0;
  }
  *tamanho = y;
  return (resultado);
}

/** Retornar valores impares de um array
 *  @param Array
 *  @param Tamanho do array
 *  @return Valores impares do array
*/
int *IntArrayOdd (int *array, int *tamanho)
{
  int *resultado = (int*)malloc(*tamanho*sizeof(int));
  int y = 0;

  for (int i = 0; i < *tamanho; i++)
  {
    if (array[i] % 2 != 0)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  if (y == 0)
  {
    resultado[y] = 0;
  }
  *tamanho = y;
  return (resultado);
}

/** Retornar o menor valor inteiro de um array
 *  @param Array
 *  @param Tamanho do array
 *  @returns O menor valor
*/
int IntArrayBiggest (int *array, int tamanho)
{
  int biggest = 0;
  int i = 0;
  biggest = array[i];
  
  while (i < tamanho)
  {
    if(array[i] > biggest)
    {
      biggest = array[i];
    }
    i++;
  }
  return (biggest);
}

/** Retornar o menor valor inteiro de um array
 *  @param Array
 *  @param Tamanho do array
 *  @returns O menor valor
*/
int IntArraySmallest (int *array, int tamanho)
{
  int smallest = 0;
  int i = 0;
  smallest = array[i];
  
  while (i < tamanho)
  {
    if(array[i] < smallest)
    {
      smallest = array[i];
    }
    i++;
  }
  return (smallest);
}

/** Retornar um array com valores maiores do que [ x ] lidos de outro array 
 *  @param Array
 *  @param Tamanho do array
 *  @param Valor para fazer a comparacao
 *  @returns Array com valores maiores do que [ x ]
*/
int *IntArrayBigger (int *array, int *tamanho, int x)
{
  int *resultado = (int*)malloc(*tamanho*sizeof(int));
  int y = 0;
  for (int i = 0; i < *tamanho; i++)
  {
    if (array[i] > x)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  *tamanho = y;
  return (resultado);
}

/** Retornar um array com valores menores ou iguais a [ x ] lidos de outro array 
 *  @param Array
 *  @param Tamanho do array
 *  @param Valor para fazer a comparacao
 *  @returns Array com valores menores ou igual a [ x ]
*/
int *IntArraySmaller_E (int *array, int *tamanho, int x)
{
  int *resultado = (int*)malloc(*tamanho*sizeof(int));
  int y = 0;
  for (int i = 0; i < *tamanho; i++)
  {
    if (array[i] <= x)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  *tamanho = y;
  return (resultado);
}

/** Ler um array de valores inteiros e retornar a media
 *  @param Array
 *  @param Tamanho do array
 *  @returns Valor real representando a media
*/
double IntArrayAverage (int *array, int tamanho)
{
  int total = 0;
  double resultado = 0.0;

  if (tamanho < 0)
  {
    tamanho = 0;
  }
  for (int i = 0; i < tamanho; i++)
  {
    total = total + array[i];
  }
  resultado = ((double)total / (double)tamanho);
  return (resultado);
}

/** Encontrar a posicao de um valor dentro de um arranjo
 *  @param Array
 *  @param Tamanho do array / Ponto de retorno para quantos valores foram encontrados
 *  @param Valor a ser procurado
 *  @param Valor para determinar a posicao inicial
 *  @returns Posicao do valor 
*/
int IntFindArray (int *array, int *tamanho, int valor, int inicio)
{
  int x = 0;
  int y = 0;
  if (inicio < 0)
  {
    inicio = 0;
  }
  for (int i = inicio; i < *tamanho; i++)
  {
    if (valor == array[i])
    {
      x = i;
      y++;
    }
  }
  *tamanho = y;
  return (x);
}

/** Mostrar valores inteiros de um arranjo dentro de um arquivo
 *  @param Nome do arquivo
*/
void IntPrintArrayFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  int tamanho = 0;
  int x = 0;
  int i = 0;

  printf ("\n%s- \n", fileName);
  fscanf (arquivo, "%d", &tamanho);
  while (!feof(arquivo) && i < tamanho)
  {
    fscanf (arquivo, "%d", &x);
    printf ("%2d: %d\n", i+1, x);
    i++;
  }
  fclose (arquivo);
}
