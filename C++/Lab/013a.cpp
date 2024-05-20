#include <iostream>
#include <fstream>

// --------------------------- inicio biblioteca

#define   null  nullptr

const int MAX = 10; // tamanho maximo

class int_Matrix
{
  private:
    int   rows    = 0;
    int   columns = 0;
    int **data    = null;
  public:

/*
  Construtor de matriz.
  @param rows    - quantidade de linhas
  @param columns - quantidade de colunas
  @param value   - valor inicial a ser guardado
*/
  int_Matrix ( int rows, int columns, int value )
  {
     if ( rows > 0 && columns > 0 )
     {   
        data = (int**) new int [rows];
        for ( int x=0; x<rows; x=x+1 )
        {   data [x] = (int*) new int [columns];
            for ( int y=0; y<columns; y=y+1 )
            {   data [x][y] = value;  }
        }
        this->rows    = rows;
        this->columns = columns;
     }
} // end constructor ( )

/*
  Metodo para guardar valor inicial em posicoes de matriz.
  @param value  - valor a ser guardado
*/
  int_Matrix* init ( int value )
  {
     return ( this );
} // end init ( )

/*
  Metodo para mostrar valores em matriz.
*/
  void print ( )
  {
  } // end print_int_matrix( )

/*
  Funcao para ler valores para matriz.
*/
  void scan ( )
  {
   // definir dados locais
  } // end scan_int_matrix( )

/*
  Metodo para gravar em arquivo valores em matriz.
  @param filename - nome do arquivo
*/
  void fprint_int_matrix
     ( std::string filename )
 {
  // definir dados locais
 } // end fprint( )

/*
  Metodo para ler de arquivo valores para matriz.
  @param filename - nome do arquivo
*/
  void fscan_int_matrix
     ( std::string filename )
  {
   // definir dados locais
  } // end fscan( )

// a definir
  int         largest_int_matrix    ( );
  int         smallest_int_matrix   ( );
  int         sum_int_matrix        ( );
  double      average_int_matrix    ( );
  int_Matrix* copy                  ( );

} ; // end class int_Matrix

/*
  Funcao para achar o maior valor em matriz.
  @return maior valor
  @param matrix - matriz onde guardar
*/
  int int_Matrix::largest_int_matrix ( )
  {
   // definir dados locais
      int maior = 0;
   // retornar o maior valor
      return ( maior );
  } // end largest_int_matrix ( )

/*
  Funcao para achar o menor valor em matriz.
  @return menor valor
*/
  int int_Matrix::smallest_int_matrix ( )
  {
   // definir dados locais
      int menor = 0;
   // retornar o menor valor
      return ( menor );
  } // end smallest_int_matrix ( )

/*
  Funcao para somar valores em matriz.
  @return soma de todos os valores
*/
  int int_Matrix::sum_int_matrix ( )
  {
   // definir dados locais
      int soma = 0;
   // retornar a soma de todos os dados
      return ( soma );
  } // end sum_int_matrix ( )

/*
  Funcao para calcular a media dos valores em matriz.
  @return media dos valores
*/
  double int_Matrix::average_int_matrix ( )
  {
   // definir dados locais
      double media = 0.0;
   // retornar a media de todos os dados
      return ( media );
  } // end average_int_matrix ( )

/*
  Metodo para copiar valores em matriz.
  @return referencia para copia da matriz
*/
  int_Matrix* int_Matrix::copy ( )
  {
   // definir dados locais
   // copiar dados de um arranjo para outro
      return ( null );
  } // end copy( )

// --------------------------- fim biblioteca

/*
   Method_01.
*/
void method_01 ( void )
{
  // testar a atribuicao de valor inicial
  int m         = 0;
  int n         = 0;
  int value     = 0;
  int_Matrix *a = null;

  std::cout << "\nm = " ;
  std::cin  >>    m     ;     std::cin.get( );
  std::cout << "\nn = " ;
  std::cin  >>    n     ;     std::cin.get( );
  std::cout << "\nvalue = " ;
  std::cin  >>    value ; getchar( );

  a = new int_Matrix ( m, n, value );
    
  a->print ( );
  std::cout << std::endl;
    
  a = a->init  ( 0 );
  a->print ( );
} // end method_01 ( )

/*
   Method_02.
*/
void method_02 ( void )
{
  // testar a exibicao de dados  
} // end method_01 ( )

/*
   Method_03.
*/
void method_03 ( void )
{
  // testar a leitura de dados do teclado
} // end method_03 ( )

/*
   Method_04.
*/
void method_04 ( void )
{
  // testar a gravacao de dados em arquivo
} // end method_04 ( )

/*
   Method_05.
*/
void method_05 ( void )
{
  // testar a leitura de dados de arquivo
} // end method_05 ( )

/*
   Method_06.
*/
void method_06 ( void )
{
  // testar a procura do maior valor
} // end method_06 ( )

/*
   Method_07.
*/
void method_07 ( void )
{
  // testar a procura do menor valor
} // end method_07 ( )

/*
   Method_08.
*/
void method_08 ( void )
{
  // testar a procura da soma de todos os dados
} // end method_08 ( )

/*
   Method_09.
*/
void method_09 ( void )
{
  // testar a procura da media de todos os dados
} // end method_09 ( )

/*
   Method_10.
*/
void method_10 ( void )
{
  // testar a copia de dados 
} // end method_10 ( )

// -------------------------- Acao principal

int main ( void )
{
 // definir dados
     int opcao = 0;

 // acoes
    do
    {
       printf ( "\nQual a opcao? " );
       scanf  ( "%d", &opcao ); getchar ( );
       //printf ( "%d\n",  opcao );
       switch ( opcao )
       {
         case  0: /* nao fazer nada */
           break;
         case  1: method_01 ( ); break;
         case  2: method_02 ( ); break;
         case  3: method_03 ( ); break;
         case  4: method_04 ( ); break;
         case  5: method_05 ( ); break;
         case  6: method_06 ( ); break;
         case  7: method_07 ( ); break;
         case  8: method_08 ( ); break;
         case  9: method_09 ( ); break;
         case 10: method_10 ( ); break;
         default:
                  printf ( "ERRO: Opcao invalida.\nApertar ENTER." );
                  getchar( );
          break;
       } // end switch
    }
    while ( opcao != 0 );
 // encerrar
     //printf ( "\nApertar ENTER\n\n" ); getchar( );
     return ( 0 );

} // end main ( )
/**
     Testes - Comentarios
*/

