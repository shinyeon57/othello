#include <stdio.h>
#include <stdlib.h>
#define	N  6		//number of space 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];			 
int main(int argc, char *argv[]) {
	//필요한 변수 선언
	init_othello();			//game reset
	//while(isgameend()==0){//game종료조건확인
	//print_othello()//배치상태출력등
	//if(배치가능칸확인))
	//continue;//둘다불가능하면반복문빠져나가기 
	//배치할좌표입력받기 
	//IF(입력좌표적절체크))
	//	if( 뒤집기시도)
	//{몇개뒤집었는지;, 턴바꿈;}
	//else 부적절한 입력임을 출력 }while end
	printf("invalid input! (should be less than 6)");	//invalid input cause of input
	printf("invalid input! (no flip happens)");			//invalid input cause of flip
	//check_result();// 결과출력 
	return 0;
	
}
