#include "planejar.h"
#include <stdio.h>
#include <string.h>

Data ler_data()
{
    Data data_final;
    scanf("%d/%d/%d ", &data_final.dia, &data_final.mes, &data_final.ano);
    return data_final;
}

int compara_data(Data data1, Data data2)
{
    if (data1.ano < data2.ano)
        return 1;

    else if (data1.ano > data2.ano)
        return -1;

    if (data1.ano == data2.ano)
    {
        if (data1.mes < data2.mes)
            return 1;
        else if (data1.mes > data2.mes)
            return -1;
        else if (data1.dia < data2.dia)
            return 1;
        else if (data1.dia > data2.dia)
            return -1;
        else
            return 1;
    }
    return 0;
}

int diferenca_data(Data data_fim, Data data_inicio)
{
    int data_em_dias1 = data_para_dias(data_fim);
    int data_em_dias2 = data_para_dias(data_inicio);
    return (data_em_dias1 - data_em_dias2);
}

int data_para_dias(Data data)
{
    int dias = data.dia;
    if (data.ano == 2022)
    {
        dias += 365;
    }
    for (int i = 1; i < data.mes; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            dias += 31;
        if (i == 4 || i == 6 || i == 9 || i == 11)
            dias += 30;
        if (i == 2)
            dias += 28;
    }
    return dias;
}

Voo registrar()
{
    Voo voo;
    scanf("%d ", &voo.numero_voo);
    scanf("%s ", voo.codigo_origem);
    scanf("%s ", voo.codigo_destino);
    voo.data = ler_data();
    scanf("%f ", &voo.valor);
    return voo;
}

void alterar(Voo voos[], int qtd_voos, int numero_voo, float novo_valor)
{
    int indice_voo;
    indice_voo = achar_indice(voos, qtd_voos, numero_voo);
    voos[indice_voo].valor = novo_valor;
}

int achar_indice(Voo voos[], int qtd_voos, int numero_voo)
{
    for (int i = 0; i <= qtd_voos; i++)
    {
        if (voos[i].numero_voo == numero_voo)
            return i;
    }
    return -1;
}

void planejar(Voo voos[], char vetor_resultado[], int qtd_voos, Data data_inicio, Data data_fim, char codigo_origem[])
{
    float preco = 10000;
    int codigo_ida, codigo_volta;
    for (int i = 0; i < qtd_voos; i++)
    {
        if (vetor_resultado[i] == 1 && strcmp(codigo_origem, voos[i].codigo_origem) == 0)
        {
            for (int j = 0; j < qtd_voos; j++)
            {
                if (vetor_resultado[j])
                {
                    if (compara_data(data_inicio, voos[i].data) >= 0 && compara_data(voos[j].data, data_fim) >= 0 && diferenca_data(voos[j].data, voos[i].data) >= 3 && strcmp(voos[i].codigo_origem, voos[j].codigo_destino) == 0 && strcmp(voos[j].codigo_origem, voos[i].codigo_destino) == 0 &&
                        (voos[i].valor + voos[j].valor) < preco)
                    {
                        preco = voos[i].valor + voos[j].valor;
                        codigo_ida = voos[i].numero_voo;
                        codigo_volta = voos[j].numero_voo;
                    }
                }
            }
        }
    }
    printf("%d\n", codigo_ida);
    printf("%d\n", codigo_volta);
}