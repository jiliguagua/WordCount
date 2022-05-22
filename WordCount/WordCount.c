#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("参数错误！");
        exit(0);
    }
    char c;
    char word[20];
    int countWord = 0, countC = 0;
    char* type = argv[1];
    FILE* fp;
    if ((fp = fopen(argv[2], "r")) == NULL) {
        printf("文件打不开！");
        exit(0);
    }
    while (fscanf(fp, "%s", word) == 1) {
        if (word[1] != '\0')
            for (int i = 1; word[i + 1] != '\0'; i++)
                if (word[i] == ',')
                    countWord++;
                else if (word[0] == ',')
                    continue;
        countWord++;
    }
    rewind(fp);
    while ((c = getc(fp)) != EOF) {
        countC++;
    }
    if (type[1] == 'c')
        printf("字符数:%d", countC);
    else if (type[1] == 'w')
        printf("单词数:%d", countWord);
    else
        printf("参数错误！");
    return 0;
}