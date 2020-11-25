#include <stdio.h>
#define N 6

int	gameboard[N][N];
int turn;

void	init_stone();			//initial stone state
void	init_othello();			//initial state of blank
void    count_stone();			//count the stone
void 	present_state_othello();

int flip_white_stone_west(int row, int col);
int flip_white_stone_east(int row, int col);
int flip_white_stone_south(int row, int col);
int flip_white_stone_north(int row, int col);
int flip_white_stone_NE(int row, int col);
int flip_white_stone_NW(int row, int col);
int flip_white_stone_SE(int row, int col);
int flip_white_stone_SW(int row, int col);

int flip_black_stone_west(int row, int col);
int flip_black_stone_east(int row, int col);
int flip_black_stone_south(int row, int col);
int flip_black_stone_north(int row, int col);
int flip_black_stone_NE(int row, int col);
int flip_black_stone_NW(int row, int col);
int flip_black_stone_SE(int row, int col);
int flip_black_stone_SW(int row, int col);

int flip_happens_first(int row, int col);
int flip_happens(int row, int col);
void flip_white_stone_result(int row, int col);
void flip_black_stone_result(int row, int col);

int check_invalid_input(int row, int col);			//checking invalid input 
void check_result(); 								//check the winner
int	isGameEnd();									//game end condition
int	blankstate();
void turnofgame();									//뒤집을 수 없을 때 자동으로  turn하는 함수 
