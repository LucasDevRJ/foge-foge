#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "principal.h"

struct cenario c;

void exibeCenario() {
	for (int i = 0; i < 5; i++) {
		printf("%s\n", c.matriz[i]);
	}
}

void alocaCenario() {
	c.matriz = malloc(sizeof(char*) * c.linhas);
	for (int i = 0; i < c.linhas; i++) {
		c.matriz[i] = malloc(sizeof(char) * (c.colunas + 1));
	}
}

void carregaCenario() {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if (f == 0) {
		printf("Erro na leitura do mapa.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(c.linhas), &(c.colunas));

	alocaCenario();
	
	for (int i = 0; i < 5; i++) {
		fscanf(f, "%s", c.matriz[i]);
	}

	fclose(f);
}

void limpaCenario() {
	for (int i = 0; i < c.linhas; i++) {
		free(c.matriz[i]);
	}

	free(c.matriz);
}
 
int acabou() {
	return 0;
}

void move(char direcao) {
	int x;
	int y;

	for (int i = 0; i < c.linhas; i++) {
		for (int j = 0; j < c.colunas; j++) {
			if (c.matriz[i][j] == '@') {
				x = i;
    			y = j; 
				break;
			}
		}
	}

	switch(direcao) {
		case 'a':
			c.matriz[x][y-1] = '@';
		break;

		case 'w':
			c.matriz[x-1][y] = '@';
		break;

		case 's':
			c.matriz[x+1][y] = '@';
		break;

		case 'd':
			c.matriz[x][y+1] = '@';
		break;
	}

	c.matriz[x][y] = '.';
}

int main() {

	carregaCenario();

	do {
		exibeCenario();

		char comando;
		scanf(" %c", &comando);
		move(comando);
	} while (!acabou());
	
	limpaCenario();
}