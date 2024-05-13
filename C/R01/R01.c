//853355_AED1

#include "io.h"
#include "puddo.h"

/** 04/27/2024
 *  @author Davi Ferreira Puddo - 853355
*/


/** Retornar soma dos divisores impares de um numero inteiro
 *  @param Valor a ser somado
 *  @returns Soma dos divisores impares
*/
int *SomaDivisorImpar (int *valor, int tamanho)
{
  int total = 0;
  int *resultado = (int*)malloc(tamanho*sizeof(int));
  for (int i = 0; i < tamanho; i++)
  {
    for (int divisor = 1; divisor != 9; divisor += 2)
    {
      if (valor[i] % divisor == 0)
      {
        total += divisor;
      }
    }
    resultado[i] = total;
    total = 0;
  }
  return (resultado);
}

/** Verficar se os numeros de um array sao primos
 *  @param Array de numeros inteiros
 *  @param Tamanho do array
 *  @returns Array de zeros e uns ||  um para os primos e zero para os nao primos
*/
int *Primos (int *array, int tamanho)
{
  int *resultado = (int*)malloc(tamanho*sizeof(int));
  int y = 0;
  for (int i = 0; i < tamanho; i++)
  {
    if (array [i] > 0)
    {
      if (array[i] % 2 != 0 && array[i] % 3 != 0 && array[i] % 5 != 0 && array[i] % 7 != 0)
      {
        resultado[y] = 1;
        y++;
      }
      else if (array[i] == 2 || array[i] == 3 || array[i] == 5 || array[i] == 7)
      {
        resultado[y] = 1;
        y++;
      }
      else
      {
        resultado[y] = 0;
        y++;
      }
    }
    else
    {
      resultado[y] = 0;
      y++;
    }
  }
  return (resultado);
}


/** Descobrir se um simbolo e um operador logico
 *  @param Caractere
 *  @returns Valor booleano
*/
int IsLogic (char x)
{
  int y = 0;
  if (x == '&' || x == '|' || x == '!')
  {
    y = 1;    
  }
  return (y);
}

/** Descobrir se um simbolo e um operador aritimetico
 *  @param Caractere
 *  @returns Valor booleano
*/
int IsArithmetic (char x)
{
  int y = 0;
  if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
  {
    y = 1;
  }
  return (y);
}

/** Descobrir se um simbolo e um operador relacional
 *  @param Caractere
 *  @returns Valor booleano
*/
int IsRelational (char x)
{
  int y = 0;
  if (x == '>' || x == '<' || x == '=')
  {
    y = 1;
  }
  return (y);
}

/** Descobrir se um simbolo e um operador separador
 *  @param Caractere
 *  @returns Valor booleano
*/
int IsSeparator (char x)
{
  int y = 0;
  if (x == ' ' || x == ',' || x == '.' || x == ';' || x == ':' || x == '_')
  {
    y = 1;
  }
  return (y);
}

/** Encontrar operadores em uma cadeia de caracteres
 *  @param Cadeia de caracteres
 *  @returns Array de valores inteiros cada um representando um tipo de operador
 *  @note Logicos-1 Aritimeticos-2 Relacionais-3 Separadpres-4
*/
int *IsOperator (char *str)
{
  int TamStr = strlen(str);
  int *resultado = (int*)malloc(TamStr*sizeof(int));
  for (int i = 0; i < TamStr; i++)
  {
    if (IsLogic(str[i]))
    {
      resultado[i] = 1;
    }
    else if (IsArithmetic(str[i]))
    {
      resultado[i] = 2;
    }
    else if (IsRelational(str[i]))
    {
      resultado[i] = 3;
    }
    else if (IsSeparator(str[i]))
    {
      resultado[i] = 4;
    }
    else 
    {
      resultado[i] = 0;
    }
  }
  return (resultado);
}

/** Encontrar letras em uma cadeia de caracteres
 *  @param Cadeia de caracteres
 *  @returns Array de numeros inteiros, onde as letras maiusculas sao 5, e as miusculas 6
*/
int *IsLetter (char *str)
{
  int TamStr = strlen(str);
  int *resultado = (int*)malloc(TamStr*sizeof(int));
  for (int i = 0; i < TamStr; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      resultado[i] = 5;
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
    {
      resultado[i] = 6;
    }
    else
    {
      resultado[i] = 0;
    }
  }
  return (resultado);
}

/** Encontrar digitos em uma cadeia de caracteres
 *  @param Cadeia de caracteres
 *  @returns Array de numeros inteiros, onde os digitos sao trocados por 7
*/
int *IsDigit (char *str)
{
  int TamStr = strlen(str);
  int *resultado = (int*)malloc(TamStr*sizeof(int));
  for (int i = 0; i < TamStr; i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      resultado[i] = 7;
    }
    else
    {
      resultado[i] = 0;
    }
  }
  return (resultado);
}

/** Identificar simbolos em uma cadeia de caracteres
 *  @param cadeia de caracteres
 *  @returns Array de numeros inteiros cada um representando um tipo de simbolo
 *  @note Logicos-1 Aritimeticos-2 Relacionais-3 Separadores-4 Letras Maiusculas-5 Letras Minusculas-6
 *  Digitos-7
*/
int *IdentifySimbol (char *str)
{
  int TamStr = strlen(str)+1;
  int *letra = IsLetter(str);
  int *digito = IsDigit(str);
  int *operador = IsOperator(str);
  int *resultado = (int*)malloc(TamStr*sizeof(int));
  int CL = 0;
  int CD = 0;
  int CO = 0;
  
  for (int i = 0; i < TamStr; i++)
  {
    resultado [i] = digito[i] + letra[i] + operador[i];
    if (resultado[i] > 0 && resultado[i] <= 4)
    {
      CO++;
    }
    else if (resultado[i] >= 5 && resultado[i] <= 6)
    {
      CL++;
    }
    else if (resultado[i] == 7)
    {
      CD++;
    }
    FILE *arquivo = fopen("CONTADORES.TXT", "wt");
    fprintf (arquivo, "%d\n%d\n%d\n", CO, CD, CL);
    fclose(arquivo);
  }
  return (resultado);
}

/** Calcular a media dod valores reais de um array 
 *  @param Array de valores reais
 *  @param Tamanho do array
 *  @returns Media dos valores
*/
double DoubleArrayAverage (double *array, int tamanho)
{
  double resultado = 0.0;
  double total = 0.0;
  if (tamanho <= 0)
  {
    tamanho = 1;
  }

  for(int i = 0; i < tamanho; i++)
  {
    total = total + array[i];
  }
  resultado = ((double)total / (double)tamanho);
  return (resultado); 
}


/** Gravar as medias, de valores reais, dos valores maiores, entre, e menores do que um intervalo [w:p]
 *  @param Array de valores reais
 *  @param Tamanho do array
 *  @param w para definir o valor inferior do intervalo
 *  @param p para definir o valor superior do intervalo 
*/
void DoubleArrayOrderedAverage (double *array, int tamanho, double w, double p)
{
  double menores [tamanho*sizeof(double)];
  double entre   [tamanho*sizeof(double)];
  double maiores [tamanho*sizeof(double)];
  double Maiores = 0.0;
  double Entre   = 0.0;
  double Menores = 0.0;
  int x = 0;
  int y = 0;
  int z = 0;

  // Separar dados
  for (int i = 0; i < tamanho; i++)
  {
    if (array[i] < w)
    {
      menores[x] = array[i];
      x++;
    }
    else if (array[i] >= w && array[i] <= p)
    {
      entre[y] = array[i];
      y++;
    }
    else if (array[i] > p)
    {
      maiores[z] = array[i];
      z++;
    }
  }

  // Tirar medias
  Menores = DoubleArrayAverage(menores, (x));
  Entre   = DoubleArrayAverage(entre,   (y));
  Maiores = DoubleArrayAverage(maiores, (z));

  // Gravar dados em um arquivo
  FILE *arquivo = fopen ("MEDIAS.TXT", "wt");
  fprintf (arquivo, "%lf\n", Maiores);
  fprintf (arquivo, "%lf\n", Entre  );
  fprintf (arquivo, "%lf\n", Menores);
  fclose  (arquivo);
}

/** Somar o inverso do cubo dos valores impares dentro do intervalo [a:b]
 *  @param Array de valores inteiros
 *  @param Tamanho do array
 *  @param Intervalo 1
 *  @param Intervalo 2
 *  @returns Soma do inverso do cubo de valores inpares (Valor real)
*/
double AddIntervalOddInverseCubic (int *array, int tamanho, int a, int b)
{
  double resultado = 0;

  // Correcao do intervalo
  if (a > b)
  {
    IntInvertValues (&a, &b);
  }

  for (int i = 0; i < tamanho; i++)
  {
    if (array[i] > a && array[i] < b && array[i] != 0)
    {
      if (array[i] % 2 != 0)
      {
        resultado += (1.0/(Pow(array[i], 3)));
      }
    }
  }
  return (resultado);
}

/** Contar valores reais que pertencem ao intervalo aberto ]a:b[
 *  @param Array de valores reais
 *  @param Tamanho do array
 *  @param Intervalo 1
 *  @param Intervalo 2
 *  @returns Contador de valores dentro do intervalo
 *  @note Serao calculados e gravados separadamente em um arquivo "PORCENTAGENS.TXT" a porcentagem 
 *        dos valores maiores e dos valores menores do que o intervalo
*/
int DoubleCountIntervalPercentage (double* array, int tamanho, double a, double b)
{
  int CEntre = 0;
  int CMaior = 0;
  int CMenor = 0;
  double PMaior = 0.0;
  double PMenor = 0.0;

  if (a > b)
  {
    DoubleInvertValues(&a, &b);
  }

  for (int i = 0; i < tamanho; i++)
  {
    if (array[i] > a && array[i] < b)
    {
      CEntre++;
    }
    else if (array[i] > b)
    {
      CMaior++;
    }
    else if (array[i] < a)
    {
      CMenor++;
    }
  }

  PMaior = ((double)CMaior / (double)tamanho)*100;
  PMenor = ((double)CMenor / (double)tamanho)*100;

  // Gravar porcentagens em um arquivo
  FILE *arquivo = fopen ("PORCENTAGENS.TXT", "wt");
  fprintf (arquivo, "%lf\n", PMaior);
  fprintf (arquivo, "%lf\n", PMenor);
  fclose  (arquivo);

  return  (CEntre);
} 

/** Determinar o tipo de ordem em um array de valores reais
 *  @param Array de valore reais
 *  @param Tamanho do array
 *  @returns 1-para ordem crescente 2-para ordem decrescente e 3-para outro tipo
 *  @note No terceiro caso o maior e o menor valor do array serao gravados em um arquivo "DADOS.TXT"
*/
int DoubleArrayOrderType (double *array, int tamanho)
{
  double maior = 0.0;
  double menor = 0.0;
  int w = 0;
  int p = 0;
  int x = 0;

  for (int i = 0; i < tamanho; i++)
  {
    if (i > 0)
    {
      if (array[i] > array[i-1])
      {
        w++;
      }
      else if (array[i] < array[i-1])
      {
        p++;
      }
    }
    else if (i == 0)
    {
      if (array[i] < array[i+1])
      {
        w++;
      }
      else if (array[i] > array[i+1])
      {
        p++;
      }
    }
  }
  if (w == tamanho) // Se o array estiver em ordem crescente
  {
    x = 1;
  }
  else if (p == tamanho) // Se o array estiver em ordem decrescente
  {
    x = 2;
  }
  else // Se o array estiver em outro tipo de ordem
  {
    maior = array[0];
    menor = array[0];
    for (int i = 0; i < tamanho; i++)
    {
      x = 3;
      if (array[i] > maior)
      {
        maior = array[i];
      }

      if (array[i] < menor)
      {
        menor = array[i];
      }
    }
    // Gravar maiores e menores valores em um arquivo
    FILE *arquivo = fopen ("DADOS.TXT", "wt");
    fprintf (arquivo, "%lf\n", maior);
    fprintf (arquivo, "%lf\n", menor);
    fclose  (arquivo);
  }

  return (x);
}

void R0101 (void)
{
  // Identificacao de dados
  int n = 0;
  int *valores = NULL;
  int *resultado = NULL;

  // Apresentacao
  println ("R0101");
  println ("");                  // Pular uma linha
  printf  ("Ler um valor inteiro [n] do teclado, depois ler [n] valores [x] do teclado. Dizer para cada ");
  printf  ("valor lido a soma de seus divisores impares calculada por uma funcao. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    n = ReadInt ("Forneca a quantidade de valores a serem lidos: ");
  } while (n <= 0);

  valores = IntWriteArray(n);

  // Calcular soma dos divisores impares
  resultado = SomaDivisorImpar(valores, n);

  // Mostrar dados
  for (int i = 0; i < n; i++)
  {
    printf ("soma dos divisores de [%d] :\n %d\n", valores[i], resultado[i]);
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0102 (void)
{
  // Identificacao de dados
  int *resultado = NULL;
  int *valores = NULL;
  int n = 0;

  // Apresentacao
  println ("R0102");
  println ("");                  // Pular uma linha
  printf  ("Ler um valor inteiro [n] do teclado para indicar uma quantidade, depois ler [n] valores inteiros ");
  println ("do teclado, dizer para cada valor lido se e primo, ou nao, verificado por funcao. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    n = ReadInt ("Forneca um valor inteiro para determinar [n]: ");
  } while (n <= 0);

  valores = IntWriteArray (n);

  // Verificacao de valores primos
  resultado = Primos(valores, n);

  // Mostrar dados
  for (int i = 0; i < n; i++)
  {
    if (resultado[i] == 1)
    {
      printf ("O valor '%d' e primo. \n", valores[i]);
    }
    else
    {
      printf ("O valor '%d' nao e primo. \n", valores[i]);
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0103 (void)
{
  // Identificacao de dados
  char *str = NULL;
  int  *resultado = NULL;

  // Apresentacao
  println ("R0103");
  println ("");                  // Pular uma linha
  printf  ("Ler uma cadeia de caracteres do teclado, e dizer se cada simbolo e um operador ");
  println ("logico, aritimetico, relacional, separador ou um outro simbolo. ");
  println ("");                  // Pular uma linha
    
  // Ler dados  
  str = ReadString("Forneca uma cadeia de caracteres", 80);
  resultado = IsOperator(str);

  // Mostrar dados
  for (int i = 0; i < (int)strlen(str); i++)
  {
    switch (resultado[i])
    {
      case 1: printf ("O simbolo [%c] e um operador logico. \n", str[i]);
      break;
      case 2: printf ("O simbolo [%c] e um operador aritimetico. \n", str[i]);
      break;
      case 3: printf ("O simbolo [%c] e um operador relacional. \n", str[i]);
      break;
      case 4: printf ("O simbolo [%c] e um operador separador. \n", str[i]);
      break;
      default: printf ("O simbolo [%c] e um outro simbolo. \n", str[i]); 
      break;
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0104 (void)
{
  // Identificacao de dados
  char *str = NULL;
  int  *resultado = NULL;
  int CO = 0;
  int CD = 0;
  int CL = 0;

  // Apresentacao
  println ("R0104");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  str = ReadString ("Forneca uma cadeia de caracteres: ", 80);
  resultado = IdentifySimbol(str);

  // Mostrar dados
  FILE *arquivo = fopen ("CONTADORES.TXT", "rt");
  fscanf (arquivo, "%d", &CO);
  fscanf (arquivo, "%d", &CD);
  fscanf (arquivo, "%d", &CL);
  fclose(arquivo);

  printf("\nOperadores:%d\nDigitos:%d\nLetras:%d\n\n",CO, CD, CL);

  int TamStr = strlen(str);
  for (int i = 0; i < TamStr; i++)
  {
    switch (resultado[i])
    {
      case 1: printf ("O simbolo [%c] e um operador logico. \n", str[i]);
      break;
      case 2: printf ("O simbolo [%c] e um operador aritimetico. \n", str[i]);
      break;
      case 3: printf ("O simbolo [%c] e um operador relacional. \n", str[i]);
      break;
      case 4: printf ("O simbolo [%c] e um operador separador. \n", str[i]);
      break;
      case 5: printf ("O simbolo [%c] e uma letra maiuscula. \n", str[i]);
      break;
      case 6: printf ("O simbolo [%c] e uma letra minuscula. \n", str[i]);
      break;
      case 7: printf ("O simbolo [%c] e um digito. \n", str[i]);
      break;
      default: printf ("O simbolo [%c] e um outro simbolo. \n", str[i]); 
      break;
    }
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0105 (void)
{
  // Identificacao de dados
  int n = 0;
  double *valores = NULL;
  double w = 0.0;
  double p = 0.0;
  double maiores = 0.0;
  double entre   = 0.0;
  double menores = 0.0;
  double MaiorMedia = 0.0;
  
  // Apresentacao
  println ("R0105");
  println ("");                  // Pular uma linha
  printf  ("Ler um valor inteiro [n], ler outros [n] valores reais, calcular e mostrar a media ");
  printf  ("dos valores menores do que o intervalo, dos valores dentro do intervalo e dos valores ");
  println ("dentro do intervalo, depois dizer qual a maior media de todas. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  do
  {
    n = ReadInt ("Forneca um valor inteiro para definir a quantidade de valores a serem lidos: ");
  } while (n <= 0);

  valores = DoubleWriteArray(n);

  w = ReadDouble ("Forneca um valor para definir o intervalo inferior: ");
  p = ReadDouble ("Forneca um valor para definir o intervalo superior: ");

  printf ("%d", n);
  // Calcular medias e gravar em um arquivo
  DoubleArrayOrderedAverage(valores, n, w, p);

  // Ler dados do arquivo
  FILE *resultado = fopen ("MEDIAS.TXT", "rt");
  fscanf(resultado, "%lf", &maiores);
  fscanf(resultado, "%lf", &entre  );
  fscanf(resultado, "%lf", &menores);
  fclose(resultado);

  // Mostrar dados
  printf ("\nEm relacao ao intervalo [%.3lf : %.3lf]:\nMaiores: %lf\nEntre: %lf\nMenores: %lf\n", 
                                      w,  p,             maiores,     entre,       menores);
  MaiorMedia = maiores;
  if (MaiorMedia < entre)
  {
    MaiorMedia = entre;
  }
  else if (MaiorMedia < menores)
  {
    MaiorMedia = menores;
  }

  if (MaiorMedia == maiores)
  {
    println ("A maior media e dos valores maiores. ");
  }
  else if (MaiorMedia == entre)
  {
    println ("A maior media e dos valores entre. ");
  }
  else if (MaiorMedia == menores)
  {
    println ("A maior media e dos valores menores. ");
  }


  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0106 (void)
{
  // Identificacao de dados
  int a = 0;
  int b = 0;
  int n = 0;
  int *valores = NULL;
  double resultado = 0;

  // Apresentacao
  println ("R0106");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  a = ReadInt ("Forneca um valor inteiro para definir um intervalo inferior: ");
  b = ReadInt ("Forneca um valor inteiro para definir um intervalo superior: ");

  valores = ReadInts(&n, -1);
  
  // Calcular
  resultado = AddIntervalOddInverseCubic(valores, n, a, b);

  // Mostrar dados
  printf ("\nTotal:\t %lf", resultado);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0107 (void)
{
  // Identificacao de dados
  double a = 0.0;
  double b = 0.0;
  double PMaior = 0.0;
  double PMenor = 0.0;
  double *valores = NULL;
  int tamanho = 0;
  int resultado = 0;

  // Apresentacao
  println ("R0107");
  println ("");                  // Pular uma linha
  printf  ("Ler dois valores reais [a] e [b] do teclado, ler outros valores reais do teclado, um ");
  printf  ("por vez, ate que o ultimo valor seja igual a zero, e nao considera-lo para os calculos. ");
  printf  ("Contar quantos desses valores estao dentro ou fora do intervalo aberto definido ]a:b[. ");
  printf  ("Para os valores fora do intervalo calcular separadamente as porcentagens do que estiverem ");
  println ("acima e abaixo do intervalo, nessa ordem. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  a = ReadDouble ("Forneca um valor real para determinar um intervalo: ");
  b = ReadDouble ("Forneca um outro valor real para determinar o intervalo: ");

  if (a > b)
  {
    DoubleInvertValues(&a, &b);
  }

  valores = ReadDoubles(&tamanho, 0);

  resultado = DoubleCountIntervalPercentage (valores, tamanho, a, b);

  // Ler dados do arquivo "PORCENTAGENS.TXT"
  FILE *arquivo = fopen ("PORCENTAGENS.TXT", "rt");
  fscanf (arquivo, "%lf", &PMaior);
  fscanf (arquivo, "%lf", &PMenor);
  fclose (arquivo);

  // Mostrar dados
  printf ("\nA quantidade de valores reais que pertencem ao intervalo: %d\n", resultado);
  printf ("\nValores maiores: %.3lf%%\nValores menores: %.3lf%%\n", PMaior, PMenor);

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0108 (void)
{
  // Identificacao de dados
  double valores [3*sizeof(double)];
  double x = 0.0; 
  double y = 0.0; 
  double z = 0.0;
  double maior = 0.0;
  double menor = 0.0;
  int resultado = 0;

  // Apresentacao
  println ("R0108");
  println ("");                  // Pular uma linha
  printf  ("Ler tres valores reais [x][y][z] do teclado, um por vez, e dizer se esses valores estao ");
  printf  ("em ordem crescente, decrescente ou em nenhuma dos duas, e nesse caso mostrar o maior e o ");
  println ("menor valor. ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  x = ReadDouble ("Forneca um valor real: ");
  y = ReadDouble ("Forneca um outro valor real: ");
  z = ReadDouble ("Forneca um terceiro valor real: ");

  // Gravar valores em um array
  valores[0] = x;
  valores[1] = y;
  valores[2] = z;

  // Calcular
  resultado = DoubleArrayOrderType(valores, 3);

  // Mostrar dados
  if (resultado == 1)
  {
    printf ("\nOs valores estao em ordem crescente. \n");
  }
  else if (resultado == 2)
  {
    printf ("\nOs valores estao em ordem decrescente. \n");
  }
  else if (resultado == 3)
  {
    FILE *arquivo = fopen ("DADOS.TXT", "rt");
    fscanf (arquivo, "%lf", &maior);
    fscanf (arquivo, "%lf", &menor);
    fclose (arquivo);
    printf ("\nOs valores estao em outro tipo de ordem. \n");
    printf ("\nMaior valor: %.3lf\nMenor valor: %.3lf\n", maior, menor);
  }
  else
  {
    printf ("\nERRO na funcao, ou no retorno dela.\n");
  }

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void R0109 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("R0109");
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

void R0110 (void)
{
  // Identificacao de dados
  // Apresentacao
  println ("R0110");
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
      println ("R01 - v0.8 - 04/30/24" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - R0101   2 - R0102");
      println ("3 - R0103   4 - R0104");
      println ("5 - R0105   6 - R0106");
      println ("7 - R0107   8 - R0108");
      println ("9 - R0109  10 - R0110");
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
          case 1:  R0101();
            break;
          case 2:  R0102();
            break;
          case 3:  R0103();
            break;
          case 4:  R0104();
            break;
          case 5:  R0105();
            break;
          case 6:  R0106();
            break;
          case 7:  R0107();
            break;
          case 8:  R0108();
            break;
          case 9:  R0109();
            break;
          case 10: R0110();
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
    0.0         00/00/00    (OK)       Criacao do arquivo R01 e seus metodos

*/