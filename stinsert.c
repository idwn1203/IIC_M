#include "common.h"
#include "data.h"
#include "scData.h"
#include "stData.h"

int stinsert(stList* list, stNode* man) {
	int i; //roop
	stNode*temp; //temp
	temp = list->head;

	for (i = 0; i < list->total; i++) {
		if (man->Einfo.name == temp->Einfo.name) {
			return 1;
		}
		else break;
	}

	temp = temp->link;
	if (list->front == NULL) {
		list->haed = man;
		list->tail = man;

	}
	else {
		list->tail->link = man;
		list->tail = man;
	}
	total++;
	return 0;



}
