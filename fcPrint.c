#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fp;

void fcPrint(scList* SC) {

	scData man;

	fp = fopen("sc.txt", "r");

	while (1) {

		fscanf(fp, "%s %s %s %s %s %s", man.year, man.month, man.day, man.txt, man.name, man.num);
		if (feof(fp)) break;
		printf("��ϳ�¥ :%s.%s.%s ��������:%s �̸�:%s ������ȣ:%s\n", man.year, man.month,man.day, man.txt, man.name, man.num);

	}
	fclose(fp);

	return;

}