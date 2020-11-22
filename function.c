#include "Untitled2.h"
#define N 6

int gameboard[N][N];

void init_stone(){									//�ʱ����� 
		
		int i,j;
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				gameboard[i][j] = ' ';				//��� 4ĭ�� �����ϰ�� ��ĭ�̴�. 
			}
		}
				
		gameboard[N/2-1][N/2-1] = 'O';				//���� ��� ĭ�� �밢�� �������� ���� ���� ���� ���´�. 
		gameboard[N/2-1][N/2] 	= 'X';
		gameboard[N/2][N/2-1] 	= 'X';
		gameboard[N/2][N/2] 	= 'O';
}

/*void init_othello(){
        
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
} */

void count_stone(){
	
	int	i,j;
	int sum_white = 0;							//sum of stone
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

int	check_invalid_input(int row, int col){
	

	if((col >= 6)||(row >= 6) ){
		printf("\ninvalid input! : should be less than 6\n");		//invalid input ; input's size
		return 1;
	}
	else if(gameboard[row][col] != ' '){
		printf("\ninvalid input! : already occupied\n");			//invalid input ; already occupied 
		return 1;
	}
	else{
		gameboard[row][col] = 'O';
		return 0;
	}
//	else if(/*flip == 0*/)
//		printf("invalid input! : no flips happen\n");
}

int flip_happens_first(int row, int col){
	
	int i,j	; 	
	int i_,j_;
	
	for(i=-1;i<2;i++){
		for(j=-1;j<2;j++){
			if(gameboard[row][col] != gameboard[row+i][col+j])	//		//8������ �ٸ� ���� �ִ�. 
			return 1;
			else
			return 0;
		}
	}
				
}

int flip_happens(int row, int col)
{
	int i,j;
	int north,south,east,west,north_east,north_west,south_east,south_west;
	
	if(flip_happens_first(row, col) == 1){
   	 	for(north=0;north<N-row-1;north++){
    		if(gameboard[row-1-north][col] == gameboard[row][col])
    			return 1;
    	}
    	for(east=0;east<N-col-1;east++){
    		if(gameboard[row][col+1+east] == gameboard[row][col])
				return 1;	
		}
		for(south=0;south<N-row-1;south++){
    		if(gameboard[row+1+south][col] == gameboard[row][col])
    			return 1;
    	}
        for(north=0;north<N-row-1;north++){
    		if(gameboard[row-1-north][col] == gameboard[row][col])
    			return 1;
    	}
    	for(north_east=0;north_east<N-row-1;north_east++){
    		if(gameboard[row-1-north_east][col+1+north_east] == gameboard[row][col])
    			return 1;
    	}
    	for(north_west=0;north_west<N-row-1;north_west++){
    		if(gameboard[row-1-north_west][col-1-north_west] == gameboard[row][col])
    			return 1;
    	}
    	for(south_east=0;south_east<N-row-1;south_east++){
    		if(gameboard[row+1+south_east][col+1+south_east] == gameboard[row][col])
    			return 1;
    	}
    	for(south_west=0;south_west<N-row-1;south_west++){
    		if(gameboard[row+1+south_west][col-1-south_west] == gameboard[row][col])
    			return 1;
		}
	}
	else
		return 0;	
	
} 

/*int turnofgame(){						//game��  �������ϱ� 
	
	if()
		return 0;						//white's turn
	else if()
		return 1; 						//black's turn
} */

int	isGameEnd(){			//������������  ĭ�̸�����ų�, ��� ���� �Ѱ��� ������ ���ϵǰų�, ���ʸ�� ������ �Ұ����� �� 

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
	if((sum_white == 36) || (sum_black == 36)) 		//��� ���� �Ѱ��� ������ ���� 
		return 1;
	else if((sum_white + sum_black) == 36)			//ĭ�� ��� á�� �� 
		return 1; 
	//else if(check_flip_happens == 0)										//���� ��� �����Ⱑ �Ұ����Ҷ� 
	//	return 1; 
	else
		return 0; 
}
void	check_result(){
	
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
	
	printf("\n*THE FINAL RESULT : WHITE = %i ,BLACK = %i \n", sum_white, sum_black);		//the final result of stone's status
	
	if(sum_black > sum_white)								//black stone > white stone ; black is winner
	printf("*THE WINNER IS BLACK\n");
	else if(sum_white > sum_black)							//white stone > black stone ; white is winner
	printf("*THE WINNER IS WHITE\n");

}

