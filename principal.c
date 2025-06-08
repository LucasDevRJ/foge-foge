#include <stdio.h>
#include <stdlib.h>
#include "principal.h"
#include "cenario.h"
#include "cenario.c"

CENARIO c;
JOGADOR posicaoJogador;

int acabou() {
	return 0;
}

void move(char direcao) {

	if (direcao != 'a' &&
		direcao != 'w' &&
		direcao != 's' &&
		direcao != 'd') 
		return;

	c.matriz[posicaoJogador.x][posicaoJogador.y] = '.';

	switch(direcao) {
		case 'a':
			c.matriz[posicaoJogador.x][posicaoJogador.y-1] = '@';
			posicaoJogador.y--;
		break;

		case 'w':
			c.matriz[posicaoJogador.x-1][posicaoJogador.y] = '@';
			posicaoJogador.x--;
		break;

		case 's':
			c.matriz[posicaoJogador.x+1][posicaoJogador.y] = '@';
			posicaoJogador.x++;
		break;

		case 'd':
			c.matriz[posicaoJogador.x][posicaoJogador.y+1] = '@';
			posicaoJogador.y++;
		break;
	}
}

int main() {

	carregaCenario(&c);
	movePersonagemNoCenario(&c, &posicaoJogador, '@');

	do {
		exibeCenario(&c);

		char comando;
		scanf(" %c", &comando);
		move(comando);
	} while (!acabou());
	
	limpaCenario(&c);
}