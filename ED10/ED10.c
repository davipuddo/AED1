//853355_AED1

#include "io.h"
#include "puddo.h"

/** Somar 2 arrays, onde o segundo e escalado por uma constante
 *  @param Array 1
 *  @param Array 2
 *  @returns referencia da struct de um arranjo contendo o resultado
*/
ref_int_array IntAddConstArray (int_array array1, int_array array2, const int p)
{
  ref_int_array resultado;
  if (array1.length <= 0 || array2.length <= 0)
  {
    println ("ERRO: Tamanho invalido. ");
  }
  else if (array1.length != (int)((double)array2.length / (double)p))
  {
    println ("ERRO: O tamanho dos arranjos sao incompativeis. ");
  }
  else
  {
    resultado = IntNewArray(array1.length);
    int w = p-1;
    int i = 0;
    while (i < array1.length && w < array2.length)
    {
      resultado->data[i] = array1.data[i] + array2.data[w];
      i++;
      w += p;
    }
  }
  return (resultado);
}

/** Verificar se os elementos de uma matrix sao iguais a zero
 *  @param Apontador do struct de uma matrix de valores inteiros
 *  @return Valor booleano referente ao resultado
*/
int IntCheckNullMatrix (ref_int_matrix matrix)
{
  bool resultado = 0;
  if (matrix == null && matrix->data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    matrix->ix = 0;
    matrix->iy = 0;
    int x = 0;
    for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix++)
    {
      for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy++)
      {
        if (matrix->data[matrix->ix][matrix->iy] != 0)
        {
          x++;
        }
      }
    }
    matrix->ix = 0;
    matrix->iy = 0;
    if (x == 0)
    {
      resultado = 1;
    }
  }
  return ((int)resultado);
}

/** Verificar se duas matrizes sao iguais
 *  @param Matrix 1
 *  @param Matrix 2
 *  @returns Valore booleano referente ao resultado
*/
int IntCheckEqualMatrix (ref_int_matrix matrix1, ref_int_matrix matrix2)
{
  bool resultado = 0;
  if (matrix1 == null || matrix1->data == null || matrix2 == null || matrix2->data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    if (matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns)
    {
      matrix1->ix = 0;
      matrix1->iy = 0;
      int x = 0;
      for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix++)
      {
        for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy++)
        {
          if (matrix1->data[matrix1->ix][matrix1->iy] != matrix2->data[matrix1->ix][matrix1->iy])
          {
            x++;
          }
        }
      } 
      matrix1->ix = 0;
      matrix1->iy = 0;
      if (x == 0)
      {
        resultado = 1;
      }
    }
  }
  return ((int)resultado);
}

/** somar duas matrizes inteiras
 *  @param Matrix 1
 *  @param Matrix 2
 *  @returns Matrix com os valores somados
*/
ref_int_matrix IntAddMatrix (ref_int_matrix matrix1, ref_int_matrix matrix2)
{
  ref_int_matrix resultado = null;
  int size1 = 0;
  int size2 = 0;
  if (matrix1 == null || matrix1->data == null || matrix2 == null || matrix2->data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    size1 = (matrix1->rows * matrix1->columns);
    size2 = (matrix2->rows * matrix2->columns);
    if (size1 > 0 && size2 > 0)
    {
      if (matrix1->rows != matrix2->rows)
      {
        if (matrix1->rows == matrix2->columns && matrix1->columns == matrix2->rows)
        {
          matrix2 = IntTransposeMatrix(matrix2);
        }
      }
      if (matrix1->rows == matrix2->rows && size1 == size2)
      {
        resultado = IntNewMatrix(matrix1->rows, matrix1->columns);
        for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix++)
        {
          for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy++)
          {
            resultado->data[matrix1->ix][matrix1->iy] = (matrix1->data[matrix1->ix][matrix1->iy] + matrix2->data[matrix1->ix][matrix1->iy]);
          }
        }
      }
    }
  }
  return (resultado);
}

/*
ref_int_matrix IntMultiplyMatrix (ref_int_matrix matrix1, ref_int_matrix matrix2)
{
  ref_int_matrix resultado = null;
  if (matrix1 == null || matrix1->data == null || matrix2 == null || matrix2->data == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Se as dimensoes das matrizes sao validas
    if (matrix1->rows > 0 && matrix1->columns > 0 && matrix2->rows > 0 && matrix2->columns > 0)
    {
      resultado = IntNewMatrix(matrix1->rows, matrix2->columns);
      // Se as dimensoes das matrizes sao diferentes
      if (matrix1->rows != matrix2->rows && matrix1->columns != matrix2->columns)
      {
        // Se as dimensoes das matrizes sao inversas
        if (matrix1->rows == matrix2->columns && matrix1->columns == matrix2->rows)
        {
          // Transpor a segunda matriz
          matrix2 = IntTransposeMatrix(matrix2);
        }
      }
      // Se as dimensoes das matrizes sao iguais
      if (matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns)
      {
        // Calcular o produto das matrizes
        for (matrix1->ix = 0; matrix1->ix < matrix1->rows; matrix1->ix++)
        {
          for (matrix1->iy = 0; matrix1->iy < matrix1->columns; matrix1->iy++)
          {
              
          }
        }
      }
    }
  }
  return (resultado);
}
*/

void ED1001 (void)
{
  // Identificacao de dados
  int_array array;
  int inferior = 0;
  int superior = 0;
  int n = 0;

  // Apresentacao
  println ("ED1001");
  println ("");                  // Pular uma linha
  printf  ("Gerar um valor inteiro aleatorio dentro de um intervalo, cujos os limites de inicio e fim serao dados como parametros. ");
  printf  ("Para testar ler os limites do intervalo do teclado, ler uma quantidade [n] de valores e gerar tais valores e armazena-los em ");
  println  ("um arranjo, gravar o arranjo em um arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  inferior = ReadInt ("Forneca um valor para determinar o intervalo inferior: ");
  superior = ReadInt ("Forneca um valor para determinar o intervalo superior: ");
  n = ReadInt ("Forneca um valor para determinar a quantidade de valores aleatorios a serem gerados: ");

  // Gerar arranjo de valores aleatorios
  array = IntRandIntervalArray(inferior, superior, n);

  // Gravar dados em um arquivo
  if (array.data)
  {
    IntWriteArrayFile ("DADOS01.TXT", array);
  }

  // Mostrar dados
  IntPrintArrayFile ("DADOS01.TXT");

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1002 (void)
{
  // Identificacao de dados
  int_array array;
  int valor = 0;
  int i = 0;
  int resultado = 0;

  // Apresentacao
  println ("ED1002");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para procurar certo valor inteiro em um arranjo. Para testar receber um nome de arquivo como parametro e ");
  println ("receber de tal arquivo um arranjo, aplicar a funcao sobre os valores lidos. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  IntWriteArrayFile("DADOS02.TXT", ReadIntArray(array));
  
  valor = ReadInt ("Forneca um valor a ser procurado: ");
  i = ReadInt ("Forneca um valor inteiro para determinar a posicao inicial: ");

  // Ler dados do arquivo
  int_array Farray = IntArrayFile("DADOS02.TXT");

  // Procurar dados
  resultado = IntFindArray(valor, i, Farray);

  // Mostrar dados
  if (resultado >= 0)
  {
    printf ("posicao: %d\n", resultado);
  }
  else
  {
    printf ("O valor fornecido nao foi encontrado no arranjo. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1003 (void)
{
  // Identificacao de dados
  int_array array1;
  int_array array2;
  int_array farray1;
  int_array farray2;
  int resultado = 0;

  // Apresentacao
  println ("ED1003");
  println ("");                  // Pular uma linha
  println ("Incluir uma funcao para operar a comparacao de dois arranjos inteiros. Para testar receber os arranjos de 2 arquivos diferentes.");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array1 = ReadIntArray();
  array2 = ReadIntArray();

  // Gravar arranjos em arquivos diferentes
  IntWriteArrayFile ("ARRANJO1.TXT", array1);
  IntWriteArrayFile ("ARRANJO2.TXT", array2);

  // Liberar espaco
  if (array1.data)
  {
    free (array1.data);
  }
  if (array2.data)
  {
    free (array2.data);
  }

  // Ler dados do arquivo
  farray1 = IntArrayFile ("ARRANJO1.TXT");
  farray2 = IntArrayFile ("ARRANJO2.TXT");

  // Verificar se os dados existem
  if (farray1.data && farray2.data)
  {
    // Comparar arranjos
    resultado = IntCmpArray (farray1, farray2);

    // Liberar espaco
    free (farray1.data);
    free (farray2.data);
  }
  else
  {
    println ("ERRO: Dados inexistentes. ");
  }

  // Mostrar dados
  if (resultado == 1)
  {
    println ("Os arranjos sao iguais. ");
  }
  else
  {
    println ("Os arranjos sao diferentes. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1004 (void)
{
  // Identificacao de dados
  int_array array1;
  int_array array2;
  int constante = 0;
  ref_int_array resultado = null;

  // Apresentacao
  println ("ED1004");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para operar uma soma de dois arranjos, com o segundo sendo escalado por uma constante. Para testar ");
  println ("receber os arranjos de 2 arquivos diferentes e aplicar a funcao sobre eles. ");
  println ("");                  // Pular uma linha

  // Ler dados
  constante = ReadPositiveInt ("Forneca um valor inteiro para definir o escalamento do segundo arranjo: ");
  array1 = ReadIntArray();
  array2 = ReadIntArray();

  // Testar compatibilidade
  if (array1.length != (int)((double)array2.length/(double)constante))
  {
    println ("O tamanho dos arranjos sao incompativeis");
  }
  else
  {
    // Escrever arranjos em arquivos
    if (array1.data)
    {
      IntWriteArrayFile ("DADOS41.TXT", array1);
    }
    if (array2.data)
    {
      IntWriteArrayFile ("DADOS42.TXT", array2);
    }

    // Ler arranjos do arquivo
    int_array Farray1 = IntArrayFile("DADOS41.TXT");
    int_array Farray2 = IntArrayFile("DADOS42.TXT");

    // Somar arranjos
    if (Farray1.data && Farray2.data)
    {
      resultado = IntAddConstArray (Farray1, Farray2, constante);

      // Mostrar dados
      if (resultado)
      {
        println ("Arranjo 1 -");
        IntPrintArray (Farray1);
        println ("\nArranjo 2 -");
        IntPrintArray (Farray2);
        println ("\nSoma -");
        IntPrintArray (*resultado);

        // Liberar memoria
        IntFreeArray (resultado);
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1005 (void)
{
  // Identificacao de dados
  int_array array;
  int_array Farray;
  int resultado = 0;

  // Apresentacao
  println ("ED1005");
  println ("");                  // Pular uma linha
  println ("Incluir uma funcao para verificar se um arranjo esta em ordem decrescente. Para testar ler o arranjo de um arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array = ReadIntArray();

  // Verificar existencia dos dados
  if (array.data)
  {
    // Gravar arranjo em um arquivo
    IntWriteArrayFile ("DADOS05.TXT", array);
  }

  // Ler arranjo do arquivo
  Farray = IntArrayFile("DADOS05.TXT");
  
  // Verificar existencia dos dados
  if (Farray.data)
  {
    resultado = IntArrayDescending(array);

    // Mostrar dados
    if (resultado == 1)
    {
      println ("O arranjo e decrescente. ");
    }
    else
    {
      println ("O arranjo nao e decrescente. ");
    }
  }


  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1006 (void)
{
  // Identificacao de dados
  ref_int_matrix matrix = null;
  ref_int_matrix Fmatrix = null;
  ref_int_matrix resultado = null;

  // Apresentacao
  println ("ED1006");
  println ("");                  // Pular uma linha
  println ("Incluir uma funcao para obter a transposta de uma matrix. Para testar receber a matrix de um arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  matrix = ReadIntMatrix();

  // Escrever matrix em um arquivo
  IntWriteMatrixFile ("DADOS06.TXT", matrix);

  // Ler dados do arquivo
  Fmatrix = IntMatrixFile ("DADOS06.TXT");

  if (Fmatrix)
  {
    // Calcular transposta
    resultado = IntTransposeMatrix(Fmatrix);

    if (resultado)
    {
      // Mostrar dados
      println ("Matrix normal-");
      IntPrintMatrix (Fmatrix);
    
      println ("\nMatrix trasposta-");
      IntPrintMatrix(resultado);
    }
  }


  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1007 (void)
{
  // Identificacao de dados
  ref_int_matrix matrix = null;
  ref_int_matrix Fmatrix = null;
  int resultado = 0;

  // Apresentacao
  println ("ED1007");
  println ("");                  // Pular uma linha
  println ("Incluir uma funcao para testar se os valores de uma matrix sao iguais a zero. Para testar receber uma matrix de um arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  matrix = ReadIntMatrix();

  // Gravar matrix no arquivo
  if (matrix)
  {
    IntWriteMatrixFile ("DADOS07.TXT", matrix);
  
    // Ler matrix do arquivo
    Fmatrix = IntMatrixFile("DADOS07.TXT");

    if (Fmatrix)
    {
      // Verificar se os valores da matrix sao iguais a zero
      resultado = IntCheckNullMatrix(Fmatrix);

      // Mostrar dados
      if (resultado == 1)
      {
        println ("Todos os elementos da matrix sao iguais a zero. ");
      }
      else if (resultado == 0)
      {
        println ("A matrix possui valores diferentes de zero. ");
      }
    }
  }
  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1008 (void)
{
  // Identificacao de dados
  ref_int_matrix matrix1 = null;
  ref_int_matrix matrix2 = null;
  ref_int_matrix Fmatrix1 = null;
  ref_int_matrix Fmatrix2 = null;
  int resultado = 0;

  // Apresentacao
  println ("ED1008");
  println ("");                  // Pular uma linha
  println ("Incluir uma funcao para testar a igualdade de duas matrizes. Para testar receber as matrizes de 2 arquivos diferentes. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  println ("Matrix 1: ");
  matrix1 = ReadIntMatrix();
  println ("\nMatrix 2: ");
  matrix2 = ReadIntMatrix();

  // Verificar dados
  if (matrix1 == null || matrix2 == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Gravar dados em 2 arquivos
    IntWriteMatrixFile ("DADOS0801.TXT", matrix1);
    IntWriteMatrixFile ("DADOS0802.TXT", matrix2);

    // Ler dados dos arquivos
    Fmatrix1 = IntMatrixFile ("DADOS0801.TXT");
    Fmatrix2 = IntMatrixFile ("DADOS0802.TXT");

    // Verificar dados 
    if (Fmatrix1 != null || Fmatrix2 != null)
    {
      // Verificar se as matrizes sao iguais
      resultado = IntCheckEqualMatrix (Fmatrix1, Fmatrix2);

      // Mostrar dados
      if (resultado == 1)
      {
        println ("As matrizes sao iguais. ");
      }
      else
      {
        println ("As matrizes sao diferentes. ");
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1009 (void)
{
  // Identificacao de dados
  ref_int_matrix matrix1 = null;
  ref_int_matrix matrix2 = null;
  ref_int_matrix Fmatrix1 = null;
  ref_int_matrix Fmatrix2 = null;
  ref_int_matrix resultado = null;

  // Apresentacao
  println ("ED1009");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para operar uma soma de matrizes com a segunda escalada por uma constante. Para testar receber as ");
  println ("matrizes de 2 arquivos diferentes. ");
  println ("");                  // Pular uma linha

  // Ler dados
  println ("Matrix 1: ");
  matrix1 = ReadIntMatrix();
  println ("\nMatrix 2: ");
  matrix2 = ReadIntMatrix();

  // Verificar dados
  if (matrix1 == null || matrix2 == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Gravar dados em 2 arquivos
    IntWriteMatrixFile ("DADOS0901.TXT", matrix1);
    IntWriteMatrixFile ("DADOS0902.TXT", matrix2);

    // Liberar espaco
    IntFreeMatrix(matrix1);
    IntFreeMatrix(matrix2);

    // Ler dados dos arquivos
    Fmatrix1 = IntMatrixFile ("DADOS0901.TXT");
    Fmatrix2 = IntMatrixFile ("DADOS0902.TXT");

    // Verificar dados 
    if (Fmatrix1 != null && Fmatrix2 != null)
    {
      // Calcular soma das matrizes
      resultado = IntAddMatrix(Fmatrix1, Fmatrix2);

      // Mostrar dados
      println ("Matriz 1-");
      IntPrintMatrix(Fmatrix1);
      println ("\nMatrix 2-");
      IntPrintMatrix(Fmatrix2);
      println ("\nSoma-");
      IntPrintMatrix(resultado);

      // Liberar espaco
      IntFreeMatrix(matrix1);
      IntFreeMatrix(matrix2);
      IntFreeMatrix(resultado);
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1010 (void)
{
  // Identificacao de dados
  ref_int_matrix matrix1 = null;
  ref_int_matrix matrix2 = null;
  ref_int_matrix Fmatrix1 = null;
  ref_int_matrix Fmatrix2 = null;
  ref_int_matrix resultado = null;

  // Apresentacao
  println ("ED1010");
  println ("");                  // Pular uma linha
  println ("Incluir uma funcao para obter o produto de duas matrizes inteiras. Para testar receber as matrizes de dois arquivos. ");
  println ("");                  // Pular uma linha
    
  println ("Matrix 1: ");
  matrix1 = ReadIntMatrix();
  println ("\nMatrix 2: ");
  matrix2 = ReadIntMatrix();

  // Verificar dados
  if (matrix1 == null || matrix2 == null)
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Gravar dados em 2 arquivos
    IntWriteMatrixFile ("DADOS1001.TXT", matrix1);
    IntWriteMatrixFile ("DADOS1002.TXT", matrix2);

    // Liberar espaco
    IntFreeMatrix(matrix1);
    IntFreeMatrix(matrix2);

    // Ler dados dos arquivos
    Fmatrix1 = IntMatrixFile ("DADOS1001.TXT");
    Fmatrix2 = IntMatrixFile ("DADOS1002.TXT");

    // Verificar dados 
    if (Fmatrix1 != null && Fmatrix2 != null)
    {
      // Calcular produto das matrizes
      //resultado = IntMultiplyMatrix(Fmatrix1, Fmatrix2);

      // Mostrar dados
      println ("Matriz 1-");
      IntPrintMatrix(Fmatrix1);
      println ("\nMatrix 2-");
      IntPrintMatrix(Fmatrix2);
      println ("\nProduto-");
      IntPrintMatrix(resultado);

      // Liberar espaco
      IntFreeMatrix(matrix1);
      IntFreeMatrix(matrix2);
      IntFreeMatrix(resultado);
    }
  }

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
      println ("ED10 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1001   2 - ED1002");
      println ("3 - ED1003   4 - ED1004");
      println ("5 - ED1005   6 - ED1006");
      println ("7 - ED1007   8 - ED1008");
      println ("9 - ED1009  10 - ED1010");
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
          case 1:  ED1001();
            break;
          case 2:  ED1002();
            break;
          case 3:  ED1003();
            break;
          case 4:  ED1004();
            break;
          case 5:  ED1005();
            break;
          case 6:  ED1006();
            break;
          case 7:  ED1007();
            break;
          case 8:  ED1008();
            break;
          case 9:  ED1009();
            break;
          case 10: ED1010();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED10 e seus metodos

*/