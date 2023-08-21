#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int info;
	struct no * proximo;
}No;

typedef struct fila{
	No* ini;
	No* fim;
} Fila;

No* insere(No* fim, int num){
	No* novo_no = (No*)malloc(sizeof(No));
	novo_no->info = num;
	novo_no->proximo = fim;
	return novo_no;
}

No* retira(No* inicio){
	No* aux = inicio; 
	inicio = aux->proximo;
	free(aux); 
	return inicio;
}

int vazia(No* fila){
	if(fila == NULL)
		return 1;
	else
		return 0;
}

Fila* cria(void){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = NULL; /* inicia a fila vazia */
	return f;
}

void entra(Fila* f, int v){
	No* novo_no = insere(f->fim, v); 
	novo_no->proximo = NULL;
	if(f->fim != NULL){ /* nos casos em que não é o primeiro elemento */
		f->fim->proximo = novo_no;
	}
	f->fim=novo_no;
	if(f->ini == NULL){ /* Fila estava vazia? */
		f->ini = f->fim;
	}
}

int sai(Fila* f){
	int num;
	if(vazia(f)){
		printf("Fila vazia.\n");
		exit(1); /* aborta programa */
	}
	num = f->ini->info;
	f->ini = retira(f->ini);
	if(f->ini == NULL){ /* Fila ficou vazia? */
		f->fim = NULL;
	}
	return num;
}



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	
	Fila* f = cria();
	entra(f, 5);
	entra(f, 2);
	entra(f, 3);
	entra(f, 4);
	printf("Primeiro elemento: %d\n", sai(f));
	
	return 0;
}