program: mkDir functions.o main.o
	gcc build/functions.o build/main.o -o bin/search
	make clean
functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/functions.o
main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

test: mkDir test_main.o functions_test.o functions.o
	gcc -Wall -Werror build/functions.o build/test_main.o build/functions_test.o -o bin/test 
	
functions_test.o: test/functions_test.c
	gcc -Wall -Werror -c test/functions_test.c -o build/functions_test.o
	
test_main.o:
	gcc -Wall -Werror -c test/test_main.c -o build/test_main.o

clean:
	rm build/*.o
mkDir:
	mkdir bin
	mkdir build
rmDir:
	rm -r bin
	rm -r build
rebuild: rmDir program
	echo "Done!"
