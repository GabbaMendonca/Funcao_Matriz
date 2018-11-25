#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    PROTOTIPOS
*/


void tamanhoDaMatriz();
void criarMatriz();


/*
    FUNÇÃO PRINCIPAL
*/


void Plateia()
{

    int filas, colunas, opcao;

    tamanhoDaMatriz(&filas, &colunas);
    criarMatriz(filas, colunas);

    /*
        Perguntar se quer salvar os dados ?
        Perguntar se quer editar o projeto atual ?

        Perguntar se quer add corredores verticais ?
        Perguntar se quer add corredores horizontais ?

        Se deseja abandonar o projeto ?
    */

    printf("\n\n    (1) >>> Salvar o projeto ?");
    printf(  "\n    (2) >>> Redimencionar o projeto atual ?");

    printf("\n\n    (3) >>> Adicionar corredor vertical ?");
    printf(  "\n    (4) >>> Adicionar corredor horizontal ?");

    printf("\n\n    (5) >>> Abandinar o projeto ?");

    do
    {
        printf("\n\n    Digite a opcao : ");
        scanf("%d%*c", &opcao);
        fflush(stdin);

        
        switch (opcao)
        {
            case 1:
                printf("SALVA OS DADOS ATUAIS");
                break;

            case 2:
                printf("EDITA O PRJETO");
                break;

            case 3:
                printf("VERTICAL");
                break;
        
            case 4:
                printf("HORIZONTAL");
                break;

            case 5:
                printf("SAIR");
                break;

            default:
                printf("Valor invalido \n");
                break;
        }

    } while (1);
}


/*
    FUNÇÕES SUCUNDARIAS
*/


void tamanhoDaMatriz(int *fil, int *col)
{

    /* 
        MENU DA MATRIZ
        Menu inicial para configurar a plateia
    */

    
    do
    {
    
        printf("CONFIGURAÇÕES! \n");

        printf("Favor informar quantas filas : ");
        scanf("%d%*c", &*fil);

        printf("Favor informar quantas colunas : ");
        scanf("%d%*c", &*col);


        printf("Dados estão corretos ? ( S / N ) : ");

        char opc;
        opc = getchar();
        fflush(stdin);

        switch(opc)
        {
            case 's':
            case 'S':
                return;

            case 'n':
            case 'N':
                break;

            default:

                printf("Opcão invalida!");
                break;
        }

    }
    while(1);

}




void criarMatriz(int filas, int colunas)    // Onde esta os corredores ?, Edição/Gravação
{

    /* 
        INICIA A MANIPULAÇÃO DA MATRIZ
        Instancia a matriz na memoria para iniciar sua criação

        Aqui ainda estamos editando a mesma e esta pode ser alterada
        Somente mostrara na tela a principio
    */


    filas++;
    colunas++;

    char opc;
    int i,j;

    int plateia[filas][colunas];



    plateia[0][0] = 45;             // Carrega posição 0 0 da matriz com (-)

    /* 
        A coluna 0 serve para identificar as filas por letra,
        sera carregado o valor de 65 a 90 equivalente A ate Z maiusculas
        na tabela ASCII.
    */

    for ( i = 1 ; i < filas; i++ )
    {
        plateia[i][0] = 64 + i;
    }



    /*
        Carrega a fila 0 com os numeros dos lugares 1,2,3,4 ...
    */
    for ( j = 1; j < colunas; j++ )
    {
        plateia[0][j] = j;
    }



    /*
        Carrega todo o resto da matriz com hufen (-) a partir da posição [1][1] 
    */ 
    for ( i = 1 ; i < filas; i++ )
    {   
        for ( j = 1; j < colunas; j++ )
        {
            plateia[i][j] = 45;
        }
    }



    /* 
        MOSTRA NA TELA A MATRIZ
        A partir daqui começa a mostrar na tela a matriz criada
        depois o intuito e separar essa parte em uma funçao que so mostra
        a matriz
    */


    /*  
        Preenche o espaço 0 0 com dois pontos
    */
    printf("%c%c%c%c%c%c%c%c%c%c", 58, 58, 58, 58, 58, 58, 58, 58, 58, 58);


    /*
        Carrega na tela a fila 0 onde mostra o numero das filas
    */
    for ( j = 1; j < colunas; j++ )
    {   
        printf(" [ - %d - ] ", plateia[ 0 ][ j ]);
    }


    /* 
        Mostra a matriz na tela
    */

    /*
        Laço responsavel por mostrar as fila da matriz
    */
    for ( i = 1 ; i < filas ; i++ )
    {

        /*
            Mostar a coluna 0 apresentando as letras respectivas
        */
        printf("\n Fila %c | ", plateia[ i ][ 0 ]); 
        

        /*
            Laço responsavel por mostrar as colunas da matriz
        */
        for ( j = 1; j < colunas; j++ ) 
        {   
            printf(" [  (%c)  ] ", plateia[ i ][ j ]);
        }

    }



    
}


/*
    Criar uma função que recebe como parametro a matriz para ser guardada e instacia um struct
*/



int main()
{
    Plateia();
    return 0;
}