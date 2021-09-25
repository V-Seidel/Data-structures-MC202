/* Tarefa 05 */
/* Autor: Vinícius Seidel */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 14

void imprime(char *vetor_dna, char *vetor_rna_traduzido, int *vetor_resultante, int tamanho_segmento);
int achar_indice(char *vetor, int tamanho_segmento, char base_nitrogenada);
void transcrever_dna(char *vetor_dna_padrao, char *vetor_rna_padrao, char *vetor_rna_traduzido, char *vetor_dna, int tamanho_segmento);
void criar_contagem(char *vetor_dna, int tamanho_segmento, int *vetor_resultante, int *vetor_auxiliar);
void achar_indice_reverso(char *vetor_dna, char base_nitrogenada, int *vetor_resultante, int *vetor_auxiliar, int indice);

/* Função principal */
int main()
{
    char *ponteiro_segmento_dna, *ponteiro_segmento_rna;
    int tamanho_segmento, *vetor_resultante, *vetor_auxiliar;
    char dna_padrao[MAX_CARACTERES], rna_padrao[MAX_CARACTERES];

    scanf("%s ", dna_padrao);
    scanf("%s ", rna_padrao);
    scanf("%d ", &tamanho_segmento);

    ponteiro_segmento_dna = malloc(tamanho_segmento * sizeof(char));
    ponteiro_segmento_rna = malloc(tamanho_segmento * sizeof(char));
    vetor_resultante = malloc(tamanho_segmento * sizeof(int));
    vetor_auxiliar = malloc(tamanho_segmento * sizeof(int));

    for (int i = 0; i < tamanho_segmento; i++)
    {
        scanf("%c ", &ponteiro_segmento_dna[i]);
        vetor_resultante[i] = 0;
        vetor_auxiliar[i] = 0;
    }

    transcrever_dna(dna_padrao, rna_padrao, ponteiro_segmento_rna, ponteiro_segmento_dna, tamanho_segmento);
    criar_contagem(ponteiro_segmento_dna, tamanho_segmento, vetor_resultante, vetor_auxiliar);
    imprime(ponteiro_segmento_dna, ponteiro_segmento_rna, vetor_resultante, tamanho_segmento);
    free(ponteiro_segmento_dna);
    free(ponteiro_segmento_rna);
    free(vetor_resultante);
    free(vetor_auxiliar);
}

void imprime(char *vetor_dna, char *vetor_rna_traduzido, int *vetor_resultante, int tamanho_segmento)
{
    printf("ID:\t");
    for (int i = 0; i < tamanho_segmento; i++)
    {
        printf("%d ", vetor_resultante[i]);
    }
    printf("\nDNA:\t");
    for (int i = 0; i < tamanho_segmento; i++)
    {
        printf("%c ", vetor_dna[i]);
    }
    printf("\n\t");
    for (int i = 0; i < tamanho_segmento; i++)
    {
        printf("| ");
    }
    printf("\nRNA:\t");
    for (int i = 0; i < tamanho_segmento; i++)
    {
        printf("%c ", vetor_rna_traduzido[i]);
    }
    printf("\n");
}

int achar_indice(char *vetor, int tamanho_segmento, char base_nitrogenada)
{
    for (int i = 0; i < tamanho_segmento; i++)
    {
        if (vetor[i] == base_nitrogenada)
        {
            return i;
        }
    }
    return -1;
}

void transcrever_dna(char *vetor_dna_padrao, char *vetor_rna_padrao, char *vetor_rna_traduzido, char *vetor_dna, int tamanho_segmento)
{
    for (int i = 0; i < tamanho_segmento; i++)
    {
        int indice_rna;
        char base_nitrogenada = vetor_dna[i];
        indice_rna = achar_indice(vetor_dna_padrao, tamanho_segmento, base_nitrogenada);
        vetor_rna_traduzido[i] = vetor_rna_padrao[indice_rna];
    }
}

void criar_contagem(char *vetor_dna, int tamanho_segmento, int *vetor_resultante, int *vetor_auxiliar)
{
    char base_nitrogenada;
    for (int i = 0; i < tamanho_segmento; i++)
    {
        base_nitrogenada = vetor_dna[i];
        achar_indice_reverso(vetor_dna, base_nitrogenada, vetor_resultante, vetor_auxiliar, i);
    }
}

void achar_indice_reverso(char *vetor_dna, char base_nitrogenada, int *vetor_resultante, int *vetor_auxiliar, int indice)
{
    for (int i = (indice - 1); i >= 0; i--)
    {
        if (vetor_dna[i] == base_nitrogenada)
        {
            vetor_auxiliar[indice] = vetor_auxiliar[i] + 1;
            vetor_resultante[indice] = vetor_auxiliar[indice];
            break;
        }
    }
}