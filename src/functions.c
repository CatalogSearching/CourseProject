#include <string.h>
#include "defines.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int words = 0;
char colors[][5] = {"0;31","0;32"};

void printToBuf(char files[][NAMELEN], char* way, char* name){
	char toArr[NAMELEN];
	for (int i = 0; i < NAMELEN; i++)
		toArr[i] = '\0';
	strcat(toArr, way);
	strcat(toArr, "/");
	strcat(toArr, name);
	strcpy(files[words], toArr);
	words++;
}
int getFiles(char files[][NAMELEN], char* argv){
	DIR* this;
	int m, c = 0;//mod (int m;)
	char newArg[NAMELEN];
	this = opendir(argv);
	if (this == NULL){
		printf("%s Ошибка: директории не существует\n", argv);
		return 0;//mod (return;)
	}
	struct dirent* h1;
	while ((h1 = readdir(this)) != NULL){
		if (h1->d_type == 8){
			printToBuf(files, argv, h1->d_name);
			c++;
		}
		else if (h1->d_type == 4 && (m = strcmp(h1->d_name, ".")) != 0 && ( m = strcmp(h1->d_name, "..") != 0)){
			strcpy(newArg, argv);
			strcat(newArg, "/");
			strcat(newArg, h1->d_name);
			getFiles(files, newArg);
		}

	}
	return c;
}
/*
finder() - функция поиска всех вхождений подстроки find в строке string
В случае успеха возвращает количество вхождений, иначе 0
*/
int finder(char *string, char* find){

    int flag = 0;
    char *p = strstr(string, find);

    if (p == NULL){
        return flag;
    } else {
        flag ++;
        string = p + strlen(find);
        flag = flag + finder(string, find);
    }
	return flag;
}
/*
searchStr - функция поиска и вывода строк, из файла, в которых найдены подстроки strFnd
file - путь к файлу
*/
int searchStr(char* file, char* strFnd){

    char strSrc[1000];
    char *estr;
    int i = 0, j = 0, counter = 0;

    printf("Поиск в файле: %s\n", file);

    FILE *infile = fopen(file, "r");

	if (infile == NULL){
		printf("Файл не найден\n");
		return 0;
	}

    while(!feof(infile)){
        counter++;
        estr = fgets(strSrc, 999, infile);
        if(estr == NULL){
            break;
        }

        i = finder(strSrc, strFnd);
		j = j + i;
        if(i != 0){
            printf("Найдены соответствия в %d-й строке: ", counter);
			strSrc[strlen(strSrc) - 1] = '\0';
            printf("%s\n", strSrc);
        }

    }

    if(j != 0){
		printf("[");
		printf("%s%sm",CSI,colors[GREEN]);
	    printf("OK");
	    printf("%s0m",CSI);
		printf("]\n\n");
    } else {
        printf("Соответствий не найдено\n");
		printf("[");
		printf("%s%sm",CSI,colors[RED]);
	    printf("FALSE");
	    printf("%s0m",CSI);
		printf("]\n\n");
    }

    fclose(infile);
	return j;
}
