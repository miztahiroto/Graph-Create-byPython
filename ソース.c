#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include <fcntl.h>

//ファイルサイズ取得
int GetFileSize(int f) {
	struct stat sb;
	fstat(f,&sb);
	return sb.st_size;
}

//メモリ確保
char* MallocChar(long size) {
	char* p = (char*)malloc(size);
	memset(p,0,size);
	return p;
}

//バイトの平均を計算
void Ave(char *p,int size) {
	double total = 0;

	// 全バイナリデータ出力
	for (int i = 0; i < size; i++) {
		total = total + p[i];
//		printf("binary: %x\n", p[i]);
	}
	

	printf("total: %.2f\n", total);
	double average = 0;
	average = total / (double)size;
	printf("average: %.2f\n", average);
//	return average;
}

int main(void){
	int size;
	char* p;
//	double average =0;
	//double total = 0;
	const char* file = "data.dat";


//	バイナリファイルの読み込みでオープン
	FILE* fp = fopen(file, "rb");

	int fd = open(file, O_RDONLY);
	size = GetFileSize(fd);

	p = MallocChar(size);

	printf("ファイルサイズ：%dbyte\n",size);


	//	ファイルからの読み込み
	fread(p, size,1, fp);

	/*
	//	読み込んだデータを画面に表示
	for (int i = 0; i < size ; i++)	{
		printf("0x%x ", p[i]);
	}
	printf("\n");
	*/

	Ave(p,size);
//	printf("\n\n");
//	printf("%f\n",average);
//	printf("total2：%f\n", total);

//	printf("ave: %f\n", average);

	fclose(fp);
	free(p);
	return 0;
}