// CODIGO DO DAVI
#include "puddo.h"

int *lerArranjo(int *tamanho)
{

    //  *tamanho = 10 - EXPERIMENTA MUDAR ESTE TAMANHO PARA QUALQUER TAMANHO,
    // FODA SE O VALOR QUE VC DIGITOU, VC PODE MUDAR AQUI E O APONTADOR IRÁ RETORNA LO DO TAMANHO QUE VC DEFINIR AQUI

    int *arranjo = (int *)malloc(*tamanho * sizeof(int));

    *tamanho = *tamanho -1;
    for (int i = 0; i < *tamanho; i++)
    {
        printf("Elemento[%d]: ", i + 1);
        scanf("%d", &arranjo[i]);
    }

    return arranjo;
}

int main(void)
{

    int n = 0; // declarar o tamanho inicial do arranjo

    printf("Tamanho Arranjo: ");
    scanf("%d", &n); // entra com o tamanho

    int *arranjoRetornado = lerArranjo(&n); // aqui que está a magica.
                                            /*
                                            você não está passando o valor de N e sim o ENDEREÇO DE MEMORIA DE N,
                                            então ele vai como  um valor, mas la, este valor pode ser alterado e vai mudar
                                            aqui dentro da main
                                            */

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arranjoRetornado[i]);
    }

    free(arranjoRetornado);

    return 0;
}
