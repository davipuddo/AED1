//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"
#include "Contatos.hpp"

void ED1301 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string nome = "";

  // Apresentacao
  println ("ED1301");
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

void ED1302 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = ""; 

  // Apresentacao
  println ("ED1302");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
  
  // Ler dados
  telefone = ReadString("Forneca o telefone do contato: ");

  // Operacao
  pessoa1.SetPhone(telefone, 0);

  // Mostrar dados
  std::cout << "Telefone: " << pessoa1.GetPhone(0) << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1303 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = "";

  // Apresentacao
  println ("ED1303");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
      
  // Ler dados
  telefone = ReadString("Forneca o telefone do contato: ");

  // Operacao
  pessoa1.SetPhone(telefone, 0);

  // Mostrar dados
  if (pessoa1.CheckPhone(0))
  {
    std::cout << "Telefone: " << pessoa1.GetPhone(0) << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1304 (void)
{
  // Identificacao de dados
  Contato dados;
  Contato pessoa1;
  std::string nome = "";
  std::string telefone = "";

  // Apresentacao
  println ("ED1304");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha4
      
  // Ler dados
  nome     = ReadString ("Forneca o nome do contato: ");
  telefone = ReadString ("Forneca o telefone do contato: ");

  // definir dados na classe
  dados.SetName(nome);
  dados.SetPhone(telefone, 0);

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

void ED1305 (void)
{
  // Identificacao de dados
  Contato dados;
  Contato pessoa1;
  std::string nome = "";
  std::string telefone = "";

  // Apresentacao
  println ("ED1305");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha4
      
  // Ler dados
  nome     = ReadString ("Forneca o nome do contato: ");
  telefone = ReadString ("Forneca o telefone do contato: ");

  // definir dados na classe
  dados.SetName(nome);
  dados.SetPhone(telefone, 0);

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

void ED1306 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string nome = "";
  std::string telefone1 = "";
  std::string telefone2 = "";

  // Apresentacao
  println ("ED1306");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  nome = ReadString("Forneca o nome do contato: ");
  telefone1 = ReadString("Forneca o telefone do contato: ");
  telefone2 = ReadString("Forneca um outro telefone do contato: ");

  // Guardar dados do contato
  pessoa1.SetName(nome);
  pessoa1.SetPhone(telefone1, 0);
  pessoa1.SetPhone(telefone2, 1);

  // Verificar dados
  if (pessoa1.IsValid())
  {
    // Mostrar dados
    pessoa1.print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1307 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  Contato pessoa2;
  Contato pessoa3;

  // Apresentacao
  println ("ED1307");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  pessoa1.AddPhone(1);
  pessoa3.AddPhone(3);

  // Mostrar dados
  std::cout << "A pessoa 1 possui [" << pessoa1.GetPhones() << "] telefones" << std::endl;
  std::cout << "A pessoa 2 possui [" << pessoa2.GetPhones() << "] telefones" << std::endl;
  std::cout << "A pessoa 3 possui [" << pessoa3.GetPhones() << "] telefones" << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1308 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = "";

  // Apresentacao
  println ("ED1308");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone = ReadString("Forneca o segundo numero de telefone do contato: ");

  // Guardar dados
  pessoa1.SetPhone(telefone, 1);

  // Verificar dados
  if (pessoa1.IsValid())
  {
    // Mostrar dados
    pessoa1.print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1309 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = "";

  // Apresentacao
  println ("ED1309");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone = ReadString("Forneca o segundo numero de telefone do contato: ");

  // Guardar dados
  pessoa1.SetPhone(telefone, 1);

  // Verificar dados
  if (pessoa1.IsValid())
  {
    // Mostrar dados
    pessoa1.print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1310 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone1 = "";
  std::string telefone2 = "";

  // Apresentacao
  println ("ED1310");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone1 = ReadString("Forneca o numero de telefone do contato: ");
  telefone2 = ReadString("Forneca um outro numero de telefone do contato: ");

  // Armazenar dados
  pessoa1.SetPhone(telefone1, 0);
  pessoa1.AddPhone(1);
  pessoa1.SetPhone(telefone2, 1);

  // Mostrar dados
  pessoa1.print();

  // Alterar dados
  pessoa1.SetPhone("", 1);

  // Mostrar dados
  pessoa1.print();

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
      println ("ED13 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1301   2 - ED1302");
      println ("3 - ED1303   4 - ED1304");
      println ("5 - ED1305   6 - ED1306");
      println ("7 - ED1307   8 - ED1308");
      println ("9 - ED1309  10 - ED1310");
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
          case 1:  ED1301();
            break;
          case 2:  ED1302();
            break;
          case 3:  ED1303();
            break;
          case 4:  ED1304();
            break;
          case 5:  ED1305();
            break;
          case 6:  ED1306();
            break;
          case 7:  ED1307();
            break;
          case 8:  ED1308();
            break;
          case 9:  ED1309();
            break;
          case 10: ED1310();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED13 e seus metodos

*/