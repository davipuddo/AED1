//853355_AED1

#include "..\io.h"
#include "..\puddo.h"

typedef struct s_int_Array
{
  int lenght;
  int *data;
  int ix;
}
int_Array;

typedef int_Array* ref_int_Array;

int_Array* new_int_Array (int n)
{
  ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));

  if (tmpArray == NULL)
  {
    println("\nERRO: Falta de espaço. ");
  }
  else
  {
    tmpArray->lenght = 0;
    tmpArray->data   = NULL;
    tmpArray->ix     = -1;
    if (n > 0)
    {
      tmpArray->lenght = n;
      tmpArray->data = (int*)malloc(n*sizeof(int));
      tmpArray->ix = 0;
    }
  }
  return (tmpArray);
}

void Free_Int_Array (ref_int_Array tmpArray)
{
  if (tmpArray != NULL)
  {
    if (tmpArray->data != NULL)
    {
      free (tmpArray->data);
    }
    free (tmpArray);
  }
}

void printlnArray (int_Array array)
{
  if (array.data)
  {
    for (array.ix = 0; array.ix < array.lenght; array.ix++)
    {
      printf ("%2d: %d\n", array.ix, array.data [array.ix]);
    }
  }
}

int_Array ReadIntArray()
{
  static int_Array array;

  do
  {
    array.lenght = ReadInt("\nlenght=");
  } while (array.lenght <= 0);

  array.data = (int*)malloc(array.lenght*sizeof(int));

  if (array.data == NULL)
  {
    array.lenght = 0;
  }
  else
  {
    for (array.ix = 0; array.ix < array.lenght; array.ix++)
    {
      array.data[array.ix]
      = ReadInt ("elemento: ");
    }
  }
  return (array);
}

void fprintlnArray (char *fileName, int_Array array)
{
  FILE *arquivo = fopen (fileName, "wt");

  fprintf (arquivo, "%d\n", array.lenght);

  if (array.data)
  {
    for(array.ix = 0; array.ix < array.lenght; array.ix++)
    {
      fprintf (arquivo, "%d\n", array.data[array.ix]);
    }
  }
  fclose (arquivo);
}

int FReadArraySize (char *fileName)
{
  int n = 0;
  FILE *arquivo = fopen (fileName, "rt");

  if (arquivo)
  {
    fscanf (arquivo, "%d", &n);

    if (n <= 0)
    {
      println ("\nERRO: Valor invalido. ");
      n = 0;
    }
    fclose (arquivo);
  }
  return (n);
}

int_Array ReadIntArrayFile (char *fileName)
{
  FILE *arquivo = fopen (fileName, "rt");
  static int_Array array;

  if (arquivo)
  {
    fscanf (arquivo, "%d", &array.lenght);
    if (array.lenght <= 0)
    {
      println ("\nERRO: Valor invalido. ");
      array.lenght = 0;
    } 
    else
    {
      array.data = (int*)malloc(array.lenght*sizeof(int));

      if (array.data)
      {
        array.ix = 0;
        while (!feof(arquivo) && array.ix < array.lenght)
        {
          fscanf (arquivo, "%d", &(array.data[array.ix]));
          array.ix++;
        }
      }
    } 
  }
  return (array);
}

ref_int_Array IntCopyArray (int_Array array)
{
  ref_int_Array copy;

  if (array.lenght <= 0)
  {
    println ("");
    array.lenght  = 0;
  }
  else
  {
    copy =  new_int_Array(array.lenght);

    if (copy)
    {
      copy->lenght = array.lenght;
      copy->data = (int*)malloc(copy->lenght*sizeof(int));

      if (copy->data == NULL || array.data == NULL)
      {
        println ("\nERRO: Falta espaço ou dados. ");
      }
      else
      {
        for (array.ix = 0; array.ix < array.lenght; array.ix++)
        {
          copy->data[array.ix] = array.data[array.ix];
        }
      }
    }
  }
  return (copy);
}

typedef struct  s_int_matrix
{
  int rows;
  int columns;
  int *(*data);
  int ix, iy;
}
int_Matrix;

typedef int_Matrix* ref_int_Matrix;

ref_int_Matrix new_int_Matrix(int rows, int columns)
{
  ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));

  if (tmpMatrix != NULL)
  {
    tmpMatrix->rows =  0;
    tmpMatrix->columns = 0;
    tmpMatrix->data = NULL;

    if (rows > 0 && columns > 0)
    {
      tmpMatrix->rows = rows;
      tmpMatrix->columns = columns;
      tmpMatrix->data = malloc(rows*sizeof(int));
      if (tmpMatrix->data)
      {
        for (tmpMatrix->ix = 0; tmpMatrix->ix < tmpMatrix->rows; tmpMatrix->ix++)
        {
          tmpMatrix->data[tmpMatrix->ix] = (int*)malloc(columns*sizeof(int));
        }
      }
    }
    tmpMatrix->ix = 0;
    tmpMatrix->iy = 0;
  }
  return (tmpMatrix);
}

void free_int_Matrix (ref_int_Matrix matrix)
{
  if (matrix != NULL)
  {
    if (matrix->data != NULL)
    {
      for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
      {
        free (matrix->data[matrix->ix]);
      }
      free(matrix->data);
    }
    free (matrix);
  }
}

/*
void printlnMatrix (ref_int_Matrix matrix)
{
  if (matrix != NULL && matrix->data != NULL)
  {
    for (matrix->ix = 0 ; matrix->ix < matrix->rows; matrix.ix++)
  }
}
*/

typedef struct s_char_array
{
  int length; 
  char* data;
} 
char_array;

typedef char_array* ref_char_array;

ref_char_array New_Char_Array (int n)
{
  ref_char_array tmpChar = null;
  if (n > 0)
  {
    tmpChar = (ref_char_array)malloc(1*sizeof(char_array));
    if (tmpChar)
    {
      tmpChar->data = (char*)malloc((n+1)*sizeof(char));
      if (tmpChar->data)
      {
        tmpChar->length = n;
      }
    }
  }
  return (tmpChar);
}

void print_char_Array (ref_char_array Chars)
{
  if (Chars)
  {
    for (int x = 0; x < Chars->length; x++)
    {
      printf ("%c", Chars->data[x]);
    }
  }
}

typedef struct s_double_array
{
  int length;
  double* data;
  int x;
} 
double_array;

typedef double_array* ref_double_array;

ref_double_array new_double_array (int n)
{
  ref_double_array tmpArray = (ref_double_array)malloc(sizeof(double));
  if (tmpArray)
  {
    tmpArray->data = null;
    tmpArray->length = 0;
    tmpArray->x = -1;

    if (n > 0)
    {
      tmpArray->data = (double*)malloc(n*sizeof(double));
      tmpArray->length = n;
      tmpArray->x = 0;
    }
  }
  else
  {
    println ("ERRO: Sem espaço. ");
  }
  return (tmpArray);
}

void DoublePrintArrayS (double_array array)
{
  if (array.data)
  {
    for (array.x = 0; array.x < array.length; array.x++)
    {
      printf ("%2d: %lf\n", array.x, array.data[array.x]);
    }
  }
}

double_array ReadDoubleArray ()
{
  static double_array array;
  do
  {
    array.length = ReadInt ("Tamanho: ");
  } while (array.length <= 0);

  array.data = (double*)malloc(array.length*sizeof(double));

  if (array.data == NULL)
  {
    array.length = 0;
  }
  else
  {
    for (array.x = 0; array.x < array.length; array.x++)
    {
      array.data[array.x] = ReadDouble ("Elemento: ");
    }
  }
  return (array);
}


void ED0X01 (void)
{
  // Identificacao de dados
  int_Array array;

  array.lenght = 5;   
  array.data = (int*)malloc(array.lenght*sizeof(int));

  if (array.data)
  {
    array.data[0] = 1;
    array.data[1] = 2;
    array.data[2] = 3;
    array.data[3] = 4;
    array.data[4] = 5;

  }

  // Apresentacao
  println ("ED0X01");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Executar metodo
  printlnArray(array);

  if (array.data)
  {
    free(array.data);
  }
  // Verificar dados
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X02 (void)
{
  // Identificacao de dados
  int_Array array;

  // Apresentacao
  println ("ED0X02");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array = ReadIntArray();

  // Mostrar dados
  if (array.data)
  {
    printf ("\n");
    printlnArray(array);
    free(array.data);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X03 (void)
{
  // Identificacao de dados
  int_Array array;

  // Apresentacao
  println ("ED0X03");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array = ReadIntArray();

  // Mostrar dados
  if (array.data)
  {
    println("");
    printlnArray (array);
    fprintlnArray ("ARRAY1.TXT", array);
    free(array.data);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X04 (void)
{
  // Identificacao de dados
  int_Array array;

  // Apresentacao
  println ("ED0X04");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array = ReadIntArrayFile("ARRAY1.TXT");

  if (array.data)
  {
    println ("");
    printlnArray (array);
    free (array.data);
  }
  // Verificar dados
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X05 (void)
{
  // Identificacao de dados
  int_Array array;
  ref_int_Array other;

  // Apresentacao
  println ("ED0X05");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array = ReadIntArrayFile("ARRAY1.TXT");

  other = IntCopyArray(array);

  // Mostrar dados
  if (array.data)
  {
    println ("\nOriginal");
    printlnArray (array);

    println ("\nCopia");
    printlnArray (*other);

    free (array.data);
    free (other->data);
    free (other);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X06 (void)
{
  // Identificacao de dados
  double_array array;

  // Apresentacao
  println ("ED0X06");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha

  // Ler dados
  array = ReadDoubleArray();

  // Mostrar dados
  if (array.data)
  {
    DoublePrintArrayS(array);
    free(array.data);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X07 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X07");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X08 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X08");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X09 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X09");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X10 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X10");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

int main (void)
{

  // Definir dado
  int opcao = 0;

  // Repetir
  do
    {

      // Identificacao
      println ("");              // Pular uma linha
      println ("ED0X - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED0X01   2 - ED0X02");
      println ("3 - ED0X03   4 - ED0X04");
      println ("5 - ED0X05   6 - ED0X06");
      println ("7 - ED0X07   8 - ED0X08");
      println ("9 - ED0X09  10 - ED0X10");
      println ("");              // Pular uma linha

      // Ler opcao
      println ("Escolha um exercicio: ");
      scanf   ("%d", &opcao);
      getchar    ();

      // Escolher opcao
      switch (opcao)
        {
          case 0:
            break;
          case 1:  ED0X01();
            break;
          case 2:  ED0X02();
            break;
          case 3:  ED0X03();
            break;
          case 4:  ED0X04();
            break;
          case 5:  ED0X05();
            break;
          case 6:  ED0X06();
            break;
          case 7:  ED0X07();
            break;
          case 8:  ED0X08();
            break;
          case 9:  ED0X09();
            break;
          case 10: ED0X10();
            break;
          default: 
              println ("");                // Pular uma linha
              println ("A opcao escolhida e invalida. ");
              println ("");                // Pular uma linha
            break;

        }

    } while (opcao != 0);

  // Fim
  pause ("Aperte <ENTER> para sair. ");
  return (0);
}

/*
    Versao      Data        Teste      Modificacoes
    0.0         00/00/00    (OK)       Criacao do arquivo ED0X e seus metodos

*/