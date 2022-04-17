#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include <fcntl.h>

//char型でメモリ確保
char* MallocChar(long size){
	char* p;
	if (!(p = (char*)malloc(size)))
		return NULL;
	memset(p, 0, size);
	return p;
}

//メモリ内の文字を表示
void Print(const char* p, long size){
	for (int i = 0; i < size; i++)
		printf("%c", *p++);
}

//ファイルサイズ取得
int GetFileSize(int f) {
	struct stat sb;
	fstat(f, &sb);
	return sb.st_size;
}

int main(){
	const char* file = "test.txt";
	FILE* fp;
	int size;
	char* p;

//	int fd = fopen(file, "r");
	fopen_s(&fp, file, "rb");
//	FILE* fp = fopen("test.txt", "r");
	int fd = open(file, O_RDONLY);

	//if (fp == NULL)	{
//		char message[300];
	//	snprintf(message, 300, "%sは存在しません。\n", file);
	//	Quit(message);
	//}

	size = GetFileSize(fd);
	if (size <= 0){
		printf("ファイルサイズを取得できませんでした。\n");
	}
	if (size > 0) {
		printf("ファイルサイズは%dバイトです。\n\n", size);
		printf("以下、ファイルの内容です。\n");
	}

	p = MallocChar(size);
	if (!p){
		printf("メモリの確保に失敗しました。\n");
	}

	fread(p, size, 1, fp);

	fclose(fp);

	//表示
	Print(p, size);

	free(p);

	return 0;
}