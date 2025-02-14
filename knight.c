#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

/* Imprime recursivamente os passos de um segmento do movimento do Cavalo */
void printKnightSegmentRecursive(int steps, const char *direction) {
    if (steps <= 0)
        return;
    printf("%s\n", direction);
    printKnightSegmentRecursive(steps - 1, direction);
}

/* Imprime recursivamente os dois segmentos do movimento do Cavalo */
void printKnightMovementRecursive(int seg, int segment1Steps, int segment2Steps,
                                  const char *primaryDir, const char *secondaryDir) {
    if (seg >= 2)
        return;
    int steps = (seg == 0) ? segment1Steps : segment2Steps;
    const char *direction = (seg == 0) ? primaryDir : secondaryDir;
    printKnightSegmentRecursive(steps, direction);
    printKnightMovementRecursive(seg + 1, segment1Steps, segment2Steps, primaryDir, secondaryDir);
}

/* Move o Cavalo de b1 para uma posicao válida em 'L' */
void moveKnight(void) {
    const char knightStartCol = 'b';
    const int knightStartRow = 1;
    char input[100];
    char knightDestCol;
    int knightDestRow;
    int validMove = 0;

    /* Loop de validacao da entrada */
    do {
        printf("\nMovimento do Cavalo (inicia em b1)\n");
        printf("Digite a posicao de destino para o Cavalo (ex: c3): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &knightDestCol, &knightDestRow) != 2) {
                knightDestCol = '\0';
                knightDestRow = -1;
            }
            knightDestCol = tolower(knightDestCol);
        }
        if (knightDestCol < 'a' || knightDestCol > 'h' ||
            knightDestRow < 1 || knightDestRow > 8) {
            printf("\nPosicao invalida. As colunas devem estar entre a-h e as linhas entre 1-8.\n");
            continue;
        }
        if (knightDestCol == knightStartCol && knightDestRow == knightStartRow) {
            printf("\nMovimento invalido. O Cavalo deve sair de sua posicao inicial.\n");
            continue;
        }
        int deltaRow = knightDestRow - knightStartRow;
        int deltaCol = knightDestCol - knightStartCol;
        if ((abs(deltaRow) == 2 && abs(deltaCol) == 1) ||
            (abs(deltaRow) == 1 && abs(deltaCol) == 2))
            validMove = 1;
        else
            printf("\nMovimento invalido para o Cavalo. Ele deve mover-se em 'L' (2 em uma direcao e 1 na outra).\n");
    } while (!validMove);

    int deltaRow = knightDestRow - knightStartRow;
    int deltaCol = knightDestCol - knightStartCol;
    int segment1Steps, segment2Steps;
    const char *primaryDir;
    const char *secondaryDir;

    /* Define os segmentos do movimento em 'L' */
    if (abs(deltaRow) == 2) {
        segment1Steps = 2;
        segment2Steps = 1;
        primaryDir = (deltaRow > 0) ? "Cima" : "Baixo";
        secondaryDir = (deltaCol > 0) ? "Direita" : "Esquerda";
    } else {
        segment1Steps = 2;
        segment2Steps = 1;
        primaryDir = (deltaCol > 0) ? "Direita" : "Esquerda";
        secondaryDir = (deltaRow > 0) ? "Cima" : "Baixo";
    }

    printf("\nMovimentacao do Cavalo:\n");
    printKnightMovementRecursive(0, segment1Steps, segment2Steps, primaryDir, secondaryDir);
}