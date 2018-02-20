#include "common.h"
#include "data.h"
#include "scData.h"
#include "stData.h"

int scinsert(scList* list, stNode* man) {
	int i; //roop
	scNode*temp; //temp
	temp = list->head;

	while (temp->link != NULL) {
		if (man->info.num == temp->info.num) {
			return 1;
		}
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

	return 0;

}