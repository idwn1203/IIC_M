#include "common.h"
#include "scData.h"
#include "stData.h"

FILE *fst;

void fstRead(stList* ST) {
	
	stData man;
	stOpt per;
	obOpt ob;
	stNode * stTemp = ST->head;
	fst = fopen("std.txt", "r");
	int i=0;

	while (1) {
	
		fscanf(fst, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", 
			man.name, man.stnum, per.grade, per.phone, per.address, per.mail, per.graduation, per.regiDate, per.drive
			, ob.monitor, ob.monidate, ob.mouse, ob.mousdate, ob.keyboard, ob.keydate);
		if (!feof(fst)) break;
		strcpy(stTemp->Einfo.name, man.name);
		strcpy(stTemp->Einfo.stnum, man.stnum);

		strcpy(stTemp->Oinfo.grade, per.grade);
		strcpy(stTemp->Oinfo.phone, per.phone);
		strcpy(stTemp->Oinfo.address, per.address);
		strcpy(stTemp->Oinfo.mail, per.mail);
		strcpy(stTemp->Oinfo.graduation, per.graduation );
		strcpy(stTemp->Oinfo.regiDate, per.regiDate);
		strcpy(stTemp->Oinfo.drive, per.drive);

		strcpy(stTemp->Minfo.monitor, ob.monitor );
		strcpy(stTemp->Minfo.monidate, ob.monidate);
		strcpy(stTemp->Minfo.mouse, ob.mouse);
		strcpy(stTemp->Minfo.mousdate, ob.mousdate);
		strcpy(stTemp->Minfo.keyboard, ob.keyboard);
		strcpy(stTemp->Minfo.keydate, ob.keydate);
		i++;
		stTemp = stTemp->link;
			}
	ST->total = i;
	fclose(fst);	
	
	return;
	
}