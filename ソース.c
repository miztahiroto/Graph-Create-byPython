#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include <fcntl.h>

//char�^�Ń������m��
char* MallocChar(long size){
	char* p;
	if (!(p = (char*)malloc(size)))
		return NULL;
	memset(p, 0, size);
	return p;
}

//���������̕�����\��
void Print(const char* p, long size){
	for (int i = 0; i < size; i++)
		printf("%c", *p++);
}

//�t�@�C���T�C�Y�擾
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
	//	snprintf(message, 300, "%s�͑��݂��܂���B\n", file);
	//	Quit(message);
	//}

	size = GetFileSize(fd);
	if (size <= 0){
		printf("�t�@�C���T�C�Y���擾�ł��܂���ł����B\n");
	}
	if (size > 0) {
		printf("�t�@�C���T�C�Y��%d�o�C�g�ł��B\n\n", size);
		printf("�ȉ��A�t�@�C���̓��e�ł��B\n");
	}

	p = MallocChar(size);
	if (!p){
		printf("�������̊m�ۂɎ��s���܂����B\n");
	}

	fread(p, size, 1, fp);

	fclose(fp);

	//�\��
	Print(p, size);

	free(p);

	return 0;
}