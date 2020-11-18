#include "Untitled2.h"
#define N 6
#define	ROWS  6
#define	COLS  6
int gameboard[N][N];

void init_stone(/*int gameboard[][N]*/){
		
		int i,j;
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				gameboard[i][j] = ' ';
			}
			}
				
		gameboard[N/2-1][N/2-1] = 'O';
		gameboard[N/2-1][N/2] 	= 'X';
		gameboard[N/2][N/2-1] 	= 'X';
		gameboard[N/2][N/2] 	= 'O';
}

void init_othello(/*int gameboard[][N]*/){
        
		int i,j;

	    printf("  0 1 2 3 4 5\n -------------\n");			//number of columns        
        for(i=0;i<N;i++){
             printf("%i|", i);								//number of rows
            for(j=0;j<N;j++)
            {  
                printf("%c|", gameboard[i][j]);
            }
            printf("\n-------------\n");
        }
            
}


int	input__white_blank(){
	
	extern gameboard[N][N];
	
	printf("put a new white othello : %i", gameboard[N][N]);
	scanf("%i", &gameboard[N][N]);
	
}
