#include <stdio.h>

#define MAX 20000

/* Funcao que inicia um array */
void init(int queue[], int participants_number);
/* Funcao que dado um array mostra todos os seus elementos */
void print(int queue[], int participants_number);
/* Funcao que dado um numero do array retorno o indice que ele se encontra*/
int findIndex(int queue[], int participants_number, int value);

/* Funcao que dado um array inverte a ordem entre os indices a e b da mesma*/
void revertArray(int queue[], int index_a, int index_b, int participants_number);
/* Funcao que dado dois indices a e b ocorre um deslocamento da posicao de a para b+1 */
void displaceElement(int queue[], int index_a, int index_b, int participants_number);

int main()
{
    /* Variaveis dos valores iniciais */
    int participants_number, movements_number;
    int movements_type, a, b;
    int index_a, index_b;

    /* Obtencaoo dos valores iniciais */
    scanf(" %d \n", &participants_number);
    scanf(" %d", &movements_number);

    /* Declaracaoo da fila com o numero de participantes totais*/
    int queue[MAX];
    init(queue, participants_number);

    for (int i = 0; i < movements_number; i++)
    {
        scanf("%d %d %d", &movements_type, &a, &b);

        index_a = findIndex(queue, participants_number, a);
        index_b = findIndex(queue, participants_number, b);

        if (movements_type == 1)
        {
            revertArray(queue, index_a, index_b, participants_number);
        }
        else if (movements_type == 2)
        {
            displaceElement(queue, index_a, index_b, participants_number);
        }
    }
    print(queue, participants_number);
    return 0;
}

/* Funcoes de movimentacao na fila */
void revertArray(int queue[], int index_a, int index_b, int participants_number)
{
    int i, j;
    i = index_a;
    j = index_b;

    while (i < j)
    {
        int aux = queue[i];
        queue[i] = queue[j];
        queue[j] = aux;

        i++;
        j--;
    }
}

void displaceElement(int queue[], int index_a, int index_b, int participants_number)
{
    int i, j;
    i = index_a;
    j = index_b;

    while (i < j)
    {
        int aux = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = aux;

        i++;
    }
}

/* Funcoes auxiliares */
void print(int queue[], int participants_number)
{
    for (int i = 0; i < participants_number; i++)
    {
        printf("%d ", queue[i]);
    }
}

void init(int queue[], int participants_number)
{
    for (int i = 0; i < participants_number; i++)
    {
        queue[i] = i + 1;
    }
}

int findIndex(int queue[], int participants_number, int value)
{
    for (int i = 0; i < participants_number; i++)
    {
        if (value == queue[i])
        {
            return i;
        }
    }
    return 0;
}