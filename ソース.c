#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

#define MAX 10

/* �e�X�g���ʂ��~���ɕ��ׂ�֐�

void des(char *moji[256], int cnt[256]) {
	char tmp[256];
	for (int i = 1; i <= MAX; i++) {
		for (int j = i+1; j <= MAX; j++) {
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
	for (int i = 0; i < MAX; ++i) {
		printf("%d�ԖڂɒZ��������́A�y%s�z�ł��B\n", i , moji[i]);
	}

	
}
*/

void des(char moji[MAX][256],char tmp[256], int cnt[10]) {
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
		printf("%d. ������%d: ������%s\n", i+1,cnt[i], moji[i]);
	}


}

/* �t�@�C������
int main() {
	char moji[256];//1�s�Ɋi�[���镶��
	int *adr;//������̃A�h���X
//	size_t cnt=0;
//	int cnt2[MAX];



	//�L�[�{�[�h���當�������� 
	for (int i = 1; i <= MAX; i++) {
		
		printf("������%d:", i);


		//�z��̐擪�A�h���X
		adr = &moji[i];
		
		//���͕������A�h���X�̕����ɓ���
		(void)scanf("%s", *moji);
//		printf("a%s\n", moji);

		printf("�z��moji�̐擪�̃A�h���X�́C%p �ł�\n", adr);
		printf("adr�̂����Ă���l�́C%d �ł�\n", *adr);

		adr += 1;    // p�́C�擪����2��������܂� 
		printf("a[2]�̒��g�́C%d �ł�\n", *adr);


//		moji[i] = arr;
//		printf("b%s\n", *moji);

//		cnt = strlen(moji[i]);
//		printf("c%d\n", cnt[i]);
//		cnt2[i] = (int)cnt;
	}

	//for (int i = 1; i <= MAX; ++i) {
	//	printf("%d, %s\n",i, moji[i]);
	//}

	//des(moji, cnt);

//	return 0;
}
*/

int main(void) {
	char moji[MAX][256];
	char tmp[256];
	int cnt[MAX];

	//�L�[�{�[�h���當�������� 
	for (int i = 0; i < MAX; i++) {
		printf("������%d:", i+1);
		//���͕������A�h���X�̕����ɓ���
		(void)scanf("%s", moji[i]);
		//printf("a%s\n", moji);
		cnt[i] = (int)strlen(moji[i]);
	}

	des(moji,tmp,cnt);
}