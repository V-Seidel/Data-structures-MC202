/* Tarefa 06 */
/* Autor: Vinícius Seidel */
/* RA: 245233 */

#include "minecraft.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXALTURA 256

/* --------------------------------Função Principal--------------------------------------- */
int main()
{
    //Declaração das variáveis utilizadas e inicialização das mesmas.
    int **matriz_altitude, m, n, seed;
    int qtdDiamante, qtdOuro, qtdFerro, qtdBlocos;
    qtdBlocos = qtdDiamante = qtdFerro = qtdOuro = 0;
    double tempoPorBloco, tempo_total;
    Bloco ***mundo;

    //Obtenção das entradas.
    scanf("%d %d ", &m, &n);
    scanf("%d ", &seed);
    scanf("%lf", &tempoPorBloco);

    //Criação da matriz de altitudes, criação do mundo e exploração do mundo.
    matriz_altitude = calcularAltitudes(m, n, seed);
    mundo = criarMundo(m, n, matriz_altitude, seed);
    tempo_total = explorarMundo(mundo, m, n, matriz_altitude, tempoPorBloco, &qtdDiamante, &qtdOuro, &qtdFerro, &qtdBlocos);

    //Saídas necessárias.
    printf("Total de Blocos: %d\n", qtdBlocos);
    printf("Tempo total: %.2fs\n", tempo_total);
    printf("Diamantes: %d\n", qtdDiamante);
    printf("Ouros: %d\n", qtdOuro);
    printf("Ferros: %d\n", qtdFerro);

    //Liberação das memórias alocas nas funções de criação.
    liberaMatriz(matriz_altitude, m, n);
    liberaMatrizEspaco(mundo, m, n);
}

/* --------------------------------Funções Essenciais--------------------------------------- */
int **calcularAltitudes(int m, int n, int seed)
{
    int **matriz_altitude, expressao, altura_final;
    matriz_altitude = alocaMatriz(m, n);

    for (int x = 0; x < m; x++)
    {
        for (int z = 0; z < n; z++)
        {
            //Cálculo da expressão e inserção do valor da altura encontrada
            expressao = seed * (202 + x + z) + 12345 + x + z;
            altura_final = expressao % 256;
            matriz_altitude[x][z] = altura_final;
        }
    }
    return matriz_altitude;
}

Bloco ***criarMundo(int m, int n, int **altitudes, int seed)
{
    Bloco ***matriz_espaco;
    matriz_espaco = alocaMatrizEspaco(m, n);

    for (int x = 0; x < m; x++)
    {
        for (int z = 0; z < n; z++)
        {
            for (int y = 0; y < MAXALTURA; y++)
            {
                if (altitudes[x][z] >= y)
                    matriz_espaco[x][z][y].tipo_de_bloco = calcularTipoBloco(x, y, z, seed);
                else
                    matriz_espaco[x][z][y].tipo_de_bloco = 21;
            }
        }
    }
    return matriz_espaco;
}

double explorarMundo(
    Bloco ***mundo, int m, int n, int **altitudes, double tempoPorBloco,
    int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos)
{
    for (int x = 0; x < m; x++)
    {
        for (int z = 0; z < n; z++)
        {
            for (int y = 0; y <= altitudes[x][z]; y++)
            {
                if (mundo[x][z][y].tipo_de_bloco <= 20)
                {
                    (*qtdBlocos)++;
                    if (mundo[x][z][y].tipo_de_bloco == 0)
                        (*qtdDiamante)++;
                    else if (mundo[x][z][y].tipo_de_bloco == 1 || mundo[x][z][y].tipo_de_bloco == 2)
                        (*qtdOuro)++;
                    else if (mundo[x][z][y].tipo_de_bloco >= 3 && mundo[x][z][y].tipo_de_bloco <= 5)
                        (*qtdFerro)++;
                }
            }
        }
    }
    return (*qtdBlocos) * tempoPorBloco;
}

/* --------------------------------Funções Auxiliares--------------------------------------- */
int **alocaMatriz(int m, int n)
{
    int **matriz_altitude;
    matriz_altitude = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
        matriz_altitude[i] = malloc(n * sizeof(int));

    return matriz_altitude;
}

Bloco ***alocaMatrizEspaco(int m, int n)
{
    Bloco ***matriz_espaco = malloc(m * sizeof(Bloco **));

    for (int i = 0; i < m; i++)
    {
        matriz_espaco[i] = malloc(n * sizeof(Bloco *));

        for (int j = 0; j < n; j++)
        {
            matriz_espaco[i][j] = malloc(MAXALTURA * sizeof(Bloco));
        }
    }
    return matriz_espaco;
}

int calcularTipoBloco(int x, int y, int z, int seed)
{
    int expressao = seed * (202 + x + y + z) + x + y + z;
    return (expressao % 33);
}

void liberaMatriz(int **matriz_altitude, int m, int n)
{
    for (int i = 0; i < m; i++)
        free(matriz_altitude[i]);

    free(matriz_altitude);
}

void liberaMatrizEspaco(Bloco ***mundo, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            free(mundo[i][j]);
        }
        free(mundo[i]);
    }

    free(mundo);
}
