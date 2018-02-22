#include "common.h"
#include "stData.h"
#include "scData.h"

FILE *fst;

void fstWrite(stList* ST) {
	stData manE;
	stOpt manO;
	obOpt objO;
	stNode * stTemp = ST->head;
	int i;
	fst = fopen("std.txt", "a");
	
	for (i = 0; i < ST->total; i++) {
		fprintf(fst, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",
			stTemp->Einfo.name, stTemp->Einfo.stnum, stTemp->Oinfo.grade, stTemp->Oinfo.phone, stTemp->Oinfo.address, stTemp->Oinfo.mail, stTemp->Oinfo.graduation, stTemp->Oinfo.regiDate, stTemp->Oinfo.drive
			, stTemp->Minfo.monitor, stTemp->Minfo.monidate, stTemp->Minfo.mouse, stTemp->Minfo.mousdate, stTemp->Minfo.keyboard, stTemp->Minfo.keydate);
		stTemp = stTemp->link;
	}
			fclose(fst);
			
			return;
}