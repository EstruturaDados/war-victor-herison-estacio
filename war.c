#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

// funções úteis

// cadastratr territórios
void cadastrarTerritorios(Territorio* mapa, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

         printf("Digite o nome do território: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Digite a cor do exército: ");
        scanf(" %s", mapa[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// exibir territórios

void exibirTerritorios(Territorio* mapa, int tamanho) {
    printf("\n===== Estado Atual dos Territórios =====\n");

    for(int i=0; i < tamanho; i++){
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Quantidade de Tropas: %d\n", mapa[i].tropas);
    }
}

// função para simular ataque entre territórios

void atacar(Territorio* atacante, Territorio* defensor){
    if(strcmp(atacante->cor, defensor->cor) == 0){
        printf("[ERRO] Ataque inválido! Não é possível atacar um território do mesmo exército.\n");
        return;
    }

    printf("\n--- Ataque de %s (%s) contra %s (%s) ---\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    

    int dadoAtacante = (rand() % 6) + 1; // Dado do atacante (1 a 6)
    int dadoDefensor = (rand() % 6) + 1;  // Dado do defensor (1 a 6)

    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf(">> O atacante venceu a batalha!\n");
        strcpy(defensor->cor, atacante->cor); // Conquista do território

        int tropasMovidas = atacante->tropas / 2; // Metade das tropas atacantes se movem
        defensor->tropas = tropasMovidas;
        atacante->tropas -= tropasMovidas;
    } else{
        printf(">> O defensor resistiu! O atacante perde 1 tropa.\n");
        atacante->tropas -= 1;
    }
}

// liberar memória

void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

// função principal

int main() {

    srand(time(NULL));

    int n;

    printf("Digite o número de territórios do mapa: ");
    scanf("%d", &n);

    Territorio* mapa = (Territorio*)calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória para o mapa.\n");
        return 1;
    }

    // Cadastro dos territórios

    cadastrarTerritorios(mapa, n);
    exibirTerritorios(mapa, n);
    
    //menu de ataque
    int opcao;
    do {
        printf("\n=== Menu de Ações ===\n");
        printf("1 - Realizar ataque\n");
        printf("2 - Exibir territórios\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            int idxAtacante, idxDefensor;
            exibirTerritorios(mapa, n);

            printf("\nEscolha o número do território atacante: ");
            scanf("%d", &idxAtacante);

            printf("Escolha o número do território defensor: ");
            scanf("%d", &idxDefensor);

            if (idxAtacante < 1 || idxAtacante > n || idxDefensor < 1 || idxDefensor > n) {
                printf("[ERRO] Índice inválido!\n");
                continue;
            }

            atacar(&mapa[idxAtacante - 1], &mapa[idxDefensor - 1]);
        }else if (opcao == 2) {
            exibirTerritorios(mapa, n);
        }
    } while (opcao != 0);
    

    liberarMemoria(mapa);

    return 0;
}
