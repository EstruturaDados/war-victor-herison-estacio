#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Ela agrupa os dados relacionados a um território:
// - nome: nome do território
// - cor: cor do exército
// - tropas: quantidade de tropas alocadas
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor que armazena 5 territórios
    Territorio territorios[5];

    // Cadastro dos 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        // Leitura do nome do território
        printf("Digite o nome do território: ");
        scanf(" %[^\n]", territorios[i].nome); // Lê string com espaços

        // Leitura da cor do exército
        printf("Digite a cor do exército: ");
        scanf(" %s", territorios[i].cor); // Lê string sem espaços

        // Leitura do número de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n===== Dados dos Territórios Cadastrados =====\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
