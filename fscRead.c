#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fsc;

void fscRead(scList* SC) {

	scData scE;
	scNode* scTemp = SC->head;
	int i = 0;

	fsc = fopen("sc.txt", "r");


	while (1) {

		if (fsc == NULL) {
			//fflush(fsc);
			printf("\nfopen error");
			SC->total = 0;
			return;
		}
		if (feof(fsc) == 0) break;
		fscanf(fsc, "%s %s %s %s %s %s", scE.num, scE.year, scE.month, scE.day, scE.txt, scE.name);
		
		 //파일 끝이면 break
		
		strcpy(scTemp->info.num, scE.num);
		strcpy(scTemp->info.year, scE.year);
		strcpy(scTemp->info.month, scE.month);
		strcpy(scTemp->info.day, scE.day);
		strcpy(scTemp->info.txt, scE.txt);
		strcpy(scTemp->info.name, scE.name);
		i++;
		scTemp = scTemp->link;
	}
	SC->total = i;
	fclose(fsc);
	return;
}