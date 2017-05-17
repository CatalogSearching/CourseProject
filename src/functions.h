#ifndef FUNC_C
#define FUNC_C
#ifndef NAMELEN
#define NAMELEN 20
#endif

int getFiles(char files[][NAMELEN], char* argv);

int searchStr(char* file, char* argv);

int finder(char *string, char* find);

#endif
