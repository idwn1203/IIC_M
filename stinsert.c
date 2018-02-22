#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fp;
char *f_name = "std.txt";

int stInsert(stList* ST, stData manE, FILE *fp) {
	int i = 0;
	stNode* stITemp = (stNode*)malloc(sizeof(stNode));
	stNode*man = (stNode*)malloc(sizeof(stNode));
	memset(man, 0, sizeof(stNode));

	fp = fopen(f_name, "a");

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
	fprintf(fp, "%s %s\n", man->Einfo.name, man->Einfo.stnum);
	//fwrite(&manE, sizeof(manE), 1, fp);
	fclose(fp);

	return 0;

}
