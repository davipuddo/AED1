//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"


void ED1701 (void)
{
  // Identificacao de dados
  ref_int_Stack dados = null;

  // Apresentacao
  println ("ED1701");
  println ("");                  // Pular uma linha
  println ("Acrescentar valor ao topo da pilha. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Stack<int>;
  dados->write();
  
  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    dados->print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1702 (void)
{
  // Identificacao de dados
  ref_int_Stack dados = null;

  // Apresentacao
  println ("ED1702");
  println ("");                  // Pular uma linha
  println ("Remover valor do topo da pilha. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Stack<int>;
  dados->write();
  
  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    println ("Original -");
    dados->print();

    // Remover elemento do topo
    dados->pop();

    // Mostrar dados
    println ("Topo removido -");
    dados->print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1703 (void)
{
  // Identificacao de dados
  ref_int_Stack dados = null;
  ref_int_Stack resultado = null;

  // Apresentacao
  println ("ED1703");
  println ("");                  // Pular uma linha
  println ("Duplicar valor do topo da pilha. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Stack<int>;
  dados->write();
  
  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    println ("Original -");
    dados->print();

    // duplicar elemento do topo
    resultado = dados->dupTop();

    // Mostrar dados
    println ("Topo Duplicado -");
    resultado->print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1704 (void)
{
  // Identificacao de dados
  ref_int_Stack dados = null;
  ref_int_Stack resultado = null;

  // Apresentacao
  println ("ED1704");
  println ("");                  // Pular uma linha
  println ("Trocar ordem dos primeiros valores em uma pilha. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Stack<int>;
  dados->write();
  
  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    println ("Original -");
    dados->print();

    // trocar elemento do topo
    resultado = dados->swap();

    // Mostrar dados
    println ("Topo trocado -");
    resultado->print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1705 (void)
{
  // Identificacao de dados
  ref_int_Stack dados = null;
  ref_int_Stack result = null;

  // Apresentacao
  println ("ED1705");
  println ("");                  // Pular uma linha
  println ("Inverter ordem dos valores em uma pilha. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Stack<int>;
  dados->write();
  
  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    println ("Original -");
    dados->print();

    // trocar elemento do topo
    result = dados->invert();

    // Mostrar dados
    println ("Invertida -");
    result->print();
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1706 (void)
{
  // Identificacao de dados
  ref_int_Queue dados = null;
  int elemento = 0;

  // Apresentacao
  println ("ED1706");
  println ("");                  // Pular uma linha
  println ("Adicionar um valor ao final da fila");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Queue<int>;
  dados->write();
  elemento = ReadInt("Forneca um valor a ser adicionado na fila. ");

  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    println ("Original -");
    dados->print();

    // Remover primeiro da fila
    dados->push(elemento);

    // Verificar dados
    if (dados)
    {
      // Mostrar dados
      println ("Alterada -");
      dados->print();
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1707 (void)
{
  // Identificacao de dados
  ref_int_Queue dados = null;

  // Apresentacao
  println ("ED1707");
  println ("");                  // Pular uma linha
  println ("Remover primeiro valor de uma fila. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Queue<int>;
  dados->write();

  // Verificar dados
  if (dados)
  {
    // Mostrar dados
    println ("Original -");
    dados->print();

    // Remover primeiro da fila
    dados->pop();

    // Verificar dados
    if (dados)
    {
      // Mostrar dados
      println ("Alterada -");
      dados->print();
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1708 (void)
{
  // Identificacao de dados
  ref_int_Queue dados1 = null;
  ref_int_Queue dados2 = null;
  int resultado = 0;

  // Apresentacao
  println ("ED1708");
  println ("");                  // Pular uma linha
  println ("Comparar duas filas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  println ("Fila 1 -");
  dados1 = new Queue<int>;
  dados1->write();

  // Verificar dados
  if (dados1 && dados1->isValid())
  {
    println ("Fila 2 -");
    dados2 = new Queue<int>;
    dados2->write();

    // Verificar dados
    if (dados2 && dados2->isValid())
    {
      // Mostrar dados
      println ("Fila 1 -");
      dados1->print();
      println ("Fila 1 -");
      dados2->print();
      resultado = dados1->compare(dados2);
      std::cout << resultado << std::endl;
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1709 (void)
{
  // Identificacao de dados
  ref_int_Queue dados1 = null;
  ref_int_Queue dados2 = null;
  ref_int_Queue result = null;

  // Apresentacao
  println ("ED1709");
  println ("");                  // Pular uma linha
  println ("Juntar duas filas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  println ("Fila 1 -");
  dados1 = new Queue<int>;
  dados1->write();

  // Verificar dados
  if (dados1)
  {
    // Ler dados
    println ("Fila 2 -");
    dados2 = new Queue<int>;
    dados2->write();

    // Verificar dados
    if (dados2)
    {
      // Juntar filas
      result = dados1->join(dados2);

      // Mostrar dados
      if (result)
      {
        result->print();
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1710 (void)
{
  // Identificacao de dados
  ref_int_Queue dados;
  int elemento = 0;
  bool resultado = false;

  // Apresentacao
  println ("ED1710");
  println ("");                  // Pular uma linha
  println ("Procurar valor em uma fila. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados = new Queue<int>;
  dados->write();

  // Verificar dados
  if (dados)
  {
    // Ler dados
    elemento = ReadInt("");

    // Procurar valor na fila
    resultado = dados->search(elemento);

    // Verificar resultado
    if (resultado)
    {
      // Mostrar dados
      std::cout << "O valor [" << elemento << "] foi encontrado na fila. " << std::endl;
    }
    else
    {
      // Mostrar dados
      std::cout << "O valor [" << elemento << "] nao foi encontrado na fila. " << std::endl;
    }
    // Mostrar dados
    println ("");
    dados->print();

  }
  
  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED17E1 (void)
{
  // Identificacao de dados
  ref_int_Queue dados1 = null;
  ref_int_Queue dados2 = null;
  ref_int_Queue resultado = null;

  // Apresentacao
  println ("ED17E1");
  println ("");                  // Pular uma linha
  println ("Intercalar duas filas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados1 = new Queue<int>;
  dados1->write();

  // Verificar dados
  if (dados1 && dados1->isValid())
  {
    // Ler dados
    dados2 = new Queue<int>;
    dados2->write();

    // Verificar dados
    if (dados2 && dados1->isValid())
    {
      // Intercalar filas
      resultado = dados1->merge(dados2);

      if (resultado && resultado->isValid())
      {
        // Mostrar dados
        dados1->print();
        dados2->print();
        resultado->print();
      }
    }
  }
  
  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED17E2 (void)
{
  // Identificacao de dados
  ref_int_Queue dados1 = null;
  ref_int_Queue dados2 = null;
  ref_int_Queue resultado = null;

  // Apresentacao
  println ("ED17E2");
  println ("");                  // Pular uma linha
  println ("Intercalar duas filas em ordem crescente. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  dados1 = new Queue<int>;
  dados1->write();

  // Verificar dados
  if (dados1 && dados1->isValid())
  {
    // Ler dados
    dados2 = new Queue<int>;
    dados2->write();

    // Verificar dados
    if (dados2 && dados1->isValid())
    {
      // Intercalar filas
      resultado = dados1->mergeUp(dados2);

      if (resultado && resultado->isValid())
      {
        // Mostrar dados
        dados1->print();
        dados2->print();
        resultado->print();
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
      println ("ED17 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0  - sair");
      println ("1  - ED1701   2 - ED1702");
      println ("3  - ED1703   4 - ED1704");
      println ("5  - ED1705   6 - ED1706");
      println ("7  - ED1707   8 - ED1708");
      println ("9  - ED1709  10 - ED1710");
      println ("11 - ED17E1  12 - ED17E2");
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
          case 1:  ED1701();
            break;
          case 2:  ED1702();
            break;
          case 3:  ED1703();
            break;
          case 4:  ED1704();
            break;
          case 5:  ED1705();
            break;
          case 6:  ED1706();
            break;
          case 7:  ED1707();
            break;
          case 8:  ED1708();
            break;
          case 9:  ED1709();
            break;
          case 10: ED1710();
            break;
          case 11: ED17E1();
            break;
          case 12: ED17E2();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED17 e seus metodos

*/