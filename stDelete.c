#include "common.h"
#include "stData.h"
#include "scData.h"


int stDelete(stList* ST, char num[len]) {

	stNode * stTemp = (stNode*)malloc(sizeof(stNode));
	stTemp = ST->head;
	stNode * stLin = (stNode*)malloc(sizeof(stNode));
	int i;

	if (ST->total == 0) {
		return 0;
	}
	else if (ST->total == 1) {
		ST->head = NULL;
		ST->tail = NULL;
		ST->total--;
		return 1;
	}
	else {
		for (i = 0; i < ST->total; i++) {
			if (strcmp(stTemp->link->Einfo.stnum, num) == 0) {
				stLin = stTemp->link->link;
				stTemp->link = stLin;
				ST->total--;
				return 1;
			}//»èÁ¦ÇÔ
			stTemp = stTemp->link;
		}
	}
	return 0;
}

