#define len 50

typedef struct {
	char name[len]; //이름
	char stnum[len]; //학번
}stData;

typedef struct {
	char grade[len]; //학년
	char phone[len]; //전화번호
	char address[len]; //주소
	char mail[len]; //메일주소
	char graduation[len]; //졸업여부
	char regiDate[len]; //등록일
	char drive[len]; //면허증
}stOpt;

typedef struct {
	char monidate[len], mousdate[len], keydate[len];// 등록날짜
	char monitor[len], mouse[len], keyboard[len];// 비품
}obOpt;

typedef struct stNode {
	stData Einfo;
	stOpt Oinfo;
	obOpt Minfo;
	struct stNode* link;
}stNode; //학생 한명

typedef struct {
	stNode* head;
	stNode* tail;
	int total;
}stList;
