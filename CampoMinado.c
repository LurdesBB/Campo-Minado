#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int EhBOMBA, ABERTA, VIZINHO;
}No;

No tabuleiro[10][10];

void inicia(){
    int i = 0, j = 0, tam = 10;

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            tabuleiro[i][j].EhBOMBA = 0;
            tabuleiro[i][j].ABERTA = 0;
            tabuleiro[i][j].VIZINHO = 0;
        }
    }
}

void sortear(int n){
    int i, j, k, tam = 10, bombas = 0;
    srand(time(NULL));

    for(i=1; i<=n; i++){
        j = rand() % tam;
        k = rand() % tam;
        if(tabuleiro[j][k].EhBOMBA == 0){
            tabuleiro[j][k].EhBOMBA = 1;
            bombas++;
        }else{
            i--;
        }  
    }
}

int coordenadaValida(int i, int j){
    int tam = 10;

    if(i>=0 && i<tam && j>=0 && j<tam){
        return 1;
    }else{
        return 0;
    }
}

int quantBombasVizinhas(int i, int j){
    int quantidade = 0;

    if(coordenadaValida(i-1,j) && tabuleiro[i-1][j].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i+1,j) && tabuleiro[i+1][j].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i,j+1) && tabuleiro[i][j+1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i,j-1) && tabuleiro[i][j-1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i-1,j-1) && tabuleiro[i-1][j-1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i-1,j+1) && tabuleiro[i-1][j+1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i+1,j-1) && tabuleiro[i+1][j-1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i+1,j+1) && tabuleiro[i+1][j+1].EhBOMBA){
        quantidade++;
    }
    return quantidade;
}

void contarBombas(){
    int i, j, tam = 10;

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            tabuleiro[i][j].VIZINHO = quantBombasVizinhas(i,j);
        }
    }
}

void imprimir(){
    int i, j, tam = 10;

    printf("\n\n\t    ");
    for(i=0; i<tam; i++){
        printf(" %d  ",i);
    }
    printf("\n\t   -----------------------------------------\n");
    for(i=0; i<tam; i++){
        printf("\t%d  |", i);
        for(j=0; j<tam; j++){
            if(tabuleiro[i][j].ABERTA){
                if(tabuleiro[i][j].EhBOMBA){
                    printf(" * ");
                }else{
                    printf(" %d ", tabuleiro[i][j].VIZINHO);
                }
            }else{
                printf("   ");
            } 
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}

void abrirNo(int i, int j){
    if(coordenadaValida(i, j) == 1 && tabuleiro[i][j].ABERTA == 0){
        tabuleiro[i][j].ABERTA = 1;
        if(tabuleiro[i][j].VIZINHO == 0){
            abrirNo(i-1,j);
            abrirNo(i+1,j);
            abrirNo(i,j+1);
            abrirNo(i,j-1);
        }
    }
}

int ganhou(){
    int i, j, tam = 10, quantidade = 0;

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            if(tabuleiro[i][j].ABERTA == 0 && tabuleiro[i][j].EhBOMBA == 0){
                quantidade++;
            }
        }
    }
    return quantidade;
}

void jogar(){
    int linha, coluna;

    do{
        imprimir();
        do{
            printf("\nDigite as coordenadas de linha e coluna: ");
            scanf("%d%d",&linha,&coluna);

            if(coordenadaValida(linha,coluna) == 0 || tabuleiro[linha][coluna].ABERTA == 1){
                printf("\nA coordenada eh invalida ou ja esta aberta!");
            }
        }while(coordenadaValida(linha,coluna) == 0 || tabuleiro[linha][coluna].ABERTA == 1);

        abrirNo(linha,coluna);
    }while(ganhou() != 0 && tabuleiro[linha][coluna].EhBOMBA == 0);

    if(tabuleiro[linha][coluna].EhBOMBA == 1){
        printf("\n\tVOCE PERDEU!!!\n");
    }else{
        printf("\n\tPARABENS VOCE GANHOU!!!\n");
    }
    imprimir();
}

int main(){
    char opcao;

    do{
        inicia();
        sortear(20);
        contarBombas();
        printf("\n\t\t\tCAMPO MINADO\n");
        jogar();
        printf("\n\tDeseja jogar novamente?\n\t\t[s/n]\n");
        scanf(" %c",&opcao);
    }while(opcao == 's');

    return 0;
}