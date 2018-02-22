#include "stData.h"
#include "scData.h"
#include "common.h"


void mMode(stList* ST, scList* SC) {
	char msw; //mMode switch
	char exit;
	int i;

	stData manE;
	stOpt manO;
	obOpt objO;
	stNode* stTemp = (stNode*)malloc(sizeof(stNode)); //student temp
	stNode* stMan = (stNode*)malloc(sizeof(stNode)); //student
	scNode* scTemp = (scNode*)malloc(sizeof(scNode)); //schedule temp
	scNode* schedule = (scNode*)malloc(sizeof(scNode)); //schedule
	char num[len]; //student number


	do {

		memset(stMan, 0, sizeof(stNode));
		memset(schedule, 0, sizeof(scNode));
		printf("\n0. exit");
		printf("\n1. View all students");
		printf("\n2. View one student");
		printf("\n3. View all schedules"); \
			scanf(" %c", &msw);

		switch (msw) {
		case '1': //view all students
			if (ST->total == 0) {
				ftPrint(ST);
				printf("\nList is empty\n");
			}
			else {
				ftPrint(ST);
				stTemp = ST->head;
				for (i = 0; i < ST->total; i++) {
					printf("%d", i);
					printf("\nName: %s ", stTemp->Einfo.name);
					printf("    Student number: %s\n", stTemp->Einfo.stnum);
					stTemp = stTemp->link;
				}
			}


			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');


			break;

		case '2': //view one student


			if (ST->total == 0) {
				printf("\nList is empty\n");
			}//�л�����Ʈ total 0�̸� �� ����Ʈ
			else {
				printf("\n������ �л��� �й�: ");
				scanf("%s", num);
				stTemp = ST->head;
				for (i = 0; i < ST->total; i++) {
					if (strcmp(stTemp->Einfo.stnum, num) == 0) {
						strcpy(manE.name, stTemp->Einfo.name);
						strcpy(manE.stnum, stTemp->Einfo.stnum);

						strcpy(manO.grade, stTemp->Oinfo.grade);
						strcpy(manO.phone, stTemp->Oinfo.phone);
						strcpy(manO.address, stTemp->Oinfo.address);
						strcpy(manO.mail, stTemp->Oinfo.mail);
						strcpy(manO.graduation, stTemp->Oinfo.graduation);
						strcpy(manO.regiDate, stTemp->Oinfo.regiDate);
						strcpy(manO.drive, stTemp->Oinfo.drive);

						strcpy(objO.monitor, stTemp->Minfo.monitor);
						strcpy(objO.monidate, stTemp->Minfo.monidate);
						strcpy(objO.mouse, stTemp->Minfo.mouse);
						strcpy(objO.mousdate, stTemp->Minfo.mousdate);
						strcpy(objO.keyboard, stTemp->Minfo.keyboard);
						strcpy(objO.keydate, stTemp->Minfo.keydate);

						break;
					}
					stTemp = stTemp->link;
				}
				if (i >= ST->total) {
					printf("\n������ �л� ����");
				}
				else {
					printf("\nName: %s", manE.name);
					printf("\nStudent number: %s", manE.stnum);
					printf("\nGrade: %s", manO.grade);
					printf("\nPhone number: %s", manO.phone);
					printf("\nAddress: %s", manO.address);
					printf("\nMail: %s", manO.mail);
					printf("\nGraduation: %s", manO.graduation);
					printf("\nRegistration Date: %s", manO.regiDate);
					printf("\nDrive: %s", manO.drive);
					printf("\n\nobject\n");
					printf("\nmonitor: %s", objO.monitor);
					printf("\nmonidate: %s", objO.monidate);
					printf("\nmouse: %s", objO.mouse);
					printf("\nmousdate: %s", objO.mousdate);
					printf("\nkeyboard: %s", objO.keyboard);
					printf("\nkeydate: %s", objO.keydate);
				}
			}

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;



		case '3': //view all schedules

			if (SC->total == 0) {
				fcPrint(SC);
				printf("\nSchedule is empty");
			} //������ ����Ʈ�� �������
			else {
				fcPrint(SC);
				scTemp = SC->head;
				for (i = 0; i < SC->total; i++) {
					printf("\n������ȣ: %s", scTemp->info.num);
					printf("    Year: %s", scTemp->info.year);
					printf("    Month: %s", scTemp->info.month);
					printf("    Day: %s", scTemp->info.day);
					printf("    TXT: %s", scTemp->info.txt);
					printf("    Name: %s", scTemp->info.name);
					scTemp = scTemp->link;
				}
			}//scTemp�� �̵��ϸ� �� ����� ���� ���

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		}//end switch
	} while (msw != '0');

}