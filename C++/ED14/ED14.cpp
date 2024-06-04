//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


void ED1401 (void)
{
  // Identificacao de dados
  PString dados("123");

  // Apresentacao
  println ("ED1401");
  println ("");
  println (" ");
  println ("");

  // Ler dados

  // Converter para inteiro
  dados.print();

  // Mostrar dados
  //std::cout << "Valor convertido: " << result << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1402 (void)
{
  // Identificacao de dados
  int x = 0;
  double resultado = 0.0;

  // Apresentacao
  println ("ED1402");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  x = ReadInt("");

  // Converter para real
  //resultado = getDouble(x);

  // Somar
  resultado += 0.1;

  // Mostrar dados
  std::cout << "Valor convertido + 0.1 : " << resultado << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1403 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1403");
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

void ED1404 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1404");
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

void ED1405 (void)
{
  // Identificacao de dados
  std::string palavra = "";

  // Apresentacao
  println ("ED1405");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  palavra = ReadString("");

  // Verificar dados
  if (palavra != "")
  {
    // Mostrar dados
    //palavra = toUpper(palavra);
    std::cout << "Cadeia com as letras minusculas convertidas. " << std::endl << palavra << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1406 (void)
{
  // Identificacao de dados
  std::string palavra = "";

  // Apresentacao
  println ("ED1406");
  println ("");                  // Pular uma linha
  println ("Converter letras maiusculas para minusculas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  palavra = ReadString("");

  // Verificar dados
  if (palavra != "")
  {
    // Mostrar dados
    //palavra = toLower(palavra);
    std::cout << "Cadeia com as letras maiusculas convertidas. " << std::endl << palavra << std::endl;
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1407 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1407");
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

void ED1408 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1408");
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