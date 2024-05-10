//853355_AED1

#include "io.h"

char MaiorLC (char *x)                // Contador de letras maiusculas maiores do que 'L'
{
  int caractere = 0,                  // Posisao do caractere
      contador  = 0,                  // Contador
      TamCad    = strlen (x);         // Tamanho da palavra

  IO_println ("A quantidade de letras maiusculas maiores que 'L' sao: ");
  IO_println ("");                    // Pular uma linha

    
  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {
      
      // Se x[caractere] for uma letra maiuscula maior do que 'L'
      if (  x[caractere] > 'L' && x[caractere] <= 'Z' )
        {
          contador++;                 // Aumentar contador por 1
        }

    }

  IO_printf ("%d\n", contador);       // Mostrar resultado

  return (0);
}

char MaiorLS (char *x)                // Mostar letras maiusculas maiores do que 'L'
{
  int caractere  = 0,                 // Posisao do caractere
      TamCad     = strlen (x);        // Tamanho da palavra

  IO_println ("As letras maiusculas maiores que 'L' sao: ");
  IO_println ("");                    // Pular uma linha

    
  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {

      // Se x[caractere] for uma letra maiuscula maior do que 'L'
      if (  x[caractere] > 'L' && x[caractere] <= 'Z' )
        {
          IO_printf ("%c\n", x[caractere]);       // Mostrar letras maiusculas maiores do que 'L'
        }
    }

    return (0);
}

char MenorLlC (char *x)               // Contar letras menores do que 'L' e 'l'
{
  int caractere = 0,                  // Posisao na cadeia de caracteres
      contador  = 0,                  // Contador
      TamCad    = strlen (x);         // Tamanho da palavra


  IO_println ("A quantidade de letras menores do que 'L' e 'l' sao: ");
  IO_println ("");                    // Pular uma linha
  
  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {

      // Se x[caractere] for uma letra maiuscula ou minuscula menor do que 'L'
      if ( (x[caractere] >= 'A' && x[caractere] < 'L') || (x[caractere] >= 'a' && x[caractere] < 'l') )
        {
          contador++;                 // Aumentar contador por 1
        }
    }

  IO_printf ("%d\n", contador);       // Mostrar resultado

  return (0);
}

char MenorLlS (char *x)               // Mostar letras menores do que 'L' e 'l'
{
  int caractere = 0,                  // Posicao do caractere na cadeia
      TamCad    = strlen(x);          // Tamanho da cadeia de caracteres

  IO_println ("As letras menores do que 'L' e 'l' sao:  ");
  IO_println ("");                    // Pular uma linha

  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {

      // Se x[caractere] for uma letra maiuscula ou minuscula menor do que 'L'
      if ( (x[caractere] >= 'A' && x[caractere] < 'L') || (x[caractere] >= 'a' && x[caractere] < 'l' ) )
        {
          IO_printf ("%c\n", x[caractere]);         // Mostrar caractere
        }
    }

  return (0);
}

int ParesC (char *x)                  // Contar numeros pares
{
  int caractere = 0,                  // Posicao na cadeia de caracteres
      TamCad    = strlen(x),          // Tamanho da cadeia de caracteres
      contador  = 0;                  // Contador

  IO_println ("A quantidade de numeros pares e: ");
  IO_println ("");                    // Pular uma linha

  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {

      //                                                  Se x[caractere] for: 
      if ((x[caractere] >= '0' && x[caractere] < '9') &&  // Numero
          ( ((int) x[caractere] % 2) == 0 ) )             // Par
        {
          contador++;                 // Aumentar contador por 1
        }
    }

    IO_printf ("%d\n", contador);
  
  return (0);
}

char NaoAlfaNumericos (char *x)       // Mostrar simbolos que nao sejam nem numeros nem letras
{
  int caractere = 0,                  // Posicao na cadeia de caracteres
      TamCad    = strlen(x);          // Tamanho da cadeia de caracteres

      IO_println ("Os simbolos nao alfanumericos sao: ");
      IO_println ("");

      //  { Leitura individual dos caracteres da cadeia  }
      for (caractere = 0; caractere < TamCad; caractere++)
        {

          //                                                  Se x[caractere] nao for :
          if ( (x[caractere] < '0' || x[caractere] > '9') &&  // Numero
               (x[caractere] < 'a' || x[caractere] > 'z') &&  // Letra minuscula
               (x[caractere] < 'A' || x[caractere] > 'Z') )   // Letra maiuscula
            {
              IO_printf ("%c\n", x[caractere]);
            }
        }

  return (0);
}

char AlfaNumericos (char *x)          // Mostrar apenas simbolos que sejam numeros ou letras
{
  int caractere = 0,                  // Posicao do caractere na cadeia de caracteres
      TamCad    = strlen(x);          // Tamanho da cadeia de caracteres

  IO_println ("Os simbolos alfanumericos sao: ");
  IO_println ("");

  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {

      //                                                   Se x[caractere] for :
      if ( (x[caractere] >= '0' && x[caractere] < '9') ||  // Numero
           (x[caractere] >= 'a' && x[caractere] < 'z') ||  // Letra minuscula
           (x[caractere] >= 'A' && x[caractere] < 'Z') )   // Letra maiuscula

        {
          IO_printf ("%c\n", x[caractere]);
        }  
    }

  return (0);
}

char AlfaNumericosP (char *x)         // Mostrar e contar a quantidade de simbolos alfanumericos em cada palavra
{
  int caractere = 0,                  // Posicao do caractere na cadeia de caracteres
      TamCad    = strlen(x),          // Tamanho da cadeia de caracteres
      contador  = 0;                  // Contador

  IO_println ("Os simbolos alfanumericos sao: ");
  IO_println ("");

  //  { Leitura individual dos caracteres da cadeia  }
  for (caractere = 0; caractere < TamCad; caractere++)
    {
      //                                                   Se x[caractere] for :
      if ( (x[caractere] >= '0' && x[caractere] < '9') ||  // Numero
           (x[caractere] >= 'a' && x[caractere] < 'z') ||  // Letra minuscula
           (x[caractere] >= 'A' && x[caractere] < 'Z') )   // Letra maiuscula
        {
          IO_printf ("%c", x[caractere]);
          contador++;
        }
      //Se x[caractere] for espaco vazio                                  
      else if ( x[caractere]   == ' ' )
        {
          IO_println ("");            // Pular uma linha
        }
    }

  IO_printf ("\n%s%d\n", "A quantidade de simbolos alfanumericos e: ", contador);

  return (0);
}

void ED_0401 (void)
{
    // Identicacao de dados
    double a = 0.0,
           b = 0.0,
           x = 0.0;
    
    int    n       = 10,
           dentro  = 0,
           fora    = 0;

    // Apresentacao
    IO_println ("ED_0401");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler dois valore reais para definir um intervalo fechado, ler certa quantidade de valores reais e ");
    IO_println ("contar quantos desses valores estao dentro do intervalo, e quantos estao fora dele");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    do
      { 

        // Ler valor
        a = IO_readdouble ("Forneca um valor real qualquer para definir um intervalo fechado: ");
        IO_println ("");              // Pular uma linha
        
        // Ler valor
        b = IO_readdouble ("Forneca um outro valor real qualquer para definir um intervalo fechado: ");
        IO_println ("");              // Pular uma linha
          
        // Verificar dados
        if (a == b)
        {
            IO_println ("O segundo valor deve ser diferente do primeiro.");
            IO_println ("");          // Pular uma linha
        }

      } while (a == b);               // Repetir ate que [a] e [b] sejam diferentes

    // Fornecer numero de repeticoes
    do                                // Repetir ate que [n] seja maior do que zero
      {

        // Ler valor
        n = IO_readint ("Forneca um valor inteiro qualquer para definir o numero de repeticoes: ");
            IO_println ("");          // Pular uma linha

        if (n <= 0)                   // Verificar valor 
          {
            IO_println ("O numero de repeticoes deve ser um numero maior do que zero. ");  // Mensagem de valor invalido
            IO_println ("");          // Pular uma linha
          }
          
      } while (n <= 0);               // Repetir ate que [n] seja maior do que zero
    
      // Mostrar dados
      do                              // Repetir ate que [n] seja zero
        {

         // Ler valor
         x = IO_readdouble ("Forneca um valor real para ser testado: ");
             IO_println ("");

         if ( (x >= a && x <= b) || (x >= b && x <= a) )                                // Se o valor fornecido pertence ao intervalo [a:b]
           {
            dentro++;                 // Adicionar ao contador de dentro
            printf     ("O valor [%.3lf] pertence ao intervalo inicial. ", x);          // Mostar valor quando pertence ao intervalo [a:b]
            IO_println ("");
           }
         else
           {
            fora++;                   // Adicionar ao contador de fora
            printf     ("O valor [%.3lf] nao pertence ao intervalo inicial.", x);       // Mostrar valor quando nao pertence ao intervalo [a:b]
            IO_println ("");
           }

         n--;                         // Diminuir o valor de [n]
         IO_println ("");
         printf     ("O numero de valores a serem testados restantes sao: %d", n);      // Mostrar o numero de testes restantes
         IO_println ("");
            
        } while (n > 0);              // Repetir ate que [n] seja zero

    // Mostrar contador
    IO_println ("");
    IO_printf  ("Dos valores fornecidos os que pertencem ao intervalo inicial sao: %d , e os que nao pertencem sao: %d ", dentro, fora);
    IO_println ("");

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0402 (void)
{
    // Identicacao de dados
    int  caractere = 0,               // Posicao na cadeia de caracteres
         contador  = 0,               // Contador
         TamCad    = 80;              // Tamanho da cadeia de caracteres

    char cadeia [TamCad];             // Cadeia de caracteres
         
    // Apresentacao
    IO_println ("ED_0402");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres, contar e mostrar a quantidade de letras maiusculas maiores do que 'L'. ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Calcular dados
    TamCad = strlen(cadeia);

    //  { Leitura individual dos caracteres da cadeia  }
    for (caractere = 0; caractere < TamCad; caractere++)
      {
        if (cadeia[caractere] > 'L' && cadeia[caractere] <= 'Z')         // Se o caractere e uma letra maiuscula
          {
            IO_printf ("O caractere [%c] e uma letra maiuscular maior do que 'L'. ", cadeia[caractere]);
            IO_println   ("");        // Pular uma linha
            contador++;
          }
      }

    // Mostrar dados
    IO_println ("");                  // Pular uma linha
    IO_printf ("A quantidade de letras maiusculas maiores do que 'L' sao: %d ", contador);

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0403 (void)
{
    // Identicacao de dados
    char  cadeia [80];                // Cadeia de caracteres
    
    // Apresentacao
    IO_println ("ED_0403");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao mostar a quantidade de letras maiusculas maiores que 'L'. ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres ");
    fgets      (cadeia, 80, stdin);    // Ler cadeia de caracteres

    // Mostrar dados
    MaiorLC (cadeia);                 // Chamar funcao [MaiorLC]
    
    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0404 (void)
{
    // Identicacao de dados
    char cadeia [80];                 // Cadeia de caracteres

    // Apresentacao
    IO_println ("ED_0404");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao mostar as letras maiusculas maiores que 'L'. ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    MaiorLS (cadeia);                 // Chamar funcao [MaiorLS]

    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0405 (void)
{
    // Identicacao de dados
    char cadeia [80];                 // Cadeia de caracteres

    // Apresentacao
    IO_println ("ED_0405");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao mostrar a quantidade de letras menores do que 'L' e 'l'. ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    MenorLlC (cadeia);                // Chamar funcao [MenorLlC]

    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0406 (void)
{
    // Identicacao de dados
    char cadeia [80];                 // Cadeia de caracteres

    // Apresentacao
    IO_println ("ED_0406");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao mostrar as letras menores do que 'L' e 'l'.  ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    MenorLlS (cadeia);                // Chamar funcao [MenorLlS]

    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0407 (void)
{
    // Identicacao de dados
    char cadeia [80];

    // Apresentacao
    IO_println ("ED_0407");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao contar os numeros pares. ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    ParesC (cadeia);                  // Chamar funcao [ParesC]

    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0408 (void)
{
    // Identicacao de dados
    char cadeia [80];                 // Cadeia de caracteres

    // Apresentacao
    IO_println ("ED_0408");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao mostrar todos os simbolos nao alfanumericos. ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    NaoAlfaNumericos (cadeia);        // Chamar funcao [NaoAlfaNumericos]

    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0409 (void)
{
    // Identicacao de dados
    char cadeia [80];                 // Cadeia de caracteres

    // Apresentacao
    IO_println ("ED_0409");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma sequencia de caracteres e com uma funcao mostrar todos os simbolos alfanumericos.  ");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Forneca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    AlfaNumericos (cadeia);           // Chamar funcao [AlfaNumericos]

    // Fim
    IO_pause ("Aperte <ENTER> para sair");
}

void ED_0410 (void)
{
    // Identicacao de dados
    char cadeia [80];

    // Apresentacao
    IO_println ("ED_0410");
    IO_println ("");                  // Pular uma linha
    IO_println ("Ler uma cadeia de caracteres e com uma funcao contar e mostrar todos os simbolos alfanumericos separados por palavras");
    IO_println ("");                  // Pular uma linha

    // Ler dados
    IO_println ("Foreca uma cadeia de caracteres: ");
    fgets      (cadeia, 80, stdin);   // Ler cadeia de caracteres

    // Mostrar dados
    AlfaNumericosP (cadeia);          // Chamar funcao [AlfaNumericosP]

    // Fim
    IO_println ("");                  // Pular uma linha
    IO_println ("");                  // Pular uma linha
    IO_pause   ("Aperte <ENTER> para sair");
}

int main (void)
{

    // Definir dado
    int opcao = 0;

    // Repetir
    do
      {

        // Identificacao
        IO_println ("");              // Pular uma linha
        IO_println ("ED04 - v1.0 - 03/22/24" );
        IO_println ("853355_AED1 - Davi Puddo");
        IO_println ("");              // Pular uma linha

        // Mostrar opcoes
        IO_println ("Exercicios: ");
        IO_println ("");              // Pular uma linha
        IO_println ("0 - sair");
        IO_println ("1 - ED0401   2 - ED0402");
        IO_println ("3 - ED0403   4 - ED0404");
        IO_println ("5 - ED0405   6 - ED0406");
        IO_println ("7 - ED0407   8 - ED0408");
        IO_println ("9 - ED0409  10 - ED0410");
        IO_println ("");              // Pular uma linha

        // Ler opcao
        IO_println ("Escolha um exercicio: ");
        scanf      ("%d", &opcao);
        getchar    ();

        // Escolher opcao
        switch (opcao)
          {
            case 0:
              break;
            case 1: ED_0401();
              break;
            case 2: ED_0402();
              break;
            case 3: ED_0403();
              break;
            case 4: ED_0404();
              break;
            case 5: ED_0405();
              break;
            case 6: ED_0406();
              break;
            case 7: ED_0407();
              break;
            case 8: ED_0408();
              break;
            case 9: ED_0409();
              break;
            case 10: ED_0410();
              break;
            default:
                IO_println ("");                // Pular uma linha
                IO_println ("A opcao escolhida e invalida. ");
                IO_println ("");                // Pular uma linha
              break;
          }

      } while (opcao != 0);

      // Fim
      IO_pause ("Aperte <ENTER> para sair. ");
      return (0);
}

/*
    Versao      Data        Teste      Modificacoes
    0.0         03/20/24    (OK)       Criacao do arquivo ED04 e seus metodos
    0.1         03/20/24    (OK)       Implementacao do ED_0401 
    0.2         03/20/24    (OK)       Implementacao do ED_0402
    0.3         03/20/24    (OK)       Implementacao do ED_0403
    0.4         03/20/24    (OK)       Implementacao do ED_0404
    0.5         03/22/24    (OK)       Implementacao do ED_0405
    0.6         03/22/24    (OK)       Implementacao do ED_0406
    0.7         03/22/24    (OK)       Implementacao do ED_0407
    0.8         03/22/24    (OK)       Implementacao do ED_0408
    0.81        03/22/24    (OK)       Mudanca na leitura da cadeia de caracteres de: 'IO_scanf' para 'fgets'
    0.9         03/22/24    (OK)       Implementacao do ED_0409
    1.0         03/22/24    (OK)       Implementacao do ED_0410
*/