#include <stdio.h>
#include <stdlib.h>
#include "principal.h"
#include "cenario.h"
#include "cenario.c"

CENARIO c;
POSICAOJOGADOR p;

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

	carregaCenario(&c);

	do {
		exibeCenario(&c);

		char comando;
		scanf(" %c", &comando);
		move(comando);
	} while (!acabou());
	
	limpaCenario(&c);
}