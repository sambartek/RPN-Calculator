#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");
		return EXIT_FAILURE;
	}

	Stack * s = malloc(sizeof(Stack));
	s->top = NULL;
  s->count = 0;

	float result = rpn(s, argv[1]); //store the result of your calculation here.

  freeStack(s);
	/* Insert code here to perform the RPN calculation.
	Don't forget to free any memory you allocate once you're done with it! */

	printf("%f\n", result);

	return EXIT_SUCCESS;
}
