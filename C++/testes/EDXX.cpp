//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"

template <typename T>
class Set
{
  private:

  T* data;
  int size;

  public:

  Set (int n)
  {
    data = null;
    size = 0;

    if (n > 0)
    {
      data = new T[n];
      size = n;
    }
  }

  Set ()
  {
    data = null;
    size = 0;
  }

  ~Set ()
  {
    delete (data);
    size = 0;
  }

  void write ()
  {
    if (data)
    {
      for (int i = 0; i < size; i++)
      {
        data[i] = ReadInt("");
      }
      std::cout << std::endl;
    }
  }

  void print ()
  {
    if (data && size > 0)
    {
      for (int i = 0; i < size; i++)
      {
        std::cout << data[i] << std::endl;
      }
      std::cout << std::endl;
    }
  }

  bool isValid()
  {
    bool result = false;
    result = (data);
    return (result);
  }

  Set* Union (Set* s2)
  {
    Set* result = null;
    Set* s1 = this;
    if (s1 && s1->data && s2 && s2->data)
    {
      result = new Set((s1->size + s2->size));

      if (result && result->data)
      {
        // Copiar primeiro conjunto
        int i = 0;
        while (i < s1->size)
        {
          result->data[i] = s1->data[i];
          i++;
        }

        // Unir ao segundo conjunto
        int y = 0;
        while (y < s2->size)
        {
          bool flag = false;
          int w = 0;
          while (w < result->size && !flag)
          {
            flag = (result->data[w] == s2->data[y]);
            w++;
          }
          if (!flag)
          {
            result->data[i] = s2->data[y];
            i++;
          }
          y++;
        }

        // Reduzir tamanho do resultado
        if (i < result->size)
        {
          Set* tmp = new Set(i);
          if (tmp && tmp->data)
          { 
            for (int t = 0; t < i; t++)
            {
              tmp->data[t] = result->data[t];
            }
            delete (result->data);
            result = tmp;
          }
        }
      }
    }
    return (result);
  }

};


void ED0X01 (void)
{
  // Identificacao de dados
  Set<int>* s1 = new Set<int>(3);
  Set<int>* s2 = new Set<int>(3);
  Set<int>* result = null;

  // Apresentacao
  println ("ED0X01");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  s1->write();
  s2->write();
  result = s1->Union(s2);
  result->print();
  // Operacao
  // Mostrar dados

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0X02 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X02");
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

void ED0X03 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X03");
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

void ED0X04 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X04");
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

void ED0X05 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED0X05");
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