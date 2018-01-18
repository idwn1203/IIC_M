#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct OB {
	int no;//����
	char ob_name[10];//�л��̸�
	char date[6];// ��ϳ�¥
	int computer, printer, keyboard;// ��ǰ

}OB;


void input(OB test[]);// ��ǰ����߰�
void output_element(OB e);// �ϳ��� ���Ҹ� ���
void output_list(OB test[]);// �迭 ������
void print_title();// �����ͳ����� �������
void search(OB test[]);// �̸� �˻�

int size;

int main() {

	OB test[MAX];// ����ü �迭����
	int menu;

	do {
		printf("\n-------------��ǰ���� ���α׷�-------------\n");
		printf("1. �Է� 2. ��ü��� 3. ��ȸ 4. ������ \n");
		printf("-------------------------------------------\n");

		printf("������ �Ͻðڽ��ϱ�?\n");
		scanf("%d", &menu);


		switch (menu)
		{
		case 1: input(test); break;// ������ �Է��ռ�ȣ��
		case 2: output_list(test); break;// ������ ����ռ�ȣ��
		case 3: search(test); break;// ������ �˻��ռ�ȣ��
		//case 4: return 0; break;
		default: printf("\n �޴��� �߸� �����Ͽ����ϴ�. \n\n");
		}

		printf("\n ==========================================\n");
		//system("cls");
	} while (menu != 4);// 4���ƴҰ�� ��ӹݺ�

	return 0;
}

// �����͸� �Է¹���Լ�
void input(OB test[]) {
	test[size].no = size + 1;
	printf("\n");
	printf("�̸� : "); scanf("%s", test[size].ob_name);
	printf("��¥ : "); scanf("%s", test[size].date);
	printf("��ǻ�Ͱ��� : "); scanf("%d", &test[size].computer);
	printf("�����Ͱ��� : "); scanf("%d", &test[size].printer);
	printf("Ű���尳�� : "); scanf("%d", &test[size].keyboard);
	size++;// �迭�������� �����ͼ� 1����
}

// ����ü�迭 test�� ����� �����͸� ����ϴ� �Լ�
void output_list(OB test[]) {
	int i;

	print_title();
	for (i = 0; i < size; i++)
		output_element(test[i]);// ����ü����ϱ�
	printf("=====================================\n");
}

// �ѹ��� �����͸� ����ϴ��Լ�
void output_element(OB e) {
	printf(" %3d  %-5s  %-5s  %3d��  %3d��  %3d�� \n",
		e.no, e.ob_name, e.date, e.computer, e.printer, e.keyboard);
}

// ��������Լ�
void print_title() {
	printf("=====================================\n");
	printf("����  �̸�  ��¥  ��ǻ��  ������  Ű����\n");
	printf("=====================================\n");
}

// ����ü�迭 test���� �̸����� �˻��ϴ� �Լ�
void search(OB test[]) {
	int i;
	char input_name[6];
	
	printf("\n >>�˻��� �̸�? ");
	scanf("%s", input_name);
	print_title();

	for (i = 0; i < size; i++)
		if (strcmp(test[i].ob_name, input_name) == 0)
			output_element(test[i]);
	printf("=====================================\n");
	
}