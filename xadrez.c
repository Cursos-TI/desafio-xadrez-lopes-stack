#include <stdio.h>

// ----------------------------------------------
// Funções recursivas e loops complexos do desafio
// ----------------------------------------------

// -------------------- TORRE --------------------
// Move recursivamente para a direita
void moverTorre(int casas) {
    if (casas == 0) return; // Caso base da recursão

    printf("Direita\n");
    moverTorre(casas - 1); // Chamada recursiva reduzindo uma casa
}

// -------------------- BISPO --------------------
// Função recursiva para o movimento diagonal superior direita
void moverBispoRecursivo(int passo, int limite) {
    if (passo == limite) return; // Caso base

    printf("Diagonal Superior Direita (recursivo) - casa %d\n", passo + 1);
    moverBispoRecursivo(passo + 1, limite); // Chamada recursiva para próxima casa
}

// Função com loops aninhados (vertical + horizontal)
void moverBispo(int limite) {
    printf("--- Movimento com loops aninhados ---\n");
    for (int i = 0; i < limite; i++) {           // Movimento vertical
        for (int j = 0; j < limite; j++) {       // Movimento horizontal
            if (i == j) {
                printf("Diagonal Superior Direita (loop) - passo [%d,%d]\n", i + 1, j + 1);
            }
        }
    }
    printf("\n--- Movimento recursivo ---\n");
    moverBispoRecursivo(0, limite);
}

// -------------------- RAINHA --------------------
// Movimento recursivo para a esquerda
void moverRainhaEsquerda(int casas) {
    if (casas == 0) return; // Caso base
    printf("Esquerda\n");
    moverRainhaEsquerda(casas - 1);
}

void moverRainha(int casas) {
    printf("--- Movimento da Rainha (para a esquerda) ---\n");
    moverRainhaEsquerda(casas);
}

// -------------------- CAVALO --------------------
// Movimento em "L" (duas casas para cima e uma para direita)
void moverCavalo() {
    printf("--- Movimento do Cavalo ---\n");
    for (int i = 0; i < 3; i++) {          // Movimento vertical (para cima)
        for (int j = 0; j < 3; j++) {      // Movimento horizontal (para direita)
            if (i == 2 && j == 1) {        // Movimento típico do Cavalo
                printf("Cavalo: Duas casas para cima e uma para direita\n");
                break;                     // Sai do loop interno ao concluir o movimento
            }
            if (i > j) continue;           // Controla o fluxo para simular o "L"
        }
    }
}

// -------------------- MAIN --------------------
int main() {
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    printf("=== Movimento da TORRE ===\n");
    moverTorre(casasTorre);

    printf("\n=== Movimento do BISPO ===\n");
    moverBispo(casasBispo);

    printf("\n=== Movimento da RAINHA ===\n");
    moverRainha(casasRainha);

    printf("\n=== Movimento do CAVALO ===\n");
    moverCavalo();

    printf("\n--- Fim dos Movimentos ---\n");
    return 0;
}