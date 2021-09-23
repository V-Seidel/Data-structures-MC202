/* Tarefa 03 */
/* Autor: Vinícius Seidel */

#include <stdio.h>
#include <string.h>

#define MAXALUNOS 100
#define MAXCARACTERES 30
#define SEPARATOR '_'

/* Função printa a lista final */
void mostrarLista(char lista[][MAXCARACTERES], int numero_alunos, int vetor_resultado[]);
/* Função que ordena um array de strings em ordem alfabética pelo BubbleSort */
void bubbleSort(char lista[][MAXCARACTERES], int numero_alunos);
/* Função compara duas strings até um determinado char */
int compararString(char str1[], char str2[], int acao_usada);
/* Função para achar homonimos e mudar o vetor resultado */
void acharHomonimos(char lista[][MAXCARACTERES], int numero_alunos, int vetor_resultado[]);

/* Função principal */
int main()
{
    /* Variáveis para entradas */
    int numero_alunos;
    char acao_desejada[MAXCARACTERES];

    scanf("%d\n", &numero_alunos);
    scanf("%s\n", acao_desejada);

    char lista_inicial[MAXALUNOS][MAXCARACTERES];
    int vetor_resultado[MAXALUNOS] = {0};

    for (int i = 0; i < numero_alunos; i++)
    {
        scanf("%s", lista_inicial[i]);
    }
    bubbleSort(lista_inicial, numero_alunos);

    if (acao_desejada[0] == 'h')
    {
        acharHomonimos(lista_inicial, numero_alunos, vetor_resultado);
    }
    mostrarLista(lista_inicial, numero_alunos, vetor_resultado);
}

/* Funções auxiliares */
void mostrarLista(char lista[][MAXCARACTERES], int numero_alunos, int vetor_resultado[])
{

    for (int i = 0; i < numero_alunos; i++)
    {
        if (vetor_resultado[i])
        {
            printf("%s", lista[i]);
            printf("\n");
        }
    }
}

int compararString(char str1[], char str2[], int acao_usada)
{
    int i = 0;
    if (acao_usada == 2)
        i = -1;
    while (str1[i] != SEPARATOR)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        else
        {
            if (acao_usada == 2)
                i -= 1;
            else
                i += 1;
        }
    }
    return 1;
}

/* Algoritmos auxiliares */
void bubbleSort(char lista[][MAXCARACTERES], int numero_alunos)
{
    char aux[MAXCARACTERES];

    for (int i = 0; i < numero_alunos - 1; i++)
    {
        for (int j = i + 1; j < numero_alunos; j++)
        {
            if (strcmp(lista[i], lista[j]) > 0)
            {
                strcpy(aux, lista[i]);
                strcpy(lista[i], lista[j]);
                strcpy(lista[j], aux);
            }
        }
    }
}

void acharHomonimos(char lista[][MAXCARACTERES], int numero_alunos, int vetor_resultado[])
{
    for (int i = 0; i < numero_alunos; i++)
    {

        if (compararString(lista[i], lista[i + 1], 1))
        {
            vetor_resultado[i] = 1;
            vetor_resultado[i + 1] = 1;
        }
    }
}
