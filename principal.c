#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//10+1 porque o \0 conta como caractere
char** mapa;
int linhas;
int colunas;

int main() {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if (f == 0) {
		printf("Erro na leitura do mapa.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &linhas, &colunas);
	printf("Linhas = %d, Colunas = %d\n", linhas, colunas);

	mapa = malloc(sizeof(char*) * linhas);
	for (int i = 0; i < linhas; i++) {
		mapa[i] = malloc(sizeof(char) * (colunas + 1));
	}
	
	for (int i = 0; i < 5; i++) {
		fscanf(f, "%s", mapa[i]);
	}
	
	for (int i = 0; i < 5; i++) {
		printf("%s\n", mapa[i]);
	}

	fclose(f);

	for (int i = 0; i < linhas; i++) {
		free(mapa[i]);
	}
	free(mapa);
}