#include <stdio.h>
#include "../thirdparty/ctest.h"
#include "../src/functions.h"

CTEST(GetFiles, File_1){
	const char exp[] = "Direct/AgainText.txt";
	extern char vals[5][NAMELEN];
	ASSERT_STR(exp, vals[0]);
}
CTEST(GetFiles, File_2){
	const char exp[] = "Direct/text.txt";
	extern char vals[5][NAMELEN];
	ASSERT_STR(exp, vals[1]);
}
CTEST(GetFiles, File_3){
	const char exp[] = "Direct/OneMoreDir/text.txt";
	extern char vals[5][NAMELEN];
	ASSERT_STR(exp, vals[2]);
}
CTEST(GetFiles, File_4){
	const char exp[] = "Direct/anotherDir/MoreTexts.txt";
	extern char vals[5][NAMELEN];
	ASSERT_STR(exp, vals[3]);
}
CTEST(GetFiles, File_5){
	const char exp[] = "Direct/anotherDir/textFile.txt";
	extern char vals[5][NAMELEN];
	ASSERT_STR(exp, vals[4]);
}
CTEST(GetFiles, Filedoesntexist){
	const char exp = 0;
	char vl[5][NAMELEN];
	int val = getFiles(vl, "ifExist");
	ASSERT_EQUAL(val, exp);
}
/*CTEST(GetFiles, GetValue){
	const int exp = 5;
	char arr[6][NAMELEN];
	int v1; 
	v1 = getFiles(arr, "Direct");
	ASSERT_EQUAL(exp, v1);
}*/
