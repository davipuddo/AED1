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

const int MAX = 100;   // Definir tamanho padrao

#define null NULL      // Generalizacao


/**                                                Funcoes de uso geral
 * --------------------------------------------------------------------
*/

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
 *  @note POSSIVEL RESTO DURANTE A LEITURA
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

/** Ler um valor inteiro maior do que zero
 *  @param Texto
 *  @returns Valor lido
 *  @note Serao lidos infinitos valores ate que um valor maior do que zero seja recebido
 *  @note (POSSIVEL RESTO DURANTE A LEITURA)
*/
int ReadPositiveInt (const char * const text)
{
  int x = 0;
  do
  {
    printf  ("%s\n", text);
    scanf   ("%d", &x);
    getchar ();
  } while (x <= 0);

  println (""); // Pular uma linha
  return (x);
}

/** Ler um valor real do teclado
 *  @param Texto
 *  @returns Valor lido
 *  @note POSSIVEL RESTO DURANTE A LEITURA
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
 *  @note POSSIVEL RESTO DURANTE A LEITURA
*/ 
char ReadChar (const char * const text)
{
  char x = '0';
  printf  ("%s\n", text);
  scanf   ("%c", &x);
  getchar ( );
  return  (x);
}

/**ANTIGO*/
/** Ler uma cadeia de caracteres do teclado
 *  @param Texto
 *  @param Tamanho da cadeia de caracteres
 *  @returns Cadeia de caracteres
*/ 
char *ReadString (const char *const text, int size)
{
  char *str = (char*)malloc(size);
  if (str == NULL)
  {
    println ("Falha na alocacao da memoria. ");
    return  (NULL);
  }
  else
  {
    printf ("%s\n", text);
    fgets  (str, size, stdin);
  }
  for (int i = 0; i < size; i++)
  {
    if (str[i] == '\n')
    {
      str[i] = '\0';
    }
  }
  return (str);
}

/**ANTIGO*/
/** Ler [n] valores inteiros e guarda-los em um array
 *  @param Tamanho inicial do array / Ponto de retorno do tamanho final do array
 *  @param Valor inteiro para determinar a condicao de parada
 *  @returns Array de numeros inteiros
*/
int *ReadInts (int *size, int s)
{
  *size = 10;
  int i = 0;
  int *resultado = (int*)malloc(*size*sizeof(int));

  do
  {
    printf  ("Forneca valores inteiros: ");
    scanf   ("%d", &resultado[i]);
    getchar ();
    
    i++;

    // Realocar memoria
    if (i >= *size)
    {
      *size += 10;
      resultado = (int*)realloc(resultado, (*size)*sizeof(int) );
    }
  } while (resultado[i-1] != (s));

  *size = i-1;
  return (resultado);
}

/** Calcular a potencia [n] de um numero [x]
 *  @param Base
 *  @param Expoente
 *  @returns Potencia de [x]
*/
int IntPow (int x, int n)
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
 *  @note Os parametros devem ser entregues como um ponteiro para o retorno por referencia
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

/** Gerar um valor inteiro aleatorio dentro de um intervalo
 *  @param Valor inferior do intervalo
 *  @param Valor superior do intervalo
 *  @return Valor inteiro pseudo-aleatorio
*/
int IntRandInterval (int inferior, int superior)
{
  int x = 0;

  // Inverter valores
  if (inferior > superior)
  {
    IntInvertValues (&inferior, &superior);
    println ("Correcao: Os valores inferior e superior foram invertidos. ");
  }

  // Gerar valor aleatorio dentro do intervalo
  x = rand() % (inferior-superior+1) + inferior;
  return (x);
}

/**                                          Funcoes para arquivo
 * --------------------------------------------------------------
*/

/** Ler e mostrar todos os valores inteiros de um arquivo
 *  @param Nome do arquivo
 *  @note NAO FUNCIONA SE HOUVER OUTRO TIPO DE VALOR
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
 *  @note POSSIVEL ERRO NA LEITURA DOS DADOS
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
 *  @param Valor inferior do intervalo
 *  @param Valor superior do intervalo
 *  @returns Caracteres lidos
*/
char *StrIntervalFile (char *fileName, char inferior, char superior)
{
  FILE *arquivo = fopen (fileName, "rt");
  char *str = (char*)malloc(81);
  char  z = '0';
  int   i = 0;

  fscanf (arquivo, "%c", &z);
  while (!feof(arquivo))
  {
    if (z >= inferior && z <= superior)
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

  while (!feof(arquivo) && i <= TamStr )
  {
    if (str[i] != '\n')
    {
      fprintf (arquivo, "%c", str[i]);
    }
    i++;
  }
  fclose (arquivo);
}

/** Mostrar todos os valores reais de um array dentro de um arquivo
 *  @param Nome do arquivo                
 *  @note  NAO FUNCIONA SE HOUVER QUALQUER OUTRO TIPO DE VALOR!
*/
void DoublePrintFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  double x = 0.0;
  int i = 0;

  printf ("\n%s- \n", fileName);
  fscanf (arquivo, "%lf", &x);
  while (!feof(arquivo))
  {
    printf ("%2d: %lf\n", i+1, x);
    fscanf (arquivo, "%lf", &x);
    i++;
  }
  fclose (arquivo);
}

/**                                              Funcoes para arranjos padrao
 * --------------------------------------------------------------------------
*/

/** Retornar valores positivos de um array
 *  @param Array de valores inteiros
 *  @param Tamanho do array
*/
int *IntArrayPositive (int *array, int *size)
{
  int *resultado = (int*)malloc(*size*sizeof(int));
  int y = 0;
  for (int i = 0; i < *size; i++)
  {
    if (array[i] > 0)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  *size = y;
  return (resultado);
}

/** Pedir [n] valores para fazer um array de valores inteiros
 *  @param Tamanho do array
 *  @returns Array de valores inteiros
*/
int *IntWriteArray (int size)
{
  int *array = (int*)malloc(size*sizeof(int));

  for (int i = 0; i < size; i++)
  {
    printf  ("Forneca [%d] valores inteiros para o array: ", size-i);
    scanf   ("%d", &array[i]);
    getchar ();
  }
  println (""); // Pular uma linha
  return (array);
}

/** Retornar valores inteiros, multiplos de [ x ], de um array
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @param Valor inteiro para definir o multiplo a ser comparado
 *  @returns Array de muliplos de [ x ]
*/
int *IntMultipleArray (int *array, int *size, int x)
{
  int *resultado = (int*)malloc(*size * sizeof(int));
  int y = 0;
  for (int i = 0; i < *size; i++)
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
  *size = y;
  return (resultado);
}

/** Retornar valores impares de um array
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @return Valores impares do array
*/
int *IntArrayOdd (int *array, int *size)
{
  int *resultado = (int*)malloc(*size*sizeof(int));
  int y = 0;

  for (int i = 0; i < *size; i++)
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
  *size = y;
  return (resultado);
}

/** Retornar o menor valor inteiro de um array
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @returns O menor valor
*/
int IntArrayBiggest (int *array, int size)
{
  int biggest = 0;
  int i = 0;
  biggest = array[i];
  
  while (i < size)
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
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @returns O menor valor
*/
int IntArraySmallest (int *array, int size)
{
  int smallest = 0;
  int i = 0;
  smallest = array[i];
  
  while (i < size)
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
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @param Valor para fazer a comparacao
 *  @returns Array com valores maiores do que [ x ]
*/
int *IntArrayBigger (int *array, int *size, int x)
{
  int *resultado = (int*)malloc(*size*sizeof(int));
  int y = 0;
  for (int i = 0; i < *size; i++)
  {
    if (array[i] > x)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  *size = y;
  return (resultado);
}

/** Retornar um array com valores menores ou iguais a [ x ] lidos de outro array 
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @param Valor para fazer a comparacao
 *  @returns Array com valores menores ou igual a [ x ]
*/
int *IntArraySmaller (int *array, int *size, int x)
{
  int *resultado = (int*)malloc(*size*sizeof(int));
  int y = 0;
  for (int i = 0; i < *size; i++)
  {
    if (array[i] < x)
    {
      resultado[y] = array[i];
      y++;
    }
  }
  *size = y;
  return (resultado);
}

/** Ler um array de valores inteiros e retornar a media
 *  @param Array de valores inteiros 
 *  @param Tamanho do array
 *  @returns Valor real representando a media
*/
double IntArrayAverage (int *array, int size)
{
  int total = 0;
  double resultado = 0.0;

  if (size < 0)
  {
    size = 0;
    println ("ERRO: Tamanho invalido. ");
  }
  for (int i = 0; i < size; i++)
  {
    total = total + array[i];
  }
  resultado = ((double)total / (double)size);
  return (resultado);
}

/** Encontrar a posicao de um valor dentro de um array
 *  @param Array de valores inteiros
 *  @param Tamanho / Ponto de retorno para quantos valores foram encontrados
 *  @param Valor a ser procurado
 *  @param Valor para determinar a posicao inicial
 *  @returns Posicao do valor 
*/
int IntFindArrayO (int *array, int *size, int valor, int inicio)
{
  int x = 0;
  int y = 0;
  if (inicio < 0)
  {
    inicio = 0;
    println ("ERRO: Posicao inicial invalida. ");
  }
  for (int i = inicio; i < *size; i++)
  {
    if (valor == array[i])
    {
      x = i;
      y++;
    }
  }
  *size = y;
  return (x);
}

/*                                               Funcoes de matrizes padrao
 * ------------------------------------------------------------------------
*/

/** Mostrar uma matrix de numeros reais
 *  @param Quantidade de linhas
 *  @param Quantidade de colunas
 *  @param Matrix de valores reais
*/
void DoublePrintMatrix (int rows, int columns, double matrix [][columns])
{
  println("");
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      printf("%3lf\t", matrix[x][y]);
    }
    println("");
  }
}

/** Ler e retornar uma matrix de valores reais de um arquivo
 *  @param Nome do arquivo
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix para onde a matrix do arquivo ira retornar
 *  @note ANTIGO
*/
void DoubleMatrixFile (char *fileName, int *rows, int *columns, double matrix[][*columns])
{
  FILE *arquivo = fopen (fileName, "rt");
  int i = 0;
  double z = 0;

  printf("\n%s-\n", fileName);

  fscanf (arquivo, "%d", &(*rows));
  fscanf (arquivo, "%d", &(*columns));

  while (!feof(arquivo) && i <((*rows)*(*columns)))
  {
    for (int x = 0; x < *rows; x++)
    {
      for (int y = 0; y < *columns; y++)
      {
        fscanf (arquivo, "%lf", &z);
        matrix[x][y] = z;
        i++;
      }
    }
  }
}

/** Fazer uma matrix de valores reais
 * @param Quantidade de linhas da matrix
 * @param Quantidade de colunas da matrix
 * @param Matrix para onde os dados serao gravados
*/
void DoubleWriteMatrix (int rows, int columns, double matrix [][columns])
{
  int i = 0;
  double z = 0;
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      printf ("Forneca [%d] valor(es) reais para a matriz: ", (rows*columns)-i);
      z = ReadDouble ("");
      matrix[x][y] = z;
      i++;
    }
  }
}

/** Escrever uma matrix de valores reais em um arquivo
 *  @param Nome do arquivo 
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
*/
void DoubleWriteMatrixFile (char *fileName, int rows, int columns, double matrix[][columns])
{
  FILE *arquivo = fopen (fileName, "wt");
  int i = 0;
  
  // Guardar dimensoes da matrix
  fprintf (arquivo, "%d\n", rows);
  fprintf (arquivo, "%d\n", columns);

  while (!feof(arquivo) && i < (rows*columns))
  {
    for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
      {
        fprintf (arquivo, "%lf\n", matrix[x][y]);
        i++;
      }
    }
  }
  fclose (arquivo);
}



/** Mostrar uma matrix de valores inteiros 
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix de valores inteiros
 *  @note ANTIGO
*/
void IntPrintMatrixO (int rows, int columns, int matrix[][columns])
{
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      printf ("%3d\t" ,matrix[x][y]);
    }
  println("");
  }
}

/** Ler e mostrar uma matrix de valores inteiros de um arquivo
 *  @param Nome do arquivo
*/
void IntPrintMatrixFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  int rows = 0;
  int columns = 0;
  int i = 0;
  int z = 0;

  printf ("\n%s-\n", fileName);

  fscanf(arquivo, "%d", &rows);
  fscanf(arquivo, "%d", &columns);
  int matrix[rows][columns];

  while (!feof(arquivo) && i < (rows*columns))
  {
    for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
      {
        fscanf (arquivo, "%d", &z);
        matrix[x][y] = z;
        i++;
      }
    }
  }
  IntPrintMatrixO(rows, columns, matrix);
}

/** Copiar uma matrix de valores reais
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Copia da matrix
 *  @param Matrix original
*/
void DoubleCopyMatrix (int rows, int columns, double copy [][columns], double matrix[][columns])
{
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      copy[x][y] = matrix[x][y];
    }
  }
}

/** Copiar uma matrix de valores inteiros
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Copia da matrix
 *  @param Matrix original
*/
void IntCopyMatrixO (int rows, int columns, int copy [][columns], int matrix[][columns])
{
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      copy[x][y] = matrix[x][y];
    }
  }
}


/**                                     Funcoes para arrays tipo struct
 *  -------------------------------------------------------------------
*/


/**                                                     Arrays inteiros
 * --------------------------------------------------------------------
*/

/** Definir struct para arrays inteiros
*/
typedef struct int_array_s
{
  int  i;
  int* data;
  int  length;
} 
int_array;

// Definir apontador para struct
typedef int_array* ref_int_array;

/** Alocar espaco para um array de inteiros 
 *  @param Tamanho
 *  @returns Array de valores inteiros
*/
ref_int_array IntNewArray (int n)
{
  ref_int_array array = (ref_int_array)malloc(sizeof(int_array));

  if (array == null)
  {
    println ("ERRO: Falta de espaco. ");
  }
  else
  {
    array->i = -1;
    array->length = 0;
    array->data = null;
    if (n > 0)
    {
      array->i = 0;
      array->length = n;
      array->data = (int*)malloc(n*sizeof(int));
    }
  }
  return (array);
}

ref_int_array IntCopyArray (int_array array)
{
  ref_int_array result = 0;
  if (array.data)
  {
    if (array.length > 0)
    {
      result = IntNewArray(array.length);
      if (result == null)
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (int i = 0; i < result->length; i++)
        {
          result->data[i] = array.data[i];
        }
      }
    }
  }
  return (result);
}

/** Mostrar um array de valores inteiros
 *   @param Array de valores inteiros tipo struct
*/
void IntPrintArray (int_array array)
{
  if (array.data)
  {
    for (array.i = 0; array.i < array.length; array.i++)
    {
      printf ("%2d: %d\n", (array.i+1), array.data[array.i]);
    }
  }
}

/** Ler um array de inteiros
 *  @returns Array de inteiros tipo struct
*/
int_array ReadIntArray ()
{
  int_array array;

  do
  {
    array.length = ReadInt("Forneca o tamanho do array: ");
  } while (array.length <= 0);

  array.data = (int*)malloc(array.length*sizeof(int));

  if (array.data == null)
  {
    println ("ERRO: Falta de espaco. ");
  }
  else
  {
    for (array.i = 0; array.i < array.length; array.i++)
    {
      array.data[array.i] = ReadInt ("Forneca um valor para o array");
    }
  }
  return (array);
}

/** Retornar um array de valores inteiros de um arquivo
 *  @param Nome do arquivo
 *  @returns Array de valores inteiros tipo struct
*/
int_array IntArrayFile (char* fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  int_array array;  

  if (arquivo)
  {
    fscanf (arquivo, "%d", &array.length);
    if (array.length > 0)
    {
      array.data = (int*)malloc(array.length*sizeof(int));
      if (array.data)
      {
        array.i = 0;
        while (!feof(arquivo) && array.i < array.length)
        {
          fscanf (arquivo, "%d", &(array.data[array.i]));
          array.i++;
        }
      }
    }
  }
  fclose (arquivo);
  return (array);
}

/** Mostrar valores inteiros de um array dentro de um arquivo
 *  @param Nome do arquivo
*/
void IntPrintArrayFile (char *fileName)
{
  int_array array;
  array = IntArrayFile (fileName);
  printf ("\n%s-\n\n", fileName);
  IntPrintArray(array);
}

/** Escrever um array de valores inteiros em um arquivo
 *  @param Nome do arquivo
 *  @param Array de valores inteiros tipo struct
*/
void IntWriteArrayFile (char *fileName, int_array array)
{
  // Se existir
  if (array.data)
  {
    // Abrir arquivo
    FILE *arquivo = fopen (fileName, "wt");

    // Verificar existencia do arquivo
    if (arquivo)
    {
      // Guardar size
      fprintf (arquivo, "%d\n", array.length);

      // Guardar valores
      for (array.i = 0; array.i < array.length; array.i++)
      {
        fprintf (arquivo, "%d\n", array.data[array.i]);
      }

      // Fechar arquivo
      fclose (arquivo);
    }
  }
}

/** Aleatorizar todos os elementos de um array de valores inteiros dado um certo intervalo
 *  @param Valor inferior do intervalo
 *  @param Valor superior do intervalo
 *  @param Quantidade de valores a serem gerados
 *  @returns Array de valores inteiros tipo struct
*/
int_array IntRandIntervalArray (int inferior, int superior, int n)
{
  int_array array;
  if (n > 0)
  {
    array.data = (int*)malloc(n*sizeof(int));
    array.length = n;

    for (array.i = 0; array.i < array.length; array.i++)
    {
      array.data[array.i] = IntRandInterval(inferior, superior);
    }
  }
  else
  {
    println ("ERRO: Valor invalido. ");
  }
  return (array);
}

/** Encontrar a posicao de um certo valor dentro de um array de valores inteiros
 *  @param Valor inteiro a ser procurado
 *  @param Posicao inicial
 *  @param Apontador do array a ser procurado
 *  @return Posicao do valor dentro do array, se estiver
*/
int IntFindArray (int value, int i, int_array array)
{
  int resultado = -1;
  if (array.data)
  {
    if (i >= 0 && i < array.length)
    {
      array.i = 0;
      while (array.i < array.length && value != array.data[array.i])
      {
        array.i++;
      }
      resultado = (array.i);
    }
  }
  return (resultado);
}

/** Comparar 2 arrays
 *  @param Array 1
 *  @param Array 2
 *  @returns Valor booleano
*/
int IntCmpArray (int_array array1, int_array array2)
{
  bool resultado = 0;
  if (array1.data == null || array2.data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (array1.length != array2.length)
    {
      resultado = 0;
    }
    else
    {
      int i = 0;
      int x = 0;
      while (i < array1.length)
      {
        if (array1.data[i] == array2.data[i])
        {
          x++;
        }
        i++;
      }
      resultado = (x == array1.length); 
    }
  }
  return ((int)resultado);
}

/** Somar 2 arrays
 *  @param Array 1
 *  @param Array 2
 *  @returns Ponteiro do resultado
*/
ref_int_array IntAddArray (ref_int_array array1, ref_int_array array2)
{
  ref_int_array resultado;
  if (array1->length <= 0 || array2->length <= 0)
  {
    println ("ERRO: Tamanho invalido. ");
  }
  else if (array1->length != array2->length)
  {
    println ("ERRO: Os arranjos sao de tamanhos diferentes. ");
  }
  else
  {
    resultado = IntNewArray(array1->length);
    for (int i = 0; i < array1->length; i++)
    {
      resultado->data[i] = array1->data[i] + array2->data[i];
    }
  }
  return (resultado);
}

/** Liberar espaco de um array
 *  @param referencia da struct do array
*/
void IntFreeArray (ref_int_array array)
{
  if (array != null)
  {
    if (array->data != null)
    {
      free (array->data);
    }
    free (array);
  }
}

/** Verificar se um arranjo esta em ordem decrescente
 *  @param Array
 *  @returns Valor booleano referente ao resultado
*/
int IntArrayDescending (int_array array)
{
  int i = 1;
  if (array.data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (array.length <= 0)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      while (i < array.length && array.data[i-1] > array.data[i])
      {
        i++;
      }

      if (i < (array.length))
      {
        i = 0;
      }
      else
      {
        i = 1;
      }
    }
  }
  return (i);
}

ref_int_array IntScaleArray (int_array array, const int Const)
{
  ref_int_array result = null;
  if (array.data)
  {
    if (array.length > 0)
    {
      result = IntNewArray(array.length);
      if (result == null)
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (int x = 0; x < result->length; x++)
        {
          result->data[x] = (array.data[x] * Const);
        }
      }
    }
  }
  return (result);
}

ref_int_array IntDescendArray (int_array array)
{
  ref_int_array result = null;
  if (array.data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (array.length > 0)
    {
      result = IntCopyArray(array);
      if (result == null)
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        int tmp = 0;
        int y = result->length-1;
        while (y > 0)
        {
          for (int i = 1; i < result->length; i++)
          {
            if (result->data[i-1] < result->data[i])
            {
              tmp = result->data[i];
              result->data[i] = result->data[i-1];
              result->data[i-1] = tmp;
            }
          }
          y--;
        }
      }
    }
  }
  return (result);
}

ref_int_array IntAscendArray (int_array array)
{
  ref_int_array result = null;
  if (array.data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (array.length > 0)
    {
      result = IntCopyArray(array);
      if (result == null)
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        int tmp = 0;
        int y = result->length-1;
        while (y > 0)
        {
          for (int i = 1; i < result->length; i++)
          {
            if (result->data[i-1] > result->data[i])
            {
              tmp = result->data[i];
              result->data[i] = result->data[i-1];
              result->data[i-1] = tmp;
            }
          }
          y--;
        }
      }
    }
  }
  return (result);
}

/*                                                         arrays reais
 * --------------------------------------------------------------------
*/

/** Definir struct para arrays inteiros
*/
typedef struct double_array_s
{
  int i;
  double *data;
  int length;
} 
double_array;

// Definir apontador para struct
typedef double_array* ref_double_array;

/** Alocar espaco para um array de inteiros 
 *  @param Tamanho do array a ser criado
 *  @returns Array de valores reais tipo struct
*/
double_array* Double_New_Array (int n)
{
  double_array *array = (double_array*)malloc(sizeof(int));
  if (array == null)
  {
    println ("ERRO: Falta espaco. ");
  }
  else
  {
    array->i = -1;
    array->data = null;
    array->length = 0;

    if (n > 0)
    {
      array->i = 0;
      array->length = n;
      array->data = (double*)malloc(n*sizeof(double));
    }
  }
  return (array);
}

/** Mostrar um array de valores reais
 *   @param Array de inteiros
*/
void DoublePrintArray (double_array array)
{
  if (array.data)
  {
    for (array.i = 0; array.i < array.length; array.i++)
    {
      printf ("%2d: %lf\n", (array.i+1), array.data[array.i]);
    }
  }
}

/** Montar um array de valores reais
 *  @returns Array de valores reais tipo struct
 */
double_array ReadDoubleArray ()
{
  double_array array;
  do
  {
    array.length = ReadInt("Forneca o tamanho do array: ");
  } while (array.length <= 0);

  array.data = (double*)malloc(array.length*sizeof(double));

  if (array.data == null)
  {
    println ("ERRO: Falta espaco. ");
  }
  else
  {
    for (array.i = 0; array.i < array.length; array.i++)
    {
      array.data[array.i] = ReadDouble ("Forneca um valor real para o array: ");
    }
  }
  return (array);
}

/** Retornar um array de valores reais de um arquivo
 *  @param Nome do arquivo
 *  @returns Array de valores reais tipo struct
*/
double_array DoubleArrayFile (char* fileName)
{
  double_array array;
  FILE *arquivo = fopen (fileName, "rt");
  int n = 0;

  fscanf (arquivo, "%d", &n);

  if (n > 0)
  {
    array.length = n;
    array.i = 0; 
    array.data = (double*)malloc(array.length*sizeof(double));

    while (!feof(arquivo) && array.i < array.length)
    {
      fscanf (arquivo, "%lf", &array.data[array.i]);
      array.i++;
    }
  }
  fclose (arquivo);
  return (array);
}

/** Escrever um array de valores reais em eu arquivo
 *  @param Nome do arquivo
 *  @param Array de valores reais tipo struct
*/
void DoubleWriteArrayFile (char *fileName, double_array array)
{
  if (array.data == NULL)
  {
    println ("ERRO: Falta espaco. ");
  }
  else
  {
    FILE *arquivo = fopen (fileName, "wt");
    fprintf (arquivo, "%d\n", array.length);

    for (array.i = 0; array.i < array.length; array.i++)
    {
      fprintf (arquivo, "%lf\n", array.data[array.i]);
    }
    fclose (arquivo);
  }
}


/**                                   Funcoes para matrizes tipo struct
 * --------------------------------------------------------------------
*/

typedef struct int_matrix_s

{
  int rows;
  int columns;
  int** data;
  int ix;
  int iy;
} 
int_matrix;

typedef int_matrix* ref_int_matrix;

/** Alocar espaco para uma matrix de valores inteiros 
 *  @param Quantidade de linhas
 *  @param Quantidade de colunas
 *  @returns Matrix de valores inteiros tipo struct
*/
ref_int_matrix IntNewMatrix (int r, int c)
{
  ref_int_matrix matrix = (ref_int_matrix)malloc(sizeof(int_matrix));

  if (matrix == null)
  {
    println ("ERRO: Falta espaco. ");
  }
  else
  {
    matrix->rows = 0;
    matrix->columns = 0;
    matrix->data = null;

    if (r > 0 && c > 0)
    {
      matrix->rows = r;
      matrix->columns = c;
      matrix->data = (int**)malloc(r*sizeof(int*));
      
      if (matrix->data)
      {
        for (int i = 0; i < matrix->rows; i++)
        {
          matrix->data[i] = (int*)malloc(c*sizeof(int));
        }
      }
    }
    else
    {
      println ("ERRO: Dimensoes invalidas. ");
    }
    matrix->ix = 0;
    matrix->iy = 0;
  }
  return (matrix);
}

ref_int_matrix IntCopyMatrix (ref_int_matrix matrix)
{
  ref_int_matrix copy = null;
  if (matrix)
  {
    if (matrix->data)
    {
      if (matrix->rows > 0 && matrix->columns > 0)
      {
        copy = IntNewMatrix(matrix->rows, matrix->columns);
        if (copy == null)
        {
          println ("ERRO: Falta de espaco. ");
        }
        else
        {
          for (int x = 0; x < copy->rows; x++)
          {
            for (int y = 0; y < copy->columns; y++)
            {
              copy->data[x][y] = matrix->data[x][y];
            }
          }
        }
      }
    }
  }
  return (copy);
}

/** Mostrar uma matrix de valores inteiros
 *  @param Matrix de valores inteiros tipo struct
*/
void IntPrintMatrix (ref_int_matrix matrix)
{
  if (matrix != null && matrix->data != null)
  {
    if (matrix->rows > 0 && matrix->columns > 0)
    {
      for (int x = 0; x < matrix->rows; x++)
      {
        for (int y = 0; y < matrix->columns; y++)
        {
          printf ("%3d\t", matrix->data[x][y]);
        }
        println ("");
      }
    }
  }
}

/** Montar uma matrix de valores inteiros
 *  @returns Matrix de valores inteiros tipo struct
 *  @note NAO TESTADA
*/
ref_int_matrix ReadIntMatrix ()
{
  int rows = 0;
  int columns = 0;

  rows    = ReadPositiveInt ("Forneca a quantidade de linhas da matrix:  ");
  columns = ReadPositiveInt ("Forneca a quantidade de colunas da matrix: ");

  ref_int_matrix matrix = IntNewMatrix(rows, columns);

  if (matrix == null)
  {
    println ("ERRO: Falta espaco. ");
  }
  else
  {
    if (matrix->data == null)
    {
      matrix->columns = 0;
      matrix->rows = 0;
    }
    else
    {
      for (int x = 0; x < matrix->rows; x++)
      {
        for (int y = 0; y < matrix->columns; y++)
        {
          matrix->data[x][y] = ReadInt ("Forneca um elemento para a matrix: ");
        }
      }
    }
  }
  return (matrix);
}

/** Gravar uma matrix de valores inteiros em um arquivo
 *  @param Nome do arquivo
 *  @param matrix
*/
void IntWriteMatrixFile (char* fileName, ref_int_matrix matrix)
{
  if (matrix == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    FILE *arquivo = fopen (fileName, "wt");

    if (arquivo)
    {
      fprintf (arquivo, "%d\n", matrix->rows);
      fprintf (arquivo, "%d\n", matrix->columns);

    if (matrix->data != null)
    {
      for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
      {
        for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
        {
          fprintf (arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
        }
      }
    }
    fclose (arquivo);
    }
  }
}

/** Retornar uma matrix de um arquivo
 *  @param Nome do arquivo
 *  @returns Apontador da struct da matrix
*/
ref_int_matrix IntMatrixFile (char* fileName)
{
  ref_int_matrix matrix = null;
  int rows = 0;
  int columns = 0;
  FILE *arquivo = fopen (fileName, "rt");
  if (arquivo)
  {
    fscanf (arquivo, "%d", &rows);
    fscanf (arquivo, "%d", &columns);
    if (rows <= 0 && columns <= 0)
    {
      println ("ERRO: Dimensoes invalidas. ");
    }
    else
    {
      matrix = IntNewMatrix(rows, columns);
      if (matrix == null && matrix->data == null)
      {
        matrix->rows = 0;
        matrix->columns = 0;
        matrix->ix = 0;
        matrix->iy = 0;
        matrix->data = null;
      }
      else if (matrix->data != null)
      {
        for (matrix->ix = 0; matrix->ix < rows; matrix->ix++)
        {
          for (matrix->iy = 0; matrix->iy < columns; matrix->iy++)
          {
            fscanf(arquivo, "%d", &matrix->data[matrix->ix][matrix->iy]);
          }
        }
        matrix->ix = 0;
        matrix->iy = 0;
      }
    }
  }
  return (matrix);
}

/** Liberar espaco da matrix da memoria
 *  @param Apontador da struct da matrix
*/
void IntFreeMatrix(ref_int_matrix matrix)
{
  if (matrix)
  {
    if (matrix->data)
    {
      free (matrix->data);
    }
  }
  free (matrix);
}

/** Traspor uma matrix
 *  @param Matrix a ser transposta
 *  @returns Matrix transposta
*/ 
ref_int_matrix IntTransposeMatrix (ref_int_matrix matrix)
{
  ref_int_matrix resultado = null;
  if (matrix == null && matrix->data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (matrix->rows <= 0 || matrix->columns <= 0)
    {
      println ("ERRO: Dimensoes invalidas. ");
    }
    else
    {
      // Inverter as dimensoes
      resultado = IntNewMatrix(matrix->columns, matrix->rows);
      if (resultado == null && resultado->data == null)
      { 
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (resultado->ix = 0; resultado->ix < resultado->rows; resultado->ix++)
        {
          for (resultado->iy = 0; resultado->iy < resultado->columns; resultado->iy++)
          {
            resultado->data[resultado->ix][resultado->iy] = matrix->data[resultado->iy][resultado->ix];
          }
        }
      }
    }
  }
  return (resultado);
}

/** somar duas matrizes inteiras
 *  @param Matrix 1
 *  @param Matrix 2
 *  @returns Matrix com os valores somados
*/
ref_int_matrix IntAddMatrix (ref_int_matrix matrix1, ref_int_matrix matrix2)
{
  ref_int_matrix resultado = null;
  if (matrix1 == null || matrix1->data == null || matrix2 == null || matrix2->data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (matrix1->rows > 0 && matrix1->columns > 0 && matrix2->rows > 0 && matrix2->columns > 0)
    {
      if (matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns)
      {
        resultado = IntNewMatrix(matrix1->rows, matrix1->columns);
        if (resultado != null && resultado->data != null)
        {
          for (int x = 0; x < matrix1->rows; x++)
          {
            for (int y = 0; y < matrix1->columns; y++)
            {
              resultado->data[x][y] = matrix1->data[x][y] + matrix2->data[x][y];
            }
          }
        }
      }
    }
  }
  return (resultado);
}

/** Escalar uma matriz a partir de uma constante
 *  @param Matrix a ser escalada
 *  @param Constante para definir o escalamento
 *  @returns Matrix escalada em forma de struct
*/
ref_int_matrix IntScaleMatrix (ref_int_matrix matrix, int Const)
{
  ref_int_matrix resultado = null;
  if (matrix == null || matrix->data == null)
  {
    println ("(IntScaleMatrix) ERRO: Dados invalidos. ");
  }
  else
  {
    if (matrix->rows <= 0 || matrix->columns <= 0)
    {
      println ("(IntScaleMatrix) ERRO: Dimensoes invalidas. ");
    }
    else
    {
      resultado = IntNewMatrix(matrix->rows, matrix->columns);
      if (resultado == null || resultado->data == null)
      {
        println ("(IntScaleMatrix) ERRO: Falta de espaco. ");
      }
      else
      {
        for (int x = 0; x < matrix->rows; x++)
        {
          for (int y = 0; y < matrix->columns; y++)
          {
            resultado->data[x][y] = (matrix->data[x][y] * Const);
          }
        }
      }
    }
  }
  return (resultado);
}

/** Calcular o produto de duas matrizes
 *  @param Matrix 1
 *  @param Matrix 2
 *  @returns Produto das matrizes em forma de struct
*/
ref_int_matrix IntMultiplyMatrix (ref_int_matrix matrix1, ref_int_matrix matrix2)
{
  ref_int_matrix result = null;
  if (matrix1 && matrix2)
  {
    if (matrix1->data && matrix2->data)
    {
      if (matrix1->rows > 0 && matrix1->columns > 0 && matrix2->rows > 0 && matrix2->columns > 0)
      {
        if (matrix1->rows != matrix2->columns)
        {
          println ("ERRO: Dimensoes incompativeis. ");
        }
        else
        {
          result = IntNewMatrix(matrix1->rows, matrix2->columns);
          if (result == null)
          {
            println ("ERRO: Falta de espaco. ");
          }
          else
          {
            for (int x = 0; x < matrix1->rows; x++)
            {
              for (int y = 0; y < matrix2->columns; y++)
              {
                result->data[x][y] = 0;
                for (int z = 0; z < matrix2->rows; z++)
                {
                  result->data[x][y] += (matrix1->data[x][z] * matrix2->data[z][y]);
                }
              }
            }
          }
        }
      }
    }
  }
  return (result);
}

/** Checar se uma matrix e uma matrix identidade
 *  @param Matrix a ser checada
 *  @returns Valor booleano referente ao resultado
*/
bool IntCheckIdentityMatrix (ref_int_matrix matrix)
{
  bool result = false;
  if (matrix)
  {
    if (matrix->data)
    {
      if (matrix->rows > 0 && matrix->columns > 0)
      {
        int x = 0;
        int y = 0;
        result = true;
        while (x < matrix->rows && y < matrix->columns && result == true)
        {
          result = (result && matrix->data[x][y] == 1);
          x++;
          y++;
        }
      }
    }
  }
  return (result);
}