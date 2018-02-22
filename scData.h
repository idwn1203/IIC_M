#define scLen 50

typedef struct scData {

	char num[scLen];//고유번호

	char year[scLen];//연도
	char month[scLen];//달
	char day[scLen];//일
	char txt[scLen];//내용
	char name[scLen];//참여자

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
