#include "common.h"
#include "scData.h"
#include "stData.h"

int scDelete(scList* SC, char num[len]) {

	scNode*scTemp = (scNode*)malloc(sizeof(scNode)); //temp
	scTemp = SC->head;
	scNode*del = (scNode*)malloc(sizeof(scNode));
	int i;

	
	if (SC->total == 0) {
		return 0;
	}
	else if (SC->total == 1) {
		SC->head == NULL;
		SC->tail == NULL;
		SC->total--;
		return 1;
	}
	else {
		for (i = 0; i < SC->total; i++) {
			if (strcmp(scTemp->link->info.num, num) == 0) {
				del = scTemp->link->link;
				scTemp->link = del;
				SC->total--;
				return 1;
			}
			scTemp = scTemp->link;
		}
	}
	return 0;
}