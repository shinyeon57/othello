#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.h"
#define	N  6					//number of space 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];						//������ �迭����	
int	turn		;	 						//�÷��̾� turn��  ���� ���� 

int main(int argc, char *argv[]) {
	
	int row,col;								//�Է¹���������ġ�����Ѻ��� 
	turn = 0 ;									//��� ���� player�� ���� �����Ѵ�. 	//black & white turn ���ϱ� =0:white, =1:black
	init_stone();								//�ʱ���۽� ���� �迭 
	//-----------------------------------------------------------------------------------------initial state 
	while(isGameEnd()==0){																//game��������Ȯ��
		present_state_othello();														//�����ġ���� 
		if(blankstate()==0)	{															//��ġ������ĭȮ�� 
			turnofgame();																//������ �� ���� �� turn�� �ڵ����� ���ư���.  			
					if(turn == 0){														//turn of white
					printf("\nPUT A NEW WHITE STONE : ");								//��ġ����ǥ�Է¹ޱ�_white 
					scanf("%i%i", &row, &col);
						if(check_invalid_input(row, col) == 0){							//checking invalid input ; when check_invalid_input == 0 > valid input 	
							gameboard[row][col] = 'O';									//flip_first�� ���ؼ� �ϴ� ���� ��ġ�����ش�._white stone	
							if(flip_happens(row, col) == 1){							//�Է��� ���� ���� �����Ⱑ �����ϴ�. 
															 
									flip_white_stone_result(row,col);		  			//������ ������ ��� ȭ�鿡 ��� 
									turn = 1; 											//������ �� ���� ������ ���ư��� 
							} 
							else{
									printf("\ninvalid input! : no flips happen\n");		//������ �� �����Ƿ� invalid input�̴� 
									gameboard[row][col] = ' ';							//������ �Է��� �ƴϹǷ� �����·� ���ư���.  
								} 
						}
					}
					
					else if(turn == 1){													//turn of black
					printf("\nPUT A NEW BLACK STONE : ");								//��ġ����ǥ�Է¹ޱ�_black 
					scanf("%i%i", &row, &col);
						if(check_invalid_input(row, col) == 0){							//checing invalid input ; when check_invalid_input == 0 > valid input 
							gameboard[row][col] = 'X';									//flip_first�� ���ؼ� �ϴ� ���� ��ġ�����ش�._black stone 									
							if(flip_happens(row, col) == 1){							//FLIP THE STONES										
																//���������������ϰ� �Ϲٲ��ֱ� 
									flip_black_stone_result(row,col);		  			//������ ������ ��� ȭ�鿡 ��� 
									turn = 0; 											//������ �� ���� ������ ���ư���  
							} 
							else{
									printf("\ninvalid input! : no flips happen\n");		//������ �� �����Ƿ� invalid input�̴� 
									gameboard[row][col] = ' ';							//������ �Է��� �ƴϹǷ� �����·� ���ư���. 
								} 
						}
					}
			}
		else 	
			break;																		//�� �̻� ä�� �� �ִ� ĭ�� �����Ƿ� ������ ����ȴ�.	
		}check_result();																// ������ 	
	return 0;
	
}
