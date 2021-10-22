/* Tarefa 07 */
/* Autor: Vinícius Seidel */
/* RA: 245233 */

/* ---------------------------Funções Essenciais------------------------------------- */

/** Função que é chamada recursivamente que resolve o quebra cabeça utilizando backtracking.**/
int resolverQuebraCabeca(int **quebra_cabeca, int tamanho_grade_total, int linha, int coluna);

/** Mostra qual a posição do próximo elemento (linha e coluna) dada a geometria do problema.**/
void proximaPosicao(int linha, int coluna, int *prox_linha, int *prox_coluna, int tamanho_grade_total);

/** Verifica se pode inserir um valor no quebra cabeça dada as seguintes condições:
 * Não possuir valor igual na linha;
 * Não possuir valor igual na coluna;
 * Ao fim de cada linha ou coluna verifica a lógica dos andares dos prédios.**/
int podeInserir(int valor, int **quebra_cabeca, int tamanho_grade, int linha, int coluna);

/* --------------------------------Funções Auxiliares--------------------------------------- */

/** Aloca dinamicamente uma matriz quadrada de tamanho tamanho_gradextamanho_grade.**/
int **alocaMatriz(int tamanho_grade);

/** Libera a memória alocada de uma matriz quadrada de tamanho tamanho_gradextamanho_grade **/
void liberaMatriz(int **quebra_cabeca, int tamanho_grade);

/** Mostra o quebra cabeça, exceto as bordas **/
void mostraMatriz(int **quebra_cabeca, int tamanho_grade);

/** Dado a completude de uma linha, verifica se os mesmos atendem às condições de terem a visão
 * do número correto de prédios**/
int testarPrediosLinha(int valor, int **quebra_cabeca, int tamanho_grade, int linha);

/** Dado a completude de uma coluna, verifica se os mesmos atendem às condições de terem a visão
 * do número correto de prédios**/
int testarPrediosColuna(int valor, int **quebra_cabeca, int tamanho_grade, int coluna);

/** Dado qualquer elemento, testa se o mesmo atende às condições do número correto de prédios **/
int testarPredios(int valor, int **quebra_cabeca, int tamanho_grade, int linha, int coluna);
