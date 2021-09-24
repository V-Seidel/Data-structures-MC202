#include "planejar.h"
#include <stdio.h>
#define MAX 100

int main()
{
    Voo voos[MAX];
    char vetor_resultado[MAX] = {0};
    char acao[MAX];
    int numero_voo;

    while (scanf("%s ", acao))
    {
        if (acao[0] == 'r')
        {
            for (int i = 0; i < MAX; i++)
            {
                if (vetor_resultado[i] == 0)
                {
                    vetor_resultado[i] = 1;
                    voos[i] = registrar();
                    break;
                }
            }
        }

        if (acao[0] == 'a')
        {
            float novo_valor;
            scanf("%d %f ", &numero_voo, &novo_valor);
            alterar(voos, MAX, numero_voo, novo_valor);
        }
        if (acao[0] == 'c')
        {
            int indice_voo;
            scanf("%d ", &numero_voo);
            indice_voo = achar_indice(voos, MAX, numero_voo);
            vetor_resultado[indice_voo] = 0;
        }
        if (acao[0] == 'p')
        {
            char codigo_origem[4];
            Data data_inicio;
            Data data_fim;
            scanf("%s ", codigo_origem);
            data_inicio = ler_data();
            data_fim = ler_data();
            planejar(voos, vetor_resultado, MAX, data_inicio, data_fim, codigo_origem);
            break;
        }
    }
}