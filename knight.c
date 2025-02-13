#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

// Função para movimentar o Cavalo.
// O Cavalo inicia na posição b1 e move-se em "L" (2 em uma direção e 1 na outra).
void moveKnight(void) {
    const char knightStartCol = 'b';
    const int knightStartRow = 1;
    char input[100];
    char knightDestCol;
    int knightDestRow;
    int validMove = 0;

    // Solicita e valida a posição de destino do Cavalo
    do {
        printf("\nMovimento do Cavalo (inicia em b1)\n");
        printf("Digite a posição de destino para o Cavalo (ex: c3): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &knightDestCol, &knightDestRow) != 2) {
                knightDestCol = '\0';
                knightDestRow = -1;
            }
            knightDestCol = tolower(knightDestCol);
        }
        // Verifica os limites do tabuleiro
        if (knightDestCol < 'a' || knightDestCol > 'h' ||
            knightDestRow < 1 || knightDestRow > 8) {
            printf("\nPosição inválida. As colunas devem estar entre a-h e as linhas entre 1-8.\n");
            continue;
        }
        int deltaRow = knightDestRow - knightStartRow;
        int deltaCol = knightDestCol - knightStartCol;
        // Verifica se o movimento do Cavalo é em "L"
        if ((abs(deltaRow) == 2 && abs(deltaCol) == 1) ||
            (abs(deltaRow) == 1 && abs(deltaCol) == 2))
            validMove = 1;
        else
            printf("\nMovimento inválido para o Cavalo. Ele deve mover-se em 'L' (2 em uma direção e 1 na outra).\n");
    } while (!validMove);

    int deltaRow = knightDestRow - knightStartRow;
    int deltaCol = knightDestCol - knightStartCol;
    int segment1Steps, segment2Steps;
    const char *primaryDir = "";
    const char *secondaryDir = "";

    // Determina os segmentos do movimento do Cavalo com base na direção do movimento
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

    // Exibe os passos do movimento do Cavalo
    printf("\nMovimentação do Cavalo:\n");
    for (int segment = 0; segment < 2; segment++) {
        int steps = (segment == 0) ? segment1Steps : segment2Steps;
        for (int i = 0; i < steps; i++) {
            if (segment == 0)
                printf("%s\n", primaryDir);
            else
                printf("%s\n", secondaryDir);
        }
    }
}