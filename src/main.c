#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "functions.h"
int main(int argc, char * argv[]){
	extern int words;
	char files[FILESC][NAMELEN];
	for (int i = 0; i < FILESC; i++){
		for (int j = 0; j < FILESC; j++){
			files[i][j] = '\0';
		}
	}	
	//printf("Search in : %s\n", argv[1]);
	getFiles(files, argv[2]);
		//printf("%s\n", files[y]);
	for (int i = 0; i < words; i++){
		searchStr(files[i], argv[1]);
	}
	return 0;
}
