#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "principal.h"
#include "cenario.h"
#include "cenario.c"

CENARIO c;
JOGADOR posicaoJogador;
int temPilula = 0;

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

		if (podeAndar(&c, opcoes[posicao][0], opcoes[posicao][1], FANTASMA)) {
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
	JOGADOR posicao;
	int encontrou = movePersonagemNoCenario(&c, &posicao, PERSONAGEM);
	return !encontrou;
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

	if (!podeAndar(&c, proximoX, proximoY, PERSONAGEM))
		return;

	if (ehPersonagem(&c, proximoX, proximoY, PILULA)) {
		temPilula = 1;
	}

	seMoveNoCenario(&c, posicaoJogador.x, posicaoJogador.y, proximoX, proximoY);
	posicaoJogador.x = proximoX;
	posicaoJogador.y = proximoY;
}

int quantidadeBombas = 3; // Adiciona uma variável para controlar a quantidade de bombas

void explodePilula(int x, int y, int quantidadeVezesParaExplodirBomba) {
    if (quantidadeVezesParaExplodirBomba == 0)
        return;

    // Verifique se y+1 está dentro dos limites da matriz
    if (y + 1 >= 0 && y + 1 < c.colunas) {
        c.matriz[x][y+1] = VAZIO;
        explodePilula(x, y + 1, quantidadeVezesParaExplodirBomba - 1);
    }
}


int main() {
    carregaCenario(&c);
    movePersonagemNoCenario(&c, &posicaoJogador, PERSONAGEM);

    do {
        printf("\n");
        printf("Tem bomba: %s\n", (temPilula ? "Sim" : "Nao"));
        printf("Bombas restantes: %d\n", quantidadeBombas); // Exibe a quantidade de bombas restantes
        exibeCenario(&c);

        char comando;
        scanf(" %c", &comando);
        move(comando);

        if (comando == BOMBA) {
            if (quantidadeBombas > 0) { // Verifica se há bombas disponíveis
                explodePilula(posicaoJogador.x, posicaoJogador.y, 3);
                quantidadeBombas--; // Decrementa a quantidade de bombas
            } else {
                printf("Sem bombas!\n"); // Exibe uma mensagem se não houver bombas disponíveis
                c.matriz[posicaoJogador.x][posicaoJogador.y+1] = VAZIO;
            }
        }

        fantasmas();
    } while (!acabou());

    limpaCenario(&c);
}