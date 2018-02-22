#include "stData.h"
#include "scData.h"
#include "common.h"


#define aP "1234"
#define mP "5678"

void aMode(stList* ST, scList* SC);
void mMode(stList* ST, scList* SC);
void sMode(stList* ST, scList* SC);

stList* createST() {
	stList* ST = (stList*)malloc(sizeof(stList));
	ST->head = NULL;
	ST->tail = NULL;
	ST->total = 0;
	return ST;
}

scList *createSC() {
	scList* SC = (scList*)malloc(sizeof(scList));
	SC->head = NULL;
	SC->tail = NULL;
	SC->total = 0;
	return SC;
}

int main() {
	char sw; //switch
	char password[len]; //password
	stList*ST = createST();
	scList*SC = createSC();

	fscRead(SC);
	//fstRead(ST);

	do {
		system("cls");		printf("\n0. exit");
		printf("\n1. administrator mode");
		printf("\n2. member mode");
		printf("\n3. standard mode");
		printf("\nEnter: ");
		scanf(" %c", &sw);

		switch (sw) {
		case '1':
			printf("\nPassword: ");
			scanf("%s", password);
			if (strcmp(password, aP) == 0) {
				aMode(ST, SC);
				break;
			}
			else {
				printf("\nPassword is wrong");
				break;
			}
		case '2':
			printf("\nPassword: ");
			scanf("%s", password);
			if (strcmp(password, mP) == 0) {
				mMode(ST, SC);
				break;
			}
			else {
				printf("\nPassword is wrong");
				break;
			}
		case '3':
			sMode(ST, SC);
			break;
		}
	} while (sw != '0');

	fscWrite(SC);
	//fstWrite(ST);

	return 0;
}