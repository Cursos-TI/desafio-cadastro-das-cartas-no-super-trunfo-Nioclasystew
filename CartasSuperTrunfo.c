#include <stdio.h>

#define MAX_CARTAS 32  // 8 estados * 4 cidades cada

typedef struct {
    char codigo[4];  
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

void cadastrarCartas(Carta cartas[], int *quantidade) {
    if (*quantidade >= MAX_CARTAS) {
        printf("Limite de cartas atingido!\n");
        return;
    }
    
    printf("Código (ex: A01): ");
    scanf("%s", cartas[*quantidade].codigo);
    printf("População: ");
    scanf("%d", &cartas[*quantidade].populacao);
    printf("Área (km²): ");
    scanf("%f", &cartas[*quantidade].area);
    printf("PIB (bilhões $): ");
    scanf("%f", &cartas[*quantidade].pib);
    printf("Pontos turísticos: ");
    scanf("%d", &cartas[*quantidade].pontos_turisticos);
    
    cartas[*quantidade].densidade = cartas[*quantidade].populacao / cartas[*quantidade].area;
    
    (*quantidade)++;
    printf("Carta cadastrada com sucesso!\n");
}

void exibirCartas(Carta cartas[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma carta cadastrada.\n");
        return;
    }
    
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nCódigo: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f bi\nPontos turísticos: %d\nDensidade Populacional: %.2f hab/km²\n",
               cartas[i].codigo, cartas[i].populacao, cartas[i].area, cartas[i].pib, cartas[i].pontos_turisticos, cartas[i].densidade);
    }
}

int (main)() {
    Carta cartas[MAX_CARTAS];
    int quantidade = 0, opcao;

    do {
        printf("\n1. Cadastrar Carta\n2. Exibir Cartas\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarCartas(cartas, &quantidade);
                break;
            case 2:
                exibirCartas(cartas, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}