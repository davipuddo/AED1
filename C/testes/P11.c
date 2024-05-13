#include <stdio.h>

int main ()
{
    char   x [80];

    scanf  ("%s", x);
    getchar();

    x [1] = ' ';

    printf ("x = %s", x);
    getchar();

    return (0);
}