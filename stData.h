#define len 50

typedef struct {
	char name[len]; //�̸�
	char stnum[len]; //�й�
}stData;

typedef struct {
	char grade[len]; //�г�
	char phone[len]; //��ȭ��ȣ
	char address[len]; //�ּ�
	char mail[len]; //�����ּ�
	char graduation[len]; //��������
	char regiDate[len]; //�����
	char drive[len]; //������
}stOpt;

typedef struct {
	char monidate[len], mousdate[len], keydate[len];// ��ϳ�¥
	char monitor[len], mouse[len], keyboard[len];// ��ǰ
}obOpt;

typedef struct stNode {
	stData Einfo;
	stOpt Oinfo;
	obOpt Minfo;
	struct stNode* link;
}stNode; //�л� �Ѹ�

typedef struct {
	stNode* head;
	stNode* tail;
	int total;
}stList;
