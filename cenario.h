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
void movePersonagemNoCenario(CENARIO* c, JOGADOR* posicaoJogador, char posicao);