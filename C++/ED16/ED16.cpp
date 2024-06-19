//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


void ED1601 (void)
{
  // Identificacao de dados
  Cell<int> dados(0, null);
  int elemento = 0;

  // Apresentacao
  println ("ED1601");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(4);
  dados.WriteCells();
  elemento = ReadInt("Forneca um valor inteiro para ser adicionado ao final: ");

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Operacao
  dados.PushBack(elemento);

  // Mostrar dados
  println ("Alterado -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1602 (void)
{
  // Identificacao de dados
  Cell <int> dados (0, null);

  // Apresentacao
  println ("ED1602");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(5);
  dados.WriteCells();

  println ("Original -");
  dados.print();

  // Operacao
  dados.PopBack();

  // Mostrar dados
  println ("Alterado -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1603 (void)
{
  // Identificacao de dados
  Cell<int> dados(0, null);
  int elemento = 0;

  // Apresentacao
  println ("ED1603");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(4);
  dados.WriteCells();
  elemento = ReadInt("Forneca um valor inteiro para ser adicionado ao inicio: ");

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Operacao
  dados.PushFront(elemento);

  // Mostrar dados
  println ("Alterado -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1604 (void)
{
  // Identificacao de dados
  Cell <int> dados (0, null);

  // Apresentacao
  println ("ED1604");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(5);
  dados.WriteCells();

  println ("Original -");
  dados.print();

  // Operacao
  dados.PopFront();

  // Mostrar dados
  println ("Alterado -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1605 (void)
{
  // Identificacao de dados
  Cell <int> dados (0, null);
  int elemento = 0;

  // Apresentacao
  println ("ED1605");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(5);
  dados.WriteCells();
  elemento = ReadInt("Forneca um valor inteiro para ser adicionado ao inicio: ");

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Operacao
  dados.PushMid(elemento);

  // Mostrar dados
  println ("Alterado -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1606 (void)
{
  // Identificacao de dados
  Cell <int> dados (0, null);

  // Apresentacao
  println ("ED1606");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(4);
  dados.WriteCells();

  println ("Original -");
  dados.print();

  // Operacao
  dados.PopMid();

  // Mostrar dados
  println ("Alterado -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1607 (void)
{
  // Identificacao de dados
  Cell<int> dados1(0, null);
  Cell<int> dados2(0, null);
  bool resultado = false;

  // Apresentacao
  println ("ED1607");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  println ("Primeira celula -");
  dados1.AddCells(ReadInt("Forneca a quantidade de elementos da celula: ")-1);
  dados1.WriteCells();
  println ("Segunda celula -");
  dados2.AddCells(ReadInt("Forneca a quantidade de elementos da celula: ")-1);
  dados2.WriteCells();

  // Comparar celulas
  resultado = dados1 == dados2;

  // Mostrar dados
  if (resultado)
  {
    println ("As celulas sao iguais. ");
  }   
  else
  {
    println ("As celulas sao diferentes. ");
  }
  println ("\nPrimeira celula -\n");
  dados1.print();
  println ("Segunda celula -\n");
  dados2.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1608 (void)
{
  // Identificacao de dados
  
  // Apresentacao
  println ("ED1608");
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

void ED1609 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1609");
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

void ED1610 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1610");
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
      println ("ED16 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1601   2 - ED1602");
      println ("3 - ED1603   4 - ED1604");
      println ("5 - ED1605   6 - ED1606");
      println ("7 - ED1607   8 - ED1608");
      println ("9 - ED1609  10 - ED1610");
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
          case 1:  ED1601();
            break;
          case 2:  ED1602();
            break;
          case 3:  ED1603();
            break;
          case 4:  ED1604();
            break;
          case 5:  ED1605();
            break;
          case 6:  ED1606();
            break;
          case 7:  ED1607();
            break;
          case 8:  ED1608();
            break;
          case 9:  ED1609();
            break;
          case 10: ED1610();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED16 e seus metodos

*/