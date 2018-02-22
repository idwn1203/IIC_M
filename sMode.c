#include "stData.h"
#include "scData.h"
#include "common.h"


void sMode(stList* ST, scList* SC) {
	char msw; //mMode switch
	char exit;
	int i;
	stNode* stTemp; //student temp

	do {

		printf("\n0. "); printf("exit");
		printf("\n1. "); printf("View all students");
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


		}//end switch
	} while (msw != '0');

}