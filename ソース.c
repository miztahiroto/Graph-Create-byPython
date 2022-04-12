#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>

struct schedule {
    int year;        /* 年 */
    int month;       /* 月 */
    int day;         /* 日 */
    int hour;        /* 時 */
    char title[100]; /* 予定 */
};

int main() {
    struct schedule entry;

	/*ファイル初期化*/
	FILE* g = fopen("test.txt", "w");
	fprintf(g, "");
	fclose(g);


	/*ファイルに書き込み(max10行)*/
	for(int i=1;i<=10;i++){

		FILE* h = fopen("test.txt", "a");

		int input = 0;
		printf("スケジュールを入力する場合は1を、しない場合は0を入力してください。");
		(void)scanf("%d", &input);
		if (input == 1) {

			int year;
			int month;
			int hour;
			int day;
			char title[256];

			printf("年を入力してください: ");
			(void)scanf("%d", &year);
			printf("月を入力してください: ");
			(void)scanf("%d", &month);
			printf("日を入力してください: ");
			(void)scanf("%d", &day);
			printf("時を入力してください: ");
			(void)scanf("%d", &hour);
			printf("タイトル入力してください: ");
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

		/*入力を終了するとき*/
		if (input == 0 || i==10) {
			printf("スケジュール入力を終了します。\n");
			printf("書き込まれたスケジュールは下記です。\n\n");

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