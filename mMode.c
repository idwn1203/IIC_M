#include "stData.h"
#include "scData.h"
#include "common.h"


void mMode(stList* ST, scList* SC) {
	char msw; //mMode switch
	char exit;
	int i;
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
		printf("\n3. View all schedules");
		printf("\n4. View all object");
		scanf(" %c", &msw);

		switch (msw) {
		case '1': //view all students
			if (ST->total == 0) {
				printf("\nList is empty\n");
			}
			else {
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
			}//학생리스트 total 0이면 빈 리스트
			else {
				printf("\n보려는 학생의 학번: ");
				scanf("%s", num);
				stTemp = ST->head;
				for (i = 0; i < ST->total; i++) {
					if (strcmp(stTemp->Einfo.stnum, num) == 0) {
						memcpy(stMan, stTemp, sizeof(stNode));
						break;
					}
					stTemp = stTemp->link;
				}
				if (i >= ST->total) {
					printf("\n보려는 학생 없음");
				}
				else {
					printf("\nName: %s", stMan->Einfo.name);
					printf("\nStudent number: %s", stMan->Einfo.stnum);
					printf("\nGrade: %s", stMan->Oinfo.grade);
					printf("\nPhone number: %s", stMan->Oinfo.phone);
					printf("\nAddress: %s", stMan->Oinfo.address);
					printf("\nMail: %s", stMan->Oinfo.mail);
					printf("\nGraduation: %s", stMan->Oinfo.graduation);
					printf("\nRegistration Date: %s", stMan->Oinfo.regiDate);
					printf("\nDrive: %s", stMan->Oinfo.drive);
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
				printf("\nSchedule is empty");
			} //스케줄 리스트가 비어있음
			else {
				scTemp = SC->head;
				for (i = 0; i < SC->total; i++) {
					printf("\n고유번호: %s", scTemp->info.num);
					printf("    Year: %s", scTemp->info.year);
					printf("    Month: %s", scTemp->info.month);
					printf("    Day: %s", scTemp->info.day);
					printf("    TXT: %s", scTemp->info.txt);
					printf("    Name: %s", scTemp->info.name);
					scTemp = scTemp->link;
				}
			}//scTemp로 이동하며 각 노드의 일정 출력

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;


		case '4': //view all object

			if (ST->total == 0) {
				printf("\nstudent is empty");
			}//학생 리스트 비어있음
			else {
				stTemp = ST->head;
				for (i = 0; i < ST->total; i++) {
					printf("\nname: %s", stTemp->Einfo.name);
					printf("    num: %s", stTemp->Einfo.stnum);
					printf("    moditor: %s", stTemp->Minfo.monitor);
					printf("    mouse: %s", stTemp->Minfo.mouse);
					printf("    keyboard: %s", stTemp->Minfo.keyboard);
					stTemp = stTemp->link;
					i++;
				}
			}//리스트의 모든 학생들의 비품 출력

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;
		}//end switch
	} while (msw != '0');

}