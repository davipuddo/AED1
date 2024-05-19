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

  Array ()
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

  bool operator== (const Array <T> other)
  {
    bool resultado = false;
    int i = 0;
    if (other.length == 0 || length != other.length)
    {
      println ("ERRO: Dado invalido. ");
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
    static Array <int> resultado (other);
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
          resultado.data[i] += this->data[i];
        }
      }
    }
    return (resultado);
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
  int getlength ()
  {
    return (length);
  }

  /** Descobrir se um array possui tamanho e dados e valido
   * 
  */
  bool isValid ()
  {
    bool result = (this->data != nullptr && this->length > 0);
    return (result);
  }

  /** Mostrar todos os valores de um array
   * 
  */
  void print ()
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
  void write ()
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
  void random (int inferior, int superior)
  {
    srand(time(0));
    if (length <= 0)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      for (int i = 0; i < length; i++)
      {
        data[i] = rand() % (superior - inferior + 1) + inferior;
      }
    }
  }

  /** Ler um array e manter apenas os seus valores pares
  */
  void even ()
  {
    Array <T> tmpArray(this->length, 0);
    if (length <= 0)
    {
      println ("ERRO: Tamanho invalido. ");
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
  void odd ()
  {
    Array <T> tmpArray(this->length, 0);
    if (length <= 0)
    {
      println ("ERRO: Tamanho invalido. ");
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
  T biggest ()
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
  T smallest ()
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
    if (inicio < 0 || fim > length)
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
    if (inicio < 0 || fim > length)
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

  bool CheckNegative ()
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

  bool CheckAscending ()
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

  bool CheckDescending ()
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

  Matrix ()
  {
    rows = 0;
    columns = 0;
    data = nullptr;
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
          std::cout << std::setw(3) << r << "," << c << ":" << std::setw(3);
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
};
#endif