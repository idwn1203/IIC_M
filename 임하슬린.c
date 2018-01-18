#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct OB {
	int no;//순번
	char ob_name[10];//학생이름
	char date[6];// 등록날짜
	int computer, printer, keyboard;// 비품

}OB;


void input(OB test[]);// 비품목록추가
void output_element(OB e);// 하나의 원소만 출력
void output_list(OB test[]);// 배열 모두출력
void print_title();// 데이터내용의 제목출력
void search(OB test[]);// 이름 검색

int size;

int main() {

	OB test[MAX];// 구조체 배열선언
	int menu;

	do {
		printf("\n-------------비품관리 프로그램-------------\n");
		printf("1. 입력 2. 전체출력 3. 조회 4. 끝내기 \n");
		printf("-------------------------------------------\n");

		printf("무엇을 하시겠습니까?\n");
		scanf("%d", &menu);


		switch (menu)
		{
		case 1: input(test); break;// 데이터 입력합수호출
		case 2: output_list(test); break;// 데이터 출력합수호출
		case 3: search(test); break;// 데이터 검색합수호출
		//case 4: return 0; break;
		default: printf("\n 메뉴를 잘못 선택하였습니다. \n\n");
		}

		printf("\n ==========================================\n");
		//system("cls");
	} while (menu != 4);// 4가아닐경우 계속반복

	return 0;
}

// 데이터를 입력밭는함수
void input(OB test[]) {
	test[size].no = size + 1;
	printf("\n");
	printf("이름 : "); scanf("%s", test[size].ob_name);
	printf("날짜 : "); scanf("%s", test[size].date);
	printf("컴퓨터개수 : "); scanf("%d", &test[size].computer);
	printf("프린터개수 : "); scanf("%d", &test[size].printer);
	printf("키보드개수 : "); scanf("%d", &test[size].keyboard);
	size++;// 배열에저장한 데이터수 1증가
}

// 구조체배열 test에 저장된 데이터를 출력하는 함수
void output_list(OB test[]) {
	int i;

	print_title();
	for (i = 0; i < size; i++)
		output_element(test[i]);// 구조체출력하기
	printf("=====================================\n");
}

// 한번의 데이터를 출력하는함수
void output_element(OB e) {
	printf(" %3d  %-5s  %-5s  %3d개  %3d개  %3d개 \n",
		e.no, e.ob_name, e.date, e.computer, e.printer, e.keyboard);
}

// 제목출력함수
void print_title() {
	printf("=====================================\n");
	printf("순번  이름  날짜  컴퓨터  프린터  키보드\n");
	printf("=====================================\n");
}

// 구조체배열 test에서 이름별로 검색하는 함수
void search(OB test[]) {
	int i;
	char input_name[6];
	
	printf("\n >>검색할 이름? ");
	scanf("%s", input_name);
	print_title();

	for (i = 0; i < size; i++)
		if (strcmp(test[i].ob_name, input_name) == 0)
			output_element(test[i]);
	printf("=====================================\n");
	
}