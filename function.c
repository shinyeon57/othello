#include "Untitled2.h"
#define N 6

int gameboard[N][N];
int turn;

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
		return 0;
	}
}

int flip_happens_first(int row, int col){
	
	int i,j	; 	
	
	for(i=-1;i<2;i++){
		for(j=-1;j<2;j++){
			if(gameboard[row][col] != gameboard[row+i][col+j]){			//�����⸦ ���� ù ����: 8������ �ٸ� ���� �ִ�. 
				if((i!=0)&&(j!=0)){
					return 1;											//1��������������ܰ�γѾ�� .��, ���� ĭ�� �ƴҶ� 
				}														//���⼭����������װ����ް�flip_happen�Լ����ٳ־Ȯ�����ıװ����ø��Լ����־������Ѿߵ�	
			}
			else{
			return 0;
			}
		}
	}
				
}

int flip_happens(int row, int col)
{
	int i,j;
	int north,south,east,west,north_east,north_west,south_east,south_west;
	
	if(flip_happens_first(row, col) == 1){								//�ٷ� �� 8���⿡ �ٸ� ���� �� �� �̻� �����Ѵ�. 
   	 	for(north=1;north<=row-1;north++){								//�Է���ǥ�� N �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row-1-north][col] == gameboard[row][col])
    			return 1;												//return 1; �ø��� �Ͼ��. 
    	}
    	for(east=1;east<N-col-1;east++){								//�Է���ǥ�� E �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row][col+1+east] == gameboard[row][col])
				return 1;	
		}
		for(south=1;south<N-row-1;south++){								//�Է���ǥ�� S �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row+1+south][col] == gameboard[row][col])
    			return 1;
    	}
        for(west=1;west<=col-1;west++){									//�Է���ǥ�� W �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row][col-1-west] == gameboard[row][col])
    			return 1;
    	}
    	for(north_east=1;north_east<=row-1;north_east++){				//�Է���ǥ�� NE �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row-1-north_east][col+1+north_east] == gameboard[row][col])
    			return 1;
    	}
    	for(north_west=1;north_west<=row-1;north_west++){				//�Է���ǥ�� NW �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row-1-north_west][col-1-north_west] == gameboard[row][col])
    			return 1;
    	}
    	for(south_east=1;south_east<N-row-1;south_east++){				//�Է���ǥ�� SE �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row+1+south_east][col+1+south_east] == gameboard[row][col])
    			return 1;
    	}
    	for(south_west=1;south_west<N-row-1;south_west++){				//�Է���ǥ�� SW �������� ���� ���� �����Ѵ�. ; 
    		if(gameboard[row+1+south_west][col-1-south_west] == gameboard[row][col])
    			return 1;
		}  
		return 2;														//���� ���� �����Ƿ� �ø��� �Ͼ�� �ʴ´�. 
	}
	else
		return 0;														//�ø��� �Ͼ�� �ʴ´�. 
	
} 


void turnofgame(){						//flip�� ���� �ʾƼ� �ڵ����� ���� turn���� �Ѿ��. 
	
	int blank_count =0 , nonflip_count = 0;
	int ch_i, ch_j;						//�����ϴ� ��ĭ�� ���� �ø��� �Ͼ�� �� Ȯ���ϱ� ���� ����. 
	
	if(turn == 0){														//�� �־�°��� �ϴ� ��ĭ�� ��� ���� �־��� �� �ø��� �� �Ͼ��. 
		for(ch_i=0;ch_i<N;ch_i++){
			for(ch_j=0; ch_j<N;ch_j++){
				if(gameboard[ch_i][ch_j] == ' '){
					gameboard[ch_i][ch_j] = 'O';
					blank_count++;						 
					if(flip_happens(ch_i, ch_j) == 1){						//�ٵ� ��� ������ �ø��� �� �Ͼ�� �ϴµ�? �װ� ��ī�İ�,,,,,>�ϳ��󵵰����ϸ鳪�����. 
						gameboard[ch_i][ch_j] = ' ';						//�������·� �ǵ����ش�. 												//�ϳ��� �ø��� �����ϴٸ� �Լ��� ����������. 
					}
					else {					//�׷����̰Ը������������???????? >>>>>>>>�������϶�continue�ϰ� �ƴϸ� break�ɰ� Ż��??? 
						gameboard[ch_i][ch_j] = ' ';						//���� ���·� �ǵ����ش�. 
						nonflip_count++;
					}
				}		
			}			
		}
		if(blank_count == nonflip_count){
			printf("TURN PASS : FLIPS CAN'T HAPPEN\n");	
			turn = 1;											//turn�� �ٲ��ش�. 
		}				
	}

	else if(turn == 1){
		for(ch_i=0;ch_i<N;ch_i++){
			for(ch_j=0; ch_j<N;ch_j++){
				if(gameboard[ch_i][ch_j] == ' '){
					gameboard[ch_i][ch_j] = 'X';
					blank_count++;
					if(flip_happens(ch_i, ch_j) == 1){																			//�ٵ� ��� ������ �ø��� �� �Ͼ�� �ϴµ�? �װ� ��ī�İ�,,,,,>�ϳ��󵵰����ϸ鳪�����. 
						gameboard[ch_i][ch_j] = ' ';						//�������·� �ǵ����ش�. 
					}
					else {				
						gameboard[ch_i][ch_j] = ' ';						//���� ���·� �ǵ����ش�.
						nonflip_count++; 
					}
				}
			}
		}
		if(blank_count == nonflip_count){
			printf("TURN PASS : FLIPS CAN'T HAPPEN\n");			
			turn = 0;											//turn�� �ٲ��ش�.
			present_state_othello();
		}
	} 
} 

int	blankstate(){
	
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
	else
		return 0;									//��ġ������ĭ���ִ� .
	
}
int	isGameEnd(){			//������������  ĭ�̸�����ų�, ��� ���� �Ѱ��� ������ ���ϵǰų�, ���ʸ�� ������ �Ұ����� �� 

	int	i,j;
/*	int sum_white = 0;		//sum of stone
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
//	else if(check_flip_happens == 0)										//���� ��� �����Ⱑ �Ұ����Ҷ� black��white��ε����Ⱑ==0�� �̰Ÿ��� �ؿ���@@@@@ 
//		return 1; 
//	else
	else*/ if((turn == 0 && flip_happens(i, j) != 1) && (turn == 1 && flip_happens(i, j) != 1))		//���ʸ�ε����Ⱑ�Ұ����Ҷ� 
			return 1;
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

