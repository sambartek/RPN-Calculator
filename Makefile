CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)
OBJS = pa11.o stack.o calc.o

all: $(OBJS) stack.h calc.h
	$(GCC) $(OBJS) -o pa11

pa11: $(OBJS) stack.h calc.h
	$(GCC) $(OBJS) -o pa11

pa11.o: pa11.c stack.h calc.h
	$(GCC) -c pa11.c -o pa11.o

stack.o: stack.c stack.h
	$(GCC) -c stack.c -o stack.o

calc.o: calc.c calc.h stack.h
	$(GCC) -c calc.c -o calc.o

tester2:  test2.o stack.o calc.o stack.h calc.h
	$(GCC)  test2.o stack.o calc.o -o tester2

test2.o: test2.c stack.h calc.h
	$(GCC) -c test2.c -o test2.o

# "make test" will run the three input files
test: pa11
	-./pa11 inputs/test1
	-./pa11 inputs/test2
	-./pa11 inputs/test3
	-./pa11 inputs/test4
	-./pa11 inputs/test5
	-./pa11 inputs/test6
	-./pa11 inputs/test7
	-./pa11 inputs/test8
	-./pa11 inputs/test9
	-./pa11 inputs/test10
	-./pa11 inputs/test11
	-./pa11 inputs/test12

test2: tester2
	./tester2 output6

# "make memory" calls valgrind to check memory errors
memory: pa11
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test1
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test2
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test3
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test4
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test5
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test6
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test7
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test8
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test9
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test10
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test11
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test12
tmemory: pa11
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test8

clean:
	/bin/rm -f *.o
	/bin/rm -f testgen
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f *.out
	/bin/rm -f output1 output2 output3 output4 output5 output6 output7 output8 output9 output10 output11 output 12 tester2 pa11
