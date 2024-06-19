//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


void ED1501 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  char caractere = '0';

  // Apresentacao
  println ("ED1501");
  println ("");                  // Pular uma linha
  println ("Adicionar caractere no final. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas 
  dados.AddCells(4);

  // Ler dados
  dados.WriteCells();
  dados.print();
  
  caractere = ReadChar("Forneca um caractere a ser adicionado ao final: ");

  // Adicionar celula no final
  dados.PushBack(caractere);

  // Mostrar dados
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1502 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);

  // Apresentacao
  println ("ED1502");
  println ("");                  // Pular uma linha
  println ("Remover caractere no final. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas 
  dados.AddCells(5);
  
  // Ler dados
  dados.WriteCells();

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Remover ultima celula
  dados.PopBack();

  // Mostrar dados
  println ("Alterada -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1503 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  char caractere = '0';

  // Apresentacao
  println ("ED1503");
  println ("");                  // Pular uma linha
  println ("Adicionar caractere no inicio. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas 
  dados.AddCells(4);

  // Ler dados
  dados.WriteCells();
  dados.print();
  
  caractere = ReadChar("Forneca um caractere a ser adicionado ao inicio: ");

  // Adicionar celula no inicio
  dados.PushFront(caractere);

  // Mostrar dados
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1504 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);

  // Apresentacao
  println ("ED1504");
  println ("");                  // Pular uma linha
  println ("Remover caractere do inicio. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas 
  dados.AddCells(5);

  // Ler dados
  dados.WriteCells();

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Remover primeira celula
  dados.PopFront();

  // Mostrar dados
  println ("Alterada -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1505 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  char caractere = '0';

  // Apresentacao
  println ("ED1505");
  println ("");                  // Pular uma linha
  println ("Adicionar caractere no meio. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas 
  dados.AddCells(5);

  // Ler dados
  dados.WriteCells();
  dados.print();
  
  caractere = ReadChar("Forneca um caractere a ser adicionado ao meio: ");

  // Adicionar celula ao meio
  dados.PushMid(caractere);

  // Mostrar dados
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1506 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);

  // Apresentacao
  println ("ED1506");
  println ("");                  // Pular uma linha
  println ("Remover caractere do meio. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas 
  dados.AddCells(4);

  // Ler dados
  dados.WriteCells();

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Remover celula do meio
  dados.PopMid();

  // Mostrar dados
  println ("Alterada -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1507 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  char caractere = '0';
  int posicao = 0;

  // Apresentacao
  println ("ED1507");
  println ("");                  // Pular uma linha
  println ("Adicionar um caractere em uma posicao [n]. ");
  println ("");                  // Pular uma linha

  // Adicionar celulas   
  dados.AddCells(4);

  // Ler dados
  dados.WriteCells();
  dados.print();
  
  posicao = ReadInt("Forneca uma posicao para adicionar um caractere: ");
  caractere = ReadChar("Forneca um caractere a ser adicionado a uma posicao fornecida: ");

  // Adicionar celula a posicao fornecida
  dados.insert(caractere, posicao);

  // Mostrar dados
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1508 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  int posicao = 0;

  // Apresentacao
  println ("ED1508");
  println ("");                  // Pular uma linha
  println ("Remover um caractere de uma posicao [n]. ");
  println ("");                  // Pular uma linha

  // Adicionar celulas  
  dados.AddCells(4);

  // Ler dados
  dados.WriteCells();
  posicao = ReadInt("Forneca um posicao para remover um caractere: ");

  // Mostrar dados
  println ("Original -");
  dados.print();

  // Remover celula da posicao fornecida
  dados.remove(posicao);

  // Mostrar dados
  println ("Alterada -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1509 (void)
{
  // Identificacao de dados
  Cell <char> dados('0', null);
  ref_char_Cell resultado = null;
  char caractere = '0';

  // Apresentacao
  println ("ED1509");
  println ("");                  // Pular uma linha
  println ("Procurar pela primeira ocorrencia de um simbolo. ");
  println ("");                  // Pular uma linha
    
  // Adicionar celulas
  dados.AddCells(5);

  // Ler dados
  dados.WriteCells();
  caractere = ReadChar("Forneca um caractere a ser procurado: ");

  // Procurar caractere
  resultado = dados.find(caractere);

  // Verificar dados
  if (resultado)
  {
    // Mostrar dados
    std::cout << "O caractere [" << resultado->getData() << 
    "] foi encontrado na celula no endereco: " << resultado << std::endl; 
  }
  else
  {
    std::cout << "O caractere [" << caractere << "] nao foi encontrado na celula. ";
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1510 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  char caractere = '0';

  // Apresentacao
  println ("ED1510");
  println ("");                  // Pular uma linha
  println ("Separar caracteres ate ocorrencia de um delimitador [x]. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados.AddCells(4);
  dados.WriteCells();
  caractere = ReadChar("Forneca o caractere delimitador: ");
  
  // Mostrar dados
  println ("Original -");
  dados.print();

  // Delimitar
  dados.tok(caractere);

  // Mostrar dados
  println ("Alterada -");
  dados.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED15E1 (void)
{
  // Identificacao de dados
  Cell<char> dados('0', null);
  ref_char_Cell resultado = null;
  char* prefixo = null;
  std::string str = "";

  // Apresentacao
  println ("ED15E1");
  println ("");                  // Pular uma linha
  println ("Procurar por um certo sufixo. ");
  println ("");                  // Pular uma linha

  // Ler dados
  str = ReadString("Forneca uma cadeia de caracteres para fornecer os dados da celula: ");
  dados.AddCells((str.length())-1);
  dados.WriteCellsB(str, 0);
  prefixo = WriteArray<char>(2);

  // Procurar prefixo
  resultado = dados.prefix(prefixo);

  if (resultado)
  {
    // Separar palavras
    resultado->tok(' ');

    // Mostrar dados
    resultado->print();
  }
  else
  {
    println ("Prefixo nao encontrado. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED15E2 (void)
{
  Cell<char> dados('0', null);
  ref_char_Cell resultado = null;
  char* sufixo = null;
  std::string str = "";

  // Apresentacao
  println ("ED15E2");
  println ("");                  // Pular uma linha
  println ("Procurar por um certo sufixo. ");
  println ("");                  // Pular uma linha

  // Ler dados
  str = ReadString("Forneca uma cadeia de caracteres para fornecer os dados da celula: ");
  dados.AddCells(str.length());
  dados.WriteCellsB(str, 0);
  sufixo = WriteArray<char>(2);

  // Procurar sufixo
  resultado = dados.sufix(sufixo);

  if (resultado)
  {
    // Separar palavras
    resultado->tok(' ');

    // Mostrar dados
    resultado->print();
  }
  else
  {
    println ("Sufixo nao encontrado. ");
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
      println ("ED15 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0  - sair");
      println ("1  - ED1501   2 - ED1502");
      println ("3  - ED1503   4 - ED1504");
      println ("5  - ED1505   6 - ED1506");
      println ("7  - ED1507   8 - ED1508");
      println ("9  - ED1509  10 - ED1510");
      println ("11 - ED15E1  12 - ED15E2");
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
          case 11: ED15E1();
            break;
          case 12: ED15E2();
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