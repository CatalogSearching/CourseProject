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
	printf("Search in : %s\n", argv[1]);
	printf("%c\n", files[2][2]);
	getFiles(files, argv[1]);
	for (int y = 0; y < words; y++){
		printf("%s\n", files[y]);
	}
	return 0;
}
