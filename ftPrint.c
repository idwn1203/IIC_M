#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fp;

void ftPrint(stList* ST) {
	
	stData man;

	fp = fopen("std.txt", "r");

	while (1) {
	
		fscanf(fp, "%s %s", man.name, man.stnum);
		if (feof(fp)) break;
		printf("�л��̸�:%s     �й�:%s\n", man.name, man.stnum);
		
	}
	fclose(fp);	

	return;
	
}