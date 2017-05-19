#define CTEST_MAIN
#define CTEST_SEGFAULT
#include "../thirdparty/ctest.h"
#include "../src/functions.h"
char vals[5][NAMELEN];
int main(int argc, const char** argv){
	getFiles(vals, "Direct");
	return ctest_main(argc, argv);
}
