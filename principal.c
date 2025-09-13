#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "principal.h"
#include "cenario.h"
#include "cenario.c"

CENARIO c;
JOGADOR posicaoJogador;

int praOndeFantasmaVai(int atualX, int atualY, int* destinoX, int* destinoY) {
	int opcoes[4][2] = {
		{ atualX, atualY + 1 },
		{ atualX + 1, atualY },
		{ atualX, atualY - 1 },
		{ atualX - 1, atualY },
	};

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		int posicao = rand() % 4;

		if (ehValida(&c, opcoes[posicao][0], opcoes[posicao][1])
			&& ehVazia(&c, opcoes[posicao][0], opcoes[posicao][1])) {
			*destinoX = opcoes[posicao][0];
			*destinoY = opcoes[posicao][1];
			return 1;
		}
	}
	return 0;
}

void fantasmas() {

	CENARIO copia;
	copiaCenario(&copia, &c);

    for(int i = 0; i < c.linhas; i++) {
        for(int j = 0; j < c.colunas; j++) {
            if(c.matriz[i][j] == FANTASMA) {

            	int destinoX;
            	int destinoY;

            	int encontrou = praOndeFantasmaVai(i, j, &destinoX, &destinoY);

                if (encontrou) {
                	seMoveNoCenario(&c, i, j, destinoX, destinoY);
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