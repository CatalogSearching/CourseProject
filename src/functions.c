#include <string.h>
#include "defines.h"
#include <dirent.h>
#include <stdio.h>
int words = 0;

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

void getFiles(char files[][NAMELEN], char* argv){
	//printf("OKK");
	int m;
	DIR* this;
	char newArg[NAMELEN];
	this = opendir(argv);
	struct dirent* h1;
	while ((h1 = readdir(this)) != NULL){
		if (h1->d_type == 8){
			printToBuf(files, argv, h1->d_name);
		}
		else if (h1->d_type == 4 && (m = strcmp(h1->d_name, ".")) != 0 && ( m = strcmp(h1->d_name, "..") != 0)){
			strcpy(newArg, argv);			
			strcat(newArg, "/");
			strcat(newArg, h1->d_name);
			getFiles(files, newArg);
		}
		
	}
}
/*
void searchStr(char* file, char* argv){
	
}*/
