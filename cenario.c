#include <stdio.h>
#include <stdlib.h>

void seMoveNoCenario(CENARIO* c, int origemX, int origemY, int xDestino, int yDestino) {
	char personagem = c->matriz[origemX][origemY];
	c->matriz[xDestino][yDestino] = personagem;
	c->matriz[origemX][origemY] = VAZIO;
}

int ehValida(CENARIO* c, int x, int y) {
	if (x >= c->linhas) 
		return 0;
	if (y >= c->colunas)
		return 0;
	return 1;
}

int ehVazia(CENARIO* c, int x, int y) {
	return c->matriz[x][y] == VAZIO;
}

void movePersonagemNoCenario(CENARIO* c, JOGADOR* posicaoJogador, char posicao) {
	for (int i = 0; i < c -> linhas; i++) {
		for (int j = 0; j < c -> colunas; j++) {
			if (c -> matriz[i][j] == posicao) {
				posicaoJogador -> x = i;
    			posicaoJogador -> y = j; 
				break;
			}
		}
	}
}

void exibeCenario(CENARIO* c) {
	for (int i = 0; i < c -> linhas; i++) {
		printf("%s\n", c -> matriz[i]);
	}
}

void alocaCenario(CENARIO* c) {
	c -> matriz = malloc(sizeof(char*) * c -> linhas);
	for (int i = 0; i < c -> linhas; i++) {
		c -> matriz[i] = malloc(sizeof(char) * (c -> colunas + 1));
	}
}

void carregaCenario(CENARIO* c) {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if (f == 0) {
		printf("Erro na leitura do mapa.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(c -> linhas), &(c -> colunas));

	alocaCenario(c);
	
	for (int i = 0; i < c -> linhas; i++) {
		fscanf(f, "%s", c -> matriz[i]);
	}

	fclose(f);
}

void limpaCenario(CENARIO* c) {
	for (int i = 0; i < c -> linhas; i++) {
		free(c -> matriz[i]);
	}

	free(c -> matriz);
}