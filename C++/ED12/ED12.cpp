//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"

void ED1201 (void)
{
  // Identificacao de dados
  Matrix <int> matrix(2, 2);
  int n = 0;

  // Apresentacao
  println ("ED1201");
  println ("");                  // Pular uma linha
  println ("Ler e gerar uma quantidade [n] de valores aleatorios dentro de um intervalo e guarda-los em uma matrix. ");
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

void ED1202 (void)
{
  // Identificacao de dados
  Matrix <int> matrix   (0, 0);
  Matrix <int> Fmatrix  (0, 0);
  Matrix <int> resultado(0, 0);
  int constante = 0;

  // Apresentacao
  println ("ED1202");
  println ("");                  // Pular uma linha
  println ("Escalar uma matrix por uma constante. Para testar receber a matrix de um arquivo. ");
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

void ED1203 (void)
{
  // Identificacao de dados
  Matrix <int> matrix (0, 0);
  Matrix <int> Fmatrix(0, 0);
  bool resultado = false;

  // Apresentacao
  println ("ED1203");
  println ("");                  // Pular uma linha
  println ("Testar se uma matrix e a matrix identidade. Para testar receber a matrix de um arquivo. ");
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

void ED1204 (void)
{
  // Identificacao de dados
  Matrix <int> matrix1 (0, 0);
  Matrix <int> matrix2 (0, 0);
  Matrix <int> Fmatrix1(0, 0);
  Matrix <int> Fmatrix2(0, 0);
  bool resultado = false;

  // Apresentacao
  println ("ED1204");
  println ("");                  // Pular uma linha
  println ("Fazer um operador para testar a igualdade de duas matrizes. Para testar receber matrizes de 2 arquivos. ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix1.SetSize();

  // Verificar dimensoes
  if (!Fmatrix1.IsValid())
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
    if (!Fmatrix2.IsValid())
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

void ED1205 (void)
{
  // Identificacao de dados
  Matrix <int> matrix1  (0, 0);
  Matrix <int> matrix2  (0, 0);
  Matrix <int> Fmatrix1 (0, 0);
  Matrix <int> Fmatrix2 (0, 0);
  Matrix <int> resultado(0, 0);

  // Apresentacao
  println ("ED1205");
  println ("");                  // Pular uma linha
  println ("Somar duas matrizes. Para testar receber matrizes de dois arquivos. ");
  println ("");                  // Pular uma linha
    
   // Ler dimensoes da matrix
  Fmatrix1.SetSize();

  // Verificar dimensoes
  if (!Fmatrix1.IsValid())
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
    if (!Fmatrix2.IsValid())
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
        Fmatrix1.fwrite("DADOS0501.TXT");
        Fmatrix2.fwrite("DADOS0502.TXT");

        // Liberar matrizes da memoria
        Fmatrix1.free();
        Fmatrix2.free();

        // Ler matrizes dos arquivos
        matrix1.fread("DADOS0501.TXT");
        matrix2.fread("DADOS0502.TXT");

        // Verificar dados
        if (!matrix1.IsValid() || !matrix2.IsValid())
        {
          println ("ERRO: Dados invalidos. ");
        }
        else
        {
          // Somar matrizes
          resultado = (matrix1 + matrix2);

          // Mostrar dados
          println("Matrix 1 -");
          matrix1.print();
          println("Matrix 2 -");
          matrix2.print();
          println("Soma -");
          resultado.print();

          // Liberar matrizes da memoria
          matrix1.free();
          matrix2.free();
          resultado.free();
        }
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1206 (void)
{
  // Identificacao de dados
  Matrix <int> matrix (0, 0);
  Matrix <int> Fmatrix(0, 0);
  Matrix <int> resultado (0, 0);

  int linha1 = 0;       // Linha a ser somada
  int linha2 = 0;       // Linha a ser somada
  int Lsoma  = 0;       // Linha do resultado da soma
  int constante = 0;

  // Apresentacao
  println ("ED1206");
  println ("");                  // Pular uma linha
  std::cout << "Operar duas linhas de uma matrix, guardando no primeiro lugar, as somas de cada elemento da primeira linha com o";
  println ("respectivo da segunda linha multiplicado por uma constante. ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix.SetSize();
  
  // Verificar dimensoes
  if (!Fmatrix.IsValid())
  {
    println ("ERRO: Dimensoes invalidass. ");
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
      // Escrever matrix no arquivo
      Fmatrix.fwrite("DADOS06.TXT");

      // Liberar matrix da memoria
      Fmatrix.free();

      // Ler matrix do arquivo
      matrix.fread("DADOS06.TXT");

      // Verificar dados
      if (!matrix.IsValid())
      {
        println ("ERRO: Dados invalidos. ");
      }
      else
      {
        // Ler dados
        do
        {
          linha1 = ReadInt("Forneca a linha a ser somada: ");
        } while (linha1 < 0);

        do
        {
          linha2 = ReadInt("Forneca a outra linha a ser somada: ");
        } while (linha2 < 0);

        do
        {
          Lsoma = ReadInt("Forneca a linha a ser alterada: ");
        } while (Lsoma < 0);

        constante = ReadInt("Fornca uma constante para definir o escalamento da segunda linha da matrix: ");

        // Somar linhas com a segunda sendo escalada
        resultado = matrix.AddScaledRows (linha1, linha2, Lsoma, constante);

        // Mostrar dados
        println ("Matrix normal -");
        matrix.print();
        println ("Matrix com soma escalada -");
        resultado.print();

        // Liberar matrizes da memoria
        matrix.free();
        resultado.free();
      } 
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1207 (void)
{
  // Identificacao de dados
  Matrix <int> matrix (0, 0);
  Matrix <int> Fmatrix(0, 0);
  Matrix <int> resultado (0, 0);

  int linha1 = 0;       // Linha a ser subtraida
  int linha2 = 0;       // Linha a ser subtraida
  int Lsoma  = 0;       // Linha do resultado da subtracao
  int constante = 0;

  // Apresentacao
  println ("ED1207");
  println ("");                  // Pular uma linha
  std::cout << "Operar duas linhas de uma matrix, guardando no primeiro lugar, as diferencas de cada elemento da primeira linha com o";
  println ("respectivo da segunda linha multiplicado por uma constante. ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix.SetSize();
  
  // Verificar dimensoes
  if (!Fmatrix.IsValid())
  {
    println ("ERRO: Dimensoes invalidass. ");
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
      // Escrever matrix no arquivo
      Fmatrix.fwrite("DADOS07.TXT");

      // Liberar matrix da memoria
      Fmatrix.free();

      // Ler matrix do arquivo
      matrix.fread("DADOS07.TXT");

      // Verificar dados
      if (!matrix.IsValid())
      {
        println ("ERRO: Dados invalidos. ");
      }
      else
      {
        // Ler dados
        do
        {
          linha1 = ReadInt("Forneca a linha a ser subtraida: ");
        } while (linha1 < 0);

        do
        {
          linha2 = ReadInt("Forneca a outra linha a ser subtraida: ");
        } while (linha2 < 0);

        do
        {
          Lsoma = ReadInt("Forneca a linha a ser alterada: ");
        } while (Lsoma < 0);

        constante = ReadInt("Fornca uma constante para definir o escalamento da segunda linha da matrix: ");

        // Subtrair linhas com a segunda sendo escalada
        resultado = matrix.SubtractScaledRows (linha1, linha2, Lsoma, constante);

        // Mostrar dados
        println ("Matrix normal -");
        matrix.print();
        println ("Matrix com subtracao escalada -");
        resultado.print();

        // Liberar matrizes da memoria
        matrix.free();
        resultado.free();
      } 
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1208 (void)
{
  // Identificacao de dados
  Matrix <int> matrix (0, 0);
  Matrix <int> Fmatrix (0, 0);
  int valor = 0;
  int linha = 0;

  // Apresentacao
  println ("ED1208");
  println ("");                  // Pular uma linha
  println ("Dizer em qual linha de uma matrix se encontra um valor [x]. ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix.SetSize();

  // Verificar dimensoes
  if (!Fmatrix.IsValid())
  {
    println ("ERRO: Dimensoes invalidas. ");
  }
  else
  {
    // Ler valores para a matrix
    Fmatrix.write();

    if (!Fmatrix.IsValid())
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever matrix no arquivo
      Fmatrix.fwrite("DADOS08.TXT");

      // Liberar matrix da memoria
      Fmatrix.free();

      // Ler matrix do arquivo
      matrix.fread("DADOS08.TXT");

      // Verificar dados
      if (!matrix.IsValid())
      {
        println ("ERRO: Dados invalidos. ");
      }
      else
      {
        // Ler dados
        valor = ReadInt("Forneca um valor para ser procurado na matrix: ");

        // Procurar valor
        matrix.find(valor);

        // Mostrar dados
        linha = matrix.getiy();
        if (linha >= 0)
        {
          std::cout << "O valor \'" << valor << "\' foi encontrado na linha [" << matrix.getiy() << "] da matrix" << std::endl;
        }
        else
        {
          std::cout << "O valor \'" << valor << "\' nao foi encontrado na matrix. ";
        }
        std::cout << std::endl;
        println("Matrix -");
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

void ED1209 (void)
{
  // Identificacao de dados
  Matrix <int> matrix (0, 0);
  Matrix <int> Fmatrix (0, 0);
  int valor = 0;
  int coluna = 0;

  // Apresentacao
  println ("ED1208");
  println ("");                  // Pular uma linha
  println ("Dizer em qual coluna de uma matrix se encontra um valor [x]. ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix.SetSize();

  // Verificar dimensoes
  if (!Fmatrix.IsValid())
  {
    println ("ERRO: Dimensoes invalidas. ");
  }
  else
  {
    // Ler valores para a matrix
    Fmatrix.write();

    if (!Fmatrix.IsValid())
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever matrix no arquivo
      Fmatrix.fwrite("DADOS09.TXT");

      // Liberar matrix da memoria
      Fmatrix.free();

      // Ler matrix do arquivo
      matrix.fread("DADOS09.TXT");

      // Verificar dados
      if (!matrix.IsValid())
      {
        println ("ERRO: Dados invalidos. ");
      }
      else
      {
        // Ler dados
        valor = ReadInt("Forneca um valor para ser procurado na matrix: ");

        // Procurar valor
        matrix.find(valor);

        // Mostrar dados
        coluna = matrix.getiy();
        if (coluna >= 0)
        {
          std::cout << "O valor \'" << valor << "\' foi encontrado na coluna [" << matrix.getiy() << "] da matrix" << std::endl;
        }
        else
        {
          std::cout << "O valor \'" << valor << "\' nao foi encontrado na matrix. ";
        }
        std::cout << std::endl;
        println("Matrix -");
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

void ED1210 (void)
{
  // Identificacao de dados
  Matrix <int> matrix   (0, 0);
  Matrix <int> Fmatrix  (0, 0);
  Matrix <int> resultado(0, 0);

  // Apresentacao
  println ("ED1210");
  println ("");                  // Pular uma linha
  println ("Transpor uma matrix. ");
  println ("");                  // Pular uma linha
    
  // Ler dimensoes da matrix
  Fmatrix.SetSize();

  // Verificar dimensoes
  if (!Fmatrix.IsValid())
  {
    println ("ERRO: Dimensoes invalidas. ");
  }
  else
  {
    // Ler valores para a matrix
    Fmatrix.write();

    if (!Fmatrix.IsValid())
    {
      println ("ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever matrix no arquivo
      Fmatrix.fwrite("DADOS10.TXT");

      // Liberar matrix da memoria
      Fmatrix.free();

      // Ler matrix do arquivo
      matrix.fread("DADOS10.TXT");

      // Verificar dados
      if (!matrix.IsValid())
      {
        println ("ERRO: Dados invalidos. ");
      }
      else
      {
        // Transpor matrix
        resultado = matrix.transpose();

        // Mostrar dados
        println ("Matrix normal -");
        matrix.print();
        println ("Matrix transposta -");
        resultado.print();

        // Liberar matrizes da memoria
        matrix.free();
        resultado.free();
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED12E1 (void)
{
  // Identificacao de dados
  Matrix <int> matrix(0, 0);
  Matrix <int> referencia(0, 0);
  bool resultado = false;

  // Apresentacao
  println ("ED12E1");
  println ("");                  // Pular uma linha
  println ("Dizer se uma matrix apresenta a caracteristica mostrada no estudo dirigido. ");
  println ("");                  // Pular uma linha
  
  // Ler dimensoes da matrix
  matrix.SetSize();

  // Verificar dimensoes
  if (matrix.IsValid())
  {
    // Inicializar matrix de referencia
    referencia.init(matrix.getrows(), matrix.getcolumns());

    // Verificar dados
    if (!referencia.IsValid())
    {
      println ("ERRO: Falta de espaco. ");
    }
    else
    {
      // Escrever valores para a matrix
      matrix.write();
      referencia.WriteAscending(1);

      // Verificar dados
      if (matrix.IsValid() && referencia.IsValid())
      {
        // Transpor matrix
        referencia = referencia.transpose();
        
        // Verificar igualdade
        resultado = (referencia == matrix);

        // Mostrar dados
        if (resultado)
        {
          println ("A matrix apresenta a caracteristica mostrada. ");
        }
        else
        {
          println ("A matrix nao apresenta a caracteristica mostrada. ");
        }
        println ("Matrix -");
        matrix.print();
        println ("Matrix referencia -");
        referencia.print();

        // Liberar matrizes da memoria
        matrix.free();
        referencia.free();
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED12E2 (void)
{
  // Identificacao de dados
  Matrix <int> matrix(0, 0);

  // Apresentacao
  println ("ED12E2");
  println ("");                  // Pular uma linha
  println ("Montar matrix com a caracteristica mostrada no estudo dirigido. ");
  println ("");                  // Pular uma linha
  
  // Ler dimensoes da matrix
  matrix.SetSize();

  // Verificar dimensoes
  if (matrix.IsValid())
  {
    // Escrever valores para a matrix
    matrix.WriteDescending(1);

    // Verificar dados
    if (matrix.IsValid())
    {
      // Transpor matrix
      matrix = matrix.transpose();

      // Mostrar dados
      matrix.print();

      // Liberar matrix da memoria
      matrix.free();
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
      println ("ED12 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0  - sair");
      println ("1  - ED1201   2 - ED1202");
      println ("3  - ED1203   4 - ED1204");
      println ("5  - ED1205   6 - ED1206");
      println ("7  - ED1207   8 - ED1208");
      println ("9  - ED1209  10 - ED1210");
      println ("11 - ED12E1  12 - ED12E2");
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
          case 1:  ED1201();
            break;
          case 2:  ED1202();
            break;
          case 3:  ED1203();
            break;
          case 4:  ED1204();
            break;
          case 5:  ED1205();
            break;
          case 6:  ED1206();
            break;
          case 7:  ED1207();
            break;
          case 8:  ED1208();
            break;
          case 9:  ED1209();
            break;
          case 10: ED1210();
            break;
          case 11: ED12E1();
            break;
          case 12: ED12E2();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED12 e seus metodos

*/