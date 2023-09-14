#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int EhBOMBA, ABERTA, VIZINHO;
}No;

No tabuleiro[21][21];

#define LINHA_FACIL 10
#define COLUNA_FACIL 10
#define MINAS_FACIL 10

#define LINHA_MEDIO 16
#define COLUNA_MEDIA 16
#define MINAS_MEDIA 40

#define LINHA_DIFICIL 21
#define COLUNA_DIFICIL 21
#define MINAS_DIFICIL 90

void inicia(int linha, int coluna){
    int i = 0, j = 0;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            tabuleiro[i][j].EhBOMBA = 0;
            tabuleiro[i][j].ABERTA = 0;
            tabuleiro[i][j].VIZINHO = 0;
        }
    }
}

void sortear(int linha, int coluna, int minas){
    int i, j;
    srand(time(NULL));

    while (minas > 0) {
        i = rand() % linha;
        j = rand() % coluna;

        if (tabuleiro[i][j].EhBOMBA == 0) {
            tabuleiro[i][j].EhBOMBA = -1;
            minas--;
        }
    }
}

int coordenadaValida(int i, int j, int linha, int coluna){
    if(i>=0 && i<linha && j>=0 && j<coluna){
        return 1;
    }else{
        return 0;
    }
}

int quantBombasVizinhas(int i, int j, int linha, int coluna){
    int quantidade = 0;

    if(coordenadaValida(i-1,j,linha,coluna) && tabuleiro[i-1][j].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i+1,j,linha,coluna) && tabuleiro[i+1][j].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i,j+1,linha,coluna) && tabuleiro[i][j+1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i,j-1,linha,coluna) && tabuleiro[i][j-1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i-1,j-1,linha,coluna) && tabuleiro[i-1][j-1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i-1,j+1,linha,coluna) && tabuleiro[i-1][j+1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i+1,j-1,linha,coluna) && tabuleiro[i+1][j-1].EhBOMBA){
        quantidade++;
    }
    if(coordenadaValida(i+1,j+1,linha,coluna) && tabuleiro[i+1][j+1].EhBOMBA){
        quantidade++;
    }
    return quantidade;
}

void contarBombas(int linha, int coluna){
    int i, j;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            tabuleiro[i][j].VIZINHO = quantBombasVizinhas(i,j,linha,coluna);
        }
    }
}

void imprimirl(int linha, int coluna){
    int i, j;
    char letra = 'A';

    if(linha==10){
        printf("\n\n\t    ");
        for(i=0; i<linha; i++){
            printf(" %c  ",letra);
            letra++;
        }
        printf("\n\t   -----------------------------------------\n");
        letra = 'A';
        for(i=0; i<linha; i++){
            printf("\t%c  |", letra);
            letra++;
            for(j=0; j<coluna; j++){
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
    }else{
        if(linha==16){
            printf("\n\n\t    ");
            char letra = 'A';
            for(i=0; i<linha; i++){
                printf(" %c  ",letra);
                letra++;
            }
            printf("\n\t    -----------------------------------------------------------------\n");
            letra = 'A';
            for(i=0; i<linha; i++){
                printf("\t%c  |", letra);
                letra++;
                for(j=0; j<coluna; j++){
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
                printf("\n\t    -----------------------------------------------------------------\n");
            }
        }else{
            printf("\n\n\t    ");
            for(i=0; i<linha; i++){
                printf(" %c  ",letra);
                letra++;
            }
            printf("\n\t    -------------------------------------------------------------------------------------\n");
            letra = 'A';
            for(i=0; i<linha; i++){
                printf("\t%c  |", letra);
                letra++;
                for(j=0; j<coluna; j++){
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
                printf("\n\t    -------------------------------------------------------------------------------------\n");
            }
        }
    }
}

void imprimirn(int linha, int coluna){
    int i, j;

    if(linha==10){
        printf("\n\n\t    ");
        for(i=0; i<linha; i++){
            printf(" %d  ",i);
        }
        printf("\n\t   -----------------------------------------\n");
        for(i=0; i<linha; i++){
            printf("\t%d  |", i);
            for(j=0; j<coluna; j++){
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
    }else{
        if(linha==16){
            printf("\n\n\t    ");
            for(i=0; i<linha; i++){
                    if(i<=9){
                        printf("  %d ",i);
                    }else{
                        printf(" %d ",i);
                    }
            }
            printf("\n\t    -----------------------------------------------------------------\n");
            for(i=0; i<linha; i++){
                printf("\t%2d  |", i);
                for(j=0; j<coluna; j++){
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
                printf("\n\t    -----------------------------------------------------------------\n");
            }
        }else{
            printf("\n\n\t    ");
            for(i=0; i<linha; i++){
                    if(i<=9){
                        printf("  %d ",i);
                    }else{
                        printf(" %d ",i);
                    }
            }
            printf("\n\t    -------------------------------------------------------------------------------------\n");
            for(i=0; i<linha; i++){
                printf("\t%2d  |", i);
                for(j=0; j<coluna; j++){
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
                printf("\n\t    -------------------------------------------------------------------------------------\n");
            }
        }
    }
}

void abrirNo(int i, int j, int l, int c){
    if(coordenadaValida(i, j,l,c) == 1 && tabuleiro[i][j].ABERTA == 0){
        tabuleiro[i][j].ABERTA = 1;
        if(tabuleiro[i][j].VIZINHO == 0){
            abrirNo(i-1,j,l,c);
            abrirNo(i+1,j,l,c);
            abrirNo(i,j+1,l,c);
            abrirNo(i,j-1,l,c);
        }
    }
}

int ganhou(int linha, int coluna){
    int i, j, quantidade = 0;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(tabuleiro[i][j].ABERTA == 0 && tabuleiro[i][j].EhBOMBA == 0){
                quantidade++;
            }
        }
    }
    return quantidade;
}

int traduz(char letra){
    int numero;
    if('A' <= letra && letra <= 'Z'){
        // Se for uma letra maiúscula
        numero = letra - 'A';
    }else if('a' <= letra && letra <= 'z'){
        // Se for uma letra minúscula
        numero = letra - 'a';
    }
    return numero;
}

void jogar(int l, int c){
    char linhac, colunac;
    int linha, coluna, opc;

    printf("\n\nDeseja jogar usando os numeros ou as letras do teclado?");
    printf("\nDigite (1) para numeros e (2) para letras: ");
    scanf("%d",&opc);
    printf("\n\t\t\tCAMPO MINADO\n");

    if(opc == 2){
        do{
            imprimirl(l,c);
            do{
                printf("\nDigite as coordenadas de linha e coluna: ");
                scanf(" %c %c",&linhac,&colunac);

                linha = traduz(linhac);
                coluna = traduz(colunac);

                if(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1){
                    printf("\nA coordenada eh invalida ou ja esta aberta!");
                }
            }while(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1);

            abrirNo(linha,coluna,l,c);
        }while(ganhou(l,c) != 0 && tabuleiro[linha][coluna].EhBOMBA == 0);

        if(tabuleiro[linha][coluna].EhBOMBA){
            printf("\n\tVOCE PERDEU!!!\n");
        }else{
            printf("\n\tPARABENS VOCE GANHOU!!!\n");
        }
        imprimirn(l,c);
    }else if(opc == 1){
        do{
            imprimirn(l,c);
            do{
                printf("\nDigite as coordenadas de linha e coluna: ");
                scanf("%d %d",&linha,&coluna);

                if(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1){
                    printf("\nA coordenada eh invalida ou ja esta aberta!");
                }
            }while(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1);

            abrirNo(linha,coluna,l,c);
        }while(ganhou(l,c) != 0 && tabuleiro[linha][coluna].EhBOMBA == 0);

        if(tabuleiro[linha][coluna].EhBOMBA){
            printf("\n\tVOCE PERDEU!!!\n");
        }else{
            printf("\n\tPARABENS VOCE GANHOU!!!\n");
        }
        imprimirn(l,c);
    }
}

int jogo(){
    char opcao;
    int linha, coluna, minas;

     do{
        printf("Escolha a dificuldade:\n");
        printf("1. Facil\n");
        printf("2. Medio\n");
        printf("3. Dificil\n");
        printf("Opcao: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linha = LINHA_FACIL;
                coluna = COLUNA_FACIL;
                minas = MINAS_FACIL;
                break;
            case 2:
                linha = LINHA_MEDIO;
                coluna = COLUNA_MEDIA;
                minas = MINAS_MEDIA;
                break;
            case 3:
                linha = LINHA_DIFICIL;
                coluna = COLUNA_DIFICIL;
                minas = MINAS_DIFICIL;
                break;
            default:
                printf("Escolha inválida.\n");
                return 1;
        }
        inicia(linha,coluna);
        sortear(linha,coluna,minas);
        contarBombas(linha,coluna);
        jogar(linha,coluna);
        printf("\n\tDeseja jogar novamente?\n\t\t[s/n]\n");
        scanf(" %c",&opcao);
    }while(opcao == 's');

    return 0;
}

int main(){
    jogo();
    return 0;
}