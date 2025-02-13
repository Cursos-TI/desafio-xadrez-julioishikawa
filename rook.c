#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

// Função para movimentar a Torre.
// A Torre inicia na posição a1 e move-se apenas na mesma linha ou coluna.
void moveRook(void) {
    const char rookStartCol = 'a';
    const int rookStartRow = 1;
    char rookDestCol;
    int rookDestRow;
    int validMove = 0;
    char input[100];

    // Solicita e valida a posição de destino da Torre
    do {
        printf("\nMovimento da Torre (inicia em a1)\n");
        printf("Digite a posição de destino para a Torre (ex: h1): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &rookDestCol, &rookDestRow) != 2) {
                rookDestCol = '\0';
                rookDestRow = -1;
            }
            rookDestCol = tolower(rookDestCol);
        }
        // Verifica se a posição está dentro dos limites do tabuleiro
        if (rookDestCol < 'a' || rookDestCol > 'h' ||
            rookDestRow < 1 || rookDestRow > 8)
            printf("\nPosição inválida. As colunas devem estar entre a-h e as linhas entre 1-8.\n\n");
        // A Torre deve mover-se apenas se a coluna for igual à inicial ou a linha for igual à inicial
        else if (rookDestCol != rookStartCol && rookDestRow != rookStartRow)
            printf("\nMovimento inválido. A Torre deve mover-se apenas na mesma coluna ou na mesma linha.\n\n");
        // Verifica se o movimento não é nulo (mantendo a mesma posição)
        else if (rookDestCol == rookStartCol && rookDestRow == rookStartRow)
            printf("\nMovimento inválido. A Torre deve sair de sua posição inicial.\n\n");
        else
            validMove = 1;
    } while (!validMove);

    // Define a direção do movimento
    const char *verticalDir   = (rookDestRow - rookStartRow > 0) ? "Cima" : "Baixo";
    const char *horizontalDir = (rookDestCol - rookStartCol > 0) ? "Direita" : "Esquerda";
    int steps = (rookDestCol == rookStartCol)
                    ? abs(rookDestRow - rookStartRow)
                    : abs(rookDestCol - rookStartCol);

    // Exibe os passos do movimento da Torre
    printf("\nMovimentação da Torre:\n");
    for (int i = 0; i < steps; i++) {
        if (rookDestCol == rookStartCol)
            printf("%s\n", verticalDir);
        else
            printf("%s\n", horizontalDir);
    }
}