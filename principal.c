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

int ehDirecao(char direcao) {
	return direcao == 'a' ||
		   direcao == 'w' ||
		   direcao == 's' ||
		   direcao == 'd';
}

void move(char direcao) {

	if (!ehDirecao(direcao)) 
		return;

	int proximoX = posicaoJogador.x;
	int proximoY = posicaoJogador.y;

	//c.matriz[posicaoJogador.x][posicaoJogador.y] = '.';

	switch(direcao) {
		case ESQUERDA:
			proximoY--;
		break;

		case CIMA:
			proximoX--;
		break;

		case BAIXO:
			proximoX++;
		break;

		case DIREITA:
			proximoY++;
		break;
	}

	if (!ehValida(&c, proximoX, proximoY))
		return;
	if (!ehVazia(&c, proximoX, proximoY))
		return;

	seMoveNoCenario(&c, posicaoJogador.x, posicaoJogador.y, proximoX, proximoY);
	posicaoJogador.x = proximoX;
	posicaoJogador.y = proximoY;
}

int main() {

	carregaCenario(&c);
	movePersonagemNoCenario(&c, &posicaoJogador, PERSONAGEM);

	do {
		exibeCenario(&c);

		char comando;
		scanf(" %c", &comando);
		move(comando);
	} while (!acabou());
	
	limpaCenario(&c);
}