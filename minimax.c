#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "4enratlla.h"
#include "minimax.h"

void canviar1per2(Node *arrel){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
                if(arrel->tauler[i][j]==1){
                    arrel->tauler[i][j]=2;
                }
                else if(arrel->tauler[i][j]==2){
                    arrel->tauler[i][j]=1;
                }
        }
    }
}

void inicialitza(Node *arrel){
    int i,j;
    arrel->n_fills=N;
    arrel->fills=malloc(arrel->n_fills*sizeof(Node*));
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arrel->tauler[i][j]=0;
        }
    }
}

Node *creaNode(Node *pare, int numFill, int prof){

    int nivell;

    if(prof%2==0){
        nivell=2;
    }
    else{
        nivell=1;
    }

    Node *p=(Node *)malloc(sizeof(Node));
    CopiaTauler(p->tauler /* desti */, pare->tauler);
    aplicarTirada(p->tauler,tiradaReal(p->tauler, numFill+1),nivell); //nivell =parell/senar
    p->profunditat=prof;

    if(comprovar(p->tauler,1) || comprovar(p->tauler,2)){
        p->n_fills=0;
        p->fills=NULL;
        p->valor=funcioHeuristica(p->tauler);
    }

    else if(prof<PF){
        p->n_fills=determinaFills(p->tauler);
        p->fills=malloc(p->n_fills * sizeof(Node *));
        if(prof%2==0){
            p->valor=-10000000;
        }
        else{
            p->valor=10000000;
        }
    }
    else{
        p->n_fills=0;
        p->fills=NULL;
        p->valor=funcioHeuristica(p->tauler);
    }
    return p;
}

void crea1Nivell(Node *pare,int prof){
    int i;
    for(i=0;i<pare->n_fills;i++){
        pare->fills[i]=creaNode(pare,i,prof);
    }
}

void crearArbre(Node *arrel, int prof){
    int i;
    prof++;
    crea1Nivell(arrel,prof); //primera fila es la tirada del ordinador = 1
    if(prof<PF){
        for(i=0;i<arrel->n_fills;i++){
            crearArbre(arrel->fills[i],prof);
        }
    }
}

void MiniMax(Node *pare){
    int i;
    for(i=0;i<pare->n_fills;i++){
        MiniMax(pare->fills[i]);
        if(pare->fills[i]->profunditat%2==0){
            if(pare->fills[i]->valor<pare->valor){
               pare->valor=pare->fills[i]->valor;
            }
        }
        else{
            if(pare->fills[i]->valor>pare->valor){
                pare->valor=pare->fills[i]->valor;
            }
        }

    }


}

double ferMiniMax(Node *pare){
    double max=-10000000;
    int tiradaNo;
    MiniMax(pare);
    for(int i=0;i<pare->n_fills;i++){
        if(pare->fills[i]->valor>max){
            max=pare->fills[i]->valor;
            tiradaNo=i;
        }
    }
    return tiradaReal(pare->tauler,tiradaNo+1);
}

void esborraArbre(Node *arrel){
    int i;
    for(i=0;i<arrel->n_fills;i++){
        esborraArbre(arrel->fills[i]);
        free(arrel->fills[i]);
    }
}


