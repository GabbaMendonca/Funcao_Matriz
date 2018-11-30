#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "_Terminal.h"

#define CRIAR_MATRIZ criarMatriz ( filas, colunas, &cVertical, numCorredorVer, &cHorizontal, numCorredorHor );

/*
    PROTOTIPOS
*/


void tamanhoDaMatriz();
void criarMatriz();
void inseriCorredor();


/*
    FUNÇÃO PRINCIPAL
*/


void Plateia()
{

    int opcao,
        filas          , colunas,
        cVertical  [10], numCorredorVer,
        cHorizontal[10], numCorredorHor;
        
        
        filas          = 0;
        colunas        = 0;
        opcao          = 0;
        numCorredorVer = 0;
        numCorredorHor = 0;


    tamanhoDaMatriz (&filas, &colunas);
    CRIAR_MATRIZ

    /*
        Perguntar se quer salvar os dados ?
        Perguntar se quer editar o projeto atual ?

        Perguntar se quer add corredores verticais ?
        Perguntar se quer add corredores horizontais ?

        Se deseja abandonar o projeto ?

        EXCLUIR UM CORREDOR'
    */

    do
    {
        // LIMPA_TERM
        // CRIAR_MATRIZ

        printf("\n\n    (1) >>> Salvar o projeto ?");
        printf(  "\n    (2) >>> Redimencionar o projeto atual ?");

        printf("\n\n    (3) >>> Adicionar corredor vertical ?");
        printf(  "\n    (4) >>> Adicionar corredor horizontal ?");

        printf("\n\n    (5) >>> Abandinar o projeto ?");

    
    
        printf("\n\n    Digite a opcao : ");
        scanf("%d%*c", &opcao);
        fflush(stdin);

        
        switch (opcao)
        {
            case 1:
                printf("SALVA OS DADOS ATUAIS");
                break;

            case 2:
                Plateia();
                break;

            case 3:
            
                CRIAR_MATRIZ
                inseriCorredor (&cVertical, &numCorredorVer);

                colunas = colunas + numCorredorVer;
                CRIAR_MATRIZ
                break;
        
            case 4:

                CRIAR_MATRIZ
                inseriCorredor (&cHorizontal, &numCorredorHor);

                filas = filas + numCorredorHor;
                CRIAR_MATRIZ
                break;

            case 5:
                printf("SAIR - VAI CHAMAR O MENU DE ADM");
                break;

            default:
                printf("Valor invalido \n");
                //opcao = 0;
                break;
        }

    } while (1); //while (opcao = 0);

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




void criarMatriz(   int filas       , int colunas,
                    int *cVertical  , int numCorredorVer,
                    int *cHorizontal, int numCorredorHor    ) // Onde esta os corredores ?, Edição/Gravação
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
            if (numCorredorVer != 0 || numCorredorHor !=0 )
            {
                
                for ( int k = 0; k < numCorredorVer; k++)
                {
                    if (cVertical[k] == j)
                    {
                        plateia[i][j] = 64; // corredor
                        goto FIM;
                    }
                }
                for ( int l = 0; l < numCorredorHor; l++)
                {
                    if (cHorizontal[l] == i)
                    {
                        plateia[i][j] = 45; // corredor
                        goto FIM;
                    }
                }

                plateia[i][j] = 32; // lugar vazio
            }
            else
            {
                plateia[i][j] = 32; // lugar vazio
            }
            
            FIM:
            continue;
        }
    }


    /* 
        MOSTRA NA TELA A MATRIZ
        A partir daqui começa a mostrar na tela a matriz criada
        depois o intuito e separar essa parte em uma funçao que so mostra
        a matriz
    */

    LIMPA_TERM
    
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


void inseriCorredor(int *vetorCorredor, int *numCorredores)
{

    int i;

    printf("\nQuantos corredores deseja inserir ? ");
    scanf("%d%*c", &*numCorredores);

    for ( i = 0; i < *numCorredores; i++ )
    {
        printf("Digite a fila do %d corredor : ", i+1);
        scanf("%d%*c", &vetorCorredor[i]);
    }

}



int main()
{
    Plateia();
    return 0;
}