#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pieces.h"

// Função para movimentar o Bispo.
// O Bispo inicia na posição c1 e deve mover-se na diagonal.
void moveBishop(void) {
    const char bishopStartCol = 'c';
    const int bishopStartRow = 1;
    char bishopDestCol;
    int bishopDestRow;
    int validMove = 0;  // Flag para controlar a validade do movimento
    char input[100];

    // Solicita e valida a posição de destino do Bispo
    do {
        printf("Movimento do Bispo (inicia em c1)\n");
        printf("Digite a posição de destino para o Bispo (ex: a3): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Extrai a coluna e a linha da entrada
            if (sscanf(input, " %c%d", &bishopDestCol, &bishopDestRow) != 2) {
                bishopDestCol = '\0';
                bishopDestRow = -1;
            }
            bishopDestCol = tolower(bishopDestCol);
        }
        // Verifica se a posição está dentro dos limites do tabuleiro
        if (bishopDestCol < 'a' || bishopDestCol > 'h' ||
            bishopDestRow < 1 || bishopDestRow > 8)
            printf("\nPosição inválida. As colunas devem estar entre a-h e as linhas entre 1-8.\n\n");
        // Verifica se o Bispo não está permanecendo na posição inicial
        else if (bishopDestCol == bishopStartCol && bishopDestRow == bishopStartRow)
            printf("\nMovimento inválido. O Bispo deve sair de sua posição inicial.\n\n");
        // Verifica se o movimento é diagonal (diferença absoluta das linhas = diferença absoluta das colunas)
        else if (abs(bishopDestRow - bishopStartRow) != abs(bishopDestCol - bishopStartCol))
            printf("\nMovimento inválido. O Bispo deve mover-se na diagonal.\n\n");
        else
            validMove = 1;
    } while (!validMove);

    // Define a direção do movimento com base na diferença entre posições
    const char *verticalDir   = (bishopDestRow - bishopStartRow > 0) ? "Cima" : "Baixo";
    const char *horizontalDir = (bishopDestCol - bishopStartCol > 0) ? "Direita" : "Esquerda";
    int steps = abs(bishopDestRow - bishopStartRow);

    // Exibe os passos do movimento do Bispo
    printf("\nMovimentação do Bispo:\n");
    for (int i = 0; i < steps; i++)
        printf("%s, %s\n", verticalDir, horizontalDir);
}