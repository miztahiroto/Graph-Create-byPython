#pragma warning(disable: 4996)
#include <stdio.h>

/* 平均 */
/*
void ave(double ave) {
    FILE* f = fopen("test.tsv", "r");
    char line[256];
    char name[256];
    int score[3]={0};

    while (fgets(line, 256, f) != NULL) {
        int total=0;
        for (int i = 1; i <= 3;i++) {
            total = total + score[i];
        }
        printf("名前:%s\n", name);
        printf("合計:%d\n", total);

        ave= total / 4;
        printf("名前:%s\n", name);
        printf("名前:%.2f\n", ave);
    }
    fclose(f);

}
*/

int main() {

    FILE* f = fopen("test.tsv", "r");
    char line[256];
    char name[256];
    int score[4];



    while (fgets(line, 256, f) != NULL) {
        (void)sscanf(line, "%s\t%d\t%d\t%d\t%d\t", &name, &score[0], &score[1], &score[2], &score[3]);
        //       for (int i = 0; i <= 3; i++) {

        //           printf("名前:%s\n", name);
        //           printf("%d点, \n", score[i]);
        for (int i = 0; i <= 3; i++) {
            for (int j= i+1; j <= 3; j++) {
                
                if (score[i] > score[j]) {
                    int tmp = score[i];
                    score[i] = score[j];
                    score[j] = tmp;
                }
                
            }
            printf("%d, ",score[i]);
        }
        printf("\n");


        int total = 0;
        for (int i = 0; i <= 3; i++) {
            total += score[i];
        }
        printf("合計:%d\n", total);
        double ave = 0;
        ave = (double)total / 4;
        printf("平均:%.2f\n", ave);
        /*
        int total = 0;
        total = score[0] + score[1] + score[2];
        printf("国語:%d点 英語:%d点 数学:%d点 物理:%d点\n", score[0], score[1], score[2], score[3]);
        printf("合計:%d\n", total);

        double ave = 0;
        ave = (double)total / 4;
        printf("平均:%.2f\n", ave);
        */

        /*
        sscanf(line, "%s\t%d\t%d\t%d\t%d\t", &name, &score[0], &score[1], &score[2], &score[3]);
        printf("名前:%s\n", name);
        printf("国語:%d点 英語:%d点 数学:%d点 物理:%d点\n", score[0], score[1], score[2], score[3]);
        */



        printf("\n");
    }

    fclose(f);
    //    printf("平均:%.2f\n",ave(ave);

    return 0;
}