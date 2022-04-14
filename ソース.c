#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

#define MAX 10

/* テスト結果を降順に並べる関数

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
		printf("%d番目に短い文字列は、【%s】です。\n", i , moji[i]);
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

	printf("入力文字列を文字数の多い順に並び変えます\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d. 文字数%d: 文字列%s\n", i+1,cnt[i], moji[i]);
	}


}

/* ファイル処理
int main() {
	char moji[256];//1行に格納する文字
	int *adr;//文字列のアドレス
//	size_t cnt=0;
//	int cnt2[MAX];



	//キーボードから文字列を入力 
	for (int i = 1; i <= MAX; i++) {
		
		printf("文字列%d:", i);


		//配列の先頭アドレス
		adr = &moji[i];
		
		//入力文字をアドレスの文字に入力
		(void)scanf("%s", *moji);
//		printf("a%s\n", moji);

		printf("配列mojiの先頭のアドレスは，%p です\n", adr);
		printf("adrのさしている値は，%d です\n", *adr);

		adr += 1;    // pは，先頭から2つ先をさします 
		printf("a[2]の中身は，%d です\n", *adr);


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

	//キーボードから文字列を入力 
	for (int i = 0; i < MAX; i++) {
		printf("文字列%d:", i+1);
		//入力文字をアドレスの文字に入力
		(void)scanf("%s", moji[i]);
		//printf("a%s\n", moji);
		cnt[i] = (int)strlen(moji[i]);
	}

	des(moji,tmp,cnt);
}