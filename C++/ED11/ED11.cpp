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
  array.random(inferior, superior);

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
  Array <int> array(5,0);
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

  // Dar valores aleatorios para o array
  Farray.random(0, 30);

  // Gravar array em um arquivo
  Farray.fwrite("DADOS04.TXT");

  // Liberar array da memoria
  Farray.free();

  // Ler dados do arquivo
  array.fread("DADOS04.TXT");

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

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1105 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1105");
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

void ED1106 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1106");
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

void ED1107 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1107");
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

void ED1108 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1108");
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

void ED1109 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1109");
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

void ED1110 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1110");
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
      println ("ED11 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1101   2 - ED1102");
      println ("3 - ED1103   4 - ED1104");
      println ("5 - ED1105   6 - ED1106");
      println ("7 - ED1107   8 - ED1108");
      println ("9 - ED1109  10 - ED1110");
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