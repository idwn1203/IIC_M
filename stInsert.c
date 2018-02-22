#include "common.h"
#include "scData.h"
#include "stData.h"


int stInsert(stList* ST, stData manE, FILE *fp) {
	int i = 0;
	stNode* stITemp = (stNode*)malloc(sizeof(stNode));
	stNode*man = (stNode*)malloc(sizeof(stNode));
	memset(man, 0, sizeof(stNode));


	//man��忡 manE�� �̸��й� �߰�
	strcpy(man->Einfo.name, manE.name);
	strcpy(man->Einfo.stnum, manE.stnum);
	

	if (ST->total != 0) {
		stITemp = ST->head;
	}


	//����Ʈ�� manE�� �й��� ��ġ�ϴ� �й� �ִ��� �˻�
	while (i < ST->total) {
		if (strcmp(stITemp->Einfo.stnum, manE.stnum) == 0) {
			return 1;
		}
		stITemp = stITemp->link;
		i++;
	}//while
	

	if (ST->total == 0) {
		ST->head = man;
		ST->tail = man;
		ST->total++;
	}
	else {
		ST->tail->link = man;
		ST->tail = man;
		ST->total++;
	}


	return 0;

}
