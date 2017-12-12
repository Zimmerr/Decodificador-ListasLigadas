//--------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: João Pedro Rodrigues Camargo E Luis Henrique Zimmermann
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>



// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
char* nroUSP1() {
    return("10258900");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
char* nroUSP2() {
    return("10258789");
}


// elemento da lista
typedef struct estr {
        char letra;
        struct estr *prox;
} NO;


// funcao principal
NO* decodificar(NO* p);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

NO* copyLista(NO* p){
    NO* ant = NULL;
    NO* resp = NULL;
    while (p) {
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->letra = p->letra;
        novo->prox = NULL;
        if(ant) ant->prox = novo;
        else resp = novo;
        ant = novo;
        p = p->prox;
    };
    return resp;
}

NO* inverter(NO* resp){
    NO* ant = NULL;
    NO* atual = resp;
    NO* next = NULL;
    while(atual){
        next = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = next;
    };
    //*resp = ant;
    return ant;
}





NO* cons(NO* resp){
    NO* p = resp;
    NO* ant1 = NULL;
    NO* F = NULL;
    int x = 0;
    while(p){
        if(p->prox)if(p->letra != 'A' &&  p->letra != 'E' && p->letra != 'I' && p->letra != 'O' && p->letra != 'U' && p->prox->letra != 'A' && p->prox->letra != 'E' && p->prox->letra != 'I' && p->prox->letra != 'O' && p->prox->letra != 'U'){
            NO* ant2 = NULL;

            while(p->letra != 'A' &&  p->letra != 'E' && p->letra != 'I' && p->letra != 'O' && p->letra != 'U'){
                NO* novo = (NO*) malloc(sizeof(NO));
                novo -> letra = p->letra;
                novo -> prox = NULL;
                if(ant2) ant2 ->prox = novo;
                if(!ant2) F = novo;

                ant2 = novo;
                if(!p->prox){
                    x = -1;
                    break;
                }
                p=p->prox;

            } //L.AGE LOTIU MES ODA DES DARUTUSTRE


            NO* ult = inverter(F);
            if(ant1) ant1->prox = ult;
            if(!ant1) resp = ult;
            F->prox = p;
            if(x== -1) F->prox = NULL;

        }
        ant1 = p;
        p = p->prox;
    }
    return resp;
}



NO* decodificar(NO* p) {

	NO* resp;
	resp = NULL;


	// seu codigo AQUI
	resp = copyLista(p);
    resp = inverter(resp);
    resp = cons(resp);
	return resp;
}




//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {

	NO* p = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista p

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
	teste = decodificar(p);

}

// por favor nao inclua nenhum código abaixo da função main()
