#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "calc.h"


int main (int argc, char ** argv) {
  if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./tester2 <output file>\n");
		return EXIT_FAILURE;
	}
  //makes empty stack
  Stack * s = malloc(sizeof(Stack));
  s->top = NULL;
  s->count = 0;

  // testing for stack
  float f1 = 2.1;
  float f2 = 1.1;
  float f3 = 44;
  float f4 = 4.00000;
  float f5 = -1.2;
  push(s,f1);
  push(s,f2);
  push(s,f3);
  push(s,f4);
  push(s,f5);
  testPrint(s);
  float result;
  result = pop(s);
  result = pop(s);
  result = pop(s);
  testPrint(s);


  // output to file
  FILE * fptr = fopen(argv[2], "w");
	if (fptr == NULL){
    freeStack(s);
		fclose(fptr);
	}
	else{
     freeStack(s);
	   fclose(fptr);
	}
  printf("Result: %f\n",result);

	return EXIT_SUCCESS;
}
