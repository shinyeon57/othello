#include <stdio.h>
#define N 6

int	gameboard[N][N];
void	init_stone();			//initial stone state
void	init_othello();			//initial state of blank
void    count_stone();			//count the stone
//void	input__white_stone();	//input the position of white stone
//void	input__white_stone();	//input the positon of black stone
void present_state_othello();
void flip_white_stone_west(int row, int col);
void flip_white_stone_east(int row, int col);
void flip_white_stone_south(int row, int col);
void flip_white_stone_north(int row, int col);
void flip_white_stone_NE(int row, int col);
void flip_white_stone_NW(int row, int col);
void flip_white_stone_SE(int row, int col);
void flip_white_stone_SW(int row, int col);
void	check_invalid_input(int row, int col);	//checking invalid input 
