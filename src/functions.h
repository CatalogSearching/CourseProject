#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#ifndef NAMELEN
#define NAMELEN 50
#endif

int getFiles(char files[][NAMELEN], char* argv);

int searchStr(char* file, char* argv);

int finder(char *string, char* find);

#endif
