#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

/* Imprime recursivamente os passos do movimento da Torre */
void printRookStepsRecursive(int steps, const char *direction) {
    if (steps <= 0)
        return;
    printf("%s\n", direction);
    printRookStepsRecursive(steps - 1, direction);
}

/* Move a Torre de a1 para uma posição válida na mesma linha ou coluna */
void moveRook(void) {
    const char rookStartCol = 'a';
    const int rookStartRow = 1;
    char rookDestCol;
    int rookDestRow;
    int validMove = 0;
    char input[100];

    do {
        printf("\nMovimento da Torre (inicia em a1)\n");
        printf("Digite a posicao de destino para a Torre (ex: h1): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &rookDestCol, &rookDestRow) != 2) {
                rookDestCol = '\0';
                rookDestRow = -1;
            }
            rookDestCol = tolower(rookDestCol);
        }
        if (rookDestCol < 'a' || rookDestCol > 'h' ||
            rookDestRow < 1 || rookDestRow > 8)
            printf("\nPosicao invalida. As colunas devem estar entre a-h e as linhas entre 1-8.\n");
        else if (rookDestCol != rookStartCol && rookDestRow != rookStartRow)
            printf("\nMovimento invalido. A Torre deve mover-se apenas na mesma coluna ou na mesma linha.\n");
        else if (rookDestCol == rookStartCol && rookDestRow == rookStartRow)
            printf("\nMovimento invalido. A Torre deve sair de sua posicao inicial.\n");
        else
            validMove = 1;
    } while (!validMove);

    const char *direction;
    int steps;
    if (rookDestCol == rookStartCol) {
        direction = (rookDestRow - rookStartRow > 0) ? "Cima" : "Baixo";
        steps = abs(rookDestRow - rookStartRow);
    } else {
        direction = (rookDestCol - rookStartCol > 0) ? "Direita" : "Esquerda";
        steps = abs(rookDestCol - rookStartCol);
    }

    printf("\nMovimentacao da Torre:\n");
    printRookStepsRecursive(steps, direction);
}