#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define CORREDOR 33
//#define CORREDOR 35



void Plateia()
{

    /* MENU DA MATRIZ
    Menu iniciar para configurar a plateia
    
    */
    int filas, colunas, opc, cont;

    /* Mostra na tela o menu de configurações  */

    do
    {
        printf("CONFIGURAÇÕES! \n");
        printf("Favor informar quantas filas : ");
        scanf("%d%*c", &filas);
        printf("Favor informar quantas colunas : ");
        scanf("%d%*c", &colunas);

        printf("Dados estão corretos ? (1 - Sim / 0 - Não)");
        printf("\n");
        scanf("%d%*c", &opc);
    }
    while(opc != 1);


    /* INICIA A MANIPULAÇÃO DA MATRIZ
    Instancia a matriz na memoria para iniciar sua criação
    Aqui inda estamos editando a mesma e esta pode ser alterada
    Somente mostrara na tela a principio
    
    */

    opc = 255;
    filas++;
    colunas++;




    /* MOSTRA A TELA A MATRIZ
    A partir daqui começa a mostrar na tela a matriz criada
    depois o intuito eseparar essa parte em uma funçao que so mostrar
    a matriz    */


//    int i,j;








    // /* Preenche o espaço 0 0 com dois pontos */
    // printf("%c%c%c%c%c%c%c%c%c%c", 58, 58, 58, 58, 58, 58, 58, 58, 58, 58);


    // /* Carrega na tela a  fila 0 onde mostra as o numero das filas */
    // for ( j = 1; j < colunas; j++ )
    // {   
    //     printf(" [ - %d - ] ", j );
    // }


    // /* Mostra a matriz na tela */
    
    // // Laço responsavel por iniciar as fila da matriz
    // for ( i = 65 ; i < filas + 65 ; i++ )
    // {


    //     // mostar a coluna 0 apresentando as letras respectivas
    //     printf("\n Fila %c | ",  i ); 

    //     // Laço responsavel por mostrar as colunas da matriz
    //     for ( j = 1; j < colunas; j++ ) 
    //     {   
    //         //printf(" [ %d (%c) ] ",j, plateia[ i ][ j ]);
    //         printf(" [  (-)  ] ");
    //     }


    // }











    // /* INICIO DA EDIÇÃO DA MATRIZ
    
    // */

    // /* Aqui é onde é possivel editar a matriz para inserir e redimencionar o corredores
    // Esta é a parte do menu
    // */

    // int ass_fi,ass_ff,ass_ci,ass_cf;

    // //volta:

    // printf("Opcs especiais! \n");
    // printf("1 - Add corredor vetical \n");
    // printf("2 - Add corredor horizontal \n");
    // printf("3 - Selecionar lugares de deficientes \n");
    // printf("0 - salvar informacoes \n");

    // scanf("%d%*c", &opc);

    // switch(opc)
    // {
    //     case 0:
    //     break;

    //     case 1:
    //     printf(" Quantos corredores ?");
    //     scanf("%d%*c", &cont);
    //     printf("Em qual coluna ?");
    //     scanf("%d%*c", &opc);
    //     colunas++;
    //     //inserirCorredorVertical(opc);
    //     //goto newPlateia;
    //     break;

    //     case 2:
    //     printf("Em qual fila ?");
    //     scanf("%d%*c", &opc);
    //     //inserirCorredorHorizontal(opc);
    //     //goto corredorHorizontal;
    //     break;

    //     case 3:
    //     printf("Selecionar assento fila inicial ?");
    //     scanf("%d%*c", &ass_fi);
    //     printf("Selecionar assento coluna inicial?");
    //     scanf("%d%*c", &ass_ci);
    //     printf("Selecionar assento fila inicial ?");
    //     scanf("%d%*c", &ass_ff);
    //     printf("Selecionar assento coluna final?");
    //     scanf("%d%*c", &ass_cf);
    //     //inserirLugaresParaDef(ass_fi,ass_cf,ass_ff,ass_cf);
    //     break;

    //     default:
    //     //goto volta;
    //     break;

    // }



    // Criando a matriz
    int plateia[filas][colunas];


    // Carrega posição 0 0 da matriz com (-)
    plateia[0][0] = 45;


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
        if (i == opc) {
            plateia[0][i] = CORREDOR;
        }
        
        else
        {
            plateia[0][i] = j;
        }
    }


    /* Carrega todo o resto da matriz com hufen (-) a partir da posição [1][1]  */ 

    for ( i = 1 ; i < filas; i++ )
    {   
        for ( j = 1; j < colunas; j++ )
        {
            
            if ( i == opc ) 
            {
                plateia[i][j] = CORREDOR;
            
            else
            {
                plateia[i][j] = 45;
            }
            

        }
    }

    /* Fim da parte de criação inicial da matriz
    
    */




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


    /* 

            |  Coluna 1 |  Coluna 2 | 
    Fila A  |  Lugar    |  Lugar    |

    */



    /* Salvar a matriz inicial
    
    */



    // digitarOpc:

    // printf("Salvar as informções ? (1 - Sim / 0 - Não)");
    // printf("\n");
    // scanf("%d%*c", &opc);

    // switch(opc)
    // {
    //     case 1:
    //     //system("clear");
    //     printf("Informações salvas com sucesso!");
    //     // goto Menu();
    //     break;

    //     case 0:
    //     // goto telaDeConfiguracoes();
    //     break;

    //     default:
    //     printf("Opção Invalida!");
    //     goto digitarOpc;
    // }

//     // registrarPlateia(plateia);
//     // REGISTRAR OS DADOS






































//     /* Parte da edição da matriz onde sera inserido os corredores
    
//     */


//     /* LOGICA DO ALGORITIMO

//     criar uma matriz maior para inserir o corredor
//     transferir os dados da matriz anterior
//     prencher com o corredor 
    
//     */

//     // corrredorVertical:

//     // int temp;    

//     // /* craindo matriz maior 
    
//     // */

//     // colunas++; // incrementa a variavel filas para aumentar o tamanho

//     // int newPlateia[filas][colunas]; //nova matriz



//     // /* inicio da transferencia 
    
//     // */


//     // // Carrega posição 0 0 da matriz com (-)
//     // newplateia[0][0] = 45;


//     // /* A coluna 0 serve para identificar as filas por letra,
//     // sera carregado o valor de 65 a 90 equivalente A ate Z maiusculas
//     // na tabela ASCII.
    
//     // */

//     // for ( i = 1 ; i < filas; i++ )
//     // {
//     //     plateia[i][0] = 64 + i;
//     // }






//     // /* Carrega a fila 0 com os numeros dos lugares 1,2,3,4 ...    */


//     // for ( j = 1; j < colunas; j++ )
//     // {
        
//     //     if (i == opc) {
//     //         Plateia[0][i] = CORREDOR;
//     //     }
        
//     //     else
//     //     {
//     //         Plateia[0][i] = j;
//     //     }

//     // }




//     // /* Carrega todo o resto da matriz com hufen (-) a partir da posição [1][1]  */ 

//     // for ( i = 1 ; i < filas; i++ )
//     // {   
//     //     for ( j = 1; j < colunas; j++ )
//     //     {
//     //         plateia[i][j] = 45; 
//     //     }
//     // }

    

// }


// // Plateia()
// // {
// //     menuInicialPlateia();

// // }

int main()
{
    Plateia();
    return 0;
}