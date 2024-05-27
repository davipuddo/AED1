//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"
#include "ED13.hpp"

void ED0X01 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string nome = "";

  // Apresentacao
  println ("ED0X01");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  nome = ReadString("Forneca o nome do contato: ");
  
  // Definir nome
  pessoa1.SetName(nome);

  // Mostrar dados
  if (pessoa1.GetName() == "")
  {
    println ("O nome nao foi definido. ");
  }
  else
  {
    std::cout << "Nome: " << pessoa1.GetName() << std::endl; 
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X02 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = "";

  // Apresentacao
  println ("ED0X02");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone = ReadString("Forneca o telefone do contato: ");

  // Operacao
  pessoa1.SetPhone(telefone);

  // Mostrar dados
  if (pessoa1.GetPhone() == "")
  {
    println ("Telefone invalido. ");
  }
  else
  {
    std::cout << pessoa1.GetPhone() << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X03 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = "";

  // Apresentacao
  println ("ED0X03");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone = ReadString("Forneca o telefone do contato: ");

  // Operacao
  pessoa1.SetPhone(telefone);

  // Mostrar dados
  if (!pessoa1.CheckPhone())
  {
    println ("Telefone invalido. ");
  }
  else
  {
    std::cout << pessoa1.GetPhone() << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X04 (void)
{
  // Identificacao de dados
  Contato dados;
  Contato pessoa1;
  std::string nome = "";
  std::string telefone = "";

  // Apresentacao
  println ("ED0X04");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha4
    
  // Ler dados
  nome     = ReadString ("Forneca o nome do contato: ");
  telefone = ReadString ("Forneca o telefone do contato: ");

  // definir dados na classe
  dados.SetName(nome);
  dados.SetPhone(telefone);

  // Escrever dados em um arquivo
  dados.fwrite("DADOS04.TXT");

  // Ler dados do arquivo
  pessoa1.fread("DADOS04.TXT");

  // Mostrar dados
  pessoa1.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X05 (void)
{
  // Identificacao de dados
  Contato dados;
  Contato pessoa1;
  std::string nome = "";
  std::string telefone = "";

  // Apresentacao
  println ("ED0X05");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha4
    
  // Ler dados
  nome     = ReadString ("Forneca o nome do contato: ");
  telefone = ReadString ("Forneca o telefone do contato: ");

  // definir dados na classe
  dados.SetName(nome);
  dados.SetPhone(telefone);

  // Escrever dados em um arquivo
  dados.fwrite("DADOS05.TXT");

  // Ler dados do arquivo
  pessoa1.fread("DADOS05.TXT");

  // Mostrar dados
  pessoa1.print();

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