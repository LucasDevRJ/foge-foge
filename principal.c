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

	int proximoX = posicaoJogador.x;
	int proximoY = posicaoJogador.y;

	//c.matriz[posicaoJogador.x][posicaoJogador.y] = '.';

	switch(direcao) {
		case 'a':
			proximoY--;
		break;

		case 'w':
			proximoX--;
		break;

		case 's':
			proximoX++;
		break;

		case 'd':
			proximoY++;
		break;
	}

	if (proximoX >= c.linhas) 
		return;
	if (proximoY >= c.colunas)
		return;
	if (c.matriz[proximoX][proximoY] != '.')
		return;

	c.matriz[proximoX][proximoY] = '@';
	c.matriz[posicaoJogador.x][posicaoJogador.y] = '.';
	posicaoJogador.x = proximoX;
	posicaoJogador.y = proximoY;
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