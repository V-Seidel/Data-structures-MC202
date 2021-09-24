typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct voo
{
    int numero_voo;
    char codigo_origem[4];
    char codigo_destino[4];
    Data data;
    float valor;
} Voo;

Data ler_data();

Voo registrar();

int compara_data(Data data1, Data data2);

int diferenca_data(Data data1, Data data2);

void alterar(Voo voos[], int qtd_voos, int numero_voo, float novo_valor);

void planejar(Voo voos[], char vetor_resultado[], int qtd_voos, Data data_inicio, Data data_fim, char codigo_origem[]);

void verificar_voo(Voo voos[], int qtd_voos, Data data_inicio, Data data_fim, char codigo_origem[]);

int achar_indice(Voo voos[], int qtd_voos, int numero_voo);

int data_para_dias(Data data);
