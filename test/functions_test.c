#include <stdio.h>
#include "../thirdparty/ctest.h"
#include "../src/functions.h"
#include "../src/defines.h"


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
char src1[] = "This is testsource string 1";
char src2[] = "This is test source str1ng 2";
char src3[] = "This is test source string string string 3";
char src4[] = "This is test source 4";
char src5[] = "This is test source strring 3";
char src6[] = "lol";
char src7[] = "";

char file1[] = "../data/text";//true
char file2[] = "../data/ts/text3";//true
char file3[] = "../data/text3";//false



char find[] = "string";
char find2[] = "test";

CTEST(SearchTest, finder_test_1){
    int exp = finder(src1, find);
    ASSERT_EQUAL(1, exp);
}

CTEST(SearchTest, finder_test_2){
    int exp = finder(src2, find);
    ASSERT_EQUAL(0, exp);
}

CTEST(SearchTest, finder_test_3){
    int exp = finder(src3, find);
    ASSERT_EQUAL(3, exp);
}

CTEST(SearchTest, finder_test_4){
    int exp = finder(src4, find);
    ASSERT_EQUAL(0, exp);
}

CTEST(SearchTest, finder_test_5){
    int exp = finder(src5, find);
    ASSERT_EQUAL(0, exp);
}

CTEST(SearchTest, finder_test_6){
    int exp = finder(src6, find);
    ASSERT_EQUAL(0, exp);
}

CTEST(SearchTest, finder_test_7){
    int exp = finder(src7, find);
    ASSERT_EQUAL(0, exp);
}

CTEST(SearchTest, searchStr_test1){
    printf("\nДолжно быть найдено 1 соответствие\n");
    int exp = searchStr(file1, find2);
    ASSERT_EQUAL(1, exp);
}

CTEST(SearchTest, searchStr_test2){
    printf("\nДолжно быть найдено 1 соответствие\n");
    int exp = searchStr(file2, find2);
    ASSERT_EQUAL(1, exp);
}

CTEST(SearchTest, searchStr_test3){
    printf("\nНе должно быть найдено соответствий\n");
    int exp = searchStr(file3, find2);
    ASSERT_EQUAL(0, exp);
}

CTEST(SearchTest, searchStr_test4){
    printf("\nФайл не должен открыться\n");
    int exp = searchStr("acv", find2);
    ASSERT_EQUAL(0, exp);
}
