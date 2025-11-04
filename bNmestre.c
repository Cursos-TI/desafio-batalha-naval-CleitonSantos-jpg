#include <stdio.h>
#include <locale.h>

    //Recursividade para mov em diagonal.
void navDiag1 (int tabuleiro [10][10]){
    int i, j;
    for (i=5, j=0; j<3;j++,i++){
        if ((i>4&&i<8)&&(j<4)){
        tabuleiro[i][j]=3;
    }}}

    //Recursividade para mov em diagonal.
void navDiag2 (int tabuleiro[10][10]){
    int i, j;
    for (i=9, j=4; i>6; i--, j++){
        if ((j>3&&j<7)&&(i>6)){
            tabuleiro [i][j]=3;
        }}}
    //Recursividade para marcação especial cone, cruz e octaedro.
void cone (int i, int j, int centro, int alcance, int limite, int tabuleiro2 [10][10]){
    alcance=0;
    for (i=0, limite=3; i< limite; i++){
        for ((j=(centro=2) - (alcance)); j <= centro + alcance; j++){
        if (i<3 && (j>=0 && j<10)){
            tabuleiro2[i][j]=1;
        }} alcance++;
        }}

void cruz (int i, int j, int tabuleiro2 [10][10]){
    for (i=1; i<6; i++){
        for (j=5; j<10; j++){
            if ((j==7 && (i>0 && i<6))|| (i==3 && (j>4 && j<=9))){
                tabuleiro2 [i][j]=1;
            }}}}

void octaedro (int i, int j, int centro, int alcance, int limite, int tabuleiro2 [10][10]){
    alcance=0;
    for (i=4, limite=7; i< limite; i++){
        for ((j=(centro=2) - (alcance)); j <= centro + alcance; j++){
        if (i>3 && i<7 && (j>=0 && j<10)){
            tabuleiro2 [i][j]=1;
        }} alcance++;
        }
    alcance=2;
    for (i=6, limite=9; i<= limite; i++){
        for ((j=(centro=2) + (alcance)); j >= centro - alcance; j--){
        if (i>=6 && i<10 && (j>=0 && j<10)){
            tabuleiro2 [i][j]=1;
        }} alcance--;
        }
}

     //Recursividade do tabuleiro sem marcação.
void tabBra (int linha, int coluna, int i, int j, int tabuleiro [10][10]){
    //Impressao da coluna.
    printf ("  ");
    for (coluna='A'; coluna < 'K'; coluna++){
        printf ("%c ", coluna);
    } printf("\n");

    //impressao da linha
    for (linha='K', i=0; linha < 'U'; linha++, i++){
        printf ("%c ", linha);
        j=0;
        //Impressão do tabuleiro.
    while (j<10){
        tabuleiro [i][j]=0;
        printf ("%d ", tabuleiro[i][j]);
        j++;
    } 
        printf ("\n");
    }}

void navVHD (int linha, int coluna, int i, int j, int tabuleiro[10][10]){
    //Impressao da coluna.
    printf ("  ");
    for (coluna='A'; coluna < 'K'; coluna++){
        printf ("%c ", coluna);
    } printf("\n");

    //impressao da linha
    for (linha='K', i=0; linha < 'U'; linha++, i++){
        printf ("%c ", linha);
        j=0;
        navDiag1(tabuleiro);
        navDiag2(tabuleiro);
        //Logica para impressao dos navios vertical/ horizontal
    while (j<10){
    if ((j==7 && (i==5 || i==6 || i==7))|| (i==3 && (j==2 || j==3 || j==4))){
            tabuleiro[i][j]=3;
        }
        printf ("%d ", tabuleiro[i][j]);
            j++;
    } printf("\n");
    }}

    //Recursividade do tabuleiro com marcações especiais.
void navEsp (int linha, int coluna, int i, int j, int tabuleiro2 [10][10]){
    //Impressao da coluna.
    printf ("  ");
    for (coluna='A'; coluna < 'K'; coluna++){
        printf ("%c ", coluna);
    } printf("\n");

    //impressao da linha
    for (linha='K', i=0; linha < 'U'; linha++, i++){
        printf ("%c ", linha);
        j=0;
        cone(i, j, 2, 0, 3, tabuleiro2);
        cruz(i, j, tabuleiro2);
        octaedro(i, j, 2, 0, 7, tabuleiro2);
        //Impressão do tabuleiro.
    while (j<10){
        printf ("%d ", tabuleiro2[i][j]);
        j++;
    } 
        printf ("\n");
    }} 

int main (){

    //Declaração de variáveis.
    char linha='K', coluna='A';
    int i=0, j=0, opcao1=0, opcao2=0, tabuleiro [10][10]={0}, tabuleiro2 [10][10]={0};

    //Menu de seleção do jogo.
    while (opcao1 < 3){
        if (opcao1==0 || opcao1==2){
    printf ("\n\n***BEM VINDO AO JOGO BATALHA NAVAL***\n\n");
    printf ("1 - COMO O JOGO FUNCIONA.\n");
    printf ("2 - ENTRAR NO JOGO.\n");
    printf ("3 - SAIR DO JOGO.\n\n");
    scanf ("%d", &opcao1);
    } else if (opcao1==1) {
        printf ("\n\n***BEM VINDO AO JOGO BATALHA NAVAL***\n\n");
        printf ("2 - ENTRAR NO JOGO.\n");
        printf ("3 - SAIR DO JOGO.\n\n");
        scanf ("%d", &opcao1);
    }

    //Switch de entrado do jogo.
    switch (opcao1){

        //Funcionamento do jogo.
        case (1):
            printf ("\nA Batalha Naval é um jogo de estratégia e dedução para dois jogadores, "); 
            printf ("cujo objetivo é afundar a esquadra inimiga antes que o adversário destrua a sua.\n\n");
        break;

        //Opções para impressão do jogo.
        case (2):
            printf ("\nSELECIONE A OPÇÃO QUE DESEJA VISUALIZAR.\n\n");
            printf ("1 - VISUALIZAR TABULEIRO EM BRANCO.\n");
            printf ("2 - EXIBIR TABULEIRO COM NAVIOS (VERTICAL/ HORIZONTAL/ DIAGONAIS)\n");
            printf ("3 - EXIBIR TABULEIRO COM MARCAÇÕES ESPECIAIS (CONE/ CRUZ/ OCTAEDRO).\n");
            printf ("4 - RETORNAR AO MENU ANTERIOR.\n");
            printf ("5 - SAIR DO JOGO.\n\n");
            scanf ("%d", &opcao2);
            
            
             
            
    //2º switch para impressão de opções do tabuleiro.
        switch (opcao2){
        //Impressão do tabuleiro em branco.
        case (1):
            tabBra(linha, coluna, i, j, tabuleiro);
            break;

        //Impressão do tabuleiro com navios na horizontal, vertical e diagonais.
        case (2):
            navVHD(linha, coluna, i, j, tabuleiro);
            break;

        //Impressão do tabuleiro com caracteres especiais.
        case (3):
           navEsp(linha, coluna, i, j, tabuleiro2);
           break;
        case (4):
            break;

        default:
        opcao1=3;
            printf ("...SAINDO...");
        break;
        } if (opcao2<5){
            break;
        } else {
            opcao1=3;
            continue;
        }
        //Case para saida do jogo.
        default:
            printf ("...SAINDO...");
        break;}}

    return 0;
}