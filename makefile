GCC=gcc
FLAGS=-g -ggdb -Wall -Werror -std=c99


main: header bitvector list padding main.c
	$(GCC) $(FLAGS) linked_list.o header.o bitvector.o padding.o main.c -o main


padding: padding.c padding.h
	$(GCC) $(FLAGS) padding.c -c

header:	header.c header.h
	$(GCC) $(FLAGS) header.c -c

bitvector: bitvector.c bitvector.h
	$(GCC) $(FLAGS) bitvector.c -c

list: linked_list.c linked_list.h
	$(GCC) $(FLAGS) linked_list.c -c



testuni:
	$(MAKE) testyxan
	$(MAKE) testfries
	$(MAKE) testtuss

testyxan:
	ssh roca5461@yxan.it.uu.se "cd ~/project/GC;git pull;make main;./main;make clean"

testtuss:
	ssh roca5461@tussilago.it.uu.se "cd ~/project/GC;git pull;make main;./main;make clean"

testfries:
	ssh roca5461@fries.it.uu.se "cd ~/project/GC;git pull;make main;./main;make clean"

clean:
	rm *.o
	rm main

cleanex:
	rm *.c~
	rm *.h~

