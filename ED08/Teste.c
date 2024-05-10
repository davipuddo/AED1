//853355_AED1

#include "io.h"
#include "puddo.h"

void teste1 (void)
{
  int arranjo [] = {1,2,3,4,5};
  IntWriteArrayFile("TESTE1.TXT", 5, arranjo);

  int *resultado = IntArrayFile("TESTE1.TXT");

  IntReadArray(resultado, 1);

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste2 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste2");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados
  printf ("%d", RandInterval(1,10));

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste3 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste3");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste4 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste4");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste5 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste5");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste6 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste6");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste7 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste7");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste8 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste8");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste9 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste9");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
}

void teste10 (void)
{
  // Identificacao de dados
  // Apresentacao
  IO_println ("teste10");
  IO_println ("");                  // Pular uma linha
  IO_println (" ");
  IO_println ("");                  // Pular uma linha
    
  // Ler dados
  // Verificar dados
  // Mostrar dados

  // Fim
  IO_println ("");                  // Pular uma linha
  IO_println ("");                  // Pular uma linha
  IO_pause   ("Aperte <ENTER> para continuar. ");
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
      IO_println ("teste- v0.0 - 00/00/00" );
      IO_println ("853355_AED1 - Davi Puddo");
      IO_println ("");              // Pular uma linha

      // Mostrar opcoes
      IO_println ("Exercicios: ");
      IO_println ("");              // Pular uma linha
      IO_println ("0 - sair");
      IO_println ("1 - teste1   2 - teste2");
      IO_println ("3 - teste3   4 - teste4");
      IO_println ("5 - teste5   6 - teste6");
      IO_println ("7 - teste7   8 - teste8");
      IO_println ("9 - teste9  10 - teste10");
      IO_println ("");              // Pular uma linha

      // Ler opcao
      IO_println ("Escolha um exercicio: ");
      IO_scanf   ("%d", &opcao);
      getchar    ();

      // Escolher opcao
      switch (opcao)
        {
          case 0:
            break;
          case 1:  teste1();
            break;
          case 2:  teste2();
            break;
          case 3:  teste3();
            break;
          case 4:  teste4();
            break;
          case 5:  teste5();
            break;
          case 6:  teste6();
            break;
          case 7:  teste7();
            break;
          case 8:  teste8();
            break;
          case 9:  teste9();
            break;
          case 10: teste10();
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
    0.0         00/00/00    (OK)       Criacao do arquivo testee seus metodos

*/