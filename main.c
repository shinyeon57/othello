#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.h"
#define	N  6		//number of space 
#define	ROWS  6
#define	COLS  6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];			 
int main(int argc, char *argv[]) {
	//�ʿ��� ���� ����
	init_stone();			//initial stone state
	init_othello();			//game reset
	//while(isgameend()==0){//game��������Ȯ��
	//print_othello()//��ġ������µ�
	//if(��ġ����ĭȮ��))
	//continue;//�ѴٺҰ����ϸ�ݺ������������� 
	input__white_blank();//��ġ����ǥ�Է¹ޱ� 
	//IF(�Է���ǥ����üũ))
	//	if( ������õ�)
	//{�����������;, �Ϲٲ�;}
	//else �������� �Է����� ��� }while end
	printf("invalid input! (should be less than 6)\n");	//invalid input cause of input
	printf("invalid input! (no flip happens)\n");			//invalid input cause of flip
	//check_result();// ������ 
	return 0;
	
}
