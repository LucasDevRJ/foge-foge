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

typedef struct posicao POSICAOJOGADOR;

void exibeCenario(CENARIO* c);
void carregaCenario(CENARIO* c);
void alocaCenario(CENARIO* c);
void limpaCenario(CENARIO* c);