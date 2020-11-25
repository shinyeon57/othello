#include "Untitled2.h"
#define N 6

int gameboard[N][N];
int turn;

void init_stone(){									//초기조건 
		
		int i,j;
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				gameboard[i][j] = ' ';				//가운데 4칸을 제외하고는 빈칸이다. 
			}
		}
				
		gameboard[N/2-1][N/2-1] = 'O';				//판의 가운데 칸에 대각선 방향으로 각각 같은 돌을 놓는다. 
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
			if(gameboard[row][col] != gameboard[row+i][col+j]){			//뒤집기를 위한 첫 조건: 8방위에 다른 돌이 있다. 
				if((i!=0)&&(j!=0)){
					return 1;											//1개라도있으면다음단계로넘어간다 .단, 같은 칸이 아닐때 
				}														//여기서어떤방향인지그값을받고flip_happen함수에다넣어서확인한후그값을플립함수에넣어서실행시켜야됨	
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
	
	if(flip_happens_first(row, col) == 1){								//바로 옆 8방향에 다른 돌이 한 개 이상 존재한다. 
   	 	for(north=1;north<=row-1;north++){								//입력좌표의 N 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row-1-north][col] == gameboard[row][col])
    			return 1;												//return 1; 플립이 일어난다. 
    	}
    	for(east=1;east<N-col-1;east++){								//입력좌표의 E 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row][col+1+east] == gameboard[row][col])
				return 1;	
		}
		for(south=1;south<N-row-1;south++){								//입력좌표의 S 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row+1+south][col] == gameboard[row][col])
    			return 1;
    	}
        for(west=1;west<=col-1;west++){									//입력좌표의 W 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row][col-1-west] == gameboard[row][col])
    			return 1;
    	}
    	for(north_east=1;north_east<=row-1;north_east++){				//입력좌표의 NE 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row-1-north_east][col+1+north_east] == gameboard[row][col])
    			return 1;
    	}
    	for(north_west=1;north_west<=row-1;north_west++){				//입력좌표의 NW 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row-1-north_west][col-1-north_west] == gameboard[row][col])
    			return 1;
    	}
    	for(south_east=1;south_east<N-row-1;south_east++){				//입력좌표의 SE 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row+1+south_east][col+1+south_east] == gameboard[row][col])
    			return 1;
    	}
    	for(south_west=1;south_west<N-row-1;south_west++){				//입력좌표의 SW 방향위로 같은 돌이 존재한다. ; 
    		if(gameboard[row+1+south_west][col-1-south_west] == gameboard[row][col])
    			return 1;
		}  
		return 2;														//같은 돌이 없으므로 플립이 일어나지 않는다. 
	}
	else
		return 0;														//플립이 일어나지 않는다. 
	
} 


void turnofgame(){						//flip이 되지 않아서 자동으로 다음 turn으로 넘어간다. 
	
	int blank_count =0 , nonflip_count = 0;
	int ch_i, ch_j;						//존재하는 빈칸에 대해 플립이 일어나는 지 확인하기 위한 변수. 
	
	if(turn == 0){														//다 넣어보는거지 일단 빈칸에 흰색 돌을 넣었을 때 플립이 안 일어난다. 
		for(ch_i=0;ch_i<N;ch_i++){
			for(ch_j=0; ch_j<N;ch_j++){
				if(gameboard[ch_i][ch_j] == ' '){
					gameboard[ch_i][ch_j] = 'O';
					blank_count++;						 
					if(flip_happens(ch_i, ch_j) == 1){						//근데 모든 곳에서 플립이 안 일어나야 하는데? 그건 어카냐고,,,,,>하나라도가능하면나가면됨. 
						gameboard[ch_i][ch_j] = ' ';						//원래상태로 되돌려준다. 												//하나라도 플립이 가능하다면 함수를 빠져나간다. 
					}
					else {					//그러면이게먼저생기면어떡하지???????? >>>>>>>>이조건일때continue하고 아니면 break걸고 탈출??? 
						gameboard[ch_i][ch_j] = ' ';						//원래 상태로 되돌려준다. 
						nonflip_count++;
					}
				}		
			}			
		}
		if(blank_count == nonflip_count){
			printf("TURN PASS : FLIPS CAN'T HAPPEN\n");	
			turn = 1;											//turn을 바꿔준다. 
		}				
	}

	else if(turn == 1){
		for(ch_i=0;ch_i<N;ch_i++){
			for(ch_j=0; ch_j<N;ch_j++){
				if(gameboard[ch_i][ch_j] == ' '){
					gameboard[ch_i][ch_j] = 'X';
					blank_count++;
					if(flip_happens(ch_i, ch_j) == 1){																			//근데 모든 곳에서 플립이 안 일어나야 하는데? 그건 어카냐고,,,,,>하나라도가능하면나가면됨. 
						gameboard[ch_i][ch_j] = ' ';						//원래상태로 되돌려준다. 
					}
					else {				
						gameboard[ch_i][ch_j] = ' ';						//원래 상태로 되돌려준다.
						nonflip_count++; 
					}
				}
			}
		}
		if(blank_count == nonflip_count){
			printf("TURN PASS : FLIPS CAN'T HAPPEN\n");			
			turn = 0;											//turn을 바꿔준다.
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
	if((sum_white == 36) || (sum_black == 36)) 		//모든 알이 한가지 색으로 통일 
		return 1;
	else if((sum_white + sum_black) == 36)			//칸이 모두 찼을 때 
		return 1;  
	else
		return 0;									//배치가능한칸이있다 .
	
}
int	isGameEnd(){			//게임종료조건  칸이모두차거나, 모든 알이 한가지 색으로 통일되거나, 양쪽모두 뒤집기 불가능할 때 

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
	if((sum_white == 36) || (sum_black == 36)) 		//모든 알이 한가지 색으로 통일 
		return 1;
	else if((sum_white + sum_black) == 36)			//칸이 모두 찼을 때 
		return 1;  
//	else if(check_flip_happens == 0)										//양쪽 모두 뒤집기가 불가능할때 black과white모두뒤집기가==0일 이거말고 밑에거@@@@@ 
//		return 1; 
//	else
	else*/ if((turn == 0 && flip_happens(i, j) != 1) && (turn == 1 && flip_happens(i, j) != 1))		//양쪽모두뒤집기가불가능할때 
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

