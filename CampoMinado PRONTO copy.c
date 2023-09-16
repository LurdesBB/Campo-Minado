#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{ //Nessa struct criamos 3 variaveis para serem 3 matrizes, uma com as bombas, outra para mostrar se a posição esta
    int EhBOMBA, ABERTA, VIZINHO; // aberta e a ultima para nos mostrar quantas bombas tem nos seus vizinhos
}No;

No tabuleiro[21][21];

#define LINHA_FACIL 10 //Aqui definimos cada uma das pré configurações de jogo, sendo elas fácil, médio e dificil.
#define COLUNA_FACIL 10
#define MINAS_FACIL 10

#define LINHA_MEDIO 16
#define COLUNA_MEDIA 16
#define MINAS_MEDIA 40

#define LINHA_DIFICIL 21
#define COLUNA_DIFICIL 21
#define MINAS_DIFICIL 90

void inicia(int linha, int coluna){ //Nessa função as 3 matrizes são iniciadas com 0
    int i = 0, j = 0;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            tabuleiro[i][j].EhBOMBA = 0;
            tabuleiro[i][j].ABERTA = 0;
            tabuleiro[i][j].VIZINHO = 0;
        }
    }
}

void sortear(int linha, int coluna, int minas){ //Essa função serve para sortear as bombas em lugares aleatórios
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

int coordenadaValida(int i, int j, int linha, int coluna){ //Aqui verifica se a coordenada é válida
    if(i>=0 && i<linha && j>=0 && j<coluna){
        return 1;
    }else{
        return 0;
    }
}

int quantBombasVizinhas(int i, int j, int linha, int coluna){ //Aqui ele verifica cada posição em volta de uma posição e retorna o número de bombas que está em volta dela

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

void contarBombas(int linha, int coluna){ //Essa função serve para sabermos quantas bombas existem perto de cada posição
    int i, j;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            tabuleiro[i][j].VIZINHO = quantBombasVizinhas(i,j,linha,coluna); //Para contarmos elas, mandamos para essa função
        }
    }
}

void imprimirl(int linha, int coluna){ //Aqui imprimimos o tabuleiro com letras
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

void imprimirn(int linha, int coluna){ //Aqui imprimimos o tabuleiro com números
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

void imprimirnl(int linha, int coluna){ //Aqui imprimimos o tabuleiro com números nas linhas e letras nas colunas
    int i, j;
    char letra = 'A';

    if(linha==10){
        printf("\n\n\t    ");
        for(i=0; i<linha; i++){
            printf(" %c  ",letra);
            letra++;
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
            letra = 'A';
            for(i=0; i<linha; i++){
                printf(" %c  ",letra);
                letra++;
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
            letra = 'A';
            for(i=0; i<linha; i++){
                printf(" %c  ",letra);
                letra++;
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

void abrirNo(int i, int j, int l, int c){ //abre a coordenada escolhida
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

int ganhou(int linha, int coluna){ //verifica se a quantidade de de espaços que faltam são todos bombas ou se existe um que não é bomba, caso seja isso, você perdeu
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

int traduz(char letra){ //Faz a tradução de letras para números, para facilitar o código
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
    char linhac, colunac, colunacc;
    int linha, coluna, opc;

    printf("\n\nDeseja jogar usando os numeros ou as letras do teclado?"); //Aqui o usuario escolhe como quer jogar
    printf("\nDigite (1) para numeros, (2) para letras ou (3) para numeros e letras: ");
    scanf("%d",&opc);
    printf("\n\t\t\tCAMPO MINADO\n");

    if(opc == 2){ //Se ele escolher 2 vem para cá, então ele jogará com letras
        do{
            imprimirl(l,c); //mando para essa função o número de linhas e colunas para ser feito o tabuleiro
            do{
                printf("\nDigite as coordenadas de linha e coluna: "); //Aqui o usuario escolhe a coordenada que quer abrir
                scanf(" %c %c",&linhac,&colunac);

                linha = traduz(linhac); //Mando as duas variaveis para essa função porque são letras, essa função traduz elas para números (a = 0, b = 1, etc), já que o resto do código funciona com números fica mais facil
                coluna = traduz(colunac); 

                if(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1){
                    printf("\nA coordenada eh invalida ou ja esta aberta!"); //verifica se a coordenada escolhida é valida
                }
            }while(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1); //faz enquanto ter coordenadas validas

            abrirNo(linha,coluna,l,c); //Abre a coordenada escolhida
        }while(ganhou(l,c) != 0 && tabuleiro[linha][coluna].EhBOMBA == 0);

        if(tabuleiro[linha][coluna].EhBOMBA){ //se a coordenada escolhida é uma bomba, você perdeu
            printf("\n\tVOCE PERDEU!!!\n");
        }else{
            printf("\n\tPARABENS VOCE GANHOU!!!\n");
        }
        imprimirn(l,c);
    }else if(opc == 1){ //Se ele escolher 1, ele jogará com números
        do{
            imprimirn(l,c); //mando para essa função o número de linhas e colunas para ser feito o tabuleiro
            do{
                printf("\nDigite as coordenadas de linha e coluna: "); //Aqui o usuario escolhe a coordenada que quer abrir
                scanf("%d %d",&linha,&coluna);

                if(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1){
                    printf("\nA coordenada eh invalida ou ja esta aberta!"); //verifica se a coordenada escolhida é valida
                }
            }while(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1); //faz enquanto ter coordenadas validas

            abrirNo(linha,coluna,l,c); //Abre a coordenada escolhida
        }while(ganhou(l,c) != 0 && tabuleiro[linha][coluna].EhBOMBA == 0);

        if(tabuleiro[linha][coluna].EhBOMBA){ //se a coordenada escolhida é uma bomba, você perdeu
            printf("\n\tVOCE PERDEU!!!\n");
        }else{
            printf("\n\tPARABENS VOCE GANHOU!!!\n");
        }
        imprimirn(l,c);
    }else if(opc == 3){ //Se o usuario escolheu 3, ele jogará com números nas linhas e letras nas colunas
        do{
            imprimirnl(l,c); //mando para essa função o número de linhas e colunas para ser feito o tabuleiro
            do{
                printf("\nDigite as coordenadas de linha (numero) e coluna (letra): "); //Aqui o usuario escolhe a coordenada que quer abrir
                scanf("%d",&linha);
                scanf("%c",&colunacc);

                coluna = traduz(colunacc); //Mando somente uma variavel para essa função porque são letras, essa função traduz elas para números (a = 0, b = 1, etc), já que o resto do código funciona com números fica mais facil

                if(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1){
                    printf("\nA coordenada eh invalida ou ja esta aberta!"); //verifica se a coordenada escolhida é valida
                }
            }while(coordenadaValida(linha,coluna,l,c) == 0 || tabuleiro[linha][coluna].ABERTA == 1); //faz enquanto ter coordenadas validas

            abrirNo(linha,coluna,l,c); //Abre a coordenada escolhida
        }while(ganhou(l,c) != 0 && tabuleiro[linha][coluna].EhBOMBA == 0);

        if(tabuleiro[linha][coluna].EhBOMBA){ //se a coordenada escolhida é uma bomba, você perdeu
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
        printf("Escolha a dificuldade:\n"); //Aqui a pessoa escolhe a dificuldade em que quer jogar
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
        inicia(linha,coluna); //Mandamos a pré definição de linhas e colunas escolhidas para essa primeira função
        sortear(linha,coluna,minas); //Depois de iniciar, mandamos para essa
        contarBombas(linha,coluna); //Após sortear as bombas, entramos nessa função
        jogar(linha,coluna); //Finalmente entramos na função do jogo mesmo
        printf("\n\tDeseja jogar novamente?\n\t\t[s/n]\n"); //Aqui caso o usuario deseje jogar novamente é só ele digitar "s", assim ira abrir novamente o menu com as escolhas de dificuldade
        scanf(" %c",&opcao);
    }while(opcao == 's'); //Se for qualquer coisa diferente de "s", ele encerrará o programa

    return 0;
}

int main(){
    jogo(); //função principal do jogo
    return 0;
}