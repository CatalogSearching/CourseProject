#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*
void getFiles(char files[][NAMELEN], char* argv){

}*/

void searchStr(char* file, char* strFnd){
    char strSrc[1000];
    char *estr;
    int i = 0, j = 0, counter = 0;
    printf("____\nПоиск в файле: %s\n", file);

    FILE *infile = fopen(file, "r");
    while(!feof(infile)){
        counter++;
        estr = fgets(strSrc, 999, infile);
        if(estr == NULL){
            break;
        }

        i = finder(strSrc, strFnd);
        if(i != 0){
            j++;
            printf("Найдены соответствия в %d строке\n", counter);
            printf("%s\n", strSrc);
        }

    }
    if(j != 0){
        printf("[OK]\n");
    } else {
        printf("Соответствий не найдено\n[FAIL]\n");
    }
    fclose(infile);
}

int finder(char *string, char* find){
    int flag = 0;
    char *p;
    p = strstr(string, find);
    if (p == NULL){
        return flag;
    }else{
        flag ++;
        string = p + strlen(find);
        finder(string, find);
    }
    return 1;
}
