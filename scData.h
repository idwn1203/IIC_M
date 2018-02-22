#define scLen 50

typedef struct scData {

	char num[scLen];//������ȣ

	char year[scLen];//����
	char month[scLen];//��
	char day[scLen];//��
	char txt[scLen];//����
	char name[scLen];//������

}scData;

typedef struct scNode {
	scData info;
	struct scNode* link;
}scNode;

typedef struct {
	scNode* head;
	scNode* tail;
	int total;
}scList;
