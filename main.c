#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.h"
#define	N  6		//number of space 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];		
int	turn		;	 						//�÷��̾� ������ ���� ���� 
int main(int argc, char *argv[]) {
	
	int i,j;									//2���� �迭�� ���� //�ʿ��� ���� ����
	int row,col;								//�Է¹���������ġ�����Ѻ��� 
//	int turn = 0;								//black & white turn ���ϱ� =0:white, =1:black
	turn = 0 ;									//��� ���� player�� ���� �����Ѵ�. 
	init_stone();								//initial stone state
	//-----------------------------------------------------------------------------------------initial state 
	while(isGameEnd()==0){						//game��������Ȯ��
		present_state_othello();					//�����ġ���� 
		if(blankstate()==0)	{				//��ġ������ĭȮ�� ��ĭ���־���ϰ�����Ⱑ�����ؾߵ� ????/�������������̶�����
			//turnofgame();							//������ �� ���� �� turn�� �ڵ����� ���ư���.  		present_state_othello()�־���ߵ�.			
					if(turn == 0){							//turn of white
					printf("\nPUT A NEW WHITE STONE : ");	//��ġ����ǥ�Է¹ޱ�_white //print_othello()//��ġ������µ�
					scanf("%i%i", &row, &col);
						if(check_invalid_input(row, col) == 0){				//checing invalid input ; when check_invalid_input == 0 > valid input 	
							gameboard[row][col] = 'O';							//flip_first�� ���ؼ� �ϴ� ���� ��ġ�����ش�? ��� ��ȿ�Է�Ȯ�����Ŀ�		
							if(flip_happens(row, col) == 1){				//FLIP THE STONES
															//���������������ϰ� �Ϲٲ��ֱ� 
									flip_white_stone_result(row,col);		  	//������ ������ ��� ȭ�鿡 ��� 
									turn = 1; 									//������ �� ���� ������ ���ư��� 
									//present_state_othello(); 
							} 
							else{
									printf("\ninvalid input! : no flips happen\n");	//������ �� �����Ƿ� invalid input�̴� 
									gameboard[row][col] = ' ';
									//present_state_othello(); 
								} 
						}
					}
					
					else if(turn == 1){							//turn of black
					printf("\nPUT A NEW BLACK STONE : ");	//��ġ����ǥ�Է¹ޱ�_white //print_othello()//��ġ������µ�
					scanf("%i%i", &row, &col);
						if(check_invalid_input(row, col) == 0){				//checing invalid input ; when check_invalid_input == 0 > valid input 
							gameboard[row][col] = 'X';							//flip_first�� ���ؼ� �ϴ� ���� ��ġ�����ش�? 									
							if(flip_happens(row, col) == 1){				//FLIP THE STONES										
																//���������������ϰ� �Ϲٲ��ֱ� 
									flip_black_stone_result(row,col);		  	//������ ������ ��� ȭ�鿡 ��� 
									turn = 0; 									//������ �� ���� ������ ���ư��� 
									//present_state_othello(); 
							} 
							else{
									printf("\ninvalid input! : no flips happen\n");	//������ �� �����Ƿ� invalid input�̴� 
									gameboard[row][col] = ' ';
									//present_state_othello(); 
								} 
						}
					}
			}
		else 	
			break;								//�� �̻� ä�� �� �ִ� ĭ�� �����Ƿ� ������ ����ȴ�.	
		}check_result();						// ������ 
												//{�����������;, �Ϲٲ�;}	
	return 0;
	
}
