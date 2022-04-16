CC = gcc

a.out: main.o hello.o nested_folder/random.o
	gcc main.o hello.o

hello.o: hello.s
	gcc -c $^

hello.s: hello.c
	gcc -S -Og $^

main.o: main.c
	gcc -c $^

test:
	cd nestedFolder; ${MAKE}

clean:
	-rm -rvf *.o
	-rm a.out
	-rm hello.s
	cd nestedFolder; ${MAKE} clean

clean2:
	-rm -rvf *.o
	-rm a.out
