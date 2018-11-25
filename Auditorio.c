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

    int filas, colunas;
    char opc;

    tamanhoDaMatriz(&filas, &colunas);
    criarMatriz(filas, colunas);

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




void criarMatriz(int filas, int colunas)    // Onde esta os corredores ?
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



    /*
        Peguntar se a matriz esta correta ? (Case MATRIZ)
        Sim,    Pergunta se deseja adicionar corredores ? (Case CORREDORES)
                Sim,    Iniciar a edição dos corredores 
                Não,    Salva a matriz
        
        Não,    Retorna ao inicio
    */ 

    do
    {

        printf("\nMatriz esta correta ? ");
        
        scanf("%s%*c", &opc);
        

        switch(opc)
        {

            /*
                Inicio do case MATRIZ
            */

            case 's':
            case 'S':
                
                printf("\n\nDeseja adicionar corredores ? ");

                scanf("%s%*c", &opc);
                fflush(stdin);

                    /*
                        Inicio do case CORREDORES
                    */
                    
                    switch(opc)
                    {
                        case 's':
                        case 'S':
                            /*  Chama a função de editar a matriz   */      printf(" FUNÇÃO EDIÇÃO ");
                            break;

                        case 'n':
                        case 'N':
                            /*  Chama a função de gravar os dados   */      printf(" GRAVAR DADOS ");
                            return;

                        default:
                            printf("Opcão invalida!");
                            break;
                    }

                    /*
                        Fim do case CORREDORES
                    */

            return;

            /*
                Fim do case MATRIZ
            */

            case 'n':
            case 'N':
                Plateia();      /*  Volta ao inicio para inserir novamente a matriz   */
                break;

            default:
                printf("Opcão invalida!");
                break;
        }


    }
    while(1);

}


/*
    Criar uma função que recebe como parametro a matriz para ser guardada e instacia um struct
*/



int main()
{
    Plateia();
    return 0;
}