#include "Untitled2.h"
#define N 6
#define	ROWS  6
#define	COLS  6
int gameboard[N][N];

void init_stone(){
		
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

void init_othello(){
        
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
        
		printf("WHITE : O , BLACK : X\n");    
}

void count_stone(){
	
	int	i,j;
	int sum_white = 0;		//sum of stone
	int	sum_black = 0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(gameboard[i][j]=='O')			//white stone: count up
				sum_white += 1;					
			else if(gameboard[i][j]=='X')		//black stone: count up
				sum_black += 1;					
		}
	}
	
	printf("\nSTATUS : WHITE = %i ,BLACK = %i\n", sum_white, sum_black);		//print the status of stone
	
}

/*void	input__white_stone(){	//input the positon of white stone
	
	int	row,col;
	
	printf("put a new white othello : ");							
	scanf("%i%i", &row, &col);
	
} 

void	input__black_stone(){	//input the positon of black stone
 
 	int	row,col;
	
	printf("put a new black othello : ");
	scanf("%i%i", &row, &col);
} */

/*void new_board(){
		
		int i,j;
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				gameboard[i][j] = ' ';
			}
		}
			
} */


void present_state_othello(){
        
		int i,j;

	    printf("  0 1 2 3 4 5\n -------------\n");			//number of columns        
        for(i=0;i<N;i++){
             printf("%i|", i);								//number of rows
            for(j=0;j<N;j++)
            {  
                printf("%c|", gameboard[i][j]);				//present state of each blank
            }
            printf("\n-------------\n");
        }
        
		printf("WHITE : O , BLACK : X\n");   
		count_stone(); 										//print the present status
}

void	check_invalid_input(int row, int col){
	

	if((col >= 6)||(row >= 6) )
		printf("\ninvalid input! : should be less than 6\n");		//invalid input ; input's size
	else if(gameboard[row][col] != ' ')
		printf("\ninvalid input! : already occupied\n");			//invalid input ; already occupied 
	else
		gameboard[row][col] = 'O';

//	else if(/*flip == 0*/)
//		printf("invalid input! : no flips happen\n");
}

void	check_flip_happens(){
	
}

