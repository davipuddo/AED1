//853355_AED1

#include "..\io.h"
#include "..\puddo.h"

void ED1001 (void)
{
  // Identificacao de dados
  int_array array;
  int inferior = 0;
  int superior = 0;
  int n = 0;

  // Apresentacao
  println ("ED1001");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  inferior = ReadInt ("Forneca um valor para determinar o intervalo inferior: ");
  superior = ReadInt ("Forneca um valor para determinar o intervalo superior: ");
  n = ReadInt ("Forneca um valor para determinar a quantidade de valores aleatorios a serem gerados: ");

  // Gerar arranjo de valores aleatorios
  array = IntRandIntervalArray(inferior, superior, n);

  // Gravar dados em um arquivo
  if (array.data)
  {
    IntWriteArrayFile ("DADOS01.TXT", array);
  }

  // Mostrar dados
  IntPrintArrayFile ("DADOS01.TXT");

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1002 (void)
{
  // Identificacao de dados
  int_array array;
  int valor = 0;
  int i = 0;
  int resultado = 0;

  // Apresentacao
  println ("ED1002");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  IntWriteArrayFile("DADOS02.TXT", ReadIntArray(array));
  
  valor = ReadInt ("Forneca um valor a ser procurado: ");
  i = ReadInt ("Forneca um valor inteiro para determinar a posicao inicial: ");

  // Ler dados do arquivo
  int_array Farray = IntArrayFile("DADOS02.TXT");

  // Procurar dados
  resultado = IntFindArray(valor, i, Farray);

  // Mostrar dados
  if (resultado >= 0)
  {
    printf ("posicao: %d\n", resultado);
  }
  else
  {
    printf ("O valor fornecido nao foi encontrado no arranjo. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1003 (void)
{
  // Identificacao de dados
  int_array array1;
  int_array array2;
  
  int_array farray1;
  int_array farray2;

  int resultado = 0;

  // Apresentacao
  println ("ED1003");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array1 = ReadIntArray();
  array2 = ReadIntArray();

  // Gravar arranjos em arquivos diferentes
  IntWriteArrayFile ("ARRANJO1.TXT", array1);
  IntWriteArrayFile ("ARRANJO2.TXT", array2);

  // Liberar espaco
  if (array1.data)
  {
    free (array1.data);
  }
  if (array2.data)
  {
    free (array2.data);
  }

  // Ler dados do arquivo
  farray1 = IntArrayFile ("ARRANJO1.TXT");
  farray2 = IntArrayFile ("ARRANJO2.TXT");

  // Verificar se os dados existem
  if (farray1.data && farray2.data)
  {
    // Comparar arranjos
    resultado = IntCmpArray (farray1, farray2);

    // Liberar espaco
    free (farray1.data);
    free (farray2.data);
  }
  else
  {
    println ("ERRO: Dados inexistentes. ");
  }

  // Mostrar dados
  if (resultado == 1)
  {
    println ("Os arranjos sao iguais. ");
  }
  else
  {
    println ("Os arranjos sao diferentes. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1004 (void)
{
  // Identificacao de dados
  int_array array1;
  int_array array2;
  int constante = 0;
  ref_int_array resultado;

  // Apresentacao
  println ("ED1004");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha

  // Ler dados
  constante = ReadPositiveInt ("Forneca um valor inteiro para definir o escalamento do segundo arranjo: ");
  array1 = ReadIntArray();
  array2 = ReadIntArray();

  // Testar compatibilidade
  if (array1.length != (int)((double)array2.length/(double)constante))
  {
    pritln ("O tamanho dos arranjos sao incompativeis");
  }
  else
  {
    // Escrever arranjos em arquivos
    if (array1.data)
    {
      IntWriteArrayFile ("DADOS41.TXT", array1);
    }
    if (array2.data)
    {
      IntWriteArrayFile ("DADOS42.TXT", array2);
    }

    // Ler arranjos do arquivo
    int_array Farray1 = IntArrayFile("DADOS41.TXT");
    int_array Farray2 = IntArrayFile("DADOS42.TXT");

    // Somar arranjos
    if (Farray1.data && Farray2.data)
    {
      resultado = IntAddConstArray (Farray1, Farray2, constante);

      // Mostrar dados
      if (resultado)
      {
        println ("Arranjo 1 -\n");
        IntPrintArray (Farray1);
        println ("\nArranjo 2 -\n");
        IntPrintArray (Farray2);
        println ("\nSoma -\n");
        IntPrintArray (*resultado);

        // Liberar memoria
        IntFreeArray (resultado);
      }
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED1005 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1005");
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

void ED1006 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1006");
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

void ED1007 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1007");
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

void ED1008 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1008");
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

void ED1009 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1009");
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

void ED1010 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("ED1010");
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
      println ("ED10 - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED1001   2 - ED1002");
      println ("3 - ED1003   4 - ED1004");
      println ("5 - ED1005   6 - ED1006");
      println ("7 - ED1007   8 - ED1008");
      println ("9 - ED1009  10 - ED1010");
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
          case 1:  ED1001();
            break;
          case 2:  ED1002();
            break;
          case 3:  ED1003();
            break;
          case 4:  ED1004();
            break;
          case 5:  ED1005();
            break;
          case 6:  ED1006();
            break;
          case 7:  ED1007();
            break;
          case 8:  ED1008();
            break;
          case 9:  ED1009();
            break;
          case 10: ED1010();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED10 e seus metodos

*/