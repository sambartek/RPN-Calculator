#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "calc.h"

float calc(float a, float b, char op) {
  if (op == ADD) {
    return (a + b);
  }
  else if (op == SUB) {
    return (b - a);
  }
  else if (op == MLT) {
    return (a * b);
  }
  else if (op == DIV) {
    return (b / a);
  }
  else{
    //printf("\nERROR: There is an error in calc.c\n");
    exit(EXIT_FAILURE);
  }
}

float rpn(Stack * s, char * file_name) {
  FILE * fptr = fopen(file_name, "r");
  if (fptr == NULL) {
    //fprintf( "ERROR: Could not open file for reading\n");
    freeStack(s);
    exit(EXIT_FAILURE);
  }
  char * str = malloc(sizeof(char)*256);
  float a = 0;
  float b = 0;
  float new = 0;
  float num = 0;
  char str_tst;
  int x = 0;
  int len;
  while (fscanf(fptr, "%s", &str[x]) != EOF) {
    str_tst = str[x];
    len = strlen(&str[x]);
    if ((str_tst == ADD || str_tst == SUB || str_tst == DIV || str_tst == MLT) && len == 1) {
      a = pop(s);
      b = pop(s);
      new = calc(a, b, str[x]);
      push(s, new);
      //printf("Push: %f\n",new);
    }
    else {
      num = (float) atof(&str[x]);
      push(s, num);
      //printf("%f\n",num);
    }
    x++; // end while loop
  }
  //testPrint(s);
  free(str);
  if (s->count > 1) {
    //fprintf(stderr, "ERROR: Too many items left in stack.\n");
    fclose(fptr);
    freeStack(s);
    exit(EXIT_FAILURE);
  }
  else{
    fclose(fptr);
    return pop(s);
  }
}
