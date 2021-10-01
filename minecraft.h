/* Tarefa 06 */
/* Autor: Vinícius Seidel */
/* RA: 245233 */

/* ---------------------------Estruturas------------------------------------- */
typedef struct
{
    int tipo_de_bloco;
} Bloco;

/* ---------------------------Funções Essenciais------------------------------------- */

/** Cria uma matriz de altitudes representando o relevo de um mundo.**/
int **calcularAltitudes(int m, int n, int seed);

/** Cria um novo mundo representado por uma matriz de blocos alocada dinamicamente.**/
Bloco ***criarMundo(int m, int n, int **altitudes, int seed);

/** Explora o mapa de um mundo e devolve o tempo necessário para minerar todo ele. 
 * Além disso, devolve a quantidade de alguns minérios de interesse.**/
double explorarMundo(
    Bloco ***mundo, int m, int n, int **altitudes, double tempoPorBloco,
    int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos);

/* ---------------------------Funções Auxiliares------------------------------------- */

/** Aloca dinamicamente uma matriz mxn.**/
int **alocaMatriz(int m, int n);

/** Aloca dinamicamente uma matriz mxnx256.**/
Bloco ***alocaMatrizEspaco(int m, int n);

/** Calcula o tipo de bloco baseado nas coordenadas e na seed do mundo.**/
int calcularTipoBloco(int x, int y, int z, int seed);

/** Libera a memória da matriz mxn alocada.**/
void liberaMatriz(int **matriz_altitude, int m, int n);

/** Libera a memória da matriz mxnx256 alocada.**/
void liberaMatrizEspaco(Bloco ***mundo, int m, int n);
