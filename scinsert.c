#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fp;


void scInsert(scList* SC, scData scE) {

	scNode* scITemp = (scNode*)malloc(sizeof(scNode));
	scNode*man = (scNode*)malloc(sizeof(scNode));
	memset(man, 0, sizeof(scNode));

	fp = fopen("sc.txt", "a");

	strcpy(man->info.year, scE.year);
	strcpy(man->info.month, scE.month);
	strcpy(man->info.day, scE.day);
	strcpy(man->info.txt, scE.txt);
	strcpy(man->info.name, scE.name);
	strcpy(man->info.num, scE.num);

	if (SC->total != 0) {
		scITemp = SC->head;
	}//IF

	if (SC->total == 0) {
		SC->head = man;
		SC->tail = man;
		SC->total++;
	}//IF
	else {
		SC->tail->link = man;
		SC->tail = man;
		SC->total++;
	}//else
	fprintf(fp, "%s %s %s %s %s %s\n", man->info.year, man->info.month, man->info.day, man->info.txt, man->info.name, man->info.num);
	//fwrite(&manE, sizeof(manE), 1, fp);
	fclose(fp);

}