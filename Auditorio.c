#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    PROTOTIPOS
*/


void menu();
void matriz();


/*
    FUNÇÃO PRINCIPAL
*/


void Plateia()
{
    int filas, colunas;

    menu(&filas, &colunas);
    matriz(filas, colunas);
}


/*
    FUNÇÕES SUCUNDARIAS
*/


void menu(int *fil, int *col)
{
    /* MENU DA MATRIZ
    Menu inicial para configurar a plateia
    

    /* Mostra na tela o menu de configurações  */

    
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

        switch(opc)
        {
            case 's':
                return;
            case 'S':
                return;
            case 'n':
                break;
            case 'N':
                break;
            default:
                printf("Opcão invalida!");
            break;
        }


    }
    while(1);

}




void matriz(int filas, int colunas)
{


    /* INICIA A MANIPULAÇÃO DA MATRIZ
    Instancia a matriz na memoria para iniciar sua criação

    Aqui inda estamos editando a mesma e esta pode ser alterada
    Somente mostrara na tela a principio
    
    */


    filas++;
    colunas++;

    // Criando a matriz
    int plateia[filas][colunas];

    // Carrega posição 0 0 da matriz com (-)
    plateia[0][0] = 45;

    int i,j;


    /* A coluna 0 serve para identificar as filas por letra,
    sera carregado o valor de 65 a 90 equivalente A ate Z maiusculas
    na tabela ASCII.
    
    */

    for ( i = 1 ; i < filas; i++ )
    {
        plateia[i][0] = 64 + i;
    }



    /* Carrega a fila 0 com os numeros dos lugares 1,2,3,4 ...    */

    for ( j = 1; j < colunas; j++ )
    {
        plateia[0][j] = j;
    }



    /* Carrega todo o resto da matriz com hufen (-) a partir da posição [1][1]  */ 

    for ( i = 1 ; i < filas; i++ )
    {   
        for ( j = 1; j < colunas; j++ )
        {
            plateia[i][j] = 45;
        }
    }



    /* MOSTRA A TELA A MATRIZ
    A partir daqui começa a mostrar na tela a matriz criada
    depois o intuito eseparar essa parte em uma funçao que so mostrar
    a matriz    */


    /* Preenche o espaço 0 0 com dois pontos */
    printf("%c%c%c%c%c%c%c%c%c%c", 58, 58, 58, 58, 58, 58, 58, 58, 58, 58);


    /* Carrega na tela a  fila 0 onde mostra as o numero das filas */
    for ( j = 1; j < colunas; j++ )
    {   
        printf(" [ - %d - ] ", plateia[ 0 ][ j ]);
    }


    /* Mostra a matriz na tela */
    
    // Laço responsavel por iniciar as fila da matriz
    for ( i = 1 ; i < filas ; i++ )
    {


        // mostar a coluna 0 apresentando as letras respectivas
        printf("\n Fila %c | ", plateia[ i ][ 0 ]); 

        // Laço responsavel por mostrar as colunas da matriz
        for ( j = 1; j < colunas; j++ ) 
        {   
            //printf(" [ %d (%c) ] ",j, plateia[ i ][ j ]);
            printf(" [  (%c)  ] ", plateia[ i ][ j ]);
        }


    }
}

int main()
{
    Plateia();
    return 0;
}