//853355_AED1

#include "../io.hpp"
#include "../puddo.hpp"

void Teste01 (void)
{
  // Identificacao de dados
  Array <int> int_array(5,0);

  // Identificacao
  println ("Teste01");

  // Definir dados
  int_array.set(0,1);
  int_array.set(1,2);
  int_array.set(2,3);
  int_array.set(3,4);
  int_array.set(4,5);

  // Mostrar dados
  int_array.print();

  // Liberar espaco da memoria
  int_array.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste02 (void)
{
  // Identificacao de dados
  Array <int> int_array(5,0);

  // Identificacao
  println ("Teste02");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  int_array.write();

  // Mostrar dados
  int_array.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste03 (void)
{
  // Identificacao de dados
  Array <int> int_array(5,0);

  // Identificacao
  println ("Teste03");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  int_array.write();

  // Gravar dados no arquivo
  int_array.fwrite("TESTE03.TXT");

  // Ler dados gravados
  int_array.fread("TESTE03.TXT");

  // Mostrar dados
  int_array.print();

  // Liberar espaco da memoria
  int_array.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste04 (void)
{
  // Identificacao de dados
  int other[] = {1,2,3,4,5};
  Array <int> int_array(10, other);

  // Identificacao
  println ("Teste04");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
  
  // Mostrar dados
  int_array.print();

  // Liberar espaco da memoria
  int_array.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste05 (void)
{
  // Identificacao de dados
  Array <int> int_array1(1, 0);

  // Identificacao
  println ("Teste05");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  int_array1.fread("TESTE03.TXT");

  // Mostrar dados
  println ("Original-");
  int_array1.print();

  // Criar copia
  Array <int> int_array2(int_array1);

  // Mostrar dados
  println ("Copia-");
  int_array2.print();

  // Liberar espaco da memoria
  int_array1.free();
  int_array2.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste06 (void)
{
  // Identificacao de dados
  Array <int> int_array1 (1,0);
  Array <int> int_array2 (1,0);

  // Identificacao
  println ("Teste06");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  int_array1.fread("TESTE03.TXT");

  // Mostrar dados
  println ("Original-");
  int_array1.print();

  // Copiar dados
  int_array2 = int_array1;

  // Mostrar dados
  println ("Copia-");
  int_array2.print();

  // Liberar espaco da memoria
  int_array1.free();
  int_array2.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste07 (void)
{
  // Identificacao de dados
  int other[] = {1,2,3};
  Array <int> int_array1 (3, other);
  Array <int> int_array2 (3, other);

  // Identificacao
  println ("Teste07");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
  
  // Mostrar dados
  println ("");
  println ("Array1-");
  int_array1.print();

  println ("Array2-");
  int_array2.print();

  // Mostar comparacao
  std::cout << "Igualdade = " << (int_array1 == int_array2) << std::endl;

  // Alterar dado
  int_array2.set(0,(-1));

  // Mostrar dados
  println ("");
  println ("Array1-");
  int_array1.print();

  println ("Array2-");
  int_array2.print();

  // Mostar comparacao
  std::cout << "Igualdade = " << (int_array1 == int_array2) << std::endl;

  // Liberar espaco da memoria
  int_array1.free();
  int_array2.free();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste08 (void)
{
  // Identificacao de dados
  Array <int> int_array1(5,0);
  Array <int> int_array2(5,0);
  Array <int> int_array3(5,0);

  // Identificacao
  println ("Teste08");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  int_array1.write();
  int_array2.write();

  // Somar
  int_array3 = int_array1 + int_array2;

  // Mostrar dados
  println ("Array1-");
  int_array1.print();
  println ("Array2-");
  int_array2.print();
  println ("Soma: ");
  int_array3.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste09 (void)
{
  // Identificacao de dados
  Array <int> array(5, 0);

  // Identificacao
  println ("Teste09");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  array.write();

  // Mostrar dados
  println ("Normal-");
  array.print();

  // Encontrar valores pares
  array.even();

  // Mostrar dados
  println ("Pares-");
  array.print();

  // Fim
  println ("");                  // Pular uma linha
  println ("");                  // Pular uma linha
  pause   ("Aperte <ENTER> para continuar. ");
}

void Teste10 (void)
{
  // Identificacao de dados
  Matrix <int> matrix(3, 3, 0);
  int x = 0;

  // Identificacao
  println ("Teste10");
  println ("");                  // Pular uma linha
  println (" ");
  println ("");                  // Pular uma linha
    
  // Ler dados
  matrix.write();

  // Mostrar dados
  println ("Matriz Normal- ");
  matrix.print();

  // Alterar valor na posicao 2:2 para 22
  matrix.set(2,2,22);

  // Mostar valor alterado
  println ("Matriz Alterada- ");
  matrix.print();

  // Liberar matrix da memoria
  matrix.free();

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
      println ("Teste - v0.0 - 00/00/00" );
      println ("853355_AED1 - Davi Puddo");
      println ("");              // Pular uma linha

      // Mostrar opcoes
      println ("Exercicios: ");
      println ("");              // Pular uma linha
      println ("0 - sair");
      println ("1 - Teste01   2 - Teste02");
      println ("3 - Teste03   4 - Teste04");
      println ("5 - Teste05   6 - Teste06");
      println ("7 - Teste07   8 - Teste08");
      println ("9 - Teste09  10 - Teste10");
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
          case 1:  Teste01();
            break;
          case 2:  Teste02();
            break;
          case 3:  Teste03();
            break;
          case 4:  Teste04();
            break;
          case 5:  Teste05();
            break;
          case 6:  Teste06();
            break;
          case 7:  Teste07();
            break;
          case 8:  Teste08();
            break;
          case 9:  Teste09();
            break;
          case 10: Teste10();
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
    0.0         00/00/00    (OK)       Criacao do arquivo Teste e seus metodos

*/