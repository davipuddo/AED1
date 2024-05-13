//853355_AED1

#include "io.h"
#include "puddo.h"

/** Retornar valores inteiros e positivos de um array de um arquivo
 *  @param Nome do arquivo
 *  @param Valor qualquer (Ponto de retorno do tamanho final do array)
 *  @returns Array de valores inteiros positivos
 */ 
int *IntArrayEvenPositiveFile (char *fileName, int *tamanho)
{
  int *array = NULL;
  array = IntArrayPositive(IntMultipleArray(IntArrayFile(fileName, &(*tamanho)), &(*tamanho), 2), &(*tamanho));
  int *resultado = (int*)malloc(*tamanho*sizeof(int));
  resultado = array;
  return (resultado);
}

/** Retornar o menor valor inteiro impar de um arranjo em um arquivo
 *  @param Nome do arquivo
 *  @returns Valor inteiro impar
*/
int IntArraySmallestOddFile (char *fileName)
{
  int tamanho = 0;
  return ( IntArraySmallest(IntArrayOdd(IntArrayFile(fileName, &tamanho), &tamanho), tamanho) );
}

/** Retornar o maior valor inteiro impar de um arranjo em um arquivo
 *  @param Nome do arquivo
 *  @returns Valor inteiro impar
*/
int IntArrayBiggestOddFile (char *fileName)
{
  int tamanho = 0;
  return ( IntArrayBiggest(IntArrayOdd(IntArrayFile(fileName, &tamanho), &tamanho), tamanho) );
}

/** Descobrir se um arranjo esta ordenado de forma decrescente
 *  @param Array
 *  @param Tamanho do array
 *  @returns Valor Booleano
*/
bool IntOrderedArray (int *array, int tamanho)
{
  int y = 0;
  int z = 0;
  for (int i = 0; i < tamanho; i++)
  {
    if (i != 0)
    { 
      if (array[i] < array[i-1])
      {
        y++;
      }
    }
  }
  if ((y+1) == tamanho)
  {
    z = 1;
  } else {
    z = 0;
  }
  return (z);
}

/** Procurar um valor inteiro dentro de um arranjo
 *  @param Arranjo
 *  @param Tamanho do arranjo
 *  @param Valor a ser procurado
 *  @param Valor para determinar a posicao inicial
 *  @returns Valor booleano
*/
bool IntSearchArray (int *array, int tamanho, int valor, int inicio)
{
  int x = 0;
  if (inicio < 0)
  {
    inicio = 0;
  }
  for (int i = inicio; i < tamanho; i++)
  {
    if (valor == array[i])
    {
      x = 1;
    }
  }
  return (x);
}


void ED0801 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int *arranjo = NULL;

  // Apresentacao
  println ("ED0801");
  println ("");                  // Pular uma linha
  printf  ("%s", "Ler o tamanho de um arranjo para inteiros, depois ler todos os seus elementos garantindo que");
  println ("so tenha valores pares e positivos. ");
  println ("");                  // Pular uma linha

  // Ler dados
  do
  {
    tamanho = ReadInt ("Forneca um tamanho para o arranjo: ");
  } while (tamanho < 0);

  arranjo = IntWriteArray(tamanho);
  int *resultado = IntMultipleArray(arranjo, &tamanho, 2); 

  IntPrintArray(resultado, tamanho);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0802 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int *array = NULL;
  int *resultado = NULL;

  // Apresentacao
  println ("ED0802");
  println ("");                  // Pular uma linha
  printf  ("Ler um arranjo com numeros inteiros e positivos de um arquivo. Valores impares e nagativos ");
  printf  ("deverao ser descartados, o arranjo e nome do arquivo serao dados como parametros. ");
  printf  ("Gravar em um arquivo primeiro o tamanho, depois os elementos, um dado por linha. ");
  println ("");                  // Pular uma linha

  // Ler dados
  tamanho = ReadInt ("Forneca o tamanho do arranjo: ");
  array = IntWriteArray(tamanho);

  // Gravar array no arquivo "DADOS02.TXT"
  IntWriteArrayFile ("DADOS02.TXT", tamanho, array);

  // Retornar valores inteiros pares e positivos do arquivo "DADOS02.TXT"
  resultado = IntArrayEvenPositiveFile("DADOS02.TXT", &tamanho);

  // Mostrar dados
  IntPrintArray (resultado, tamanho);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0803 (void)
{
  // Identificacao de dados
  int n = 0;
  int x = 0;
  int y = 0;

  // Apresentacao
  println ("ED0803");
  println ("");                  // Pular uma linha
  printf  ("Com uma funcao gerar um valor inteiro aleatoriamente dentro de um intervalo, cujos ");
  printf  ("limites de inicio e de fim serao recebidos como parametros. Para testar, ler os limites ");
  printf  ("do intervalo do teclado e depois ler a quantidade [n] de elementos a serem gerados. ");
  printf  ("Gerar essa quantidade [n] de valores aleatorios e armazenar em um arranjo, grava-los ");
  println (", um por linha, em um arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    n = ReadInt ("Forneca a quantidade de valores aleatorios a ser gerada: ");
  } while (n <= 0);

  x = ReadInt ("Forne um valor para determinar o menor valor de um intervalo: ");

  do
  {
    y = ReadInt ("Forne um valor para determinar o maior valor de um intervalo: ");
  } while (x > y);

  // Gravar array de numeros aleatorios no arquivo "DADOS03.TXT" 
  IntWriteArrayFile("DADOS03.TXT", n, IntArrayRandInterval (x, y, n));
  
  // Mostrar dados
  //IntPrintFile     ("DADOS03.TXT");
  IntPrintArrayFile("DADOS03.TXT");

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0804 (void)
{
  // Identificacao de dados
  int tamanho = 0;

  // Apresentacao
  println ("ED0804");
  println ("");                  // Pular uma linha
  printf  ("Incluir um metodo e uma funcao para procurar o menor valor impar em um arranjo de um arquivo. ");
  printf  ("Para testar, receber o nome de um arquivo como parametro e aplicar a funcao sobre o ");
  println ("arranjo com os valores lidos do arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    tamanho = ReadInt("Forneca um tamanho para o arranjo: ");
  } while (tamanho <= 0);

  // Gravar array no arquivo "DADOS04.TXT"
  IntWriteArrayFile("DADOS04.TXT", tamanho, IntWriteArray(tamanho));
  
  // Mostrar dados
  printf ("%d", IntArraySmallestOddFile("DADOS04.TXT"));

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0805 (void)
{
  // Identificacao de dados
  int tamanho = 0;

  // Apresentacao
  println ("ED0805");
  println ("");                  // Pular uma linha
  printf  ("Incluir um metodo e uma funcao para procurar o maior valor impar em um arranjo de um arquivo. ");
  printf  ("Para testar, receber um nome de arquivo como parametro e aplicar a funcao sobre o ");
  println ("arranjo com  os valores lidos do arquivo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    tamanho = ReadInt("Forneca um tamanho para o arranjo: ");
  } while (tamanho <= 0);

  // Gravar array no arquivo "DADOS05.TXT"
  IntWriteArrayFile("DADOS05.TXT", tamanho, IntWriteArray(tamanho));

  // Mostrar dados
  printf ("%d", IntArrayBiggestOddFile("DADOS05.TXT"));

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0806 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int *array = NULL;
  int *dados = NULL;
  double media = 0.0;

  // Apresentacao
  println ("ED0806");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para determinar a media de valores em um arranjo. Para testar, ler um arquivo ");
  printf  ("e armazenar seus dados em um arranjo, separar este arranjo em 2 arquivos, um com os valores ");
  println ("menores ou iguais a media, e no outro os maiores do que ela. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
   do
  {
    tamanho = ReadInt("Forneca um tamanho para o arranjo: ");
  } while (tamanho <= 0);

  // Gravar array no arquivo "DADOS06.TXT"
  array = IntWriteArray(tamanho);
  IntWriteArrayFile ("DADOS06.TXT", tamanho, array);

  // Ler arquivo "DADOS06.TXT"
  dados = IntArrayFile("DADOS06.TXT", &tamanho);
  media = IntArrayAverage(dados, tamanho);
  int w = tamanho;
  int p = tamanho;

  int *maior = IntArrayBigger(dados, &w, (int)media );
  IntWriteArrayFile("MAIORES.TXT", w, maior);

  int *menor = IntArraySmaller_E (dados, &p, (int)media);
  IntWriteArrayFile("MENORES.TXT", p, menor);

  // Mostrar dados
  printf ("Media: %.2lf\n", media);
  IntPrintArrayFile ("MAIORES.TXT");
  IntPrintArrayFile ("MENORES.TXT");

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0807 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int *array = NULL;

  // Apresentacao
  println ("ED0807");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para receber um arranjo como parametro e dizer se esta ordenado, ou nao, ");
  println ("em ordem decrescente. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    tamanho = ReadInt("Forneca um tamanho para o arranjo: ");
  } while (tamanho <= 0);

  array = IntWriteArray(tamanho);

  // Mostrar dados
  if (IntOrderedArray(array, tamanho))
  {
    println ("O arranjo esta ordenado de forma decrescente. ");
  }
  else
  {
    println ("O arranjo nao esta ordenado de forma decrescente. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0808 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int x = 0;
  int p = 0;
  int *array = NULL;
  int *dados = NULL;

  // Apresentacao
  println ("ED0808");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para procurar determinado valor em um arranjo e dizer se esse valor ");
  printf  ("pode ser encontrado nele, a partir de uma certa posicao inicial. Para testar, ler um arquivo e ");
  printf  ("armazenar os dados em um arranjo, depois ler um valor a ser procurando dentro do arranjo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    tamanho = ReadInt("Forneca o tamanho do arranjo: ");
  } while (tamanho <= 0);

  array = IntWriteArray(tamanho);
  x = ReadInt ("Forneca um valor para ser procurado no arranjo: ");
  p = ReadInt ("Forneca um valor para definir a posicao inicial de procura: ");

  // Gravar dados no arquivo "DADOS08.TXT"
  IntWriteArrayFile("DADOS08.TXT", tamanho, array);

  dados = IntArrayFile("DADOS08.TXT", &tamanho);

  // Mostrar dados
  if (IntSearchArray(dados, tamanho, x, p))
  {
    println ("O valor fornecido pode ser encontrado no arranjo. ");
  }
  else
  {
    println ("O valor fornecido nao pode ser encontrado no arranjo. ");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0809 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int x = 0;
  int p = 0;
  int resultado = 0;
  int *array = NULL;
  int *dados = NULL;

  // Apresentacao
  println ("ED0809");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para procurar por determinado valor em um arranjo e dizer a posicao deste. ");
  printf  ("Para testar, ler um arquivo e armazenar seus dados em um arranjo, e depois ler um valor inteiro ");
  printf  ("para ser procurado, e determinar em qual posicao ele foi encontrado, se houver. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    tamanho = ReadInt ("Forneca um tamanho para o arranjo: ");
  } while (tamanho <= 0); 

  array = IntWriteArray(tamanho);
  x = ReadInt ("Forneca o valor que deseja procurar: ");
  p = ReadInt ("Forneca um valor para definir a posicao inicial da procura: ");
  
  // Gravar dados no arquivo "DADOS09.TXT"
  IntWriteArrayFile("DADOS09.TXT", tamanho, array);
  
  // Ler dados do arquivo "DADOS09.TXT"
  dados = IntArrayFile("DADOS09.TXT", &tamanho);

  // Salvar o tamanho do arranjo
  int n = tamanho;

  // Procurar dados
  resultado = IntFindArray(dados, &n, x, p);

  // Mostrar dados
  if (n != 0)
  {
    printf ("O valor '%d'  foi encontrado %d vez(es), a ultima vez na posicao [%d]\n", x, n, resultado);
  }
  else
  {
    printf ("O valor '%d' nao foi encontrado no arranjo. \n", x);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void ED0810 (void)
{
  // Identificacao de dados
  int tamanho = 0;
  int x = 0;
  int p = 0;
  int resultado = 0;
  int *array = NULL;
  int *dados = NULL;

  // Apresentacao
  println ("ED0810");
  println ("");                  // Pular uma linha
  printf  ("Incluir uma funcao para procurar por determinado valor em um arranjo e dizer quantas ");
  printf  ("vezes esse valor foi encontrado, dada uma certa posicao inicial da busca. Para testar ");
  printf  ("ler um arquivo e armazenar seus dados em um arranjo, depois ler um valor inteiro para ser ");
  println ("procurado e determinar quantas vezes ele foi encontrado, se hover. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    tamanho = ReadInt ("Forneca um tamanho para o arranjo: ");
  } while (tamanho <= 0);

  dados = IntWriteArray (tamanho);

  // Gravar dados no arquivo "DADOS10.TXT"
  IntWriteArrayFile ("DADOS10.TXT", tamanho, dados);

  // Ler dados do arquivo "DADOS10.TXT"
  array = IntArrayFile ("DADOS10.TXT", &tamanho);

  x = ReadInt ("Forneca o valor inteiro a ser procurado: ");
  p = ReadInt ("Forneca um valor inteiro para determinar a posicao inicial da busca: ");

  // Procurar valor
  int w = tamanho;
  resultado = IntFindArray (array, &w, x, p);

  // Mostrar dados
  if (w != 0)
  {
    printf ("O valor '%d'  foi encontrado %d vez(es), a ultima vez na posicao [%d]\n", x, w, resultado);
  }
  else
  {
    printf ("O valor '%d' nao foi encontrado no arranjo. \n", x);
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
      println ("ED08 - v1.0 - 04/26/24" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - ED0801   2 - ED0802");
      println ("3 - ED0803   4 - ED0804");
      println ("5 - ED0805   6 - ED0806");
      println ("7 - ED0807   8 - ED0808");
      println ("9 - ED0809  10 - ED0810");
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
          case 1:  ED0801();
            break;
          case 2:  ED0802();
            break;
          case 3:  ED0803();
            break;
          case 4:  ED0804();
            break;
          case 5:  ED0805();
            break;
          case 6:  ED0806();
            break;
          case 7:  ED0807();
            break;
          case 8:  ED0808();
            break;
          case 9:  ED0809();
            break;
          case 10: ED0810();
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
    0.0         00/00/00    (OK)       Criacao do arquivo ED08 e seus metodos

*/