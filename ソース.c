#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
	int cnt; // ������
	char moji;//������
} MOJI;

// qsort�Ŕ��肷�邽�߂̊֐��B�ʂɓ�����Ƃ͂��ĂȂ��Ba��b���r���đ傫����ΐ��̒l��Ԃ��Ώ����ɂȂ�B
// ����̓e�X�g�̓_�Ȃ̂Œl���傫�����i�~���j������Aif�����̔�����t�ɂ��Ă���B
int compar(const void* a, const void* b) {
	if (((MOJI*)a)->cnt < ((MOJI*)b)->cnt) {
		return 1;
	}
	else {
		return -1;
	}
}




void des(char moji[MAX][256], char tmp[256], int cnt[10]) {
	//	char tmp[256];
	for (int i = 0; i < MAX; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (cnt[i] < cnt[j]) {
				//				char tmp = cnt[i];
								//cnt[i] = cnt[j];
								//cnt[j] = tmp;



				strcpy(tmp, moji[i]);
				printf("%s, \n", tmp);

				strcpy(moji[i], moji[j]);
				//				printf("%s, \n", moji[i]);

				strcpy(moji[j], tmp);
				//				printf("%s, \n", moji[j]);
			}
		}
		//	printf("%d, \n",  cnt[i]);
		//	printf("%s, \n", moji[i]);
	}

	printf("���͕�����𕶎����̑������ɕ��ѕς��܂�\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d. ������%d: ������%s\n", i + 1, cnt[i], moji[i]);
	}


}



int main(void) {
	char moji[MAX][256];
	char tmp[256];
	int cnt[MAX];

	MOJI youso[MAX] ;

	//�L�[�{�[�h���當�������� 
	for (int i = 0; i < MAX; i++) {
		printf("������%d:", i + 1);
		//���͕������A�h���X�̕����ɓ���
		(void)scanf("%s", moji[i]);

		youso[i].moji = moji;
		youso[i].cnt= (int)strlen(youso[i].moji);
		//printf("a%s\n", moji);

	}

	// �\�[�g�O
	for (int i = 0; i < MAX; i++) {
		printf("������: % d, ������ : % s\n", youso[i].cnt, youso[i].moji);
	}

	// ���тŃ\�[�g
	qsort(youso, MAX, cnt, compar);

	// �\�[�g��
	printf("\n->\n\n");
	for (int i = 0; i < 10; i++) {
		printf("�o�Ȕԍ�:%d, ����:%d\n", youso[i].cnt, youso[i].moji);
	}

//	des(moji, tmp, cnt);
}