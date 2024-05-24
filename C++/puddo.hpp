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
    println (text);
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
  int x = 0;
  println (text);
  std::cin >> x;
  getchar( );
  return (x);
}

int ReadPositiveInt (std::string text)
{
  int x = 0;
  do
  { 
    println (text);
    std::cin >> x;
    getchar();
  } while (x <= 0);
  return (x);
}

int IntRandom (int x, int y)
{
  int resultado = rand() % x + y;
  return (resultado);
}

void IntInvertValues(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
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

  Array (void)
  {
    length   = 0;
    data = nullptr;
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
      length = other.length;
      data = new T[other.length];
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
      IntInvertValues(&initial, &final);
    }
    if (min > max)
    {
      IntInvertValues(&min, &max);
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
      IntInvertValues(&inicio, &fim);
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
      IntInvertValues(&inicio, &fim);
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
  T optional;
  T **data;

  public:
  Matrix (int r, int c, T initial)
  {
    optional = initial;
    rows = 0;
    columns = 0;
    data = nullptr;
    if (r > 0 && c > 0)
    {
      rows = r;
      columns = c;
      data = new T*[rows];
      for (int i = 0; i < this->rows; i++)
      {
        data[i] = new T[columns];
      }
    }
  }

  Matrix (void)
  {
    rows = 0;
    columns = 0;
    data = nullptr;
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

  void set(int r, int c, int value)
  {
    if (r >= 0 && r < rows && c >= 0 && c < columns)
    {
      data[r][c] = value;
    }
  }

  T get (int r, int c)
  {
    T x = optional;
    if (r >= 0 && r < rows && c >= 0 && c < columns)
    {
      x = data[r][c];
    }
  }

  int getrows ()
  {
    int rows = this->rows;
    return (rows);
  }

  int getcolumns ()
  {
    int columns = this->columns;
    return (columns);
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
      for (int r = 0; r < rows; r++)
      {
        for (int c = 0; c < columns; c++)
        {
          std::cout << std::setw(3) << r << "," << c << ":" << "\t";
          std::cin >> data[r][c]; 
        }
      }
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
        rows = r;
        columns = c;
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

  bool CheckIdentity ()
  {
    int x = 0;
    int y = 0;
    int i = 1;
    bool result = true;
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
    return (result);
  }

};
#endif