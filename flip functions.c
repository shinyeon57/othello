#include "Untitled2.h"
#define N 6

//e w n s ne nw se sw
int flip_white_stone_west(int row, int col)				//flip black stone >>>>> white stone
{
 	
 	int	west ;													//direction : west
 	int j ;													//for flip of west column
	int sum_w=0	;											//the number of flip stones ; west 

    for(west=0;west<col-1;west++){
    		if(gameboard[row][col-1-west] == 'O'){		
            	for(j=0;j<west;j++){
  					if(gameboard[row][col-1-j] == 'X'){
    				gameboard[row][col-1-j] = 'O';			//filp the black stones
            		sum_w++	;									//count the number of flip stones ; west 	
    				}
				}
			}	
	}
	return sum_w;
}

int flip_white_stone_east(int row, int col)						//flip black stone to white stone
{
 	
 	int	east ;														//direction : east
 	int	j	;														//for flip of east column
	int sum_e=0	;													//the number of flip stones ; east 

    for(east=0;east<N-col-1;east++){
    		if(gameboard[row][col+1+east] == 'O'){
            	for(j=0;j<east;j++){
    				if(gameboard[row][col+1+j] == 'X'){
    				gameboard[row][col+1+j] = 'O';						//filp the black stones
   				    sum_e++	;											//count the number of flip stones ; east
				}
    		}
		}
	}
	return sum_e;
}

int flip_white_stone_south(int row, int col)						//flip black stone to white stone
{
 	
 	int	south ;														//direction : south
 	int	i	;														//for flip of south row
	int sum_s=0	;													//the number of flip stones ; south 

    for(south=0;south<N-row-1;south++){
    		if(gameboard[row+1+south][col] == 'O'){
    			for(i=0;i<south;i++){
    				if(gameboard[row+1+i][col] == 'X'){
    				gameboard[row+1+i][col] = 'O';						//filp the black stones
    	            sum_s++	;											//count the number of flip stones ; south
   				}			
			}		
		}
	}
	return sum_s;
}


int flip_white_stone_north(int row, int col)						//flip black stone to white stone
{
 	
 	int	north ;														//direction : north
 	int	i	;														//for flip of north row
	int sum_n=0	;													//the number of flip stones ; north 

    for(north=0;north<N-row-1;north++){
    		if(gameboard[row-1-north][col] == 'O'){
    			for(i=0;i<north;i++){
    				if(gameboard[row-1-north][col] == 'X'){
    				gameboard[row-1-north][col] = 'O';						//filp the black stones
                	sum_n++	;											//count the number of flip stones ; north	
    			}	
			}
		}
	}
	return sum_n;
}

int flip_white_stone_NE(int row, int col)						//flip black stone to white stone
{
 	
 	int	north_east ;														//direction : NE
 	int	i	;														//for flip of NE
	int sum_NE=0	;													//the number of flip stones ; NE 

    for(north_east=0;north_east<N-row-1;north_east++){
    		if(gameboard[row-1-north_east][col+1+north_east] == 'O'){
            	for(i=0;i<north_east;i++){
    				if(gameboard[row-1-i][col+1+i] == 'X'){
    				gameboard[row-1-i][col+1+i] = 'O';						//filp the black stones
    				sum_NE++	;
    			}
			}
		}
	}
	return sum_NE;
}

int flip_white_stone_NW(int row, int col)						//flip black stone to white stone
{
 	
 	int	north_west ;														//direction : NW
 	int	i	;														//for flip of NW
	int sum_NW=0	;													//the number of flip stones ; NW 

    for(north_west=0;north_west<N-row-1;north_west++){
    		if(gameboard[row-1-north_west][col-1-north_west] == 'O'){
            	for(i=0;i<north_west;i++){
    				if(gameboard[row-1-i][col-1-i] == 'X'){
    				gameboard[row-1-i][col-1-i] = 'O';						//filp the black stones
                	sum_NW++	;											//count the number of flip stones ; NW	
    			}
			}
		}
	}
	return sum_NW;
}

int flip_white_stone_SE(int row, int col)						//flip black stone to white stone
{
 	
 	int	south_east ;														//direction : SE
 	int	i	;														//for flip of SE
	int sum_SE=0	;													//the number of flip stones ; SE 

    for(south_east=0;south_east<N-row-1;south_east++){
    		if(gameboard[row+1+south_east][col+1+south_east] == 'O'){
    			for(i=0;i<south_east;i++){
    				if(gameboard[row+1+i][col+1+i] == 'X'){
    				gameboard[row+1+i][col+1+i] = 'O';						//filp the black stones
    	            sum_SE++	;											//count the number of flip stones ; SE
				}
    		}		
		}	
	}
	return sum_SE;
}

int flip_white_stone_SW(int row, int col)						//flip black stone to white stone
{
 	
 	int	south_west ;														//direction : SW
 	int	i	;														//for flip of south SW
	int sum_SW=0	;													//the number of flip stones ; SW 

    for(south_west=0;south_west<N-row-1;south_west++){
    		if(gameboard[row+1+south_west][col-1-south_west] == 'O'){
            	for(i=0;i<south_west;i++){
    				if(gameboard[row+1+south_west][col-1-south_west] == 'X'){
    				gameboard[row+1+south_west][col-1-south_west] = 'O';						//filp the black stones
    	            sum_SW++	;											//count the number of flip stones ; SW
				}
    		}	
		}
	}
	return sum_SW;
}

void flip_white_stone_result(int row, int col){		//흰색돌검은색돌로뒤집고결과출력하기 
	
	printf("	::FLIP RESULT::		\nE = %d, W = %d, S = %d, N = %d, SE = %d, SW = %d, NE = %d, NW = %d\n", flip_white_stone_east(row,col),
	flip_white_stone_west(row,col), flip_white_stone_south(row,col),flip_white_stone_north(row,col),
	flip_white_stone_SE(row,col),flip_white_stone_SW(row,col),flip_white_stone_NE(row,col),flip_white_stone_NW(row,col));
	
} 
