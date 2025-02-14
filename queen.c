#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

/* Imprime recursivamente os passos do movimento da Rainha */
void printQueenStepsRecursive(int steps, const char *verticalDir, const char *horizontalDir) {
    if (steps <= 0)
        return;
    
    if (verticalDir[0] != '\0' && horizontalDir[0] != '\0')
        printf("%s, %s\n", verticalDir, horizontalDir);
    else if (verticalDir[0] != '\0')
        printf("%s\n", verticalDir);
    else if (horizontalDir[0] != '\0')
        printf("%s\n", horizontalDir);
    
    printQueenStepsRecursive(steps - 1, verticalDir, horizontalDir);
}

/* Move a Rainha de d1 para um destino válido */
void moveQueen(void) {
    const char queenStartCol = 'd';
    const int queenStartRow = 1;
    char queenDestCol;
    int queenDestRow;
    int validMove = 0;
    char input[100];

    do {
        printf("\nMovimento da Rainha (inicia em d1)\n");
        printf("Digite a posicao de destino para a Rainha (ex: g4): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &queenDestCol, &queenDestRow) != 2) {
                queenDestCol = '\0';
                queenDestRow = -1;
            }
            queenDestCol = tolower(queenDestCol);
        }
        if (queenDestCol < 'a' || queenDestCol > 'h' ||
            queenDestRow < 1 || queenDestRow > 8) {
            printf("\nPosicao invalida. As colunas devem estar entre a-h e as linhas entre 1-8.\n");
        } else {
            int deltaRow = queenDestRow - queenStartRow;
            int deltaCol = queenDestCol - queenStartCol;
            if (!((queenDestRow == queenStartRow) || (queenDestCol == queenStartCol) ||
                  (abs(deltaRow) == abs(deltaCol))))
                printf("\nMovimento invalido. A Rainha deve mover-se horizontalmente, verticalmente ou diagonalmente.\n");
            else if (queenDestRow == queenStartRow && queenDestCol == queenStartCol)
                printf("\nMovimento invalido. A Rainha deve sair de sua posicao inicial.\n");
            else
                validMove = 1;
        }
    } while (!validMove);

    int deltaRow = queenDestRow - queenStartRow;
    int deltaCol = queenDestCol - queenStartCol;
    int steps;
    const char *verticalDir = "";
    const char *horizontalDir = "";

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

    printf("\nMovimentacao da Rainha:\n");
    printQueenStepsRecursive(steps, verticalDir, horizontalDir);
}