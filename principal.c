#include <stdio.h>
#include <stdlib.h>
#include "principal.h"
#include "cenario.h"
#include "cenario.c"

CENARIO c;
JOGADOR posicaoJogador;

void fantasmas() {

	CENARIO copia;
	copiaCenario(&copia, &c);

    for(int i = 0; i < c.linhas; i++) {
        for(int j = 0; j < c.colunas; j++) {
            if(c.matriz[i][j] == FANTASMA) {
                if(ehValida(&c, i, j+1) && ehVazia(&c, i, j+1)) {
                    seMoveNoCenario(&c, i, j, i, j+1);
                }
            }

        }
    }

    limpaCenario(&copia);
}

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
		fantasmas();
	} while (!acabou());
	
	limpaCenario(&c);
}