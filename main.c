#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.h"
#define	N  6		//number of space 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];			 
int main(int argc, char *argv[]) {
	
	int i,j;									//2���� �迭�� ���� //�ʿ��� ���� ����
	int row,col;								//�Է¹���������ġ�����Ѻ��� 
	init_stone();								//initial stone state
	//-----------------------------------------------------------------------------------------initial state 
	//while(isgameend()==0){						//game��������Ȯ��
		present_state_othello();					//�����ġ���� 
		//if()					//��ġ������ĭȮ�� 
					{//continue;//�ѴٺҰ����ϸ�ݺ������������� 
					printf("put a new white othello : ");	//��ġ����ǥ�Է¹ޱ�_white //print_othello()//��ġ������µ�
					scanf("%i%i", &row, &col);
				//	check_invalid_input(row, col);			//checking invalid input  //�Է¹����򵹰��־��ֱ� 
					}
		if(check_invalid_input(row, col) == 0){	//�������Է��� 
			
			if(flip_happens(row, col) == 1){
				flip_white_stone_result(row,col);		//FLIP THE BLACK STONES TO WHITE
				present_state_othello();  
			}
			else
				printf("\ninvalid input! : no flips happen");
}
		else 									//���������Է� �̹� �Լ��� ��������Ƿ� �ٽ� �ҷ��� �ʿ�xxxxxx 
 
			
			check_result();// ������ 
		//{�����������;, �Ϲٲ�;}	
	return 0;
	
}
