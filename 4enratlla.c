#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "4enratlla.h"
#include "minimax.h"

int taulerPle(int tauler[N][N]){
    int i,j,aux=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(tauler[i][j]!=0){
                aux++;
            }
        }
    }
    if(aux==(N*N)){
        return 1; //tauler ple
    }
    else{
        return 0;
    }
}

int comprovarTirada(int tauler[N][N],int p){
    if(0<p && p<N+1 && tauler[0][p-1]==0){
        return 1; //si esta lliure la fila de mes amunt es podra tirar
    }
    else{
        return 0;
    }
}

void CopiaTauler(int desti[N][N], int origen[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            desti[i][j]=origen[i][j];
        }
    }
}

int determinaFills(int tauler[N][N]){
    int fills=0,i;
    for(i=0;i<N;i++){
        if(tauler[0][i]==0){ //mirem la fila de mes amunt nomes
            fills++;
        }
    }
    return fills;
}

int comprovar(int taulell[N][N],int jugador){
    int i,j;

    for(j=0;j<N;j++){
        for(i=0;i<(N-3);i++){
            if(taulell[i][j]==jugador && taulell[i+1][j]==jugador && taulell[i+2][j]==jugador && taulell[i+3][j]==jugador){
                return jugador;
            }
        }
    }

    for(j=0;j<(N-3);j++){
        for(i=0;i<N;i++){
            if(taulell[i][j]==jugador && taulell[i][j+1]==jugador && taulell[i][j+2]==jugador && taulell[i][j+3]==jugador){
                return jugador;
            }
        }
    }

    for(i=0;i<(N-3);i++){
        for(j=(N-1);j>2;j--){
            if(taulell[i][j]==jugador && taulell[i+1][j-1]==jugador && taulell[i+2][j-2]==jugador && taulell[i+3][j-3]==jugador){
                return jugador;
            }
        }
    }


    for(j=0;j<(N-3);j++){
        for(i=0;i<(N-3);i++){
            if(taulell[i][j]==jugador && taulell[i+1][j+1]==jugador && taulell[i+2][j+2]==jugador && taulell[i+3][j+3]==jugador){
                return jugador;
            }
        }
    }

    return 0;
}

int tiradaReal(int tauler[N][N], int tiradaFalsa){
    int i,comprovar=0;
    for(i=0;i<N;i++){
        comprovar=comprovar+comprovarTirada(tauler,i+1); //si es pot tirar =1 sino =0
        if(comprovar==tiradaFalsa){
            break;
        }
    }
    return i+1;
}

void imprimir(int tauler[N][N]){
    int i,j;
    printf("\n  ");
    for(i=0;i<N;i++){
        printf("%i   ",i+1);
    }
    printf("\n\n");
    for(i=0;i<N;i++){
        printf("| ");
        for(j=0;j<N;j++){
            if(tauler[i][j]==1){
                printf("X | ");
            }
            else if(tauler[i][j]==2){
                printf("O | ");
            }
            else{
                printf("  | ");
            }
        }
    printf("\n");
    }
}

void aplicarTirada(int tauler[N][N],int p, int jugador){
    int i;
    for(i=N-1;i>=0;i--){
        if(tauler[i][p-1]==0){
            tauler[i][p-1]=jugador;
            break;
        }
    }
}

int taulerguanyat(int tauler[N][N]){
    if(comprovar(tauler,1)==1) return 0; //comprovar si pc ha guanyat
    return 47;
}

int taulerperdut(int tauler[N][N]){
    if(comprovar(tauler,2)==2) return 0; //comprovar si huma ha guanyat
    return 47;
}

int mirarVertical3(int tauler[N][N],int i, int j,int jugador){
        if(tauler[i][j]==jugador && tauler[i+1][j]==jugador && tauler[i+2][j]==jugador){
            return 1;
        }
        else{
            return 0;
        }
}

int mirarHoritzontal3(int tauler[N][N],int i, int j,int jugador){
        if(tauler[i][j]==jugador && tauler[i][j+1]==jugador && tauler[i][j+2]==jugador){
            return 1;
        }
        else{
            return 0;
        }
}

int mirarDiagonals3(int tauler[N][N],int i, int j,int jugador){ //molts repetits
        int aux=0;
        if(tauler[i][j]==jugador && tauler[i+1][j+1]==jugador && tauler[i+2][j+2]==jugador){
            aux++;
        }
        if(tauler[i][j]==jugador && tauler[i-1][j+1]==jugador && tauler[i-2][j+2]==jugador){
            aux++;
        }
        return aux;
}

int mirarVertical2(int tauler[N][N],int i, int j,int jugador){
        if(tauler[i][j]==jugador && tauler[i+1][j]==jugador){
            return 1;
        }
        else{
            return 0;
        }
}

int mirarHoritzontal2(int tauler[N][N],int i, int j,int jugador){
        if(tauler[i][j]==jugador && tauler[i][j+1]==jugador){
            return 1;
        }
        else{
            return 0;
        }
}

int mirarDiagonals2(int tauler[N][N],int i, int j,int jugador){ //molts repetits
        int aux=0;
        if(tauler[i][j]==jugador && tauler[i+1][j+1]==jugador){
            aux++;
        }
        if(tauler[i][j]==jugador && tauler[i-1][j+1]==jugador){
            aux++;
        }
        return aux;
}

int comptar2(int tauler[N][N],int jugador){
    int i,j,suma=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            suma=suma+mirarVertical2(tauler,i,j,jugador)+mirarHoritzontal2(tauler,i,j,jugador)+mirarDiagonals2(tauler,i,j,jugador);
        }
    }
    return suma;
}

int comptar3(int tauler[N][N],int jugador){
    int i,j,suma=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            suma=suma+mirarVertical3(tauler,i,j,jugador)+mirarHoritzontal3(tauler,i,j,jugador)+mirarDiagonals3(tauler,i,j,jugador);
        }
    }
    return suma;
}

double funcioHeuristica(int tauler[N][N]){

    int tres=0,dos=0,tres_oposats=0,dos_oposats=0;
    tres=comptar3(tauler,1);
    dos=comptar2(tauler,1)-2*tres;
    tres_oposats=comptar3(tauler,2);
    dos_oposats=comptar2(tauler,2)-2*tres_oposats;
    if(taulerguanyat(tauler)==0){
        return 100000;
    }
    else if(taulerperdut(tauler)==0){
        return -100000;
    }
    else{
        return (tres*100 + dos*10) - (tres_oposats*100+dos_oposats*10);
    }

}

int main(){

    int p,joc=0;

	printf("\n\n");
	printf("                                                                      \n");
	printf("            4 EN RATLLA EN .C                                         \n");
	printf("                                                                      \n");
	printf("                                                                      \n");
	printf("          |   |   |   |   |   |                                       \n");
	printf("          |   |   |   |   |   |                                       \n");
	printf("          |   |   |   |   |   |                                       \n");
	printf("          |   |   |   | O |   |                                       \n");
	printf("          |   | X |   | X | O |                                       \n");
	printf("          | O | O | O | X | X |                                       \n");
	printf("          ---------------------                                       \n");
	printf("                                                                      \n");
	printf("                                                                      \n");
	printf("                                                                      \n");
	printf("    Premer tecla 1 per jugar VS Inteligencia Artificial (MODE DIFICIL)     \n");
	printf("    Premer tecla 2 per jugar VS Inteligencia Artificial (MODE FACIL)       \n");
	printf("    Premer tecla 3 per Jugador1 VS Jugador2                           \n");
	printf("    Premer tecla 4 per veure una simulacio                            \n");
	printf("                                                                      \n");


    char tecla = getch();



    if(tecla=='1'){
        system("cls");
        Node *arrel=(Node *)malloc(sizeof(Node));
        srand(time(0));
        inicialitza(arrel);
        imprimir(arrel->tauler);

        while(joc==0){
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }
            printf("\nOn vols tirar? ");
            scanf("%i",&p);
            system("cls");
            aplicarTirada(arrel->tauler,p,2);
            imprimir(arrel->tauler);
            if(comprovar(arrel->tauler,2)!=0){
                joc=2;
                break;
            }
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }
            crearArbre(arrel,0);
            MiniMax(arrel);
            aplicarTirada(arrel->tauler,ferMiniMax(arrel),1);
            esborraArbre(arrel);
            system("cls");
            imprimir(arrel->tauler);
            joc=comprovar(arrel->tauler,1);
        }
        if(joc==1){
            printf("\n\nHA GUANYAT L'ORDINADOR\n");
        }
        else if(joc==4){
            printf("Tauler ple! EMPAT\n");
        }
        else{
            printf("\n\nHA GUANYAT EL JUGADOR HUMA\n");
        }

    }

    else if(tecla=='2'){
        system("cls");
        Node *arrel=(Node *)malloc(sizeof(Node));
        srand(time(0));
        inicialitza(arrel);
        imprimir(arrel->tauler);

        while(joc==0){
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }
            printf("\nOn vols tirar? ");
            scanf("%i",&p);
            system("cls");
            aplicarTirada(arrel->tauler,p,2);
            imprimir(arrel->tauler);
            if(comprovar(arrel->tauler,2)!=0){
                joc=2;
                break;
            }
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }
            aplicarTirada(arrel->tauler,1+rand()%N,1);
            system("cls");
            imprimir(arrel->tauler);
            joc=comprovar(arrel->tauler,1);
        }
        if(joc==1){
            printf("\n\nHA GUANYAT INTELIGENCIA ARTIFICAL ALEATORIA\n");
        }
        else if(joc==4){
            printf("Tauler ple! EMPAT\n");
        }
        else{
            printf("\n\nHA GUANYAT EL JUGADOR HUMA\n");
        }

    }

    else if(tecla=='3'){
        system("cls");
        Node *arrel=(Node *)malloc(sizeof(Node));
        srand(time(0));
        inicialitza(arrel);
        imprimir(arrel->tauler);
        while(joc==0){
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }
            printf("\nOn vols tirar Jugador O? ");
            scanf("%i",&p);
            system("cls");
            aplicarTirada(arrel->tauler,p,2);
            imprimir(arrel->tauler);
            if(comprovar(arrel->tauler,2)!=0){
                joc=2;
                break;
            }
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }
            printf("\nOn vols tirar Jugador X? ");
            scanf("%i",&p);
            system("cls");
            aplicarTirada(arrel->tauler,p,1);
            system("cls");
            imprimir(arrel->tauler);
            joc=comprovar(arrel->tauler,1);
        }
        if(joc==1){
            printf("\n\nHA GUANYAT JUGADOR X\n");
        }
        else if(joc==4){
            printf("Tauler ple! EMPAT\n");
        }
        else{
            printf("\n\nHA GUANYAT JUGADOR O\n");
        }

    }

    else if(tecla=='4'){
        system("cls");
        Node *arrel=(Node *)malloc(sizeof(Node));
        srand(time(0));
        inicialitza(arrel);
        imprimir(arrel->tauler);
        p=1+rand()%N;
        aplicarTirada(arrel->tauler,p,1);
        while(joc==0){

            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }

            canviar1per2(arrel);

            crearArbre(arrel,0);
            MiniMax(arrel);
            p=ferMiniMax(arrel);

            canviar1per2(arrel);

            system("cls");
            aplicarTirada(arrel->tauler,p,2);
            esborraArbre(arrel);
            imprimir(arrel->tauler);
            if(comprovar(arrel->tauler,2)!=0){
                joc=2;
                break;
            }
            if(taulerPle(arrel->tauler)==1){
                joc=4;
                break;
            }

            crearArbre(arrel,0);
            MiniMax(arrel);
            aplicarTirada(arrel->tauler,ferMiniMax(arrel),1);
            esborraArbre(arrel);
            system("cls");
            imprimir(arrel->tauler);
            joc=comprovar(arrel->tauler,1);
        }
        if(joc==1){
            printf("\n\nHA GUANYAT ORDINADOR X\n");
        }
        else if(joc==4){
            printf("Tauler ple! EMPAT\n");
        }
        else{
            printf("\n\nHA GUANYAT ORDINADOR O\n");
        }
    }

    else{
        system("cls");
        printf("Error de lectura!!\n");
    }

    return 0;

}



