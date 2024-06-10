//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


char* PushBack(char* str, char x)
{
  char* result = null;
  if (str != null)
  {
    int size = strlen(str);
    result = (char*)calloc((size+2), sizeof(char));

    for (int i = 0; i < size; i++)
    {
      result[i] = str[i];
    }
    result[size] = x;
  }

  return (result);
}

void ED1501 (void)
{
  // Identificacao de dados
  char* str;
  char* result = null;
  char x = '0';

  // Apresentacao
  println ("ED1501");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  str = WriteArray<char>(4);
  x = ReadChar("Forneca um caractere para ser adicionado a cadeia: ");

  // Adicionar caractere a cadeia
  result = PushBack(str, x);

  // Verificar dados
  if (result != null)
  {
    // Mostrar dados
    println ("Original - ");
    PrintArray(str);

    println ("Alterado - ");
    PrintArray(result);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1502 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1502");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  // Operacao
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1503 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1503");
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

void ED1504 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1504");
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

void ED1505 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1505");
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

void ED1506 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1506");
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

void ED1507 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1507");
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

void ED1508 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1508");
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

void ED1509 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1509");
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

void ED1510 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1510");
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
      println ("ED15 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1501   2 - ED1502");
      println ("3 - ED1503   4 - ED1504");
      println ("5 - ED1505   6 - ED1506");
      println ("7 - ED1507   8 - ED1508");
      println ("9 - ED1509  10 - ED1510");
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
          case 1:  ED1501();
            break;
          case 2:  ED1502();
            break;
          case 3:  ED1503();
            break;
          case 4:  ED1504();
            break;
          case 5:  ED1505();
            break;
          case 6:  ED1506();
            break;
          case 7:  ED1507();
            break;
          case 8:  ED1508();
            break;
          case 9:  ED1509();
            break;
          case 10: ED1510();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED15 e seus metodos

*/