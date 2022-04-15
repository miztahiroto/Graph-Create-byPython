#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
	int cnt; // 文字数
	char moji;//文字列
} MOJI;

// qsortで判定するための関数。別に難しいことはしてない。aとbを比較して大きければ正の値を返せば昇順になる。
// 今回はテストの点なので値が大きい順（降順）だから、if文内の判定を逆にしている。
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

	printf("入力文字列を文字数の多い順に並び変えます\n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d. 文字数%d: 文字列%s\n", i + 1, cnt[i], moji[i]);
	}


}



int main(void) {
	char moji[MAX][256];
	char tmp[256];
	int cnt[MAX];

	MOJI youso[MAX] ;

	//キーボードから文字列を入力 
	for (int i = 0; i < MAX; i++) {
		printf("文字列%d:", i + 1);
		//入力文字をアドレスの文字に入力
		(void)scanf("%s", moji[i]);

		youso[i].moji = moji;
		youso[i].cnt= (int)strlen(youso[i].moji);
		//printf("a%s\n", moji);

	}

	// ソート前
	for (int i = 0; i < MAX; i++) {
		printf("文字数: % d, 文字列 : % s\n", youso[i].cnt, youso[i].moji);
	}

	// 成績でソート
	qsort(youso, MAX, cnt, compar);

	// ソート後
	printf("\n->\n\n");
	for (int i = 0; i < 10; i++) {
		printf("出席番号:%d, 成績:%d\n", youso[i].cnt, youso[i].moji);
	}

//	des(moji, tmp, cnt);
}