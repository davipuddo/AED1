//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


void ED1401 (void)
{
  // Identificacao de dados
  PString dados("");
  int resultado = 0;

  // Apresentacao
  println ("ED1401");
  println ("");
  println (" ");
  println ("");

  // Ler dados
  dados.write("");

  // Converter para inteiro
  resultado = dados.getInt();

  // Mostrar dados
  std::cout << "Valor convertido para inteiro: " << resultado << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1402 (void)
{
  // Identificacao de dados
  PString dados("");
  double resultado = 0.0;

  // Apresentacao
  println ("ED1402");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");

  // Converter para real
  resultado = dados.getDouble();

  // Mostrar dados
  std::cout << "Valor convertido para real: " << resultado << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1403 (void)
{
  // Identificacao de dados
  PString dados("");
  bool resultado = false;

  // Apresentacao
  println ("ED1403");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");

  // Converter dados
  resultado = dados.getBool();

  // Mostrar dados
  std::cout << "Valor convertido para bool: " << resultado << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1404 (void)
{
  // Identificacao de dados
  PString dados("");
  std::string str = "";
  bool resultado = false;

  // Apresentacao
  println ("ED1404");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");
  str = ReadString("Forneca uma cadeia de caracteres a ser procurada: ");

  // Procurar valor
  resultado = dados.find(str);

  // Mostrar dados
  if (resultado)
  {
    println ("A cadeia de caracteres foi encontrada dentro do objeto. ");
  }
  else
  {
    println ("A cadeia de caracteres nao foi encontrada dentro do objeto. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1405 (void)
{
  // Identificacao de dados
  PString dados("");
  std::string str = "";

  // Apresentacao
  println ("ED1405");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");

  // Converter dados
  str = dados.toUpper();

  // Verificar dados
  if (str != "")
  {
    // Mostrar dados
    std::cout << "Cadeia com as letras minusculas convertidas: " << std::endl << str << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1406 (void)
{
  // Identificacao de dados
  PString dados("");
  std::string str = "";

  // Apresentacao
  println ("ED1406");
  println ("");                  // Pular uma linha
  println ("Converter letras maiusculas para minusculas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");

  // Converter dados
  str = dados.toLower();

  // Verificar dados
  if (str != "")
  {
    // Mostrar dados
    std::cout << "Cadeia com as letras maiusculas convertidas. " << std::endl << str << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1407 (void)
{
  // Identificacao de dados
  PString dados("");
  std::string str = "";
  char antigo = '0';
  char novo = '0';

  // Apresentacao
  println ("ED1407");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");
  antigo = ReadChar("Forneca o caractere a ser substituido: ");
  novo = ReadChar("Forneca o caractere que ira o substituir: ");

  // Substituir valores
  str = dados.replace(antigo, novo);

  // Mostrar dados
  if (str != "")
  {
    std::cout << "Cadeia com caracteres substituidos: " << std::endl << str << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1408 (void)
{
  // Identificacao de dados
  PString dados("");
  int n = 0;
  std::string str = "";

  // Apresentacao
  println ("ED1408");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.write("");
  n = ReadInt("Forneca um valor inteiro para definir a quantidade de casas a serem puladas pela cifra: ");

  // Criptografar dados
  str = dados.encrypt(n);

  // Verificar dados
  if (str != "")
  {
    // Mostrar dados
    std::cout << "Dado criptografado: " << str << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1409 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1409");
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

void ED1410 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1410");
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
      println ("ED14 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1401   2 - ED1402");
      println ("3 - ED1403   4 - ED1404");
      println ("5 - ED1405   6 - ED1406");
      println ("7 - ED1407   8 - ED1408");
      println ("9 - ED1409  10 - ED1410");
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
          case 1:  ED1401();
            break;
          case 2:  ED1402();
            break;
          case 3:  ED1403();
            break;
          case 4:  ED1404();
            break;
          case 5:  ED1405();
            break;
          case 6:  ED1406();
            break;
          case 7:  ED1407();
            break;
          case 8:  ED1408();
            break;
          case 9:  ED1409();
            break;
          case 10: ED1410();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED14 e seus metodos

*/