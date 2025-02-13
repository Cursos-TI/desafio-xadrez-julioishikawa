#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

// Função para movimentar a Rainha.
// A Rainha inicia na posição d1 e pode mover-se horizontalmente, verticalmente ou diagonalmente.
void moveQueen(void) {
    const char queenStartCol = 'd';
    const int queenStartRow = 1;
    char queenDestCol;
    int queenDestRow;
    int validMove = 0;
    char input[100];

    // Solicita e valida a posição de destino da Rainha
    do {
        printf("\nMovimento da Rainha (inicia em d1)\n");
        printf("Digite a posição de destino para a Rainha (ex: g4): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &queenDestCol, &queenDestRow) != 2) {
                queenDestCol = '\0';
                queenDestRow = -1;
            }
            queenDestCol = tolower(queenDestCol);
        }
        // Verifica os limites do tabuleiro
        if (queenDestCol < 'a' || queenDestCol > 'h' ||
            queenDestRow < 1 || queenDestRow > 8)
            printf("\nPosição inválida. As colunas devem estar entre a-h e as linhas entre 1-8.\n\n");
        else {
            int deltaRow = queenDestRow - queenStartRow;
            int deltaCol = queenDestCol - queenStartCol;
            // Verifica se o movimento é horizontal, vertical ou diagonal
            if (!((queenDestRow == queenStartRow) || (queenDestCol == queenStartCol) ||
                  (abs(deltaRow) == abs(deltaCol))))
                printf("\nMovimento inválido. A Rainha deve mover-se horizontalmente, verticalmente ou diagonalmente.\n\n");
            else if (queenDestRow == queenStartRow && queenDestCol == queenStartCol)
                printf("\nMovimento inválido. A Rainha deve sair de sua posição inicial.\n\n");
            else
                validMove = 1;
        }
    } while (!validMove);

    int deltaRow = queenDestRow - queenStartRow;
    int deltaCol = queenDestCol - queenStartCol;
    int steps;
    const char *verticalDir = "";
    const char *horizontalDir = "";

    // Define a direção do movimento da Rainha
    if (queenDestRow == queenStartRow) {
        steps = abs(deltaCol);
        horizontalDir = (deltaCol > 0) ? "Direita" : "Esquerda";
    } else if (queenDestCol == queenStartCol) {
        steps = abs(deltaRow);
        verticalDir = (deltaRow > 0) ? "Cima" : "Baixo";
    } else {
        steps = abs(deltaRow);
        verticalDir = (deltaRow > 0) ? "Cima" : "Baixo";
        horizontalDir = (deltaCol > 0) ? "Direita" : "Esquerda";
    }

    // Exibe os passos do movimento da Rainha
    printf("\nMovimentação da Rainha:\n");
    for (int i = 0; i < steps; i++) {
        if (verticalDir[0] != '\0' && horizontalDir[0] != '\0')
            printf("%s, %s\n", verticalDir, horizontalDir);
        else if (verticalDir[0] != '\0')
            printf("%s\n", verticalDir);
        else if (horizontalDir[0] != '\0')
            printf("%s\n", horizontalDir);
    }
}