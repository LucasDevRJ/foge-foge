void exibeCenario();
void carregaCenario();
void alocaCenario();
void limpaCenario();
void move(char direcao);
int acabou();

struct cenario {
	char** matriz;
	int linhas;
	int colunas;
};