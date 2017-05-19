#include <stdio.h>
#include "../src/functions.h"
#include "../thirdparty/ctest.h"
#include "../src/defines.h"

char src1[] = "This is testsource string 1";
char src2[] = "This is test source str1ng 2";
char src3[] = "This is test source string string string 3";
char src4[] = "This is test source 4";
char src5[] = "This is test source strring 3";
char src6[] = "lol";
char src7[] = "";

char find[] = "string";

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
