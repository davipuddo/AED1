//853355_AED1

#include "..\io.h"
#include "..\puddo.h"

/** Fazer uma matrix de numeros reais negativos
 *  @param Quantidade de linhas
 *  @param Quantidade de colunas
 *  @param Matrix de valores reais
*/
void DoubleWriteNegativeMatrix (int rows, int columns, double matrix [][columns])
{
  double z = 0;
  int i = 0;
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      printf ("Forneca [%d] valor(es) negativo(s):  ", (rows*columns)-i);
      z = ReadDouble ("");
      if (z < 0)
      {
        matrix[x][y] = z;
        i++;
      }
      else // Voltar para a posicao anterior 
      { 
        if (y > 0)
        {y--;}
        else if (y == 0)
        {
          y = -1;
        }
      }
      if (y < 0)
      { y = (rows)-1;  x--; } 
      if (x < 0)
      { x = -1; }
    }
  }
}

/** Ler e mostrar os valores na diagonal principal de uma matrix de valores reais
 *  @param Quantidade de linhas na matrix
 *  @param Quantidade de colunas na matrix
 *  @param Matrix
*/
void DoubleMainDiagonalMatrix (int rows, int columns, double matrix[][columns])
{
  if (rows != columns)
  {
    println ("ERRO:'DoubleMainDiagonalMatrix' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int i = 0;
    double copia [rows][columns];

    DoubleCopyMatrix(rows, columns, copia, matrix);
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i == 0)
        {
          i = columns;
        }
        else
        {
          copia[r][c] = 0;
          i--;
        }
      }
    }

    DoublePrintMatrix(rows,columns,copia);
    println ("");

    int x = 0;
    int y = 0;
    while (x != rows && y != columns)
    {
      printf ("%3lf\t", copia[x][y]);
      x++;
      y++;
    }
    println("");
  }
}

/** Ler e mostrar os valores na diagonal secundaria de uma matrix de valores reais
 *  @param Quantidade de linhas na matriz
 *  @param Quantidade de colunas na matriz
 *  @param Matriz
*/
void DoubleSecondaryDiagonalMatrix (int rows, int columns, double matrix[][columns])
{
  if (rows != columns)
  {
    println ("ERRO:'DoubleSecondaryDiagonalMatrix' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int i = columns-1;
    double copia [rows][columns];
    DoubleCopyMatrix(rows, columns, copia, matrix);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i == 0)
        {
          printf ("%.3lf\t", copia[r][c]);
          i = columns - 2;
        }
        else
        {
          copia[r][c] = 0;
          i--;
        }
        if (r == (columns-1))
        {
          i = columns-1;
        }
      }
    }
    println ("");
    DoublePrintMatrix(rows, columns, copia);
  }
}

/** Mostrar os valores do triangulo principal de uma matrix
 *  @param Quantidade de linhas da matix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
*/
void DoubleMainTriangle (int rows, int columns, double matrix[][columns])
{
  if (rows != columns)
  {
    println ("ERRO:'DoubleMainTriangle' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int w = 1;
    int i = w;
    double copia [rows][columns];
    DoubleCopyMatrix(rows, columns, copia, matrix);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i <= 0)
        {
          copia[r][c] = 0;
        }
        else
        {
          printf ("%.3lf\t", copia[r][c]);
        }
        i--;
      }
      w++;
      i = w;
    }
    println ("");
    DoublePrintMatrix(rows, columns, copia);
  }
}

/** Mostrar os valores do triangulo principal invertido de uma matrix
 *  @param Quantidade de linhas da matix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
*/
void DoubleMainInverseTriangle (int rows, int columns, double matrix[][columns])
{
  if (rows != columns)
  {
    println ("ERRO:'DoubleMainInverseTriangle' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int w = 0;
    int i = w;
    double copia [rows][columns];
    DoubleCopyMatrix(rows, columns, copia, matrix);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i <= 0)
        {
          printf ("%.3lf\t", copia[r][c]);
        }
        else
        {
          copia[r][c] = 0;
        }
        i--;
      }
      w++;
      i = w;
    }
    println ("");
    DoublePrintMatrix(rows, columns, copia);
  }
}

/** Mostrar os valores do triangulo secundario de uma matrix
 *  @param Quantidade de linhas da matix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
*/
void DoubleSecondaryTriangle (int rows, int columns, double matrix[][columns])
{
  if (rows != columns)
  {
    println ("ERRO:'DoubleSecondaryTriangle' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int w = columns-1;
    int i = w;
    double copia [rows][columns];
    DoubleCopyMatrix(rows, columns, copia, matrix);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i <= 0)
        {
          printf ("%.3lf\t", copia[r][c]);
        }
        else
        {
          copia[r][c] = 0;
        }
        i--;
      }
      w--;
      i = w;
    }
    println ("");
    DoublePrintMatrix(rows, columns, copia);
  }
}

/** Mostrar os valores do triangulo secundario invertido de uma matrix
 *  @param Quantidade de linhas da matix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
*/ 
void DoubleSecondaryInverseTriangle (int rows, int columns, double matrix[][columns])
{
  if (rows != columns)
  {
    println ("ERRO:'DoubleSecondaryInverseTriangle' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int w = columns;
    int i = w;
    double copia [rows][columns];
    DoubleCopyMatrix(rows, columns, copia, matrix);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i <= 0)
        {
          copia[r][c] = 0;
        }
        else
        {
          printf ("%.3lf\t", copia[r][c]);
        }
        i--;
      }
      w--;
      i = w;
    }
    println ("");
    DoublePrintMatrix(rows, columns, copia);
  }
}

/** Verificar se valores abaixo da diagonal principal de uma matrix sao iguais a zero
 *  @param Quantidade de linhas da matix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
 *  @returns Valor inteiro relativo a verificacao dos valores abaixo da diagonal principal
 *  @note 1 - se todos forem 0 | 2 - se alguns forem 0 | 3 - se nenhum for zero
*/
int DoubleCheckZeroUnderMainTriangle (int rows, int columns, double matrix[][columns])
{
  int x = 0;
  if (rows != columns)
  {
    println ("ERRO:'DoubleCheckZeroUnderMainTriangle' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int w = 0;
    int i = w;
    int n = 0;

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i > 0)
        {
          if (matrix[r][c] == 0.0)
          {
            x++;
          }
          n++;
        }
        i--;
      }
      w++;
      i = w;
    }

    if (x == n)
    {
      x = -1;
    }
    else if (x == 0)
    {
      x = 0;
    }
  }
  return (x);
}

/** Verificar se valores acima da diagonal principal de uma matrix sao iguais a zero
 *  @param Quantidade de linhas da matix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix
 *  @returns Valor inteiro relativo a verificacao dos valores abaixo da diagonal principal
 *  @note 1 - se todos forem 0 | 2 - se alguns forem 0 | 3 - se nenhum for zero
*/
int DoubleCheckZeroAboveMainTriangle (int rows, int columns, double matrix[][columns])
{
  int x = 0;
  if (rows != columns)
  {
    println ("ERRO:'DoubleMainInverseTriangle' so pode ser usada para matrizes quadradas. ");
  }
  else
  {
    int w = 1;
    int i = w;
    int n = 0;
    double copia [rows][columns];
    DoubleCopyMatrix(rows, columns, copia, matrix);

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < columns; c++)
      {
        if (i <= 0)
        {
          if (matrix[r][c] == 0.0)
          {
            x++;
          }
          n++;
        }
        i--;
      }
      w++;
      i = w;
    }
    if (x == n)
    {
      x = -1;
    }
    else if (x == 0)
    {
      x = 0;
    }
  }
  return (x);
}

/** Escrever uma matriz de valores inteiros crescente
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix de valores inteiros
 *  @note O parametro da matrix e apenas para onde ele ira retornar
*/
void IntAscendingMatrix (int rows, int columns, int matrix[][columns])
{
  int n = 0;
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      n++;
      matrix[x][y] = n;
    }
  } 
}

/** Escrever uma matriz de valores inteiros decrescente
 *  @param Quantidade de linhas da matrix
 *  @param Quantidade de colunas da matrix
 *  @param Matrix de valores inteiros
 *  @note O parametro da matrix e apenas para onde ele ira retornar
*/
void IntDescendingMatrix (int rows, int columns, int matrix[][columns])
{
  int n = (rows*columns);
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      matrix[x][y] = n;
      n--;
    }
  } 
}


void ED0901 (void)
{
  // Identificacao de dados
  int linha = 0;
  int coluna = 0;

  // Apresentacao
  println ("ED0901");
  println ("");                  // Pular uma linha
  printf  ("Ler as dimensoes de uma matriz real, bem como todos os seus elementos(apenas valores ");
  println ("negativos). Verificar se as dimensoes sao nulas ou negativas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz: ");
  coluna = ReadPositiveInt ("Forneca a quantiade de colunas da matriz: ");

  double matrix [linha][coluna];

  DoubleWriteNegativeMatrix (linha, coluna, matrix);

  // Mostrar dados
  DoublePrintMatrix(linha, coluna, matrix); 

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0902 (void)
{
  // Identificacao de dados
  int linha = 0;
  int coluna = 0;

  // Apresentacao
  println ("ED0902");
  println ("");                  // Pular uma linha
  printf  ("Gravar uma matriz real em um arquivo, a matriz e o nome do arquivo serao dados como ");
  printf  ("parametros, para testar, usar a leitura da matriz do exercicio anterior. Usar outro ");
  println ("metodo para ler e recuperar a matriz do arquivo, antes de mostra-la. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
  coluna = ReadPositiveInt ("Forneca a quantidade de colunas da matriz: ");

  // Inicializar matrizes
  double matrix  [linha][coluna];
  double Fmatrix [linha][coluna];

  // Ler matriz
  DoubleWriteNegativeMatrix (linha, coluna, matrix);

  // Gravar matriz no arquivo "DADOS02.TXT"
  DoubleWriteMatrixFile ("DADOS02.TXT", linha, coluna, matrix);

  // Ler matriz do arquivo "DADOS02.TXT"
  DoubleMatrixFile ("DADOS02.TXT", &linha, &coluna, Fmatrix);

  // Mostrar dados
  DoublePrintMatrix(linha, coluna, Fmatrix);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0903 (void)
{
  // Identificacao de dados
  int linha = 0;
  int coluna = 0;

  // Apresentacao
  println ("ED0903");
  println ("");                  // Pular uma linha
  println ("Mostrar somente os valores na diagonal principal de uma matriz real, se for quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  //Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix); 

  // Mostrar dados
  println ("\nMatrix Normal-");
  DoublePrintMatrix    (linha, coluna, matrix);
  println ("\nMatrix Diagonal-");
  DoubleMainDiagonalMatrix (linha, coluna, matrix);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0904 (void)
{
  // Identificacao de dados
  int linha = 0;
  int coluna = 0;

  // Apresentacao
  println ("ED0904");
  println ("");                  // Pular uma linha
  println ("Mostrar somente os valores na diagonal secundaria de uma matriz real, se for quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);
  
  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatrix Normal-");
  DoublePrintMatrix    (linha, coluna, matrix);
  println ("\nMatrix Diagonal-\n");
  DoubleSecondaryDiagonalMatrix (linha, coluna, matrix);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0905 (void)
{
  // Identificacao de dados
  int linha  = 0;
  int coluna = 0;

  // Apresentacao
  println ("ED0905");
  println ("");                  // Pular uma linha
  printf  ("Mostrar somente os valores abaixo e na diagonal principal de uma matriz real, se for ");
  println ("quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatrix Normal-");
  DoublePrintMatrix  (linha, coluna, matrix);
  println ("\nMatrix Triangulo principal-\n");
  DoubleMainTriangle (linha, coluna, matrix);
  

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0906 (void)
{
  // Identificacao de dados
  int linha = 0; 
  int coluna = 0;

  // Apresentacao
  println ("ED0906");
  println ("");                  // Pular uma linha
  printf  ("Mostrar somente os valores acima e na diagonal principal de uma matriz real, se for ");
  println ("quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatrix Normal-");
  DoublePrintMatrix  (linha, coluna, matrix);
  println ("\nMatrix Triangulo principal invertido-\n");
  DoubleMainInverseTriangle (linha, coluna, matrix);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0907 (void)
{
  // Identificacao de dados
  int linha = 0; 
  int coluna = 0;

  // Apresentacao
  println ("ED0907");
  println ("");                  // Pular uma linha
  printf  ("Mostrar somente os valores abaixo e na diagonal secundaria de uma matriz real, se for ");
  println ("quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatrix Normal-");
  DoublePrintMatrix  (linha, coluna, matrix);
  println ("\nMatrix Triangulo secundario-\n");
  DoubleSecondaryTriangle (linha, coluna, matrix);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0908 (void)
{
  // Identificacao de dados
  int linha = 0; 
  int coluna = 0;

  // Apresentacao
  println ("ED0908");
  println ("");                  // Pular uma linha
  printf  ("Mostrar somente os valores acima e na diagonal secundaria de uma matriz real, se for ");
  println ("quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatrix Normal-");
  DoublePrintMatrix  (linha, coluna, matrix);
  println ("\nMatrix Triangulo secundario invertido-\n");
  DoubleSecondaryInverseTriangle (linha, coluna, matrix);


  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0909 (void)
{
  // Identificacao de dados
  int linha = 0; 
  int coluna = 0;
  int resultado = 0;

  // Apresentacao
  println ("ED0909");
  println ("");                  // Pular uma linha
  printf  ("Com o uso de uma funcao, testar se os valores acima da diagonal principal de uma matriz ");
  println ("real sao iguais a zero");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Chamar funcao
  resultado = DoubleCheckZeroUnderMainTriangle (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatriz- ");
  DoublePrintMatrix(linha, coluna, matrix);
  println("");

  if (resultado == -1)
  {
    println ("Todos os valores abaixo da diagonal principal da matriz sao iguais a zero. ");
  }
  else if (resultado == 0)
  {
    println ("Nenhum dos valores abaixo da diagonal principal da matriz sao iguais a zero. ");
  }
  else
  {
    println ("Um ou mais valores abaixo da diagonal principal da matriz sao iguais a zero. ");
    printf  ("Quantidade de valores: %d\n", resultado);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0910 (void)
{
 // Identificacao de dados
  int linha = 0; 
  int coluna = 0;
  int resultado = 0;

  // Apresentacao
  println ("ED0910");
  println ("");                  // Pular uma linha
  printf  ("Com o uso de uma funcao, testar se os valores abaixo da diagonal principal de uma matriz ");
  println ("real sao iguais a zero");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  double matrix[linha][coluna];

  // Ler matriz
  DoubleWriteMatrix (linha, coluna, matrix);

  // Chamar funcao
  resultado = DoubleCheckZeroAboveMainTriangle (linha, coluna, matrix);

  // Mostrar dados
  println ("\nMatriz- ");
  DoublePrintMatrix(linha, coluna, matrix);
  println("");

  if (resultado == -1)
  {
    println ("Todos os valores acima da diagonal principal da matrix sao iguais a zero. ");
  }
  else if (resultado == 0)
  {
    println ("Nenhum dos valores acima da diagonal principal da matrix sao iguais a zero. ");
  }
  else
  {
    println ("Um ou mais valores acima da diagonal principal da matrix sao iguais a zero. ");
    printf  ("Quantidade de valores: %d\n", resultado);
  }


  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED09E1 (void)
{
  // Identificacao de dados
  int linha = 0; 
  int coluna = 0;

  // Apresentacao
  println ("ED09E1");
  println ("");                  // Pular uma linha
  printf  ("Mostrar somente os valores acima e na diagonal secundaria de uma matriz real, se for ");
  println ("quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matrizes
  int matrix [linha][coluna];

  // Calcular matriz
  IntAscendingMatrix (linha, coluna, matrix);

  // Escrever matriz no arquivo
  IntWriteMatrixFile ("DADOSE1.TXT", linha, coluna, matrix);

  // Mostar dados
  IntPrintMatrixFile ("DADOSE1.TXT");

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED09E2 (void)
{
  // Identificacao de dados
  int linha = 0; 
  int coluna = 0;

  // Apresentacao
  println ("ED09E1");
  println ("");                  // Pular uma linha
  printf  ("Mostrar somente os valores acima e na diagonal secundaria de uma matriz real, se for ");
  println ("quadrada. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    linha  = ReadPositiveInt ("Forneca a quantidade de linhas da matriz:  ");
    coluna = ReadPositiveInt ("Fornece a quantidade de colunas da matriz: ");

    if (linha != coluna)
    {
      println ("ERRO: Favor fornecer uma matriz quadrada.\n");
    }
  } while (linha != coluna);

  // Inicializar matriz
  int matrix [linha][coluna];

  // Calcular matriz
  IntDescendingMatrix (linha, coluna, matrix);
  
  // Escrever matriz no arquivo
  IntWriteMatrixFile ("DADOSE2.TXT", linha, coluna, matrix);

  // Mostar dados
  IntPrintMatrixFile ("DADOSE2.TXT");

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
      println ("ED09 - v1.2 - 05/05/24" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0  - sair");
      println ("1  - ED0901   2 - ED0902");
      println ("3  - ED0903   4 - ED0904");
      println ("5  - ED0905   6 - ED0906");
      println ("7  - ED0907   8 - ED0908");
      println ("9  - ED0909  10 - ED0910");
      println ("11 - ED09E1  12 - ED09E2");
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
          case 1:  ED0901();
            break;
          case 2:  ED0902();
            break;
          case 3:  ED0903();
            break;
          case 4:  ED0904();
            break;
          case 5:  ED0905();
            break;
          case 6:  ED0906();
            break;
          case 7:  ED0907();
            break;
          case 8:  ED0908();
            break;
          case 9:  ED0909();
            break;
          case 10: ED0910();
            break;
          case 11: ED09E1();
            break;
          case 12: ED09E2();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED09 e seus metodos

*/