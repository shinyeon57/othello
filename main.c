#include <stdio.h>
#include <stdlib.h>
#include "Untitled2.h"
#define	N  6		//number of space 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];			 
int main(int argc, char *argv[]) {
	
	int i,j;									//2차원 배열의 변수 //필요한 변수 선언
	int row,col;								//입력받은돌의위치를위한변수 
	init_stone();								//initial stone state
	//-----------------------------------------------------------------------------------------initial state 
	//while(isgameend()==0){						//game종료조건확인
		present_state_othello();					//현재배치상태 
		//if()					//배치가능한칸확인 
					{//continue;//둘다불가능하면반복문빠져나가기 
					printf("put a new white othello : ");	//배치할좌표입력받기_white //print_othello()//배치상태출력등
					scanf("%i%i", &row, &col);
				//	check_invalid_input(row, col);			//checking invalid input  //입력받은흰돌값넣어주기 
					}
		if(check_invalid_input(row, col) == 0){	//적절한입력임 
			
			if(flip_happens(row, col) == 1){
				flip_white_stone_result(row,col);		//FLIP THE BLACK STONES TO WHITE
				present_state_othello();  
			}
			else
				printf("\ninvalid input! : no flips happen");
}
		else 									//부적절한입력 이미 함수가 실행됐으므로 다시 불러올 필요xxxxxx 
 
			
			check_result();// 결과출력 
		//{몇개뒤집었는지;, 턴바꿈;}	
	return 0;
	
}
