//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


char* PushBack (const char* str, char x)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str);
    copy = (char*)calloc(size+1, sizeof(char));
    char *ptr = &copy[0];

    for (int i = 0; i < size; i++)
    {
      *ptr = str[i];
      std::cout << copy[i];
      ptr++;
    }
    *ptr = x;
  }

  return (copy);
}

char* PopBack (const char* str)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str)-1;
    copy = (char*)calloc(size, sizeof(char));
    char *ptr = &copy[0];

    for (int i = 0; i < size; i++)
    {
      *ptr = str[i];
      ptr++;
    }
  }
  return (copy);
}

char* PushFront (const char* str, char x)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str);
    copy = (char*)calloc((size+1), sizeof(char));
    char *ptr = &copy[0];
    int NSize = size+1;

    *ptr = x;
    ptr++;
    for (int i = 0; i < NSize; i++)
    {
      *ptr = str[i];
      ptr++;
    }
  }
  return (copy);
}

char* PopFront (const char* str)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str);
    copy = (char*)calloc(size-1, sizeof(char));
    char *ptr = &copy[0];

    for (int i = 1; i < size; i++)
    {
      *ptr = str[i];
      ptr++;
    }
  }
  return (copy);
}

char* PushMid (const char* str, char x)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str);
    if (size <= 1)
    {
      println ("ERRO: Tamanho invalido. ");
    }
    else
    {
      int mid = 0;
      copy = (char*)calloc((size+1), sizeof(char));
      char* ptr = &copy[0];

      mid = ((double)size/2.0);

      for (int i = 0; i < size; i++)
      {
        if (i == mid)
        {
          *ptr = x;
          ptr++;
        }
        *ptr = str[i];
        ptr++;
      }
    }
  }
  return (copy);
}

char* PopMid (const char* str)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str)-1;
    copy = (char*)calloc(size, sizeof(char));
    char *ptr = &copy[0];

    int mid = ((double)size/2.0);

    int y = 0;
    for (int i = 0; i < size; i++)
    {
      if (i == mid)
      {
        y++;
      }
      *ptr = str[y];
      ptr++;
      y++;
    }
  }
  return (copy);
}

char* StrInsert (const char* str, char x, int index)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str);
    if (index < 0 || index > (size))
    {
      println ("ERRO: Posicao invalida. ");
      std::cout << std::endl << "Deseja alterar a posicao ?" << std::endl << "[S/N]";
      char tmp = ReadChar(" ");
      if (tmp == 's' || tmp == 'S')
      {
        int Nindex = ReadInt("Nova posicao: ");
        copy = StrInsert(str, x, Nindex);
      }
    }
    else
    {
      copy = (char*)calloc(size+2, sizeof(char));
      char *ptr = &copy[0];

      for (int i = 0; i < size; i++)
      {
        if (i == index)
        {
          *ptr = x;
          ptr++;
        }
        *ptr = str[i];
        ptr++;
      }
    }
  }
  return (copy);
}

char* StrRemove (const char* str, char index)
{
  char* copy = null;
  if (str)
  {
    int size = strlen(str)-1;
    if (index < 0 || index > (size-1))
    {
      println ("ERRO: Posicao invalida. ");
      std::cout << std::endl << "Deseja alterar a posicao ?" << std::endl << "[S/N]";
      char tmp = ReadChar(" ");
      if (tmp == 's' || tmp == 'S')
      {
        int Nindex = ReadInt("Nova posicao: ");
        copy = StrRemove(str, Nindex);
      }
    }
    else
    {
      copy = (char*)calloc(size, sizeof(char));
      char *ptr = &copy[0];

      int y = 0;
      for (int i = 0; i < size; i++)
      {
        if (i == index)
        {
          y++;
        }
        *ptr = str[y];
        ptr++;
        y++;
      }
    }
  }
  return (copy);
}

char* StrFind (char* str, char x)
{
  char* result = null;
  if (str)
  {
    int i = 0;
    int size = strlen(str);
    char *ptr = &str[0];
    while (i < size && *ptr != x)
    {
      i++;
      ptr++;
    }

    if (i < size)
    {
      result = ptr;
    }    
    ptr = null;
  }
  return (result);
}

char* StrSplit (char* str, char x)
{
  char* result = null;
  if (str)
  {
    int i = 0;
    int size = strlen(str);
    result = (char*)calloc(1, sizeof(char));
    while (i < size && str[i] != x)
    {
      i++;
    }
    if (i < size)
    {
      result = &str[i];
    }    
  }
  return (result);
}

char* tok (char* str, char x)
{
  char* result = null;
  if (str)
  {
    int i = 0;
    int size = strlen(str);
    result = (char*)calloc(size+1, sizeof(char));
    while (i < size && str[i] != x)
    {
      result[i] = str[i];
      i++;
    }
    int Rsize = strlen(result);
    if (Rsize < size)
    {
      result = (char*)realloc(result, (Rsize+1)*sizeof(char));
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
  char* str = null;
  char* resultado = null;
  char x = '0';
  int tamanho = 0;
  int posicao = 0;

  // Apresentacao
  println ("ED1507");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  x = ReadChar ("Forneca o caractere a ser inserido na cadeia: ");
  posicao = ReadInt ("Forneca a posicao da cadeia onde ele sera inserido: ");

  // Adicionar caractere na posicao fornecida
  resultado = StrInsert(str, x, posicao);

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

void ED1508 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  int tamanho = 0;
  int posicao = 0;

  // Apresentacao
  println ("ED1508");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  posicao = ReadInt ("Forneca a posicao da cadeia onde o caractere sera removido: ");

  // Removar caractere da posicao fornecida
  resultado = StrRemove(str, posicao);

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

void ED1509 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  int tamanho = 0;
  char x = '0';

  // Apresentacao
  println ("ED1509");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt ("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  x = ReadChar ("Forneca o caractere a ser procurado na cadeia: ");

  // Procurar caractere na cadeia 
  resultado = StrFind(str, x);

  // Verificar dados
  // Mostrar dados
  std::cout << resultado << std::endl;

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1510 (void)
{
  // Identificacao de dados
  char* str = null;
  char* resultado = null;
  int tamanho = 0;
  char x = '0';

  // Apresentacao
  println ("ED1510");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  tamanho = ReadInt("Forneca o tamanho da cadeia: ");
  str = WriteArray<char>(tamanho);
  x = ReadChar("");

  resultado = tok(str, x);

  PrintArray(str);
  PrintArray(resultado);

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