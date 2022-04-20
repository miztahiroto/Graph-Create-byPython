#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include <fcntl.h>

//�t�@�C���T�C�Y�擾
int GetFileSize(int f) {
	struct stat sb;
	fstat(f,&sb);
	return sb.st_size;
}

//�������m��
char* MallocChar(long size) {
	char* p = (char*)malloc(size);
	memset(p,0,size);
	return p;
}

//�o�C�g�̕��ς��v�Z
void Ave(char *p,int size) {
	double total = 0;

	// �S�o�C�i���f�[�^�o��
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


//	�o�C�i���t�@�C���̓ǂݍ��݂ŃI�[�v��
	FILE* fp = fopen(file, "rb");

	int fd = open(file, O_RDONLY);
	size = GetFileSize(fd);

	p = MallocChar(size);

	printf("�t�@�C���T�C�Y�F%dbyte\n",size);


	//	�t�@�C������̓ǂݍ���
	fread(p, size,1, fp);

	/*
	//	�ǂݍ��񂾃f�[�^����ʂɕ\��
	for (int i = 0; i < size ; i++)	{
		printf("0x%x ", p[i]);
	}
	printf("\n");
	*/

	Ave(p,size);
//	printf("\n\n");
//	printf("%f\n",average);
//	printf("total2�F%f\n", total);

//	printf("ave: %f\n", average);

	fclose(fp);
	free(p);
	return 0;
}