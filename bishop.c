#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

/* Imprime os passos do movimento do Bispo recursivamente. */
void moveBishopRecursive(int steps, const char *verticalDir, const char *horizontalDir) {
    if (steps <= 0)
        return;
    printf("%s, %s\n", verticalDir, horizontalDir);
    moveBishopRecursive(steps - 1, verticalDir, horizontalDir);
}

/* Move o Bispo a partir de c1 para um destino diagonal informado pelo usuário. */
void moveBishop(void) {
    const char bishopStartCol = 'c';
    const int bishopStartRow = 1;
    
    char bishopDestCol;
    int bishopDestRow;
    int validMove = 0;
    char input[100];

    /* Solicita e valida a posição de destino */
    do {
        printf("Movimento do Bispo (inicia em c1)\n");
        printf("Digite a posicao de destino para o Bispo (ex: a3): ");
        
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, " %c%d", &bishopDestCol, &bishopDestRow) != 2) {
                bishopDestCol = '\0';
                bishopDestRow = -1;
            }
            bishopDestCol = tolower(bishopDestCol);
        }
        
        if (bishopDestCol < 'a' || bishopDestCol > 'h' ||
            bishopDestRow < 1 || bishopDestRow > 8)
            printf("\nPosicao invalida. As colunas devem estar entre a-h e as linhas entre 1-8.\n\n");
        else if (bishopDestCol == bishopStartCol && bishopDestRow == bishopStartRow)
            printf("\nMovimento invalido. O Bispo deve sair de sua posicao inicial.\n\n");
        else if (abs(bishopDestRow - bishopStartRow) != abs(bishopDestCol - bishopStartCol))
            printf("\nMovimento invalido. O Bispo deve mover-se na diagonal.\n\n");
        else
            validMove = 1;
    } while (!validMove);

    const char *verticalDir = (bishopDestRow - bishopStartRow > 0) ? "Cima" : "Baixo";
    const char *horizontalDir = (bishopDestCol - bishopStartCol > 0) ? "Direita" : "Esquerda";
    int steps = abs(bishopDestRow - bishopStartRow);

    printf("\nMovimentacao do Bispo:\n");
    moveBishopRecursive(steps, verticalDir, horizontalDir);
}
