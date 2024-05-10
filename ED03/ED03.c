//855335_AED1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// io.h :
// Mostrar texto
void print (char *text)
{
    printf ("%s", text);
}

// Mostrar texto e pular uma linha
void println (char *text)
{
    printf ("%s\n", text);
}

// Texto e esperar um caractere
void pause (char *text)
{
    printf  ("%s\n", text);
    getchar ();
}

// Ler Valor real
double readdouble (char *text)
{
    double  x = 0.0;
    
    printf  ("%s\n", text);
    scanf   ("%lf", &x);
    getchar ();

    return  (x);
}

// Ler Caractere
char readchar (char *text)
{
    char x = '0';

    printf  ("%s\n", text);
    scanf   ("%c", &x);
    getchar ();

    return  (x);
}

// Ler Bool
int readbool (char *text)
{
    int x = 0;

    printf  ("%s\n", text);
    scanf   ("%d", &x);
    getchar ();

    return  (x != 0);
}

// Ler valor inteiro
int readint (char *text)
{
    int x = 0;

    printf  ("%s\n", text);
    scanf   ("%d", &x);
    getchar ();

    return  (x);
}
// Fim io.h

// ED_0311
void ED_0311 (void)
{

    // Identificacao de dados
    int  caractere    = 0,              // Posicao do caractere
         TamPalavra   = 80,             // Tamanho da palavra
         contador     = 0;              // Contador de caracteres
    char palavra [TamPalavra];          // Palavra fornecida

    // Apresentacao
    println ("ED_0311");
    println ("\nLer uma palavra e mostrar as letras maiusculas. \n");

    // Ler dados
    println ("");           //Pular uma linha
    println ("Digite uma palavra : ");
    scanf   ("%s", palavra);
    getchar ();

    //Mostra dados
    printf ("Em relacao a palavra ( %s ) os caracteres maiusculos sao: \n", palavra);

    for (caractere = 0; caractere < TamPalavra; caractere++)            // Ler cada caractere da palavra
      {
            // Analisar dados
        if (palavra[caractere] >= 'A' && palavra[caractere] <= 'Z')
          { 
            // Se o caractere for maiusculo
            printf ("[ %c ]\n", palavra[caractere]);
            contador++;
          }
        else
          {
            if (contador == 0)
              {
                println ("Nenuma letra maiuscula foi digitada");
                contador++;       //Parar contador
              }
          }
  
      }

    // Fim
    print ("");             //Pular uma linha
    print ("");             //Pular uma linha
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0312
void ED_0312 (void)
{
    // Identificacao de dados
    int  caractere  = -1,              // Posicao do caractere
         contador   =  0,              // Contador de caracteres
         TamPalavra = 80;              // Tamanho da palavra
    char palavra [TamPalavra];         // Palavra fornecida

    // Apresentacao
    println ("ED_0312");
    println ("\nLer uma palavra, contar e mostrar todas as letras maiusculas. ");

    // Ler dados
    println ("");       //Pular uma linha
    println ("Forneca uma palavra: ");
    scanf   ("%s", palavra);
    getchar ();

    // Mostrar dados
    printf ("A palavra [ %s ] possui as seguintes letras maiusculas: \n", palavra);

    for (caractere = 0; caractere < TamPalavra; caractere++)
      {
        // Analise dos dados
        if (palavra[caractere] >= 'A' && palavra[caractere] <= 'Z')       // Se o caractere for maiusculo
          {
            printf ("[ %c ]\n", palavra[caractere]);
            contador++;
          }
        else                                                              // Se o caractere for minusculo                                                            
          {
            if (contador < 0)
              {
                printf ("A palavra [ %s ] nao possui letras maiusculas. ", palavra);
                contador++;       //Parar contador
              }
          }
      }
    printf ("\nA palavra [ %s ] possui: '%d' letras maiusculas. \n", palavra, contador);

    // Fim
    println ("");
    pause   ("Aperte <ENTER> para continuar. ");
}

// ED_0313
void ED_0313 (void)
{
    // Identificacao de dados
    int  caractere  =  0,              // Posicao do caractere 
         contador   =  0,              // Contador de caracteres
         TamPalavra = 80;              // Tamanho da palavra
    char palavra [TamPalavra];         // Palavra fornecida

    // Apresentacao
    println ("ED_0313");
    println ("\nLer uma palavra, contar e mostrar todas as letras maiusculas percorrendo do fim para o inicio. ");
    println ("");        //Pular uma linha

    // Ler dados
    println ("Forneca uma palavra: ");
    scanf   ("%s", palavra);
    getchar ();

    // Leitura dos caracteres
    printf ("A palavra [ %s ] possui as seguintes letras maiusculas: \n", palavra);

    TamPalavra = strlen(palavra);       // Tamanho da palavra fornecdia

    for (caractere = TamPalavra; caractere >= 0; caractere--)
      {
        if (palavra[caractere] >= 'A' && palavra[caractere] <= 'Z')       // Se a palavra for maiuscula
          {
            printf ("[ %c ]\n", palavra[caractere]);
            contador++;
          }
      }

    // Mostrar dados
    printf ("\nA palavra [ %s ] possui: '%d' letras maiusculas. \n", palavra, contador);

    // Fim
    println ("");        // Pular uma linha
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0314
void ED_0314 (void)
{

    // Identificacao de dados
    int  caractere  = 0,              // Posicao do caractere
         contador   = 0,              // Contador de caracteres
         TamPalavra = 80;             // Tamanho da palavra
    char palavra [TamPalavra];        // Palavra fornecida

    // Apresentacao
    println ("ED_0314");
    println ("\nContar e mostrar todos os simbolos que forem letras, ou maiusculas ou minusculas. ");
    println ("");       //Pular uma linha
    
    // Ler dados
    println ("Forneca uma palavra: ");
    scanf   ("%s", palavra);
    getchar ();

    // Leitura de caracteres
    printf ("A palavra [ %s ] possui as seguintes letras: \n", palavra);

    // Repeticao
    for (caractere = 0; caractere < TamPalavra; caractere++)
      {
        // Se o caractere nao for uma letra
        if ( (palavra[caractere] >= 'A' && palavra[caractere] <= 'Z') || (palavra[caractere] >= 'a' && palavra[caractere] <= 'z') )
          {
            printf ("[ %c ]\n", palavra[caractere]);
            contador++;
          }
      }

    // Mostrar dados
    printf  ("A palavra [ %s ] possui '%d' letras. ", palavra, contador);
    println ("");

    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0315
void ED_0315 (void)
{

    // Identificacao de dados
    int  caractere = 0,           // Posicao do caractere
         contador  = 0,           // Contador de caracteres
         TamCad    = 80;          // Tamanho da cadeia de caracteres
    char cadeia [TamCad];         // Cadeia de caracteres fornecida

    // Apresentacao
    println ("ED_0315");
    println ("\nContar e mostrar todos os digitos fornecidos, percorrendo do fim para o inicio. ");
    println ("");       // Pular uma linha

    // Ler dados
    println ("Forneca uma cadeia de caracteres. ");
    scanf   ("%s", cadeia);
    getchar ();

    // Mostrar dados
    printf ("A cadeia [ %s ] possui os seguintes digitos: ", cadeia);

    TamCad = strlen(cadeia);          //Ler o tamanho da cadeia de caracteres fornecida

      // Leitura individual de caracteres
    for (caractere = TamCad; caractere >= 0; caractere--)
      {
        if (cadeia[caractere] >= '0' && cadeia[caractere] <= '9')         // Se o caractere for um digito
          {
              // Mostrar digitos
            printf ("[ %c ]\n", cadeia[caractere]);
            contador++;
          }
      }
      // Mostrar contador
    printf  ("A cadeia de caracteres [ %s ] possui '%d' digitos. ", cadeia, contador);
    println ("");         // Pular uma linha

    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0316
void ED_0316 (void)
{
    // Identificacao de dados
    int  caractere = 0,         // Posicao do caractere
         contador  = 0,         // Contador de caracteres
         TamCad    = 80;        // Tamanho da cadeia de caracteres
    char cadeia [TamCad];       // Cadeia de caracteres fornecida
    
    // Apresentacao
    println ("ED_0316");
    println ("\nA partir de uma cadeia de caracteres contar e mostrar tudo o que nao for digito ou letra. ");
    println ("");       // Pular uma linha

    // Ler dados
    println ("Forneca uma cadeia de caracteres. ");
    scanf   ("%s", cadeia);
    getchar ();
    
    // Mostrar dados
    printf ("Em relacao a cadeia de caracteres [ %s ] os caracteres que nao sao nem digitos nem letras sao: ", cadeia);

    TamCad = strlen(cadeia);        // Leitura do tamanho da cadeia de caracteres

      // Leitura individual de caracteres
    for (caractere = 0; caractere < TamCad; caractere++)
      {
        // Se o caractere nao for uma letra
        if ( ( cadeia[caractere] < 'A' || cadeia[caractere] > 'Z' ) &&        // Se o caractere nao for uma letra maiuscula
             ( cadeia[caractere] < 'a' || cadeia[caractere] > 'z' ) &&        // Se o caractere nao for uma letra minuscula
             ( cadeia[caractere] < '0' || cadeia[caractere] > '9' ) )         // Se o caractere nao for um digito

          {
            // Se o caractere nao for nenhum dos tres acima
              // Mostrar caracteres
            printf ("[ %c ]\n", cadeia[caractere]);
            contador++;
          }  

      }
    
    // Mostrar contador
    printf  ("A cadeia de caracteres [ %s ] possui '%d' caracteres que nao sao nem digitos nem letras. ", cadeia, contador);
    println ("");       // Pular uma linha

    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0317
void ED_0317 ()
{
    // Identificacao de dados
    int a = 0,        // Intervalo 1
        b = 0,        // Intervalo 2
        n = 0,        // Numero de valores a serem testados
        x = 0,        // Valores a serem testados
 contador = 0;        // Contador de valores

    // Apresentacao
    println ("ED_0317");
    println ("");           // Pular uma linha
    println ("Ler dois valores inteiros, que servirao para definir um intervalo. ");
    println ("Ler um valor inteiro, que servira para limitar os valores a serem lidos. ");
    println ("Repetir a leitura de tais valores, um por vez, entao contar e mostrar quantos dentre esses valores");
    println ("pertencem ao intervalo inicial e sao multiplos de 6. ");
    println ("");           // Pular uma linha


    // Ler dados
      // Definir intervalo
         Definir_Intervalo:       // Ponto de retorno em caso de um valor invalido
    println ("Forneca um valor inteiro qualquer para definir um intervalo: ");
    scanf   ("%d", &a);
    getchar ();
    println ("");       // Pular uma linha

    println ("Forneca um outro valor inteiro qualquer para definir um intervalo: ");
    scanf   ("%d", &b);
    getchar ();
    println ("");

      // Verificar dados
    if (a == b)
      {
        println ("O segundo valor deve ser diferente do primeiro. ");
        println ("");                 // Pular uma linha
        goto Definir_Intervalo;       // Repetir "Definir intervalo" ate [a] ser diferente de [b]
      }

      // Definir o numero de valores a serem testados
         Definir_Numero_Valores:        // Ponto de retorno em caso de um valor invalido
    println ("Forneca um valor inteiro qualquer para definir o numero de valores a serem testados: ");
    scanf   ("%d", &n);
    getchar ();
    println ("");

      // Verificar dados
    if (n <= 0)
      {
        println ("O valor deve ser um numero inteiro maior do que zero. ");
        println ("");
        goto Definir_Numero_Valores;  // Repetir "Definir o numero de valores a serem testados" ate que [n] seja maior do que zero
      }

    // Ler valores a serem testados
    do                                                   // Repetir ate que [n] chegue a zero
      {
        printf  ("Forneca um valor para ser testado: ");
        scanf   ("%d", &x);
        getchar ();
        println ("");

        // Testar valor
          //   [ Se x pertence ao intervalo inicial ]    [  Se x e um multiplo de 6 ]
        if ( ( (x <= a && x >= b  ) || (x <= b && x >= a) ) && (x % 6) == 0 )      // Se x pertence ao intervalo [a:b] e um multiplo de 6
          {
            printf  ("O valor [ %d ] pertence ao intervalo inicial e tambem e um multiplo de 6 ", x);
            println ("");       // Pular uma linha
            contador++;
          }
        else if ( (x <= a && x >= b  ) || (x <= b && x >= a) )    // Se x pertence ao intervalo [a:b] mas nao e um multiplo de 6
          {
            printf  ("O valor [ %d ] pertence ao intervalo inicial, mas nao e um multiplo de 6 ", x);
            println ("");       // Pular uma linha
          }
        else if ( (x % 6) == 0 )                                  // Se x nao pertence ao intervalo [a:b] mas e um multiplo de 6
          {
            printf  ("O valor [ %d ] nao pertence ao intervalo inicial, mas e um multiplo de 6", x);
            println ("");       // Pular uma linha
          }
        else                                                      // Se x nao pertence nem ao intervalo [a:b] e nem e um multiplo de 6
          {
            printf  ("O valor [ %d ] nao pertence ao intervalo inicial e nao e um multiplo de 6. ", x);
            println ("");       // Pular uma linha
          }
        // Contagem de valores restantes
        n--;
        println ("");           // Pular uma linha
        printf  ("Valores a serem testados restantes : %d", n);
        println ("");           // Pular uma linha

      } while (n != 0);

      // Contador de valores que pertencem ao intervalo [a:b] e sao multiplos de 6
      printf  ("O numero de valores que pertencem ao intervalo inicial e sao multiplos de 6 sao: %d", contador);
      println ("");       // Pular uma linha
      println ("");       // Pular uma linha

    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_03187
void ED_0318 (void)
{
    // Identificacao de dados
    int a = 0,                    // Intervalo 1
        b = 0,                    // Intervalo 2
        n = 0,                    // Numero de valores a serem testados
        x = 0,                    // Valores a serem testados
contador  = 0;                    // Contador de caracteres
        
    // Apresentacao
    println ("ED_0318");
    println ("");                 // Pular uma linha
    println ("Ler dois valores inteiros, que servirao para definir um intervalo. ");
    println ("Ler um valor inteiro, que servira para limitar os valores a serem lidos. ");
    println ("Repetir a leitura de tais valores, um por vez, entao contar e mostrar quantos dentre esses valores");
    println ("os que forem multiplos de 4, que nao forem multiplos de 5 e pertencam ao intervalo inicial. ");
    println ("");                 // Pular uma linha

    // Ler dados
      // Definir intervalo
      do                          // Repetir "Definir intervalo" ate que os valores [a] e [b] sejam diferentes
        {      
          // Ler intervalo 1
          println ("Forneca um valor inteiro qualquer pra servir como um intervalo: ");             
          scanf   ("%d", &a);
          getchar ();
          println ("");           // Pular uma linha

          // Ler intervalo 2
          println ("Forneca um outro valor inteiro qualquer pra servir como um intervalo: ");
          scanf   ("%d", &b);
          getchar ();
          println ("");           // Pular uma linha
          
          if (a == b)             // Verificar dados
            {
              println ("O segundo valor deve ser diferente do primeiro. ");
              println ("");       // Pular uma linha
            }

        } while (a == b);

      // Definir o numero de valores a serem testado
      do                          // Repetir "Definir o numero de valores a serem testado" ate que [n] seja um numero maior do que zero
        {
          println ("Forneca um valor inteiro para definir o numero de valores a serem testados: ");
          scanf   ("%d", &n);
          getchar ();
          println ("");           // Pular uma linha

          if (n <= 0)             // Verificar dados
          {
            println ("O numero de repeticoes deve ser um numero inteiro maior do que zero. ");
            println ("");         // Pular uma linha
          }

        } while (n <= 0);

      // Ler valores a serem testados
      do 
        { 
          // Ler valor
          println ("Forneca um valor para ser testado: ");
          scanf   ("%d", &x);
          getchar ();
          println ("");           // Pular uma linha

        // Testar valores
          //  [Se x pertence ao intervalo inicial ]   [Se x e multiplo de 4]   [Se x e multiplo de 5]
        if ( ( (x <= a && x >= b) || (x <= b && x >= a) ) && (x % 4) == 0  &&  (x % 5) == 0 )    // Se x pertence ao intervalo inicial, e e multiplo de 4 e 5
          {
            printf  ("O valor [ %d ] pertence ao intervalo inicial e e um multiplo de 4 e de 5. ", x);
            println ("");         // Pular uma linha
            contador++;
          }
        else if ( ( (x <= a && x >= b) || (x <= b && x >= a) ) && (x % 4) == 0 )   // Se x pertence ao intervalo inicial e e multiplo de 4, mas nao de 5
          {
            printf  ("O valor [ %d ] pertence ao intervalo inicial e e um multiplo de 4, mas nao de 5. ", x);
            println ("");         // Pular uma linha
          }
        else if ( ( (x <= a && x >= b) || (x <= b && x >= a) ) && (x % 5) == 0 )   // Se x pertence ao intervalo inicial e e multiplo de 5, mas nao de 4
          {
            printf  ("O valor [ %d ] pertence ao intervalo inicial e e um multiplo de 5, mas nao de 4. ", x);
            println ("");         // Pular uma linha
          }
        else if ( (x <= a && x >= b) || (x <= b && x >= a) )    // Se x pertence ao intervalo inicial, mas nao e multiplo nem de 4 nem de 5
          {
            printf  ("O valor [ %d ] pertence ao intervalo inicial, mas nao e multiplo nem de 4, nem de 5. ", x);
            println ("");         // Pular uma linha
          }
        else if ( (x % 4) == 0 && (x % 5) == 0 )                // Se x nao pertence ao intervalo inicial e e multiplo de 4 e de 5
          {
            printf  ("O valor [ %d ] nao pertence ao intervalo inicial, mas e multiplo tanto de 4 como de 5. ", x);
            println ("");         // Pular uma linha
          }
        else if ( (x % 4) == 0 )  // Se x nao pertence ao intervalo inicial e e multiplo de 4, mas nao de 5
          {
            printf  ("O valor [ %d ] nao pertence ao intervalo inicial, e multiplo de 4, mas nao de 5. ", x);
            println ("");         // Pular uma linha
          }
        else if ( (x % 5) == 0 )  // Se x nao pertence ao intervalo inicial e e multiplo de 5, mas nao de 4
          {
            printf ("O valor [ %d ] nao pertence ao intervalo inicial, e multiplo de 5, mas nao de 4. ", x);
            println ("");         // Pular uma linha
          }
        else                      // Se x nao pertence ao intervalo inicial, e nao e multiplo de 4 nem de 5
          {
            printf ("O valor [ %d ] nao pertence ao intervalo inicial, nao e multiplo de 4 e nem de 5. ", x);
            println ("");         // Pular uma linha
          } 

        // Contagem de valores restantes
        n--;
        println ("");
        printf  ("Valores a serem testados restantes: %d", n);
        println ("");

        } while (n != 0);
      
    // Contador
    println ("");         // Pular uma linha
    printf  ("A contagem de valores que pertencem ao intervalo inicial, e sao multiplos tanto de 4 como de 5 sao: [%d] ", contador);
    println ("");         // Pular uma linha

    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0319
void ED_0319 (void)
{
    // Identificacao de dados
    // Apresentacao
    println ("ED_0319");
    println ("\n");
    // Ler dados
    // Verificar dados
    // Calcular dados
    // Mostrar dados
    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

// ED_0320
void ED_0320 (void)
{
    // Identificacao de dados
    // Apresentacao
    println ("ED_0320");
    println ("\n");
    // Ler dados
    // Verificar dados
    // Calcular dados
    // Mostrar dados
    // Fim
    pause ("Aperte <ENTER> para continuar. ");
}

int main (void)
{
    // Definir dado
    int opcao = 0;

    // Repeticao
    do 
    {
        // Identificacao
        println ("");            // Pular uma linha
        println ("ED03 - v0.14 - 15/03/24");
        println ("853355_AED1 - Davi Puddo\n");

        // Mostrar opcoes
        println ("Opcoes: " );
        println ("0 - Sair");
        println ("1 - 0311   2 - 0312");
        println ("3 - 0313   4 - 0314");
        println ("5 - 0315   6 - 0316");
        println ("7 - 0317   8 - 0318");
        println ("9 - 0319  10 - 0320");
        println ("");

        // Ler opcao
        println ("Escolha um exercicio: ");
        scanf   ("%d", &opcao);
        getchar ();

        // Escolher opcao
        switch  ( opcao )
        {
            case 0:
              break;
            case 1:  ED_0311();
              break;        
            case 2:  ED_0312();
              break;        
            case 3:  ED_0313();
              break;
            case 4:  ED_0314();
              break;
            case 5:  ED_0315();
              break;
            case 6:  ED_0316();
              break;
            case 7:  ED_0317();
              break;
            case 8:  ED_0318();
              break;
            case 9:  ED_0319();
              break;
            case 10: ED_0320();
              break;
            default:
                println ("\nA Opcao digitada e invalida\n");
                break;
        }
    } while (opcao != 0);       //Fim repeticao

    // Fim
    pause  ("Aperte <ENTER> para sair.");
    return (0);
}

/*
    Versao      Data        Teste      Modificacoes
    0.0         03/11/24    (OK)       Criacao do arquivo ED03 e seus metodos
    0.1         03/11/24    (OK)       Implementacao do ED_0311
    0.2         03/13/24    (OK)       Melhoria do ED_0311
    0.3         03/13/24    (OK)       Implementacao do ED_0312
    0.4         03/13/24    (OK)       Melhoria do ED_0312
    0.5         03/13/24    (OK)       Implementacao do ED_0313
    0.6         03/14/24    (OK)       Implementacao do ED_0314
    0.7         03/14/24    (ERRO)     Implementacao do ED_0315
    0.8         03/14/24    (ERRO)     Correcao na identificacao de dados do ED_0315
    0.9         03/14/24    (OK)       Correcao na leitura individual de dados do ED_0315
    0.10        03/14/24    (ERRO)     Implementacao do ED_0316
    0.11        03/14/24    (OK)       Adicao da leitura do tamanho da cadeia de caractere do ED_0316
    0.12        03/14/24    (OK)       Implementacao do ED_0317
    0.13        03/15/24    (OK)       Melhoria do ED_0317
    0.14        03/15/24    (OK)       Implementacao do ED_0318
*/ 