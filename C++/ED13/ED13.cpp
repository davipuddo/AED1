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
  println ("Ler do teclado um valor e atribui-lo ao nome (Atributo de um objeto). ");
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
  println ("Ler do teclado e atribuir um valor ao telefone (Atributo de um objeto)");
  println ("");                  // Pular uma linha
  
  // Ler dados
  telefone = ReadString("Forneca o telefone do contato: ");

  // Operacao
  pessoa1.SetPhone(0, telefone);

  // Mostrar dados
  if (pessoa1.GetPhone(0) == "")
  {
    println ("Telefone invalido. ");
  }
  else
  {
    std::cout << "Telefone: " << pessoa1.GetPhone(0) << std::endl;
  }

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
  println ("Testar se um telefone e valido, ou nao. ");
  println ("");                  // Pular uma linha
      
  // Ler dados
  telefone = ReadString("Forneca o telefone do contato: ");

  // Operacao
  pessoa1.SetPhone(0, telefone);

  // Mostrar dados
  if (pessoa1.CheckPhone(0) && pessoa1.GetPhone(0) != "99999-9999")
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
  std::string nome = "";
  std::string telefone = "";

  // Apresentacao
  println ("ED1304");
  println ("");                  // Pular uma linha
  println ("Gravar dados de um contato em um arquivo. ");
  println ("");                  // Pular uma linha
      
  // Ler dados
  nome       = ReadString ("Forneca o nome do contato: ");
  telefone  = ReadString ("Forneca o telefone  do contato: ");

  // Definir dados na classe
  dados.SetName(nome);
  dados.SetPhone(0, telefone);

  // Verificar dados
  if (!dados.IsValid())
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    // Escrever dados em um arquivo
    dados.fwrite("DADOS04-05.TXT");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1305 (void)
{
  // Identificacao de dados
  Contato pessoa1;

  // Apresentacao
  println ("ED1305");
  println ("");                  // Pular uma linha
  println ("Ler dados de um contato gravados em um arquivo. ");
  println ("");                  // Pular uma linha

  // Ler dados do arquivo
  pessoa1.fread("DADOS04-05.TXT");

  // Mostrar dados
  if (!pessoa1.IsValid())
  {
    println ("ERRO: Dados invalidos. ");
  }
  else
  {
    pessoa1.print();
  }

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
  std::string endereco1 = "";
  std::string endereco2 = "";

  // Apresentacao
  println ("ED1306");
  println ("");                  // Pular uma linha
  println ("Adicionar um segundo telefone ao contato. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  nome = ReadString("Forneca o nome do contato: ");
  telefone1 = ReadString("Forneca o telefone do contato: ");
  telefone2 = ReadString("Forneca um outro telefone do contato: ");
  endereco1 = ReadString("Forneca o endereco do contato: ");
  endereco2 = ReadString("Forneca o endereco do contato: ");


  // Guardar dados do contato
  pessoa1.SetName(nome);
  pessoa1.SetPhone(0, telefone1);
  pessoa1.SetPhone(1, telefone2);
  pessoa1.SetAdress(0, 0, endereco1);
  pessoa1.SetAdress(1, 0, endereco2);
  pessoa1.SetAdress(1, 1, "nada");

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
  println ("Indicar quantos telefones estao associados a cada objeto. ");
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
  println ("Atribuir um valor ao segundo telefone. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone = ReadString("Forneca o segundo numero de telefone do contato: ");

  // Guardar dados
  pessoa1.SetPhone(1, telefone);

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
  println ("Atribuir um valor apenas ao segundo telefone");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone = ReadString("Forneca o segundo numero de telefone do contato: ");

  // Guardar dados
  pessoa1.SetPhone(1, telefone);

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
  println ("Remover apenas o valor do segundo telefone. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefone1 = ReadString("Forneca o numero de telefone do contato: ");
  telefone2 = ReadString("Forneca um outro numero de telefone do contato: ");

  // Armazenar dados
  pessoa1.SetPhone(0, telefone1);
  pessoa1.AddPhone(1);
  pessoa1.SetPhone(1, telefone2);

  // Mostrar dados
  pessoa1.print();

  // Alterar dados
  pessoa1.SetPhone(1, "");

  // Mostrar dados
  pessoa1.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED13E1 (void)
{
  // Identificacao de dados
  Contato pessoa1;
  std::string telefone = "";
  int telefones = 0;

  // Apresentacao
  println ("ED13E1");
  println ("");                  // Pular uma linha
  println ("Modificar a classe para lidar com [n] telefones. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  telefones = ReadInt ("Forneca a quantidade de telefones a serem adicionados: ");
  pessoa1.AddPhone(telefones);

  // Guardar dados
  int TN = (telefones+1);
  for (int i = 0; i < TN; i++)
  {
    pessoa1.SetPhone(i, ReadString("Forneca um numero de telefone do contato: "));
  }

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

void ED13E2 (void)
{
  // Identificacao de dados
  Contato dados;
  Contato pessoa1;
  std::string nome = "";
  std::string telefone1 = "";
  std::string telefone2 = "";
  std::string enderecoR1 = "";
  std::string enderecoR2 = "";
  std::string enderecoP1 = "";
  std::string enderecoP2 = "";

  // Apresentacao
  println ("ED13E2");
  println ("");                  // Pular uma linha
  println ("Adicionar enderecos a classe. ");
  println ("");                  // Pular uma linha
      
  // Ler dados e guarda-los no objeto
  
    /* Nome */
  nome       = ReadString ("Forneca o nome do contato: ");
  dados.SetName(nome);

    /* Telefones */

      // Verificar nome
  if (dados.CheckName())
  {
    telefone1  = ReadString ("Forneca o telefone 1 do contato: ");
    dados.SetPhone(0, telefone1);

    // Verificar telefone 1
    if (dados.CheckPhone(0))
    {
      telefone2  = ReadString ("Forneca o telefone 2 do contato: ");
      dados.SetPhone(1, telefone2);

         /* Enderecos */

      // Verificar telefone 2
      if (dados.CheckPhone(1))
      {
        enderecoR1 = ReadString ("Forneca o endereco Residencial 1 do contato: ");
        dados.SetAdress(0, 0, enderecoR1);
        
        // Verificar endereco residencial 1
        if (dados.CheckAdress(0, 0))
        {
          enderecoR2 = ReadString ("Forneca o endereco Residencial 2 do contato: ");
          dados.SetAdress(0, 1, enderecoR2);

          // Verificar endereco residencial 2
          if (dados.CheckAdress(0, 1))
          {
            enderecoP1 = ReadString ("Forneca o endereco Profissional 1 do contato: ");
            dados.SetAdress(1, 0, enderecoP1);

            // Verificar endereco profissional 1
            if (dados.CheckAdress(1, 0))
            {
              enderecoP2 = ReadString ("Forneca o endereco Profissional 2 do contato: ");
              dados.SetAdress(1, 1, enderecoP2);
              
              // Verificar todos os dados
              if (!dados.IsValid())
              {
                println ("ERRO: Dados invalidos. ");
              }
              else
              {
                // Escrever dados em um arquivo
                dados.fwrite("DADOSE2.TXT");

                // Ler dados do arquivo
                pessoa1.fread("DADOSE2.TXT");

                // Verificar dados
                if (!pessoa1.IsValid())
                {
                  println ("ERRO: Dados invalidos. ");
                }
                else
                {
                  // Mostrar dados
                  pessoa1.print();
                }
              }
            }
          }
        }
      }

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
      println ("ED13 - v1.0 - 31/05/24" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0  - sair");
      println ("1  - ED1301   2 - ED1302");
      println ("3  - ED1303   4 - ED1304");
      println ("5  - ED1305   6 - ED1306");
      println ("7  - ED1307   8 - ED1308");
      println ("9  - ED1309  10 - ED1310");
      println ("11 - ED13E1  12 - ED13E2");
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
          case 11: ED13E1();
            break;
          case 12: ED13E2();
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