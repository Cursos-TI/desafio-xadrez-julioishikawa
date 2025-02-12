#include <stdio.h>
#include <stdlib.h>   // Para a função abs()
#include <ctype.h>    // Para a função tolower()

int main() {
    /* ========================= BISPO ========================= */
    // Posição inicial fixa do Bispo: c1
    char bishopStartCol = 'c';
    int bishopStartRow = 1;

    // Variáveis para armazenar a posição de destino
    char bishopDestCol;
    int bishopDestRow;
    int bishopValid = 0;  // Flag para controlar a validade do movimento

    // Loop para solicitar os dados até que o movimento seja válido
    do {
        printf("Movimento do Bispo (inicia em c1)\n");
        printf("Digite a coluna de destino para o Bispo (a-h): ");
        scanf(" %c", &bishopDestCol);
        bishopDestCol = tolower(bishopDestCol);  // Padroniza para minúsculo

        printf("Digite a linha de destino para o Bispo (1-8): ");
        scanf("%d", &bishopDestRow);

        // Verifica se a posição informada está dentro dos limites do tabuleiro
        if (bishopDestCol < 'a' || bishopDestCol > 'h' ||
            bishopDestRow < 1   || bishopDestRow > 8) {
            printf("\nPosicao invalida. As colunas devem estar entre A-H e as linhas entre 1-8.\n\n");
        }
        // O Bispo deve se mover de sua posição inicial
        else if (bishopDestCol == bishopStartCol && bishopDestRow == bishopStartRow) {
            printf("\nMovimento invalido para o Bispo. O Bispo deve se mover de sua posicao inicial.\n\n");
        }
        // O movimento do Bispo deve ser diagonal: a diferença absoluta entre linhas e colunas deve ser igual
        else if (abs(bishopDestRow - bishopStartRow) != abs(bishopDestCol - bishopStartCol)) {
            printf("\nMovimento invalido para o Bispo. O movimento deve ser diagonal.\n\n");
        }
        else {
            bishopValid = 1;
        }
    } while (!bishopValid);

    // Determina as direções (vertical e horizontal) para o movimento do Bispo
    char *bishopVertical   = (bishopDestRow - bishopStartRow > 0) ? "Cima"   : "Baixo";
    char *bishopHorizontal = (bishopDestCol - bishopStartCol > 0) ? "Direita": "Esquerda";
    int bishopSteps = abs(bishopDestRow - bishopStartRow);  // Em movimento diagonal, ambas as diferenças são iguais

    // Impressão dos passos utilizando um loop "for"
    printf("\nMovimentacao do Bispo:\n");
    for (int i = 0; i < bishopSteps; i++) {
        printf("%s, %s\n", bishopVertical, bishopHorizontal);
    }
    
    /* ========================= TORRE ========================= */
    // Posição inicial fixa da Torre: a1
    char towerStartCol = 'a';
    int towerStartRow = 1;

    // Variáveis para armazenar a posição de destino
    char towerDestCol;
    int towerDestRow;
    int towerValid = 0;  // Flag para controlar a validade do movimento

    // Loop para solicitar os dados até que o movimento seja válido
    do {
        printf("\nMovimento da Torre (inicia em a1)\n");
        printf("Digite a coluna de destino para a Torre (a-h): ");
        scanf(" %c", &towerDestCol);
        towerDestCol = tolower(towerDestCol);  // Padroniza para minúsculo

        printf("Digite a linha de destino para a Torre (1-8): ");
        scanf("%d", &towerDestRow);

        // Verifica se a posição informada está dentro dos limites do tabuleiro
        if (towerDestCol < 'a' || towerDestCol > 'h' ||
            towerDestRow < 1   || towerDestRow > 8) {
            printf("\nPosicao invalida. As colunas devem estar entre A-H e as linhas entre 1-8.\n\n");
        }
        // A Torre deve mover-se apenas na mesma linha OU na mesma coluna
        else if (towerDestCol != towerStartCol && towerDestRow != towerStartRow) {
            printf("\nMovimento invalido para a Torre. Ela deve mover-se apenas na mesma linha ou coluna.\n\n");
        }
        // A Torre deve se mover de sua posição inicial
        else if (towerDestCol == towerStartCol && towerDestRow == towerStartRow) {
            printf("\nMovimento invalido para a Torre. A torre deve se mover de sua posicao inicial.\n\n");
        }
        else {
            towerValid = 1;
        }
    } while (!towerValid);

    // Determina as direções (vertical e horizontal) para o movimento da Torre
    char *towerVertical   = (towerDestRow - towerStartRow > 0) ? "Cima"   : "Baixo";
    char *towerHorizontal = (towerDestCol - towerStartCol > 0) ? "Direita": "Esquerda";
    int towerSteps = (towerDestCol == towerStartCol) 
                        ? abs(towerDestRow - towerStartRow) 
                        : abs(towerDestCol - towerStartCol);

    // Impressão dos passos utilizando um loop "for"
    printf("\nMovimentacao da Torre:\n");
    for (int i = 0; i < towerSteps; i++) {
        // Se o movimento for vertical (mesma coluna), exibe apenas a direção vertical;
        // caso contrário, exibe a direção horizontal.
        if (towerDestCol == towerStartCol)
            printf("%s\n", towerVertical);
        else
            printf("%s\n", towerHorizontal);
    }

    /* ========================= RAINHA ========================= */
    // Posição inicial fixa da Rainha: d1
    char queenStartCol = 'd';
    int queenStartRow = 1;
    
    // Variáveis para armazenar a posição de destino
    char queenDestCol;
    int queenDestRow;
    int queenValid = 0;  // Flag para o movimento válido

    // Loop para solicitar os dados até que o movimento seja válido para a Rainha
    // A Rainha pode mover-se horizontalmente, verticalmente ou diagonalmente.
    do {
        printf("\nMovimento da Rainha (inicia em d1)\n");
        printf("Digite a coluna de destino para a Rainha (a-h): ");
        scanf(" %c", &queenDestCol);
        queenDestCol = tolower(queenDestCol);
        
        printf("Digite a linha de destino para a Rainha (1-8): ");
        scanf("%d", &queenDestRow);
        
        // Verifica se a posição informada está dentro dos limites do tabuleiro
        if (queenDestCol < 'a' || queenDestCol > 'h' ||
            queenDestRow < 1   || queenDestRow > 8) {
            printf("\nPosicao invalida. As colunas devem estar entre A-H e as linhas entre 1-8.\n\n");
        }
        else {
            int deltaRowQueen = queenDestRow - queenStartRow;
            int deltaColQueen = queenDestCol - queenStartCol;
            
            // Verifica se é um movimento horizontal, vertical ou diagonal
            if (!((queenDestRow == queenStartRow) || (queenDestCol == queenStartCol) ||
                  (abs(deltaRowQueen) == abs(deltaColQueen)))) {
                printf("\nMovimento invalido para a Rainha. Ela deve mover-se horizontalmente, verticalmente ou diagonalmente.\n\n");
            } 
            else if (queenDestRow == queenStartRow && queenDestCol == queenStartCol) {
                printf("\nMovimento invalido para a Rainha. A rainha deve se mover de sua posicao inicial.\n\n");
            } else {
                queenValid = 1;
            }
        }
    } while (!queenValid);
    
    // Determina o número de passos e as direções do movimento da Rainha
    int queenSteps;
    char *queenVertical = "";
    char *queenHorizontal = "";
    int deltaRowQueen = queenDestRow - queenStartRow;
    int deltaColQueen = queenDestCol - queenStartCol;
    
    // Se o movimento for horizontal
    if (queenDestRow == queenStartRow) {
        queenSteps = abs(deltaColQueen);
        queenHorizontal = (deltaColQueen > 0) ? "Direita" : "Esquerda";
    } 
    // Se o movimento for vertical
    else if (queenDestCol == queenStartCol) {
        queenSteps = abs(deltaRowQueen);
        queenVertical = (deltaRowQueen > 0) ? "Cima" : "Baixo";
    } 
    // Movimento diagonal
    else {
        queenSteps = abs(deltaRowQueen);  // (abs(deltaRowQueen) == abs(deltaColQueen))
        queenVertical = (deltaRowQueen > 0) ? "Cima" : "Baixo";
        queenHorizontal = (deltaColQueen > 0) ? "Direita" : "Esquerda";
    }
    
    // Impressão dos passos utilizando um loop "for"
    printf("\nMovimentacao da Rainha:\n");
    for (int queenCount = 0; queenCount < queenSteps; queenCount++) {
        if (queenVertical[0] != '\0' && queenHorizontal[0] != '\0')
            printf("%s, %s\n", queenVertical, queenHorizontal);
        else if (queenVertical[0] != '\0')
            printf("%s\n", queenVertical);
        else if (queenHorizontal[0] != '\0')
            printf("%s\n", queenHorizontal);
    }

    
    return 0;
}