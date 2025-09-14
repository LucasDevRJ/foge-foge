#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define PILULA 'P'
#define BOMBA 'b'

void move(char direcao);
int acabou();
int ehDirecao(char direcao);
void fantasmas();
int praOndeFantasmaVai(int atualX, int atualY, int* destinoX, int* destinoY);
void chamaExplodePilula();
void explodePilula(int x, int y, int somaX, int somaY, int quantidadeVezesParaExplodirBomba);

#endif