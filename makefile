GCC=gcc
FLAGS=-g -ggdb -Wall -Werror -std=c11


main: header bitvector list main.c
	$(GCC) $(FLAGS) linked_list.o header.o bitvector.o main.c -o main



header:	header.c header.h
	$(GCC) $(FLAGS) header.c -c

bitvector: bitvector.c bitvector.h
	$(GCC) $(FLAGS) bitvector.c -c

list: linked_list.c linked_list.h
	$(GCC) $(FLAGS) linked_list.c -c


testyxan:
	ssh roca5461@yxan.it.uu.se "cd ~/project/GC;git pull;make main;./main;make clean"

clean:
	rm *.o
	rm main 
	rm *.c~
	rm *.h~

