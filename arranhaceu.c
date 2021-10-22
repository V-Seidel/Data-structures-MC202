/* Tarefa 07 */
/* Autor: Vinícius Seidel */
/* RA: 245233 */

#include "arranhaceu.h"
#include <stdio.h>
#include <stdlib.h>

/* --------------------------------Função Principal--------------------------------------- */
int main()
{

    int tamanho_grade, **quebra_cabeca;

    scanf("%d", &tamanho_grade);

    quebra_cabeca = alocaMatriz(tamanho_grade + 2);

    //Leitura das entradas e atribuição às bordas do quebra cabeça
    for (int i = 0; i < tamanho_grade + 2; i++)
    {
        for (int j = 0; j < tamanho_grade + 2; j++)
            scanf("%d", &quebra_cabeca[i][j]);
    }
    resolverQuebraCabeca(quebra_cabeca, tamanho_grade + 2, 1, 1);

    liberaMatriz(quebra_cabeca, tamanho_grade + 2);
}

/* --------------------------------Função Essenciais--------------------------------------- */

int resolverQuebraCabeca(int **quebra_cabeca, int tamanho_grade_total, int linha, int coluna)
{
    int prox_linha, prox_coluna;

    //Caso final
    if (linha > (tamanho_grade_total - 2))
    {
        mostraMatriz(quebra_cabeca, tamanho_grade_total);
        return 1;
    }

    proximaPosicao(linha, coluna, &prox_linha, &prox_coluna, tamanho_grade_total);

    for (int i = 1; i < (tamanho_grade_total - 1); i++)
    {
        if (podeInserir(i, quebra_cabeca, tamanho_grade_total, linha, coluna))
        {
            quebra_cabeca[linha][coluna] = i;

            if (resolverQuebraCabeca(quebra_cabeca, tamanho_grade_total, prox_linha, prox_coluna))
                return 1;
        }
    }

    quebra_cabeca[linha][coluna] = 0;
    return 0;
}

void proximaPosicao(int linha, int coluna, int *prox_linha, int *prox_coluna, int tamanho_grade_total)
{
    if (coluna < (tamanho_grade_total - 2))
    {
        *prox_linha = linha;
        *prox_coluna = coluna + 1;
    }
    else
    {
        *prox_linha = linha + 1;
        *prox_coluna = 1;
    }
}

int podeInserir(int valor, int **quebra_cabeca, int tamanho_grade, int linha, int coluna)
{
    for (int i = 1; i < tamanho_grade - 1; i++)
    {
        if (quebra_cabeca[i][coluna] == valor)
            return 0;
    }
    for (int j = 1; j < tamanho_grade - 1; j++)
    {
        if (quebra_cabeca[linha][j] == valor)
            return 0;
    }

    if (testarPredios(valor, quebra_cabeca, tamanho_grade, linha, coluna) == 0)
        return 0;

    if (linha == (tamanho_grade - 2))
    {
        if (testarPrediosColuna(valor, quebra_cabeca, tamanho_grade, coluna) == 0)
            return 0;
    }

    if (coluna == (tamanho_grade - 2))
    {
        if (testarPrediosLinha(valor, quebra_cabeca, tamanho_grade, linha) == 0)
            return 0;
    }
    return 1;
}

/* --------------------------------Funções Auxiliares--------------------------------------- */

int **alocaMatriz(int tamanho_grade_total)
{
    int **quebra_cabeca;
    quebra_cabeca = malloc((tamanho_grade_total) * sizeof(int *));

    for (int i = 0; i < (tamanho_grade_total); i++)
        quebra_cabeca[i] = malloc((tamanho_grade_total) * sizeof(int));

    return quebra_cabeca;
}

void liberaMatriz(int **quebra_cabeca, int tamanho_grade_total)
{
    for (int i = 0; i < tamanho_grade_total; i++)
        free(quebra_cabeca[i]);

    free(quebra_cabeca);
}

void mostraMatriz(int **quebra_cabeca, int tamanho_grade_total)
{
    for (int i = 1; i < (tamanho_grade_total - 1); i++)
    {
        for (int j = 1; j < (tamanho_grade_total - 1); j++)
            printf("%d ", quebra_cabeca[i][j]);
        printf("\n");
    }
}

int testarPrediosLinha(int valor, int **quebra_cabeca, int tamanho_grade, int linha)
{
    int contador_dir = 0;
    int maior_predio = 0;
    quebra_cabeca[linha][tamanho_grade - 2] = valor;

    for (int i = (tamanho_grade - 2); i > 0; i--)
    {
        if (quebra_cabeca[linha][i] > maior_predio)
        {
            contador_dir++;
            maior_predio = quebra_cabeca[linha][i];
        }
    }
    if (contador_dir != quebra_cabeca[linha][tamanho_grade - 1])
    {
        quebra_cabeca[linha][tamanho_grade - 2] = 0;
        return 0;
    }

    else
        return 1;
}

int testarPrediosColuna(int valor, int **quebra_cabeca, int tamanho_grade, int coluna)
{
    int contador_baixo = 0;
    int maior_predio = 0;
    quebra_cabeca[tamanho_grade - 2][coluna] = valor;

    for (int i = (tamanho_grade - 2); i > 0; i--)
    {
        if (quebra_cabeca[i][coluna] > maior_predio)
        {
            contador_baixo++;
            maior_predio = quebra_cabeca[i][coluna];
        }
    }

    if (contador_baixo != quebra_cabeca[tamanho_grade - 1][coluna])
    {
        quebra_cabeca[tamanho_grade - 2][coluna] = 0;
        return 0;
    }

    else
        return 1;
}

int testarPredios(int valor, int **quebra_cabeca, int tamanho_grade, int linha, int coluna)
{
    int contador_cima = 0;
    int contador_esq = 0;
    int maior_predio = 0;
    quebra_cabeca[linha][coluna] = valor;

    for (int i = 1; i < tamanho_grade - 1; i++)
    {
        if (quebra_cabeca[linha][i] > maior_predio)
        {
            contador_esq++;
            maior_predio = quebra_cabeca[linha][i];
        }
    }

    maior_predio = 0;
    for (int i = 1; i < tamanho_grade - 1; i++)
    {
        if (quebra_cabeca[i][coluna] > maior_predio)
        {
            contador_cima++;
            maior_predio = quebra_cabeca[i][coluna];
        }
    }

    if (linha == tamanho_grade - 2 && contador_cima != quebra_cabeca[0][coluna])
    {
        quebra_cabeca[linha][coluna] = 0;
        return 0;
    }

    if (coluna == tamanho_grade - 2 && contador_esq != quebra_cabeca[linha][0])
    {
        quebra_cabeca[linha][coluna] = 0;
        return 0;
    }

    if (contador_cima > quebra_cabeca[0][coluna] || contador_esq > quebra_cabeca[linha][0])
    {
        quebra_cabeca[linha][coluna] = 0;
        return 0;
    }

    else
        return 1;
}