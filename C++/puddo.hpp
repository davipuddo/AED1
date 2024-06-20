/** 853355 AED1
 * @author Davi Ferreira Puddo
*/

#include <iostream>    // para entradas e saidas
#include <fstream>     // para arquivos
#include <sstream>     // para conversoes
#include <string>      // para cadeias de caracteres
#include <cstdio>      // para entradas e saida
#include <cstdlib>     // para a biblioteca padrao
#include <cstring>     // para cadeias de caracteres
#include <stddef.h>    // para definicoes basicas
#include <stdarg.h>    // para tratar argumentos
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo
#include <limits>
#include <iomanip>

/** Mostrar uma cadeia de caracteres e pular uma linha
 *  @param Texto a ser mostrado
*/

#define null NULL
#define nullptr NULL

void println (std::string text)
{
    std::cout << text << std::endl;
}

/** Pausar execucao do programa
 *  @param Texto a ser mostrado
*/
void pause (std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << (text);
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
}

/** Ler um valor inteiro
 *  @param Texto a ser mostrado
 *  @returns Valor inteiro
*/
int ReadInt (std::string text)
{
  if (text == "")
  {
    text = "Forneca um valor inteiro: ";
  }
  int x = 0;
  std::cout << (text);
  std::cin >> x;
  getchar( );
  std::cout << std::endl;
  return (x);
}

int ReadPositiveInt (std::string text)
{
  if (text == "")
  {
    text = "Forneca um valor inteiro maior do que zero: ";
  }
  int x = 0;
  do
  { 
    std::cout << (text);
    std::cin >> x;
    getchar();
  } while (x <= 0);
  std::cout << std::endl;
  return (x);
}

double ReadDouble (std::string text)
{
  if (text == "")
  {
    text = "Forneca um valor real: ";
  }
  double x = 0.0;
  std::cout << (text);
  std::cin >> x;
  getchar();
  std::cout << std::endl;
  return (x);
}

char ReadChar (std::string text)
{
  if (text == "")
  {
    text = "Forneca um caractere: ";
  }
  char x = '0';
  std::cout << (text);
  std::cin >> x;
  getchar();
  std::cout << std::endl;
  return (x);
}

std::string ReadString (std::string text)
{
  if (text == "")
  {
    text = "Forneca uma cadeia de caracteres: ";
  }
  std::string x = "";
  std::cout << (text);
  std::getline(std::cin, x);
  std::cout << std::endl;
  return (x);
}

template <typename T>
T ReadT (std::string text)
{
  if (text == "")
  {
    text = "Forneca um dado: ";
  }
  T x = (T)0;
  std::cout << (text);
  std::cin >> x;
  getchar();
  std::cout << std::endl;
  return (x);
}

int IntRandom (int x, int y)
{
  int resultado = rand() % x + y;
  return (resultado);
}

template <typename T>
void InvertValues (T *x, T *y)
{
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

template <typename T>
T* WriteArray (int size)
{
  T* data = null;
  T x;
  
  if (typeid(T) == typeid(char))
  {
    data = (char*)calloc(size+1, sizeof(char));
  }
  else
  {
    data = new T[size];
  }

  for (int i = 0; i < size; i++)
  {
    std::cout << "Forneca [" << i << "] elementos para o arranjo: ";
    std::cin >> x; getchar();
    data[i] = x;
  }
  return (data);
}

template <typename T>
void PrintArray (T* data)
{
  int size = strlen(data);
  std::cout << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cout << i << ": " << data[i] << std::endl;
  }
  std::cout << std::endl;
}

#ifndef _MYARRAY_HPP
#define _MYARRAY_HPP

template <typename T>
class Array
{
  private:
  T optional;
  int length;
  T *data;
  
  public:

  Array (int n, T initial)
  {
    optional = initial;
    length = 0;
    data = nullptr;

    if (n > 0)
    {
      length = n;
      data = new T[length];
    }
  }

  Array ()
  {
    length   = 0;
    data = nullptr;
  }
  
  void init (int n)
  {
    if (n > 0)
    {
      length = n;
      data = new T[length];
    }
  }

  Array (int length, int other[])
  {
    if (length < 0)
    {
      println("ERRO: Tamanho invalido. ");
    }
    else
    {
      this->length = length;
      data = new T[this->length];
      for (int i = 0; i < this->length; i++)
      {
        data[i] = other[i];
      }
    }
  }

  Array (const Array& other)
  {
    if (other.length <= 0)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      this->init(other.length);
      for (int i = 0; i < other.length; i++)
      {
        data[i] = other.data[i];
      }
    }
  }


  Array& operator= (const Array <T> other)
  {
    if (other.length <= 0)
    {
      println ("ERRO: Dado invalido. ");
    }
    else
    {
      this->length = other.length;
      this->data = new T[other.length];
      for (int i = 0; i < other.length; i++)
      {
        data[i] = other.data[i];
      }
    }
    return (*this);
  }

  bool EqualInPosition (const Array <T> other, const int position)
  {
    bool result = false;
    result = (this->data[position] == other.data[position]);
    return (result);
  }

  bool operator== (const Array <T> other)
  {
    bool resultado = false;
    int i = 0;
    if (other.length == 0 || length != other.length)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      i = 0;
      resultado = true;
      while (i < this->length && resultado)
      {
        resultado = resultado && (data[i] == other.data[i]);
        i++;
      }
    }
    return (resultado);
  }

  Array& operator+ (const Array <T> other)
  {
    static Array <int> result (other);
    if (other.length <= 0)
    {
      println ("ERRO: Falta dados. ");
    }
    else
    {
      if (other.length != this->length)
      {
        println ("ERRO: Os arrays sao incompativeis. ");
      }
      else
      {
        for (int i = 0; i < this->length; i++)
        {
          result.data[i] += this->data[i];
        }
      }
    }
    return (result);
  }

  Array& operator - (const Array <T> other)
  {
    static Array <int> result(other);
    if (other.length <= 0)
    {
      println ("ERRO: Falta dados. ");
    }
    else
    {
      if (other.length != this->length)
      {
        println ("ERRO: Os arrays sao incompativeis. ");
      }
      else
      {
        for (int i = 0; i < this->length; i++)
        {
          result.data[i] = this->data[i] - result.data[i];
        }
      }
    }
    return (result);
  }

  T& operator[] (const int position)
  {
    static T value = optional;

    if (position <= 0 || length <= position)
    {
      println ("ERRO: Posicao invalida. ");
    }
    else
    {
      value = data[position];
    }
    return (value);
  }

  void free()
  {
    if (data != nullptr)
    {
      delete (data);
      data = nullptr;
    }
  }

  void set (int position, T value)
  {
    if (0 <= position && position < length)
    {
      data[position] = value;
    }
  }

  T get (int position)
  {
    T value = optional;

    if (0 <= position && position < length)
    {
      value = data[position];
    }

    return (value);
  }

  /***/
  int getlength (void)
  {
    return (length);
  }

  /** Descobrir se um array possui tamanho e dados e valido
   * 
  */
  bool isValid (void)
  {
    bool result = (this->data != nullptr && this->length > 0);
    return (result);
  }

  /** Mostrar todos os valores de um array
   * 
  */
  void print (void)
  {
    println ("");
    for (int i = 0; i < length; i++)
    {
      std::cout << std::setw(3) << i << ":" << std::setw(9) << data[i] << std::endl;
    }
    println ("");
  }

  /** Fornecer dados para um array
   * 
  */
  void write (void)
  {
    println("");
    for (int x = 0; x < length; x++)
    {
        std::cout << std::setw(3) << x << ":";
        std::cin >> data[x];
    }
  }

  /** Escrever um array em um arquivo
   *  @param Nome do arquivo
  */
  void fwrite (std::string fileName)
  {
    std::ofstream file;

    file.open (fileName);
    file << length << std::endl;
    for (int i = 0; i < length; i++)
    {
      file << data[i] << std::endl;
    }
    file.close();
  }

  /** Ler e substituir um array de um arquivo
   *  @param Nome do arquivo
  */
  void fread (std::string fileName)
  {
    int n = 0;
    std::ifstream file;
    file.open (fileName);
    file >> n;
    if (n <= 0)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      length = n;
      data = new T[n];

      for (int i = 0; i < length; i++)
      {
        file >> data[i];
      }
    }
    file.close();
  }

  /** Substituir os valores de um array por valores aleatorios dado um intervalo
   *  @param Intervalo inferior
   *  @param Intervalo superior
  */
  void random (int initial, int final, int min, int max)
  {
    if (initial > final)
    {
      InvertValues<int>(&initial, &final);
    }
    if (min > max)
    {
      InvertValues<int>(&min, &max);
    }
    if (initial < 0 || final > (length-1))
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      srand(time(0));
      for (int i = 0; i < length; i++)
      {
        data[i] = rand() % (max - min + 1) + min;
      }
    }
  }

  /** Ler um array e manter apenas os seus valores pares
  */
  void even (void)
  {
    Array <T> tmpArray(this->length, 0);
    if (!tmpArray.isValid())
    {
      println ("(even) ERRO: Falta de espaco. ");
    }
    else
    {
      int c = 0;
      for (int i = 0; i < this->length; i++)
      {
        if (this->data[i] % 2 == 0)
        {
          tmpArray.data[c] = this->data[i];
          c++;
        }
      }
      if (c <= 0)
      {
        println ("Nenhum valor par foi encontrado no arranjo. ");
      }
      else
      {
        this->length = c;
        for (int i = 0; i < this->length; i++)
        {
          this->data[i] = tmpArray.data[i];
        }
      }
      tmpArray.free();
    }
  }

  /** Ler um array e manter apenas os seus valores impares
  */
  void odd (void)
  {
    Array <T> tmpArray(this->length, 0);
    if (!tmpArray.isValid())
    {
      println ("(odd) ERRO: Falta de espaco. ");
    }
    else
    {
      int c = 0;
      for (int i = 0; i < this->length; i++)
      {
        if (this->data[i] % 2 != 0)
        {
          tmpArray.data[c] = this->data[i];
          c++;
        }
      }
      if (c <= 0)
      {
        println ("Nenhum valor par foi encontrado no arranjo. ");
      }
      else
      {
        this->length = c;
        for (int i = 0; i < this->length; i++)
        {
          this->data[i] = tmpArray.data[i];
        }
      }
      tmpArray.free();
    }
  }

  /** Descobrir o maior valor de um array
   *  @returns O maior valor
  */
  T biggest (void)
  {
    T resultado = this->data[0];
    for (int i = 0; i < this->length; i++)
    {
      if (resultado < this->data[i])
      {
        resultado = this->data[i];
      }
    }
    return (resultado);    
  }

  /** Descobrir o menor valor de um array
   *  @returns O menor valor
  */
  T smallest (void)
  {
    T resultado = this->data[0];
    for (int i = 0; i < this->length; i++)
    {
      if (resultado > this->data[i])
      {
        resultado = this->data[i];
      }
    }
    return (resultado);    
  }

  /** Somar todos os valores de um array dado um certo intervalo
   *  @param Posicao inicial da busca
   *  @param Final inicial da busca
   *  @returns Soma dos valores
  */
  T addinterval (int inicio, int fim)
  {
    T result = 0;

    if (inicio > fim)
    {
      InvertValues<int>(&inicio, &fim);
    }
    if (inicio < 0 || fim > (length-1))
    {
      println ("ERRO: Intervalo invalido. ");
    }
    else
    {
      for (int i = inicio; i < fim; i++)
      {
        result += this->data[i];
      }
    }
    return (result);
  }

  /** Descobrir a media dos valores em um array dado um intervalo
   *  @param Posicao inicial da busca
   *  @param Final inicial da busca
   *  @returns Media dos valores
  */
  double average(int inicio, int fim )
  {
    double result = 0.0;
    if (inicio > fim) 
    {
      InvertValues<int>(&inicio, &fim);
    }
    if (inicio < 0 || fim > (length -1))
    {
      println ("ERRO: Intervalo invalido. ");
    }
    else
    {
      T soma = addinterval(inicio, fim);
      result = ((double)soma / (double)((fim-inicio)));
    }
    return (result);
  }

  bool CheckNegative (void)
  {
    bool result = false;
    int i = 0;
    while (i < this->length && this->data[i] < 0)
    {
      i++;
    }
    result = (i == this->length);
    return (result);
  }

  bool CheckAscending (void)
  {
    bool result = false;
    int i = 1;
    while (i < this->length && this->data[i-1] < this->data[i] )
    {
      i++;
    }
    result = (i == this->length);
    return (result);
  }

  bool CheckDescending (void)
  {
    bool result = false;
    int i = 1;
    while (i < this->length && this->data[i-1] > this->data[i] )
    {
      i++;
    }
    result = (i == this->length);
    return (result);
  }

  bool CheckValue (T value)
  {
    bool result = false;
    int i = 0;
    while (i < this->length && this->data[i] != value)
    {
      i++;
    }
    result = (i < this->length);
    return (result);
  }

  void scale (const T Const)
  {
    for (int i = 0; i < length; i++)
    {
      this->data[i] = (this->data[i] * Const);
    }
  }

  void ScaleInterval (const T Const, int initial, int final)
  {
    for (int i = initial; i < final; i++)
    {
      this->data[i] = (this->data[i] * Const);
    }
  }

  void descend (void)
  {
    int tmp = 0;
    int y = length-1;
    while (y > 0)
    {
      for (int i = 1; i < length; i++)
      {
        if (data[i-1] < data[i])
        {
          tmp = data[i];
          data[i] = data[i-1];
          data[i-1] = tmp;
        }
      }
      y--;   
    }
  }

  void ascend (void)
  {
    int tmp = 0;
    int y = length-1;
    while (y > 0)
    {
      for (int i = 1; i < length; i++)
      {
        if (data[i-1] > data[i])
        {
          tmp = data[i];
          data[i] = data[i-1];
          data[i-1] = tmp;
        }
      }
      y--;   
    }
  }

};

#endif

#ifndef _MYMATRIX_HPP
#define _MYMATRIX_HPP

template <typename T>
class Matrix
{
  private:
  int rows;
  int columns;
  T **data;
  int ix;
  int iy;

  public:
  Matrix (int r, int c)
  {
    ix = -1;
    iy = -1;
    rows = 0;
    columns = 0;
    data = nullptr;
    if (r > 0 && c > 0)
    {
      ix = 0;
      iy = 0;
      rows = r;
      columns = c;
      data = new T*[rows];
      for (int i = 0; i < this->rows; i++)
      {
        data[i] = new T[columns];
      }
    }
  }

  Matrix ()
  {
    ix = -1;
    iy = -1;
    rows = 0;
    columns = 0;
    data = nullptr;
  }

  void init(int r, int c)
  {
    if (r > 0 && c > 0)
    {
      ix = 0;
      iy = 0;
      rows = r;
      columns = c;
      data = new T*[rows];
      for (int i = 0; i < this->rows; i++)
      {
        data[i] = new T[columns];
      }
    }
  }

  void SetSize ()
  {
    int r = ReadPositiveInt("Forneca a quantidade de linhas da matrix.  ");
    int c = ReadPositiveInt("Forneca a quantidade de colunas da matrix. ");
    this->init(r, c);
  }

  bool IsValid()
  {
    bool result = false;
    if (this->rows > 0 && this->columns > 0 && this->data != null)
    {
      result = true;
    }
    return (result);
  }

  void set(int r, int c, T value)
  {
    if (r >= 0 && r < rows && c >= 0 && c < columns)
    {
      data[r][c] = value;
    }
  }

  T get (int r, int c)
  {
    T x;
    if (r >= 0 && r < rows && c >= 0 && c < columns)
    {
      x = data[r][c];
    }
    return (x);
  }

  int getrows ()
  {
    return (this->rows);
  }

  int getcolumns ()
  {
    return (this->columns);
  }

  int getix()
  {
    return (this->ix);
  }

  int getiy()
  {
    return(this->iy);
  }

  int getdimensions()
  {
    return (this->getcolumns() * this->getrows());
  }

  void write()
  {
    println ("");
    if (rows <= 0 && columns <= 0)
    {
      println ("ERRO: Dimensoes invalidas. ");
    }
    else
    {
      println ("Forneca os valores para a matrix: ");
      std::cout << std::endl;
      for (int r = 0; r < rows; r++)
      {
        for (int c = 0; c < columns; c++)
        {
          std::cout << std::setw(3) << r << "," << c << ":" << "\t";
          std::cin >> data[r][c]; 
        }
      }
      std::cout << std::endl;
    }
  }

  void print()
  {
    println ("");
    if (data == nullptr)
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      if (rows > 0 && columns > 0)
      {
        for (int x = 0; x < rows; x++)
        {
          for (int y = 0; y < columns; y++)
          {
            std::cout << std::setw(3) << data[x][y] << " ";
          }
          std::cout << std::endl;
        } 
      }
      std::cout << std::endl;
    }
  }

  void free()
  {
    if (data != nullptr)
    {
      delete(data);
      data = nullptr;
    }
  }

  void fwrite(const std::string fileName)
  {
    std::ofstream file;
    file.open (fileName);
    file << rows << std::endl << columns << std::endl;
    for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
      {
        file << data[x][y] << std::endl;
      }
    }
    file.close();
  }

  void fread(const std::string fileName)
  {
    int r = 0;
    int c = 0;
    std::ifstream file;
    file.open (fileName);
    if (!(file >> r))
    {
      std::cout << "O arquivo [" << fileName << "] nao pode ser aberto. ";
    }
    else
    {
      file >> c;
      if (r <= 0 && c <= 0)
      {
        println ("(fread) ERRO: Dimensoes invalidas. ");
      } 
      else
      {
        this->init(r, c);
        for (int x = 0; x < rows; x++)
        {
          for (int y = 0; y < columns; y++)
          {
            file >> this->data[x][y];
          }
        }
      }
    }
    file.close();
  }

  void random (int initial, int final)
  {
    srand(time(0));
    for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
      {
        data[x][y] = rand() % (final - initial + 1) + initial; 
      }
    }
  }

  void copy (Matrix <T> matrix)
  {
    if (matrix.IsValid())
    {
      this->init(matrix.rows, matrix.columns);
      for (int x = 0; x < matrix.rows; x++)
      {
        for (int y = 0; y < matrix.columns; y++)
        {
          this->data[x][y] = matrix.data[x][y];
        }
      }
    }
  }

  bool operator== (Matrix <T> matrix)
  {
    bool result = false;
    if (matrix.IsValid() && this->IsValid())
    {
      if (matrix.rows == this->rows && matrix.columns == this->columns)
      {
        int x = 0;
        int y = 0;
        result = true;
        while (x < this->rows && result)
        {
          y = 0;
          while (y < this->columns && result)
          {
            result = (result && (matrix.data[x][y] == this->data[x][y]));
            y++;
          }
          x++;
        }
      }
    }
    return (result);
  }

  void operator=  (Array <T> array)
  {
    int size = array.getlength();
    int r = 2;
    int c = 0;
    bool odd = 0;
    if (size % 2 == 0)
    {
      c = (size/2.0);
    }
    else
    {
      c = ((size/2.0)+0.5);
      odd = 1;
    }
    if (r <= 0 || c <= 0)
    {
      println ("ERRO: Conversao invalida. ");
    }
    else
    {
      this->rows = r;
      this->columns = c;
      int i = 0;
      for (int x = 0; x < rows; x++)
      {
        for (int y = 0; y < columns; y++)
        {
          this->data[x][y] = array.get(i);
          i++;
        }
      }
      if (odd)
      {
        this->data[(rows-1)][(columns-1)] = 0;
      }
    }
  }

  Matrix operator+ (Matrix <T> matrix)
  {
    Matrix <T> result(0, 0);
    if (matrix.IsValid())
    {
      if (matrix.rows != this->rows || this->columns != matrix.columns)
      {
        println ("ERRO: Dimensoes incompativeis. ");
      }
      else
      {
        result.init(rows, columns);
        if (!result.IsValid())
        {
          println ("ERRO: Falta de espaco. ");
        }
        else
        {
          for (int x = 0; x < rows; x++)
          {
            for (int y = 0; y < columns; y++)
            {
              result.data[x][y] = (matrix.data[x][y] + this->data[x][y]);
            }
          }
        }
      }
    }
    return (result);
  }

  Matrix operator* (const int Const)
  {
    Matrix <T> result(0,0);
    if (this->IsValid())
    {
      result.init(rows,columns);
      if (!result.IsValid())
      {
        println ("ERRO: Falta de espaco. ");
      }
      for (int x = 0; x < rows; x++)
      {
        for (int y = 0; y < columns; y++)
        {
          result.data[x][y] = (this->data[x][y] * Const);
        }
      }
    }
    return (result);
  }

  Matrix operator* (Matrix <T> matrix)
  {
    Matrix <T> result(0,0);
    if (matrix.IsValid())
    {
      if (matrix.rows != this->columns || this->rows != matrix.columns)
      {
        println ("ERRO: Dimensoes incompativeis. ");
      }
      else
      {
        result.init(this->rows, matrix.columns);
        if (result.IsValid())
        {
          for (int x = 0; x < this->rows; x++)
          {
            for (int y = 0; y < matrix.columns; y++)
            {
              result.data[x][y] = 0;
              for (int z = 0; z < matrix.rows; z++)
              {
                result.data[x][y] += (this->data[x][z] * matrix.data[z][y]);
              }
            }
          }
        }
      }
    }
    return (result);
  }

  Matrix ScaleRow (int r, const int Const)
  {
    Matrix <T> result (0, 0);
    if (r < 0 || r > (rows-1))
    {
      println ("ERRO: Posicao invalida. ");
    }
    else
    {
      result.copy(*this);
      if (!result.IsValid())
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (int y = 0; y < columns; y++)
        {
          result.data[r][y] = (this->data[r][y] * Const);
        }
      }
    }
    return (result);
  }

  Matrix AddRows (int row1, int row2, int Frow)
  {
    Matrix <T> result(0, 0);
    int Trows = (this->rows - 1);
    if (row1 < 0 || row1 > Trows || row2 < 0 || row2 > Trows || Frow < 0 || Frow > Trows)
    {
      println ("ERRO: Tamanhos invalidos. ");
    }
    else
    {
      result.copy(*this);
      if (!result.IsValid())
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (int y = 0; y < columns; y++)
        {
          result.data[Frow][y] = (this->data[row1][y] + this->data[row2][y]);
        }
      }
    }
    return (result);
  }

  /** Somar linhas de uma matrix com a segunda sendo escalada por uma constante
   *  @param Linha a ser somada
   *  @param Linha a ser somada
   *  @param Linha do resultado da soma
   *  @param Constante para definir o escalamento
   *  @returns Matrix com a soma de 2 linhas com a segunda sendo escalada
  */
  Matrix AddScaledRows (int row1, int row2, int Frow, const int Const)
  {
    Matrix <T> result(0, 0);
    int Trows = (this->rows - 1);
    if (row1 < 0 || row1 > Trows || row2 < 0 || row2 > Trows || Frow < 0 || Frow > Trows)
    {
      println ("ERRO: Tamanhos invalidos. ");
    }
    else
    {
      result.copy(*this);
      if (!result.IsValid())
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (int y = 0; y < columns; y++)
        {
          result.data[Frow][y] = (this->data[row1][y] + (this->data[row2][y] * Const));
        }
      }
    }
    return (result);
  }

  /** Subtrair linhas de uma matrix com a segunda sendo escalada por uma constante
   *  @param Linha a ser subtraida
   *  @param Linha a ser subtraida
   *  @param Linha do resultado da subtracao
   *  @param Constante para definir o escalamento
   *  @returns Matrix com a ssubtracao de 2 linhas com a segunda sendo escalada
  */
  Matrix SubtractScaledRows (int row1, int row2, int Frow, const int Const)
  {
    Matrix <T> result(0, 0);
    int Trows = (this->rows - 1);
    if (row1 < 0 || row1 > Trows || row2 < 0 || row2 > Trows || Frow < 0 || Frow > Trows)
    {
      println ("ERRO: Tamanhos invalidos. ");
    }
    else
    {
      result.copy(*this);
      if (!result.IsValid())
      {
        println ("ERRO: Falta de espaco. ");
      }
      else
      {
        for (int y = 0; y < columns; y++)
        {
          result.data[Frow][y] = (this->data[row1][y] - (this->data[row2][y] * Const));
        }
      }
    }
    return (result);
  }

  bool CheckIdentity ()
  {
    int x = 0;
    int y = 0;
    int i = 1;
    bool result = true;
    if (rows != columns)
    {
      result = false;
    }
    else
    {
      while (x < rows && result)
      {
        while (y < columns)
        {
          if (i == 1)
          {
            result = (result && this->data[x][y] == 1);
          }
          else
          {
            result = (result && this->data[x][y] == 0);
          }
          y++;
          i--;
        }
        x++;
        i = (x+1);
      }
    }
    return (result);
  }

  void find (int z)
  {
    int x = 0;
    int y = 0;
    ix = -1;
    iy = -1;
    while (x < rows && ix == -1)
    {
      y = 0;
      while (y < columns && iy == -1)
      {
        if (this->data[x][y] == z)
        {
          ix = x;
          iy = y;
        }
        y++;
      }
      x++;
    }
  }

  void WriteAscending (const int Const)
  {
    int i = 1;
    for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
      {
        this->data[x][y] = (i*Const);
        i++;
      }
    }
  }
  
  void WriteDescending (const int Const)
  {
    int i = (rows*columns);
    for (int x = 0; x < rows; x++)
    {
      for (int y = 0; y < columns; y++)
      {
        this->data[x][y] = (i*Const);
        i--;
      }
    }
  }

  Matrix transpose ()
  {
    Matrix <T> result(0, 0);
    if (this->IsValid())
    {
      result.init(columns, rows);
      if (!result.IsValid())
      {
        println("ERRO: Dados invalidos. ");
      }
      else
      {
        for (int x = 0; x < result.rows; x++)
        {
          for (int y = 0; y < result.columns; y++)
          {
            result.data[x][y] = this->data[y][x];
          }
        }
      }
    }
    return (result);
  }

};
#endif

#ifndef _MYSTRING_HPP
#define _MYSTRING_HPP

class PString
{
  private:
  int length;
  std::string data;

  public:

  PString (std::string other)
  {
    length = other.length();
    data.resize(length);
    data = other;
  }

  ~PString (void)
  {
    length = 0;
    data = "N/A";
  }

  void resize (int n)
  {
    if (n > 0)
    {
      data.resize(n);
      this->length = n;
    }
  }

  void copy (const PString& other)
  {
    if (other.length > 0)
    {
      this->resize(other.length);
      for (int i = 0; i < length; i++)
      {
        this->data[i] = other.data[i];
      }
    }
  }

  void operator= (std::string str)
  {
    PString result(str);
    if (result.length <= 0)
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      this->copy(result);
    }
  }

  void write (const std::string text)
  {
    PString result("");
    std::string str = ReadString(text);
    result = str;
    if (result.length <= 0)
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      this->copy(result);
    }
    println("");
  }

  void print (void)
  {
    if (this->length <= 0)
    {
      println ("ERRO: Objeto invalido. ");
    }
    else
    {
      for (int i = 0; i < length; i++)
      {
        std::cout << this->data[i];
      }
      std::cout << std::endl;
    }
  }

  void fwrite (const std::string text)
  {
    if (length > 0)
    {
      std::fstream file;
      file.open(text, std::ios::out);
      file << length << std::endl << data << std::endl;
      file.close();
    }
  }

  void fread (const std::string text)
  {
    int Flen = 0;
    std::string Fdata = "";

    std::fstream file;
    file.open(text, std::ios::in);

    file >> Flen;
    std::getline(file, Fdata);
    std::getline(file, Fdata);

    PString tmp (Fdata);
    this->copy(tmp);
  }

  std::string get (void)
  {
    return (data);
  }

  int getLength (void)
  {
    return (this->length);
  }

  int getInt (void)
  {
    int result = -1;
    if (length > 0)
    {
      bool negative = false;
      int i = 0;

      if (data[0] == '-')
      {
        negative = true;
        i++;
      }

      result = 0;
      while (i < length)
      {
        if ((data[i] >= '0' && data[i] <= '9' ))
        {
          result += (int)((data[i]-48))*(int)(pow(10, length-1-i));
        }
        else
        {
          i = length;
          result = -1;
        }
        i++;
      }
      if (negative)
      {
        result *= -1;
      }

    }
    return(result);
  }

  double getDouble (void)
  {
    double result = 0.0;

    if (length > 0)
    {
      bool negative = false;
      int dot = -1;
      int i = 0;
      int y = 0;

      if (data[0] == '-')
      {
        negative = true;
        i++;
        y++;
      }

      while (i < length)
      {
        if (data[i] == ',' || data[i] == '.')
        {
          dot = i;
        }
        else if (data[i] >= '0' && data[i] <= '9')
        {
          y++;
          result += (double)(data[i]-48)*(double)(pow(10, length-y));
        }
        else
        {
          result = -1;
          i = length;
        }
        i++;
      }

      if (dot > 0)
      {
        for (int i = dot; i < length; i++)
        {
          result /= 10;
        }
      }

      if (negative)
      {
        result *= -1.0;
      }
    }
    return (result); 
  }

  bool getBool (void)
  {
    bool result = false;
    if (length > 0)
    {
      if (length == 1)
      {
        result = (data[0] == '1' || data[0] == 'T');
      }
      else if (length == 4)
      {
        int i = 0;
        while (i < length)
        {
          result = (data[0] == 't' && data[1] == 'r' && data[2] == 'u' && data[3] =='e');
          i++;
        }
      }
    }
    return (result);
  }

  bool find (std::string other)
  {
    bool result = false;
    int size = other.length();
    if (length > 0 && size > 0)
    {
      for (int i = 0; i < length; i++)
      {
        if (this->data[i] == other[0])
        {
          result = true;
          for (int y = 0; y < size; y++)
          {
            result = (result && (this->data[i+y] == other[y]));
          }
        }
      }
    }
    return (result);
  }

  std::string replace (const char Old, const char New)
  {
    std::string result = this->data;
    if (length > 0)
    {
      for (int i = 0; i < length; i++)
      {
        if (result[i] == Old)
        {
          result[i] = New;
        }
      }
    }
    return (result);
  }

  std::string toUpper (void)
  {
    std::string result = this->get();
    for (int i = 0; i < length; i++)
    {
      if (data[i] >= 'a' && data[i] <= 'z')
      {
        result[i] = data[i] - 32;
      }
    }
    
    return (result);
  }

  std::string toLower (void)
  {
    std::string result = this->get();
    for (int i = 0; i < length; i++)
    {
      if (data[i] >= 'A' && data[i] <= 'Z')
      {
        result[i] = data[i] + 32;
      }
    }
    
    return (result);
  }

  std::string encrypt (int key)
  {
    std::string result = this->toUpper();
    for (int i = 0; i < length; i++)
    {
      if (result[i] >= 'A' && result[i] <= 'Z')
      {
        result[i] = result[i] + key;
        if (result[i] > 90)
        {
          result[i] = (result[i] - 90) + 64;
        }
      }
    }
    return (result);
  }

  std::string decrypt (int key)
  {
    std::string result = this->get();
    for (int i = 0; i < length; i++)
    {
      if (result[i] >= 'A' && result[i] <= 'Z')
      {
        result[i] = result[i] - key;
        if (result[i] < 65)
        {
          result[i] = 90 - (result[i] - 64);
        }
      }
    }
    return (result);
  }

  int split (Array <std::string>& words, char delimiter)
  {
    int y = 0;
    if (length > 0)
    {
      std::string tmp = "";
      tmp.resize(length);
      words.init((length+1)/2.0);
      for (int i = 0; i < length; i++)
      {
        if (data[i] != delimiter)
        {
          tmp[i] = data[i];
        }
        else
        {
          words.set(y, tmp);
          tmp = "";
          tmp.resize(length);
          y++;
        }
      }
      words.set(y, tmp);

      // Reduzir tamanho do array
      while (words.get((words.getlength() - 1)) == "")
      {
        Array <std::string> TMP(words);
        words.init((words.getlength() - 1));
        for (int i = 0; i < words.getlength(); i++)
        {
          words.set(i, TMP.get(i));
        }
      }
    }
    return (y+1);
  }

  std::string invert (void)
  {
    int i = 0;
    int y = length-1;
    std::string result = data;
    while (i < length)
    {
      result[i] = data[y];
      i++;
      y--;
    }
    return (result);
  }

};

#endif

template <typename T>
class Cell
{
  private:

  T data;
  Cell* link;

  public:

  // Constructor
  Cell (T value, Cell* ptr)
  {
      this->data = value;
      this->link = ptr;
  }

  // Return Cell data
  T getData()
  {
      return (data);
  }

  // Set Cell data
  void setData(T x)
  {
      data = x;
  }

  // Return Cell link
  Cell* getLink()
  {
      return (link);
  }

  // Set Cell link
  void setLink (Cell* x)
  {
      link = x;
  }

  // Show all linked Cells from origin data
  void print ()
  {
    std::cout << '[' << data << ']' << std::endl;
    if (link)
    {
        this->link->print();
    }
    else
    {
        std::cout << std::endl;
    }
  }

  // Set all linked Cells from origin to 0 and desconnect them
  void free ()
  {
    if (link)
    {
        this->link->free();
    }
    this->data = 0;
    this->link = null;
  }

  // Add Cell to the end
  void PushBack (T value)
  {
    if (link)
    {
        link->PushBack(value);
    }
    else
    {
        link = new Cell<T> (value, null);
    }
  }

  // Add [n] Cells to the end
  void AddCells (int n)
  {
    if (link)
    {
        link->AddCells(n);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            this->PushBack((T)0);
        }
    }
  }

  void WriteCells ()
  {
    std::cout << "Forneca um elemento para a celula [" << Count(0) <<  "] : ";
    this->data = ReadT<T>(" ");
    if (link)
    {
      link->WriteCells();
    }
  }

  void WriteCellsB (const std::string x, int i)
  {
    this->data = x[i];
    if (link)
    {
      link->WriteCellsB(x, i+1);
    } 
  }

  // Remove last Cell
  void PopBack ()
  {
    if (link)
    {
        if (link->link)
        {
            link->PopBack();
        }
        else
        {
            link->data = 0;
            link = null;
        }
    }
  }

  // Add Cell to the start
  void PushFront (T value)
  {
    link = new Cell<T> (data, link);
    data = value;
  }

  // Remove first Cell
  void PopFront ()
  {
    if (link)
    {
        data = link->data;
        if (link->link)
        {
            link->PopFront();
        }
        else
        {
            link->data = 0;
            link = null;
        }
    }
  }

  // Return the number of Cells
  int Count (int x)
  {
    x++;
    if (link)
    {
        return this->link->Count(x);
    }
    else
    {
        return (x);
    }
  }

  int GetCount ()
  {
    return (this->Count(0));
  }

  // Add Cell in the middle
  void PushMid (T value)
  {
    Cell *ptr = null;
    if (link)
    {
        int c = this->Count(0);
        int mid = ((double)c / 2.0);
        ptr = this;
        
        int w = (mid-1);
        for (int i = 0; i < w; i++)
        {
            ptr = ptr->link;
        }
        Cell *b = new Cell<T>(value, ptr->link);
        ptr->link = b;
    }
  }

  // Remove middle Cell
  void PopMid ()
  {
    Cell *ptr = null;
    if (link)
    {
        int c = this->Count(0);
        int mid = ((double)c / 2.0);
        ptr = this;
        
        int w = (mid-1);
        for (int i = 0; i < w; i++)
        {
            ptr = ptr->link;
        }
        ptr->data = 0;
        delete (ptr->link);
        ptr->link = ptr->link->link; 
    }
  }

  // Adicionar uma celula em uma posicao [p]
  void insert (T value, int p)
  {
    Cell *ptr = null;
    if (link)
    {
        if (this->Count(0) < p)
        {
            println ("ERRO: Posicao invalida. ");
        }
        else
        {
            ptr = this;
            for (int i = 0; i < p; i++)
            {
                ptr = ptr->link;
            }
            ptr->PushFront(value);
        }
    }
  }

  // Remover uma celula de posicao [p]
  void remove (int p)
  {
    Cell *ptr = null;
    if (link)
    {
        if (this->Count(0) < p)
        {
            println ("ERRO: Posicao invalida. ");
        }
        else
        {
            ptr = this;
            for (int i = 0; i < p; i++)
            {
                ptr = ptr->link;
            }
            ptr->PopFront();
        }
    }
  }

  // Retornar apontador para uma celula com o valor fornecido
  Cell* find (T value)
  {
    Cell *ptr = null;
    if (data == value)
    {
        ptr = this;
    }
    else if (link)
    {
        ptr = this;
        int c = Count(0);
        int i = 0;
        while (i < c && ptr->data != value)
        {
            i++;
            ptr = ptr->link;
        }
    }
    return (ptr);
  }

  // Separar caracteres ate delimitador
  void tok (T dlm)
  {
    Cell *ptr = null;
    if (link)
    {
      if (link->data == dlm)
      {
        ptr = this;
        ptr->link->free();
        ptr->link = null;
      }
      else
      {
        this->link->tok(dlm);
      }
    }
  }

  Cell *prefix (const std::string prefix)
  {
    Cell *result = null;
    int size = Count(0);
    int psize = prefix.length();
    if (psize > size)
    {
      println ("ERRO: Tamanho de prefixo invalido. ");
    }
    else
    {
      Cell *ptr = this;
      result = ptr;
      int i = 0;
      int w = 0;
      while (i < size && w < psize)
      {
        if (ptr->data == ' ')
        {
          ptr = ptr->link;
          result = ptr;;
          i++;
        }
        if (ptr->data == prefix[w])
        {
          w++;
        }
        else
        {
          w = 0;
        }
        ptr = ptr->link;
        i++;
      }
      if (w < psize)
      {
        result = null;
      }
    }
    return (result);
  }

  Cell *sufix (const std::string sufix)
  {
    Cell *result = null;
    int size = Count(0);
    int psize = sufix.length();
    if (psize > size)
    {
      println ("ERRO: Tamanho de sufixo invalido. ");
    }
    else
    {
      result = this;
      Cell *ptr = this;
      int i = 0;
      int w = 0;
      while (i < size && w < psize)
      {
        if (ptr->data == ' ')
        {
          ptr = ptr->link;
          result = ptr;
          i++;
        }
        else if (ptr->data == sufix[w])
        {
          w++;
        }
        else
        {
          w = 0;
        }
        ptr = ptr->link;
        i++;
      }
      if (w < psize)
      {
        result = null;
      }
    }
    return (result);
  }

  bool operator== (Cell& other)
  {
    bool result = false;
    if (other.link)
    {
      int size = Count(0);
      if (size == other.Count(0))
      {
        result = true;
        int i = 0;
        while (i < size && result)
        {
          result = (this->data == other.data);
          i++;
        }
        if (i < size)
        {
          result = false;
        }
      }
    }
    return (result);
  }

  void concat (Cell& other)
  {
    if (other.data)
    {
      if (!link)
      {
        link = &other;
      }
      else
      {
        Cell *ptr = this;
        while (ptr->link)
        {
          ptr = ptr->link;
        }
        ptr->link = &other;
      }
    }
  }

  Cell *copy (void)
  {
    Cell<T>* result = new Cell<T>((T)0, null);
    if (result)
    {
      int size = this->Count(0);
      result->AddCells(size-1);

      Cell *Rptr = result;
      Cell *Tptr = this;

      for (int i = 0; i < size; i++)
      {
        Rptr->data = Tptr->data;
        Rptr = Rptr->link;
        Tptr = Tptr->link;
      }
    }
    return (result);
  }

  Cell *ascend (void)
  {
    Cell<T>* result = this->copy();
    if (result)
    {
      int size = result->Count(0);
      if (size > 1)
      {
        Cell *back = result;
        int y = size-1;
        int i = 0;
        while (y > 0)
        {
          back = result;
          i = 0;
          while (i < size && back->link)
          {
            if (back->data > back->link->data)
            {
              int tmp = back->link->data;
              back->link->data = back->data;
              back->data = tmp;
            }
            back = back->link;
            i++;
          }
          y--;
        }
      }
    }
    return (result);
  }

  Cell *intercalate (Cell& other)
  {
    Cell<T>* result = new Cell<T>((T)0, null);
    
    if (result)
    {
      Cell *cell_a = this;
      Cell *cell_b = &other;

      int size_a = cell_a->Count(0);
      int size_b = cell_b->Count(0);
      int size_r = (size_a + size_b);

      result->AddCells(size_r -1);
      
      Cell *back = result;

      bool end_a = false;
      bool end_b = false;
      for (int i = 0; i < size_r; i++)
      {
        if ((i % 2 == 0 || end_b) && !end_a)
        {
          back->data = cell_a->data;
          back = back->link;
          if (cell_a->link)
          {
            cell_a = cell_a->link;
          }
          else
          {
            end_a = true;
          }
        }
        else if (!end_b)
        {
          back->data = cell_b->data;
          back = back->link;
          if (cell_b->link)
          {
            cell_b = cell_b->link;
          }
          else
          {
            end_b = true;
          }
        }
      }
    }
    return (result);
  }

    Cell *intercalateUp (Cell& other)
    {
      Cell<T>* result = new Cell<T>((T)0, null);
      if (result)
      {
        result = this->intercalate(other);
        result = result->ascend();
      }
      return (result);
    }

};

typedef Cell<int >* ref_int_Cell ;
typedef Cell<char>* ref_char_Cell;
typedef Cell<double>* ref_double_Cell;
