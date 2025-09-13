#define PERSONAGEM '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

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

void exibeCenario(CENARIO* c);
void carregaCenario(CENARIO* c);
void alocaCenario(CENARIO* c);
void limpaCenario(CENARIO* c);
int movePersonagemNoCenario(CENARIO* c, JOGADOR* posicaoJogador, char posicao);
int ehValida(CENARIO* c, int x, int y);
int ehVazia(CENARIO* c, int x, int y);
void seMoveNoCenario(CENARIO* c, int origemX, int origemY, int xDestino, int yDestino);
void copiaCenario(CENARIO* destino, CENARIO* origem);