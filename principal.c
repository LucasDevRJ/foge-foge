#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//10+1 porque o \0 conta como caractere
char** cenario;
int linhas;
int colunas;

void exibeCenario() {
	for (int i = 0; i < linhas; i++) {
		free(cenario[i]);
	}
	free(cenario);
}

void alocaCenario() {
	cenario = malloc(sizeof(char*) * linhas);
	for (int i = 0; i < linhas; i++) {
		cenario[i] = malloc(sizeof(char) * (colunas + 1));
	}
}

void carregaCenario() {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if (f == 0) {
		printf("Erro na leitura do mapa.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &linhas, &colunas);

	alocaCenario();
	
	for (int i = 0; i < 5; i++) {
		fscanf(f, "%s", cenario[i]);
	}

	fclose(f);
}

int main() {
	
	carregaCenario();

	for (int i = 0; i < 5; i++) {
		printf("%s\n", cenario[i]);
	}

	exibeCenario();
}