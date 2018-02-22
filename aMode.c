#include "stData.h"
#include "scData.h"
#include "common.h"


void aMode(stList*ST, scList*SC) {
	char asw; //amode switch
	char exit; //exit

	stNode* stTemp = (stNode*)malloc(sizeof(stNode));;
	stNode* stMan = (stNode*)malloc(sizeof(stNode));;
	stData manE;
	stOpt manO;
	obOpt objO;

	scNode* scTemp = (scNode*)malloc(sizeof(scNode));
	scNode* schedule = (scNode*)malloc(sizeof(scNode)); //schedule temp
	scData scE;

	char num[len]; //student number or schedule number
	int i = 0; //judge set
	int count = 0;
	char anum[150];

	FILE *fp;
	char *f_name = "std.txt";

	do {

		system("cls");
		printf("\n0. "); printf("exit");

		printf("\n1. "); printf("View all Students");
		printf("\n2. "); printf("View one student");
		printf("\n3. "); printf("Insert student");
		printf("\n4. "); printf("Modify student");
		printf("\n5. "); printf("Delete student");

		printf("\n6. "); printf("View all schedule");
		printf("\n7. "); printf("Insert schedule");
		printf("\n8. "); printf("Delete schedule");

		printf("\n9. "); printf("View all Object");
		printf("\n10. "); printf("Modify object");


		printf("\nEnter: ");
		scanf(" %c", &asw);

		switch (asw) {
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
						strcpy(manE.name, stTemp->Einfo.name);
						strcpy(manE.stnum, stTemp->Einfo.stnum);

						strcpy(manO.grade, stTemp->Oinfo.grade);
						strcpy(manO.phone, stTemp->Oinfo.phone);
						strcpy(manO.address, stTemp->Oinfo.address);
						strcpy(manO.mail, stTemp->Oinfo.mail);
						strcpy(manO.graduation, stTemp->Oinfo.graduation);
						strcpy(manO.regiDate, stTemp->Oinfo.regiDate);
						strcpy(manO.drive, stTemp->Oinfo.drive);

						break;
					}
					stTemp = stTemp->link;
				}
				if (i >= ST->total) {
					printf("\n보려는 학생 없음");
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
				}
			}

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		case '3': //insert student

				  //memset(man, 0, sizeof(stNode));
			printf("\nInsert Student\n");

			printf("\nName: ");
			scanf("%s", manE.name);
			printf("\nStudent number: ");
			scanf("%s", manE.stnum);

			i = stInsert(ST, manE);
			printf("\n인원 총합: %d", ST->total);

			if (i == 1) {
				printf("\n이미 있는 학생\n");
			}
			else {
				printf("\nGrade: ");
				scanf("%s", manO.grade);
				printf("\nPhone number:");
				scanf("%s", manO.phone);
				printf("\nAddress: ");
				scanf("%s", manO.address);
				printf("\nMail: ");
				scanf("%s", manO.mail);
				printf("\nGraduation: ");
				scanf("%s", manO.graduation);
				printf("\nRegistration Date:");
				scanf("%s", manO.regiDate);
				printf("\nDrive:");
				scanf("%s", manO.drive);
				i = stModify(ST, manE, manO);
			}

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		case '4': //modify student

			if (ST->total == 0) {
				//리스트 비어있음
				printf("\nstudent list is empty");
			}
			else {
				printf("\n수정할 학생의 학번 입력: ");
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

						break;
					}
					stTemp = stTemp->link;
				}

				if (i >= ST->total) {
					//해당 학생 없음
					printf("\n해당 학생 없음");
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
					//학생 원래 정보 출력

					printf("\nModify Obtional info\n");
					printf("\nGrade: ");
					scanf("%s", manO.grade);
					printf("\nPhone number:");
					scanf("%s", manO.phone);
					printf("\nAddress: ");
					scanf("%s", manO.address);
					printf("\nMail: ");
					scanf("%s", manO.mail);
					printf("\nGraduation: ");
					scanf("%s", manO.graduation);
					printf("\nRegistration Date:");
					scanf("%s", manO.regiDate);
					printf("\nDrive:");
					scanf("%s", manO.drive);
					i = stModify(ST, manE, manO);

					if (i == 0) {
						printf("\n해당학생 없음-수정 실패");
					}
				}
			}
			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		case '5': //delete student

			if (ST->total == 0) {
				printf("\n학생 리스트 비어있음");
			}
			else {
				printf("\n지우려는 학생의 학번: ");
				scanf("%s", num);
				i = stDelete(ST, num);
				if (i == 0) {
					printf("\n일치하는 학생이 없습니다.");
				}
			}
			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		case '6': //view all schedule

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

		case '7': //insert schedule


			printf("year: ");
			scanf("%s", scE.year);
			printf("month: ");
			scanf("%s", scE.month);
			printf("day: ");
			scanf("%s", scE.day);
			printf("txt: ");
			scanf("%s", scE.txt);
			printf("name: ");
			scanf("%s", scE.name);
			count++;
			sprintf(anum, "%s%s%d", scE.year, scE.month, count);
			strcpy(scE.num, anum);
			printf("num: %s", scE.num);
			//strcat(num, schedule->info.month);			

			//strcpy(schedule->info.num, num);

			scInsert(SC, scE);


			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		case '8':  //delete schedule

			if (SC->total == 0) {
				printf("\nSchedule is empty");
			}//스케줄 없음
			else {
				printf("\n삭제하려는 스케줄 고유번호 입력: ");
				scanf("%s", num);
				i = scDelete(SC, num);

				if (i == 0) {
					printf("\n해당 스케줄 없음");
				}//고유번호 같은 스케줄 없음
			}

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		case '9': //View all object

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

		case '10': //modify object

			if (ST->total == 0) {
				//학생리스트 비어있음
				printf("\nStudent list is empty");
			}
			else {
				printf("\n비품 수정할 학생의 학번 : ");
				scanf("%s", num);
				stTemp = ST->head;
				for (i = 0; i < ST->total; i++) {
					if (strcmp(stTemp->Einfo.stnum, num) == 0) {
						strcpy(manE.name, stTemp->Einfo.name);
						strcpy(manE.stnum, stTemp->Einfo.stnum);

						strcpy(objO.monitor, stTemp->Minfo.monitor);
						strcpy(objO.monidate, stTemp->Minfo.monidate);
						strcpy(objO.mouse, stTemp->Minfo.mouse);
						strcpy(objO.mousdate, stTemp->Minfo.mousdate);
						strcpy(objO.keyboard, stTemp->Minfo.keyboard);
						strcpy(objO.keydate, stTemp->Minfo.keydate);
					}
					stTemp = stTemp->link;
				}
				if (i >= ST->total) {
					//그런학생 없어
					printf("\n해당 학생 없음");
				}
				else {
					printf("\nname: %s", manE.name);
					printf("    stnum: %s", manE.stnum);
					printf("    monitor: %s", objO.monitor);
					printf("    mouse: %s", objO.mouse);
					printf("    keyboard: %s", objO.keyboard); //원래 학생 정보 출력

					printf("\nmodify pbject\n");
					printf("\nmonitor: ");
					scanf("%s", objO.monitor);
					printf("\n,mouse: ");
					scanf("%s", objO.mouse);
					printf("\nkeyboard: ");
					scanf("%s", objO.keyboard); //비품 수정
					//i = obModify(ST, manE, objO);
				} //반환된 학생 이름, 학번 출력 후 비품 수정
			}

			do {
				printf("\n0.exit");
				printf("\nEnter: ");
				scanf(" %c", &exit);
			} while (exit != '0');
			break;

		}//end switch

	} while (asw != '0');
}