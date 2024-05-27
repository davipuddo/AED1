#include "../puddo.h"

void fibonacci(int x, int y, int z, int n, int i)
{
    z = x + y;
    y = x;
    x = z;
    printf ("%d\n", z);
    if (i < n)
    {
        fibonacci(x, y, z, n, i+1);
    }
}

void m01 (void)
{
    int n = 0;
    printf ("n = ");
    scanf("%d", &n);
    getchar();
    fibonacci(1, 0, 0, n, 0);
}

int main(void)
{
    int x = 0;
    do
    {
        x = ReadInt("S:");
        switch (x)
        {
            case 1: m01();
                break;
        }
    } while (x != 0);
    return (0);
}
