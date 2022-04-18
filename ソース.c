#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

int main() {

	FILE* fp = fopen("test.txt", "r");
	/*
	while ((c = getc(fp)) != EOF) {
		//* c がアルファベットの小文字か大文字なら 
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			alpha[c]++;        //* カウントする 
		}
		printf("%c\n",c);
	}
	*/
	char a[] = { "ABBBSAaaaacccgv" };
	int cnt[52] = { 0 };

	int len = (int)strlen(a);

	char line[256];
	while (fgets(line, 256, fp) != NULL) {
//		printf("%s", line);
	}
//	printf("\n\n");
	//printf("%s\n", line[0]);
//	printf("%s\n", line);
	//int len= strlen(line);
	//printf("%d", len);

	//char line[256];
	//while (fgets(line, 256, f) != NULL) {
	//	printf("%s", line);
	//}

	//大文字、小文字を配列に入れる
	char komoji[26] = { 0 };
	char oomoji[52] = { 0 };

	int i = 0;
	for (int c = 'A'; c <= 'Z'; c++) {
		komoji[i] = c;
		printf("%c\t", komoji[i]);
		i = i++;
	}
	
	int j = 26;
	for (int c = 'a'; c <= 'z'; c++) {
		oomoji[j] = c;
		printf("%c\t", oomoji[j]);
		j = j++;
	}
	
	//カウント
	for (int k = 0; k < len; k++) {
		if (a[k] >= 'A' && a[k] <= 'Z') {
			cnt[(a[k]- 'A') ]++;
		}
		if (a[k] >= 'a' && a[k] <= 'z'){
			cnt[(a[k] - 'a') + 26]++;
		}
	}

	printf("文字の出現回数\n");
	for (int k = 0; k < 26; k++) {
		printf(" % c : % d\n", komoji[k], cnt[k]);
	}
	for (int k = 26; k < 52; k++) {
		printf(" % c : % d\n", oomoji[k], cnt[k ]);
	}

	char moji[256];
	for (int k = 0; k < 26; k++) {
		moji[k] = komoji[k];
		printf(" %c\n", komoji[k]);
	}
	for (int k = 26; k < 52; k++) {
		moji[k] = oomoji[k];
		printf(" %c\n" ,oomoji[k]);
	}


	//sort
	char tmp[256];
	for (int k = 0; k < 52; k++) {
		for (int l = k + 1; l < 52; l++) {
			if (cnt[k] < cnt[l]) {
				int tmp2 = 0;
				//tmp2= alpha[fig[k]];
				//alpha[fig[k]] = alpha[fig[j]];
				//alpha[fig[j]] = tmp;
				tmp2 = cnt[k];
				cnt[k] = cnt[l];
				cnt[l] = tmp2;

				strcpy(tmp,moji[k]);
				strcpy(moji[k], moji[l]);
				strcpy(moji[l], tmp);
			}
		}
	}



	/*
	char fig[26] = { 0 };

	int i = 0;
	for (c = 'a'; c <= 'z'; c++) {
		fig[i] = c;
		printf("%c\t", fig[i]);
		i = i++;
	}
	printf("\n\n");


	for (c = 'a'; c <= 'z'; c++) { //小文字の出現頻度を 
		printf("%c:%d\t", c, alpha[c]);
	}
	
	printf("\n\n");
	
	for (c = 'A'; c <= 'Z'; c++){    // 大文字の出現頻度を 
		printf("%c:%d\t", c, alpha[c]);        
	}
	printf("\n");

	printf("%d \t", alpha[c]);
	
	//sort
	char tmp[256]={0};
	for (int k = 0; k < 26; k++) {
		for (int j = k + 1; j < 5; j++) {
			if (alpha[fig[k]] < alpha[fig[j]]) {
				int tmp2 = 0;
				//tmp2= alpha[fig[k]];
				//alpha[fig[k]] = alpha[fig[j]];
				//alpha[fig[j]] = tmp;
				tmp2 = alpha[k];
				alpha[k] = alpha[j];
				alpha[j] = tmp;

				//strcpy(tmp,fig[k]);
				//strcpy(fig[k], fig[j]);
				//strcpy(fig[j], tmp);
			}
		}
	}
	*/
	for (int k = 0; k < 52; k++) {
		printf("%d,%c \t", cnt[k],moji[k]);
	}
	printf("\n\n");

	fclose(fp);

	return 0;
}