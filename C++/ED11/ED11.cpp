//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"

void ED1101 (void)
{
  // Identificacao de dados
  Array <int> array(5, 0);
  int inferior = 0;
  int superior = 0;

  // Apresentacao
  println ("ED1101");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  inferior = ReadInt("Forneca um valor inteiro para definir o intervalo inferior: ");
  superior = ReadInt("Forneca um valor inteiro para definir o intervalo superior: ");
  array.random(inferior, superior, 1, 100);

  // Gravar array em um arquivo
  array.fwrite("DADOS01.TXT");

  // Ler dados do arquivo
  array.fread("DADOS01.TXT");

  // Mostrar dados
  array.print();

  // Liberar espaco da memoria
  array.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1102 (void)
{
  // Identificacao de dados
  Array <int> Farray(10, 0);
  int x = 0;
  int size = 0;

  // Apresentacao
  println ("ED1102");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  size = ReadPositiveInt("Forneca o tamanho do array: ");

  // Verificar tamanho
  if (size > 0)
  {
    // Inicializar array
    Array <int> array(size, 0);

    // Ler dados
    array.write();

    // Gravar array em um arquivo
    array.fwrite("DADOS02.TXT");

    // Liberar array da memoria
    array.free();

    // Ler array do arquivo
    Farray.fread("DADOS02.TXT");

    // Operacao
    Farray.even();
    x = Farray.biggest();

    // Mostrar dados
    println ("");
    std::cout << x << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1103 (void)
{
  // Identificacao de dados
  Array <int> Farray(10, 0);
  int x = 0;
  int size = 0;

  // Apresentacao
  println ("ED1103");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  size = ReadPositiveInt("Forneca o tamanho do array: ");

  // Verificar tamanho
  if (size > 0)
  {
    // Inicializar array
    Array <int> array(size, 0);

    // Ler dados
    array.write();

    // Gravar dados no arquivo
    array.fwrite("DADOS03.TXT");

    // Liberar array da memoria
    array.free();

    // Ler dados do arquivo
    Farray.fread("DADOS03.TXT");

    // Encontrar menor valor impar
    Farray.odd();
    x = Farray.smallest();

    // Mostrar dados
    println ("");
    std::cout << x << std::endl;
  }
  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1104 (void)
{
  // Identificacao de dados
  Array <int> array(10,0);
  int inicio = 0;
  int fim = 0;
  int soma = 0;

  // Apresentacao
  println ("ED1104");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  Array <int> Farray(ReadPositiveInt("Forneca o tamanho do array: "), 0);

  // Verificacao dos dados
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Dar valores aleatorios para o array
    Farray.random(0, 30,0, 100);

    // Verificacao dos dados
    if (!Farray.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    // Gravar array em um arquivo
    Farray.fwrite("DADOS04.TXT");

    // Liberar array da memoria
    Farray.free();

    // Ler dados do arquivo
    array.fread("DADOS04.TXT");

    // Verificacao dos dados
    if (!array.isValid())
    {
      println("(Array) ERRO: Dados invalidos. ");
    }
    else
    {
      // Ler dados
      inicio = ReadInt("Forneca um valor inteiro para definir a posicao inicial a ser somada: ");
      fim = ReadInt("Forneca um valor inteiro para definir a posicao final  a ser somada: ");

      // Somar valores do intervalo dado
      soma = array.addinterval(inicio, fim);

      // Mostrar dados
      println ("Array- ");
      array.print();
      println ("Soma- ");
      std::cout << soma << std::endl;

      // Liberar array da memoria
      array.free();
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1105 (void)
{
  // Identificacao de dados
  Array <int> array(10, 0);
  double media = 0.0;
  int inicio = 0;
  int fim = 0;

  // Apresentacao
  println ("ED1105");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  Array <int> Farray(ReadPositiveInt("Forneca um valor para definir o tamanho do array: "), 0);

  // Verificacao dos dados
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Dar valores aleatorios para o array
    Farray.random(0, 30, 0, 100);

    // Verificacao dos dados
    if (!Farray.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    else
    {
      // Gravar dados em um arquivo
      Farray.fwrite("DADOS05.TXT");

      // Liberar array da memoria
      Farray.free();

      // Ler dados do arquivo
      array.fread("DADOS05.TXT");

      // Verificacao dos dados
      if (!array.isValid())
      {
        println ("(array) ERRO: Dados invalidos.  ");
      }
      else
      {
        // Ler intervalo
        inicio = ReadInt("Forneca um valor inteiro para definir a posicao inicial a ser somada: ");
        fim = ReadInt("Forneca um valor inteiro para definir a posicao final  a ser somada: ");

        // Descobrir media
        media = array.average(inicio, fim);
        
        // Mostrar dados
        println ("Array- ");
        array.print();
        println ("Media- ");
        std::cout << media << std::endl;

        // Liberar array da memoria
        array.free();
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1106 (void)
{
  // Identificacao de dados
  Array <int> array(10, 0);
  int resultado = 0;

  // Apresentacao
  println ("ED1106");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  Array <int> Farray(ReadPositiveInt("Forneca o tamanho do array: "), 0);
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Ler dados do array
    Farray.write();
    if (!Farray.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever dados no arquivo
      Farray.fwrite("DADOS06.TXT");

      // Liberar array da memoria
      Farray.free();

      // Ler dados do arquivo
      array.fread("DADOS06.TXT");

      if (!array.isValid())
      {
        println ("(array) ERRO: Dados invalidos. ");
      }
      else
      {
        // Procurar valores negativos
        resultado = array.CheckNegative();

        // Liberar array da memoria
        array.free();

        // Mostrar dados
        if (resultado == 1)
        {
          println ("Todos os valores do array sao negativos. ");
        }
        else
        {
          println ("O array possui valores positivos. ");
        }
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1107 (void)
{
  // Identificacao de dados
  Array <int> array(10, 0);
  int resultado = 0;

  // Apresentacao
  println ("ED1107");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler tamanho do array
  Array <int> Farray(ReadPositiveInt("Forneca o tamanho do array: "), 0);

  // Verificar se o tamanho do array e valido
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Ler dados para o array
    Farray.write();

    // Checar dados
    if (!Farray.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever dados no arquivo
      Farray.fwrite("DADOS07.TXT");

      // Liberar array da memoria
      Farray.free();

      // Ler dados do arquivo
      array.fread("DADOS07.TXT");

      // Checar dados
      if (!array.isValid())
      {
        println ("(array) ERRO: Dados invalidos. ");
      }
      else
      {
        // Verificar se o arranjo esta em ordem crescente
        resultado = array.CheckAscending();

        // Liberar array da memoria
        array.free();

        // Mostrar dados
        if (resultado == 1)
        {
          println ("O array esta em ordem crescente. ");
        }
        else
        {
          println ("O array esta em um tipo de ordem diferente de crescente. ");
        }
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1108 (void)
{
  // Identificacao de dados
  Array <int> array(10, 0);
  int valor = 0;
  bool resultado = 0;

  // Apresentacao
  println ("ED1108");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler tamanho do array
  Array <int> Farray(ReadPositiveInt("Forneca o tamanho do array: "), 0);

  // Verificar tamanho do array
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Ler dados do array
    Farray.write();

    // Checar dados
    if (!Farray.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever dados no arquivo
      Farray.fwrite("DADOS08.TXT");

      // Liberar array da memoria
      Farray.free();

      // Ler dados do arquivo
      array.fread("DADOS08.TXT");

      // Checar dados
      if (!array.isValid())
      {
        println ("(array) ERRO: Dados invalidos. ");
      }
      else
      {
        // Ler valor a ser procurado
        valor = ReadInt("Forneca um a valor a ser procurado no array: ");

        // Procurar valor a ser procurado
        resultado = array.CheckValue(valor);

        // Mostrar dados
        if (resultado == 1)
        {
          std::cout << "O valor [" << valor << "] " << "esta presente no array" << std::endl; 
        }
        else
        {
          std::cout << "O valor [" << valor << "] " << "nao esta presente no array" << std::endl;
        }
        println ("Array- ");
        array.print();

        // Liberar array da memoria
        array.free();
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1109 (void)
{
  // Identificacao de dados
  Array <int> array(10, 0);
  int constante = 0;
  int inicio = 0;
  int fim = 0 ;

  // Apresentacao
  println ("ED1109");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler tamanho do array
  Array <int> Farray(ReadPositiveInt("Forneca o tamanho do array: "), 0);

  // Verificar tamanho do array
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Ler dados para o array
    Farray.write();
    
    if (!Farray.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever dados no arquivo
      Farray.fwrite("DADOS09.TXT");

      // Liberar array da memoria
      Farray.free();

      // Ler dados do arquivo
      array.fread("DADOS09.TXT");

      // Checar dados
      if (!array.isValid())
      {
        println ("(array) ERRO: Dados invalidos. ");
      }
      else
      {
        // Ler dados
        inicio = ReadInt("Forneca um valor inteiro para definir a posicao inicial a ser escalada: ");
        fim    = ReadInt("Forneca um valor inteiro para definir a posicao final  a ser escalada: ");
        constante = ReadPositiveInt("Forneca um valor inteiro para definir o escalamento do array: ");

        // Escalar arranjo
        array.ScaleInterval(constante, inicio, fim);

        // Mostrar dados
        array.print();

        // Liberar array da memoria
        array.free();       
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1110 (void)
{
  // Identificacao de dados
  Array <int> array(10, 0);

  // Apresentacao
  println ("ED1110");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  Array <int> Farray(ReadPositiveInt("Forneca o tamanho do array. "), 0);

  // Verificar tamanho do array
  if (Farray.getlength() <= 0)
  {
    println ("(Farray) ERRO: Tamanho invalido. ");
  }
  else
  {
    // Ler valores para o array
    Farray.write();

    if (!array.isValid())
    {
      println ("(Farray) ERRO: Dados invalidos. ");
    }
    else
    {
      // Escrever dados no arquivo
      Farray.fwrite("DADOS10.TXT");

      // Liberar espaco da memoria
      Farray.free();

      // Ler dados do arquivo
      array.fread("DADOS10.TXT");

      // Checar dados
      if (!array.isValid())
      {
        println ("(array) ERRO: Dados invalidos. ");
      }
      else
      {
        // Verificar se o array esta em ordem decrescente
        if (array.CheckDescending() == 1)
        {
          println ("O array ja esta em ordem decresc1ente. ");
        }
        else
        {
          // Mostrar array original
          println ("Array original- ");
          array.print();

          // Colocar em ordem decrescente
          array.descend();

          // Mostrar array em ordem decrescente
          println ("Array decrescente- ");
          array.print();

          // Liberar array da memoria
          array.free();
        }
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED11E1 (void)
{
  // Identificacao de dados
  Array <int> array1(5, 0);
  Array <int> array2(5, 0);
  int posicao = 0;
  bool resultado = false;

  // Apresentacao
  println ("ED11E1");
  println ("");                  // Pular uma linha
  println ("Dizer se dois arranjos sao diferentes pelo menos em uma posicao. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  println ("Forneca dados para os arranjos: ");
  array1.write();
  array2.write();
  do
  {
    posicao = ReadInt("Forneca um valor inteiro para definir a posicao dos arranjos a ser comparada. ");
  } while (posicao < 0);

  // Verificar dados
  if (!array1.isValid() || !array2.isValid())
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Verificar posicoes
    resultado = array1.EqualInPosition(array2, posicao);

    // Mostrar dados
    println ("Arranjo 1 -");
    array1.print();
    println ("Arranjo 2 -");
    array2.print();
    if (resultado)
    {
      std::cout << "Os arranjos sao iguais na posicao [" << posicao << "]" << std::endl;
    }
    else
    {
      std::cout << "Os arranjos sao diferentes na posicao [" << posicao << "]" << std::endl;
    }
    array1.free();
    array2.free();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED11E2 (void)
{
  // Identificacao de dados
  Array <int> array1(5, 0);
  Array <int> array2(5, 0);
  Array <int> resultado(5, 0);

  // Apresentacao
  println ("ED11E2");
  println ("");                  // Pular uma linha
  println ("Calcular a diferenca entre dois arranjos para todas as posicoes. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  println ("Forneca dados para os arranjos: ");
  array1.write();
  array2.write();

  // Verificar dados
  if (!array1.isValid() || !array2.isValid())
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Calcular a diferenca dos arranjos
    resultado = array1 - array2;

    // Mostrar dados
    println ("array 1 -");
    array1.print();
    println ("array 2 -");
    array2.print();
    println ("diferenca -");
    resultado.print();

    // Liberar arranjos da memoria
    array1.free();
    array2.free();
    resultado.free();
  }
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
      println ("ED11 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0  - sair");
      println ("1  - ED1101   2 - ED1102");
      println ("3  - ED1103   4 - ED1104");
      println ("5  - ED1105   6 - ED1106");
      println ("7  - ED1107   8 - ED1108");
      println ("9  - ED1109  10 - ED1110");
      println ("11 - ED11E1  12 - ED11E2");
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
          case 1:  ED1101();
            break;
          case 2:  ED1102();
            break;
          case 3:  ED1103();
            break;
          case 4:  ED1104();
            break;
          case 5:  ED1105();
            break;
          case 6:  ED1106();
            break;
          case 7:  ED1107();
            break;
          case 8:  ED1108();
            break;
          case 9:  ED1109();
            break;
          case 10: ED1110();
            break;
          case 11: ED11E1();
            break;
          case 12: ED11E2();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED11 e seus metodos

*/