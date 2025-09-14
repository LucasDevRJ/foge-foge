#ifndef _CENARIO_H
#define _CENARIO_H

#define PERSONAGEM '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define PILULA 'P'

struct cenario {
	char** matriz;
	int linhas;
	int colunas;
};

typedef struct cenario CENARIO;

struct posicaoJogador {
	int x;
	int y;
};

typedef struct posicaoJogador JOGADOR;

void carregaCenario(CENARIO* c);
void alocaCenario(CENARIO* c);
void limpaCenario(CENARIO* c);
void exibeCenario(CENARIO* c);
int movePersonagemNoCenario(CENARIO* c, JOGADOR* posicaoJogador, char posicao);
int ehValida(CENARIO* c, int x, int y);
int ehVazia(CENARIO* c, int x, int y);
void seMoveNoCenario(CENARIO* c, int origemX, int origemY, int xDestino, int yDestino);
void copiaCenario(CENARIO* destino, CENARIO* origem);
int ehParede(CENARIO* c, int x, int y);
int podeAndar(CENARIO* c, int x, int y, char personagem);
int ehParede(CENARIO* c, int x, int y);
int ehPersonagem(CENARIO* c, int x, int y, char personagem);

#endif