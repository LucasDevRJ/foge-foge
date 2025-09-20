#include <stdio.h>
#include "cenario.h"

char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoPersonagem[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};


#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define PILULA 'P'
#define BOMBA 'b'

void exibeComandos() {
	printf("--------|COMANDOS|----------\n");
	printf("Cima = w\n");
	printf("Baixo = s\n");
	printf("Direita = d\n");
	printf("Esquerda = a\n");
	printf("Bomba = b\n");
	printf("----------------------------\n");
}

void exibeObjetivo() {
	printf("--------|OBJETIVO|----------\n");
	printf("Exploda os fantasmas antes que eles te comam.\n");
	printf("----------------------------\n");
}


void exibeParte(char desenho[4][7], int parte) {
	printf("%s", desenho[parte]);
}

void exibeCenario(CENARIO* c) {
	for (int i = 0; i < c -> linhas; i++) {

		for (int parte = 0; parte < 4; parte++) {
			for (int j = 0; j < c -> colunas; j++) {
				switch(c -> matriz[i][j]) {
					case FANTASMA:
						exibeParte(desenhoFantasma, parte);
					break;

					case PERSONAGEM:
						exibeParte(desenhoPersonagem, parte);
					break;

					case PILULA:
						exibeParte(desenhoPilula, parte);
					break;

					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						exibeParte(desenhoParede, parte);
					break;

					case VAZIO:
						exibeParte(desenhoVazio, parte);
					break;
				}
			}
			printf("\n");
		}
	}
}