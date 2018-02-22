#include "common.h"
#include "stData.h"
#include "scData.h"

int stModify(stList* ST, stData manE, stOpt manO) {
	stNode * stTemp = ST->head;
	stNode *stMan = (stNode*)malloc(sizeof(stNode));

	int i;

	if (ST->total == 0) {
		return 0;
	}
	else {
		for (i = 0; i < ST->total; i++) {
			if (strcmp(stTemp->Einfo.stnum, manE.stnum) == 0) {
				strcpy(stTemp->Oinfo.grade, manO.grade);
				strcpy(stTemp->Oinfo.phone, manO.phone);
				strcpy(stTemp->Oinfo.mail, manO.mail);
				strcpy(stTemp->Oinfo.graduation, manO.graduation);
				strcpy(stTemp->Oinfo.regiDate, manO.regiDate);
				strcpy(stTemp->Oinfo.drive, manO.drive);
				return 1;
			}
			stTemp = stTemp->link;
		}
		return 1;
	}

	return 0;
}