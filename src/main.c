#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "functions.h"

int main(int argc, char * argv[]){

	if (argc < 3) {
		char help_flag[] = "-help";
		if (argc == 2){
			if (strcmp(argv[1], help_flag) == 0){
				printf("./bin/search <строка> <пути до директорий через пробел>\n");
				return 0;
			}
			printf("Некорректное количество аргументов, введите ./search -help для просмотра доступных команд\n");
			return 1;
		}
		printf("Некорректное количество аргументов, введите ./search -help для просмотра доступных команд\n");
		return 1;
	}

	extern int words;
	char files[FILESC][NAMELEN];
	int count_files = 0, count = 0;
	char colors[][5] = {"0;31","0;32"};

	//Основной цикл
	for (int i = 2; i < argc; i++){
		for (int i = 0; i < FILESC; i++){
			for (int j = 0; j < FILESC; j++){
				files[i][j] = '\0';
			}
		}
		words = 0;
		count_files = count_files + getFiles(files, argv[i]);
		for (int j = 0; j < words; j++){
			count = count + searchStr(files[j], argv[1]);
		}
	}

	if (count == 0){
		printf("%s%sm",CSI,colors[RED]);
	} else {
		printf("%s%sm",CSI,colors[GREEN]);
	}

	if (count % 10 == 1){
		printf("Найдено %d соответствие", count);
	} else if (count % 10 == 2 || count % 10 == 3 || count % 10 == 4){
		printf("Найдено %d соответствия", count);
	} else {
		printf("Найдено %d соответствий", count);
	}

	if (count_files % 10 == 1){
		printf(" в %d файле\n", count_files);
	} else {
		printf(" в %d файлах\n", count_files);
	}
	return 0;
}
