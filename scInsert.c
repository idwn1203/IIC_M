#include "common.h"
#include "scData.h"
#include "stData.h"


void scInsert(scList* SC, scData scE) {

	scNode* scITemp = (scNode*)malloc(sizeof(scNode));
	scNode*scd = (scNode*)malloc(sizeof(scNode));
	memset(scd, 0, sizeof(scNode));



	strcpy(scd->info.year, scE.year);
	strcpy(scd->info.month, scE.month);
	strcpy(scd->info.day, scE.day);
	strcpy(scd->info.txt, scE.txt);
	strcpy(scd->info.name, scE.name);
	strcpy(scd->info.num, scE.num);

	if (SC->total != 0) {
		scITemp = SC->head;
	}
	else if (SC->total == 0) {
		SC->head = scd;
		SC->tail = scd;
		SC->total++;
	}else {
		SC->tail->link = scd;
		SC->tail = scd;
		SC->total++;
	}//else

}