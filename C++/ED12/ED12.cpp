//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


void ED0X01 (void)
{
  // Identificacao de dados
  Matrix <int> matrix(2, 2);
  int n = 0;

  // Apresentacao
  println ("ED0X01");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  n = ReadPositiveInt("Forneca a quantidade de valores a serem gerados: ");
  Array <int> array(n, 0);
  if (array.getlength() <= 0)
  {
    println ("(array) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Dar valores aleatorios ao array
    array.random(0, (array.getlength()-1), 0, 100);
    if (!array.isValid())
    {
      println ("(array) ERRO: Falta de espaco. ");
    }
    else
    {
      // Converter array para matrix
      matrix = array;

      // Mostrar matrix
      println ("Matrix -");
      matrix.print();

      // Liberar dados da memoria
      array.free();
      matrix.free();
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X02 (void)
{
  // Identificacao de dados
  Matrix <int> Fmatrix(0, 0);
  Matrix <int> resultado(0, 0);
  Matrix <int> matrix(0, 0);
  int constante = 0;

  // Apresentacao
  println ("ED0X02");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  Fmatrix.SetSize();
  Fmatrix.write();

  // Escrever matrix no arquivo
  Fmatrix.fwrite("DADOS02.TXT");

  // Liberar matrix da memoria
  Fmatrix.free();

  // Ler matrix do arquivo
  matrix.fread("DADOS02.TXT");

  // Verificar dados
  if (matrix.IsValid())
  {   
    // Verificar dados
    if (matrix.IsValid())
    {
      // Escalar matrix
      constante = ReadInt("Forneca a constante para definir o escalamento da matrix: ");
      resultado = matrix * constante;
      if (resultado.IsValid())
      {
        // Mostrar dados
        println ("Matrix escalada -");
        resultado.print();
      }
    }
    // Liberar matrix da memoria
    matrix.free();
    resultado.free();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X03 (void)
{
  // Identificacao de dados
  Matrix <int> Fmatrix(0, 0);
  Matrix <int> matrix(0, 0);
  bool resultado = false;

  // Apresentacao
  println ("ED0X03");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix.SetSize();

  // Verificar dimensoes
  if (Fmatrix.getcolumns() <= 0 || Fmatrix.getrows() <= 0)
  {
    println ("ERRO: Dimensoes invalidas. ");
  }
  else
  {
    // Ler valores para a matrix
    Fmatrix.write();

    // Verificar dados
    if (!Fmatrix.IsValid())
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever dados no arquivo
      Fmatrix.fwrite("DADOS03.TXT");

      // Liberar matrix da memoria
      Fmatrix.free();

      // Ler dados do arquivo
      matrix.fread("DADOS03.TXT");

      // Verificar dimensoes
      if (matrix.IsValid())
      {
        // Verificar se a matrix e a matrix identidade
        resultado = matrix.CheckIdentity();

        // Mostrar dados
        if (resultado)
        {
          println ("A matrix fornecida e a matrix identidade. ");
        }
        else
        {
          println ("A matrix fornecida nao e a matrix identidade. ");
        }
        println ("Matrix -");
        matrix.print();

        // Liberar matrix da memoria
        matrix.free();
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X04 (void)
{
  // Identificacao de dados
  Matrix <int> Fmatrix1(0, 0);
  Matrix <int> Fmatrix2(0, 0);
  Matrix <int> matrix1(0, 0);
  Matrix <int> matrix2(0, 0);
  bool resultado = false;

  // Apresentacao
  println ("ED0X04");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix1.SetSize();

  // Verificar dimensoes
  if (Fmatrix1.getdimensions() <= 0)
  {
    println ("ERRO: Dimensoes invalidas. ");
  }
  else
  {
    // Ler valores para a matrix 
    Fmatrix1.write();

    // Ler tamanho da matrix
    Fmatrix2.SetSize();

    // Verificar dimensoes
    if (Fmatrix2.getdimensions() <= 0)
    {
      println ("ERRO: Dimensoes invalidas. ");
    }
    else
    {
      // Ler valores para a matrix
      Fmatrix2.write();

      // Verificar dados
      if (!Fmatrix1.IsValid() || !Fmatrix2.IsValid())
      {
        println ("ERRO: Dados invalidos. ");
      }
      else
      {
        // Escrever matrizes nos arquivos
        Fmatrix1.fwrite("DADOS0401.TXT");
        Fmatrix2.fwrite("DADOS0402.TXT");

        // Liberar matrizes da memoria
        Fmatrix1.free();
        Fmatrix2.free();

        // Ler matrizes dos arquivos
        matrix1.fread("DADOS0401.TXT");
        matrix2.fread("DADOS0402.TXT");

        // Verificar dados
        if (!matrix1.IsValid() || !matrix2.IsValid())
        {
          println ("ERRO: Dados invalidos. ");
        }
        else
        {
          // Verificar igualdade das matrizes
          resultado = matrix1 == matrix2;

          // Mostrar dados
          if (resultado)
          {
            println ("As matrizes sao iguais. ");
          }
          else
          {
            println ("As matrizes sao diferentes. ");
          }
          println ("Matriz 1 -");
          matrix1.print();
          println ("Matriz 2 -");
          matrix2.print();

          // Liberar matrizes da memoria
          matrix1.free();
          matrix2.free();
        }
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X05 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X05");
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

void ED0X06 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X06");
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