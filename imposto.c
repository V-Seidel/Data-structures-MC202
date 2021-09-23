#include <stdio.h>

/* Constantes dos tamanhos máximos para a tabela */
#define MAX 1000
#define COLUMNS 15

/* Constantes dos valores das alíquotas */
#define ALIQUOTAMENSAL01 1499.15
#define ALIQUOTAMENSAL02 2246.75
#define ALIQUOTAMENSAL03 2995.70
#define ALIQUOTAMENSAL04 3743.19

#define ALIQUOTAANUAL01 18000.00
#define ALIQUOTAANUAL02 26400.00
#define ALIQUOTAANUAL03 36000.00
#define ALIQUOTAANUAL04 44400.00

/* Função que printa a tabela final na tela */
void print(float output_table[][COLUMNS], int numero_funcionarios);
/* Função que executa o calculo do imposto mensal */
void calcularImpostoMensal(float output_table[][COLUMNS], float rendimento_mensal, int row, int column);
/* Função que executa o calculo do imposto anual */
void calcularImpostoAnual(float output_table[][COLUMNS], float valor_anual[COLUMNS], int row, float abatimento);
/* Função que soma o valor do salário de cada mês */
float somarSalario(float input_table[]);
/* Função que soma o valor dos impostos de cada mês */
float somarImpostos(float output_table[][COLUMNS], int row);

int main()
{
    /* Variaveis dos valores iniciais */
    int numero_funcionarios;
    float rendimento_mensal;
    float abatimento;

    /* Obtencao dos valores iniciais */
    scanf("%d\n", &numero_funcionarios);

    /* Declaracaoo da matriz*/
    float output_table[MAX][COLUMNS];
    float input_table[COLUMNS];
    float valor_anual[MAX];

    for (int row = 0; row < numero_funcionarios; row++)
    {

        for (int column = 0; column < 12; column++)
        {
            scanf("%f", &rendimento_mensal);
            input_table[column] = rendimento_mensal;
            calcularImpostoMensal(output_table, rendimento_mensal, row, column);
        }
        valor_anual[row] = somarSalario(input_table);
    }

    for (int row = 0; row < numero_funcionarios; row++)
    {
        scanf("%f", &abatimento);
        calcularImpostoAnual(output_table, valor_anual, row, abatimento);
    }
    print(output_table, numero_funcionarios);
    return 0;
}

/* Funcoes auxiliares */
float somarSalario(float input_table[])
{
    float soma_anual = 0;
    for (int column = 0; column < COLUMNS; column++)
    {
        soma_anual = soma_anual + input_table[column];
    }
    return soma_anual;
}

float somarImpostos(float output_table[][COLUMNS], int row)
{
    float soma_anual = 0;
    for (int column = 0; column < (COLUMNS - 2); column++)
    {
        soma_anual = soma_anual + output_table[row][column];
    }
    return soma_anual;
}

void print(float output_table[][COLUMNS], int numero_funcionarios)
{
    printf("Jan Fev Mar Abr Mai Jun Jul Ago Set Out Nov Dez Retido Devido Ajuste\n");
    for (int row = 0; row < numero_funcionarios; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            printf("%.2f\t", output_table[row][column]);
        }
        printf("\n");
    }
}

/* Funcoes de cálculo do imposto */
void calcularImpostoMensal(float output_table[][COLUMNS], float rendimento_mensal, int row, int column)
{
    float taxa_mensal_1 = (ALIQUOTAMENSAL02 - ALIQUOTAMENSAL01) * 0.075;
    float taxa_mensal_2 = (ALIQUOTAMENSAL03 - ALIQUOTAMENSAL02) * 0.15;
    float taxa_mensal_3 = (ALIQUOTAMENSAL04 - ALIQUOTAMENSAL03) * 0.225;

    if (rendimento_mensal <= ALIQUOTAMENSAL01)
    {
        output_table[row][column] = 0;
    }

    else if ((rendimento_mensal > ALIQUOTAMENSAL01) && (rendimento_mensal <= ALIQUOTAMENSAL02))
    {
        output_table[row][column] = (rendimento_mensal - ALIQUOTAMENSAL01) * 0.075;
    }

    else if ((rendimento_mensal > ALIQUOTAMENSAL02) && (rendimento_mensal <= ALIQUOTAMENSAL03))
    {
        output_table[row][column] = taxa_mensal_1 + (rendimento_mensal - ALIQUOTAMENSAL02) * 0.15;
    }

    else if ((rendimento_mensal > ALIQUOTAMENSAL03) && (rendimento_mensal <= ALIQUOTAMENSAL04))
    {
        output_table[row][column] = taxa_mensal_1 + taxa_mensal_2 + (rendimento_mensal - ALIQUOTAMENSAL03) * 0.225;
    }

    else if (rendimento_mensal > ALIQUOTAMENSAL04)
    {
        output_table[row][column] = taxa_mensal_1 + taxa_mensal_2 + taxa_mensal_3 + (rendimento_mensal - ALIQUOTAMENSAL04) * 0.275;
    }
}

void calcularImpostoAnual(float output_table[][COLUMNS], float valor_anual[MAX], int row, float abatimento)
{
    float taxa_anual_1 = (ALIQUOTAANUAL02 - ALIQUOTAANUAL01) * 0.075;
    float taxa_anual_2 = (ALIQUOTAANUAL03 - ALIQUOTAANUAL02) * 0.15;
    float taxa_anual_3 = (ALIQUOTAANUAL04 - ALIQUOTAANUAL03) * 0.225;
    float rendimento_anual = valor_anual[row] - abatimento;

    if (rendimento_anual <= ALIQUOTAANUAL01)
    {
        output_table[row][13] = 0;
    }

    else if ((rendimento_anual > ALIQUOTAANUAL01) && (rendimento_anual <= ALIQUOTAANUAL02))
    {
        output_table[row][13] = (rendimento_anual - ALIQUOTAANUAL01) * 0.075;
    }

    else if ((rendimento_anual > ALIQUOTAANUAL02) && (rendimento_anual <= ALIQUOTAANUAL03))
    {
        output_table[row][13] = taxa_anual_1 + (rendimento_anual - ALIQUOTAANUAL02) * 0.15;
    }

    else if ((rendimento_anual > ALIQUOTAANUAL03) && (rendimento_anual <= ALIQUOTAANUAL04))
    {
        output_table[row][13] = taxa_anual_1 + taxa_anual_2 + (rendimento_anual - ALIQUOTAANUAL03) * 0.225;
    }

    else if (rendimento_anual > ALIQUOTAANUAL04)
    {
        output_table[row][13] = taxa_anual_1 + taxa_anual_2 + taxa_anual_3 + (rendimento_anual - ALIQUOTAANUAL04) * 0.275;
    }

    output_table[row][12] = somarImpostos(output_table, row);
    output_table[row][14] = output_table[row][13] - output_table[row][12];
}
