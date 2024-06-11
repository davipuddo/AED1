//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


char* PushBack (char* str, char x)
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

char* PopBack (char* str)
{
  char* result = null;
  if (str != null)
  {
    int size = strlen(str)-1;
    result = (char*)calloc(size, sizeof(char));

    for (int i = 0; i < size; i++)
    {
      result[i] = str[i];
    }
  }
  return (result);
}

char* PushFront (char* str, char x)
{
  char* result = null;
  if (str != null)
  {
    int size = strlen(str);
    result = (char*)calloc((size+2), sizeof(char));

    int y = 0;
    int NSize = size+1;

    result[0] = x;
    for (int i = 1; i < NSize; i++)
    {
      result[i] = str[y];
      y++;
    }
  }
  return (result);
}

char* PopFront (char* str)
{
  char* result = null;
  if (str != null)
  {
    int size = strlen(str)-1;
    int y = 1;
    result = (char*)calloc(size, sizeof(char));

    for (int i = 0; i < size; i++)
    {
      result[i] = str[y];
      y++;
    }
  }
  return (result);
}

char* PushMid (char* str, char x)
{
  char* result = null;
  if (str != null)
  {
    int size = strlen(str);
    if (size <= 1)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      int mid = 0;
      int y = 0;
      result = (char*)calloc((size+2), sizeof(char));

      mid = ((double)size/2.0);

      for (int i = 0; i < size; i++)
      {
        if (i == mid)
        {
          y++;
        }
        result[y] = str[i];
        y++;
      }
      result[mid] = x;
    }
  }
  return (result);
}

char* PopMid (char* str)
{
  char* result = null;
  if (str != null)
  {
    int size = strlen(str)-1;
    result = (char*)calloc(size, sizeof(char));
    int mid = ((double)size/2.0);

    int y = 0;
    for (int i = 0; i < size; i++)
    {
      if (i == mid)
      {
        y++;
      }
      result[i] = str[y];
      y++;
    }
  }
  return (result);
}

void ED1501 (void)
{
  // Identificacao de dados
  char* str;
  char* resultado = null;
  char x = '0';
  int tamanho = 0;

  // Apresentacao
  println ("ED1501");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt ("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  x = ReadChar("Forneca um caractere para ser adicionado ao final da cadeia: ");

  // Adicionar caractere no final da cadeia
  resultado = PushBack(str, x);

  // Verificar dados
  if (resultado != null)
  {
    // Mostrar dados
    println ("Original - ");
    PrintArray(str);

    println ("Alterada - ");
    PrintArray(resultado);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1502 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  int tamanho = 0;

  // Apresentacao
  println ("ED1502");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  
  // Remover ultimo caractere da cadeia
  resultado = PopBack(str);

  // Mostrar dados
  if (resultado != null)
  {
    println ("Original -");
    PrintArray(str);

    println ("Alterada -");
    PrintArray(resultado);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1503 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  char x = '0';
  int tamanho = 0;

  // Apresentacao
  println ("ED1503");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  x = ReadChar ("Forneca um caractere para ser adicionado na frente da cadeia: ");

  // Adicionar caractere na frente
  resultado = PushFront(str, x);

  // Verificar dados
  if (resultado != null)
  {
    // Mostrar dados
    println ("Original -");
    PrintArray(str);

    println ("Alterada -");
    PrintArray(resultado); 
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1504 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  int tamanho = 0;

  // Apresentacao
  println ("ED1504");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);

  // Remover primeiro caractere da cadeia
  resultado = PopFront(str);

  // Verificar dados
  if (resultado != null)
  {
    // Mostrar dados
    println ("Original -");
    PrintArray(str);

    println ("Alterada -");
    PrintArray(resultado); 
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1505 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  char x = '0';
  int tamanho = 0;

  // Apresentacao
  println ("ED1505");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  x = ReadChar("Forneca um caractere a ser adicionado ao meio da cadeia fornecida: ");

  // Adicionar caractere no meio da cadeia
  resultado = PushMid(str, x);

  // Verificar dados
  if (resultado != null)
  {
    // Mostrar dados
    println ("Original -");
    PrintArray(str);

    println ("Alterada -");
    PrintArray(resultado);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1506 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  int tamanho = 0;

  // Apresentacao
  println ("ED1506");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);

  // Remover caractere do meio da cadeia
  resultado = PopMid(str);

  // Verificar dados
  if (resultado != null)
  {
    // Mostrar dados
    println ("Original -");
    PrintArray(str);
    
    println ("Alterada -");
    PrintArray(resultado);
  }

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