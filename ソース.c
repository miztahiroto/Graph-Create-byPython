#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

struct schedule {
    int year;        /* �N */
    int month;       /* �� */
    int day;         /* �� */
    int hour;        /* �� */
    char title[100]; /* �\�� */
};

int main() {
    struct schedule entry;

	/*�t�@�C��������*/
	FILE* g = fopen("test.txt", "w");
	fprintf(g, "");
	fclose(g);


	/*�t�@�C���ɏ�������(max10�s)*/
	for(int i=1;i<=10;i++){

		FILE* h = fopen("test.txt", "a");

		int input = 0;
		printf("�X�P�W���[������͂���ꍇ��1���A���Ȃ��ꍇ��0����͂��Ă��������B");
		(void)scanf("%d", &input);
		if (input == 1) {

			int year;
			int month;
			int hour;
			int day;
			char title[256];

			printf("�N����͂��Ă�������: ");
			(void)scanf("%d", &year);
			printf("������͂��Ă�������: ");
			(void)scanf("%d", &month);
			printf("������͂��Ă�������: ");
			(void)scanf("%d", &day);
			printf("������͂��Ă�������: ");
			(void)scanf("%d", &hour);
			printf("�^�C�g�����͂��Ă�������: ");
			(void)scanf("%s", &title);

			entry.year = year;
			entry.month = month;
			entry.day = day;
			entry.hour = hour;
			strcpy(entry.title, title);

			printf("%d : %04d/%02d/%02d %02d:00 %s\n\n",
				i, entry.year, entry.month, entry.day, entry.hour, entry.title);

			fprintf(h, "%d : %04d/%02d/%02d %02d:00 %s\n",
				i, entry.year, entry.month, entry.day, entry.hour, entry.title);
		}
		fclose(h);

		/*���͂��I������Ƃ�*/
		if (input == 0 || i==10) {
			printf("�X�P�W���[�����͂��I�����܂��B\n");
			printf("�������܂ꂽ�X�P�W���[���͉��L�ł��B\n\n");

			FILE* f = fopen("test.txt", "r");

			char line[256];
			while (fgets(line, 256, f) != NULL) {
				printf("%s", line);
			}
			fclose(f);
			break;
		}
	}
    return 0;
}