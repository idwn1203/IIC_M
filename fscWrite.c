#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fsc;

void fscWrite(scList* SC) {

	scData scE;
	scNode* scTemp = SC->head;
	int i;

	fsc = fopen("sc.txt", "r+");
	
	for (i = 0; i < SC->total; i++) {
<<<<<<< HEAD
		fprintf(fsc, "%s %s %s %s %s %s", scTemp->info.num, scTemp->info.year, scTemp->info.month, scTemp->info.day, scTemp->info.txt, scTemp->info.name);
=======
		fprintf(fsc, "%s %s %s %s %s %s\n", scTemp->info.num, scTemp->info.year, scTemp->info.month, scTemp->info.day, scTemp->info.txt, scTemp->info.name);
>>>>>>> scFileio
		scTemp = scTemp->link;
	}

	fclose(fsc);

	return;

}