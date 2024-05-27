
#include "../puddo.hpp"

int main (void)
{
    char x = '0';
    do
    {
        x = ReadChar("S/N");
    } while (x != 'S' || x != 'N');
    if (x == 'S')
    {
        println("Feliz");
    }
    return(0);
}