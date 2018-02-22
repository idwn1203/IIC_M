#include "common.h"
#include "scData.h"
#include "stData.h"


int stInsert(stList* ST, stData manE, FILE *fp) {
	int i = 0;
	stNode* stITemp = (stNode*)malloc(sizeof(stNode));
	stNode*man = (stNode*)malloc(sizeof(stNode));
	memset(man, 0, sizeof(stNode));


	//man노드에 manE의 이름학번 추가
	strcpy(man->Einfo.name, manE.name);
	strcpy(man->Einfo.stnum, manE.stnum);
	

	if (ST->total != 0) {
		stITemp = ST->head;
	}


	//리스트에 manE의 학번과 일치하는 학번 있는지 검색
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
