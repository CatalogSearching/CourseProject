program: mkDir functions.o main.o
	gcc build/functions.o build/main.o -o bin/search
	make clean
functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/functions.o
main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o
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
