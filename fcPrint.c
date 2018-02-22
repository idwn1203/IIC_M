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
		printf("등록날짜 :%s.%s.%s 일정내용:%s 이름:%s 고유번호:%s\n", man.year, man.month,man.day, man.txt, man.name, man.num);

	}
	fclose(fp);

	return;

}