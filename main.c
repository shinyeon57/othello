#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.h"
#define	N  6		//number of space 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];		
int	turn		;	 						//플레이어 순서를 위한 변수 
int main(int argc, char *argv[]) {
	
	int i,j;									//2차원 배열의 변수 //필요한 변수 선언
	int row,col;								//입력받은돌의위치를위한변수 
//	int turn = 0;								//black & white turn 정하기 =0:white, =1:black
	turn = 0 ;									//흰색 돌의 player가 먼저 시작한다. 
	init_stone();								//initial stone state
	//-----------------------------------------------------------------------------------------initial state 
	while(isGameEnd()==0){						//game종료조건확인
		present_state_othello();					//현재배치상태 
		if(blankstate()==0)	{				//배치가능한칸확인 빈칸이있어야하고뒤집기가가능해야됨 ????/게임종료조건이랑같음
			//turnofgame();							//뒤집을 수 없을 때 turn이 자동으로 돌아간다.  		present_state_othello()넣어줘야됨.			
					if(turn == 0){							//turn of white
					printf("\nPUT A NEW WHITE STONE : ");	//배치할좌표입력받기_white //print_othello()//배치상태출력등
					scanf("%i%i", &row, &col);
						if(check_invalid_input(row, col) == 0){				//checing invalid input ; when check_invalid_input == 0 > valid input 	
							gameboard[row][col] = 'O';							//flip_first를 위해서 일단 돌을 위치시켜준다? 대신 유효입력확인한후에		
							if(flip_happens(row, col) == 1){				//FLIP THE STONES
															//몇개뒤집었는지출력하고 턴바꿔주기 
									flip_white_stone_result(row,col);		  	//뒤집고 뒤집은 결과 화면에 출력 
									turn = 1; 									//뒤집은 후 다음 턴으로 돌아가기 
									//present_state_othello(); 
							} 
							else{
									printf("\ninvalid input! : no flips happen\n");	//뒤집을 수 없으므로 invalid input이다 
									gameboard[row][col] = ' ';
									//present_state_othello(); 
								} 
						}
					}
					
					else if(turn == 1){							//turn of black
					printf("\nPUT A NEW BLACK STONE : ");	//배치할좌표입력받기_white //print_othello()//배치상태출력등
					scanf("%i%i", &row, &col);
						if(check_invalid_input(row, col) == 0){				//checing invalid input ; when check_invalid_input == 0 > valid input 
							gameboard[row][col] = 'X';							//flip_first를 위해서 일단 돌을 위치시켜준다? 									
							if(flip_happens(row, col) == 1){				//FLIP THE STONES										
																//몇개뒤집었는지출력하고 턴바꿔주기 
									flip_black_stone_result(row,col);		  	//뒤집고 뒤집은 결과 화면에 출력 
									turn = 0; 									//뒤집은 후 다음 턴으로 돌아가기 
									//present_state_othello(); 
							} 
							else{
									printf("\ninvalid input! : no flips happen\n");	//뒤집을 수 없으므로 invalid input이다 
									gameboard[row][col] = ' ';
									//present_state_othello(); 
								} 
						}
					}
			}
		else 	
			break;								//더 이상 채울 수 있는 칸이 없으므로 게임이 종료된다.	
		}check_result();						// 결과출력 
												//{몇개뒤집었는지;, 턴바꿈;}	
	return 0;
	
}
