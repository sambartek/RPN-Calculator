#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void push(Stack * s, float val) {
  if (s == NULL) {
    return;
  }
  Node * new = malloc(sizeof(Node));
  new->data = val;
  new->next = NULL;
  Node * old_top = s->top;
  s->top = new;
  new->next = old_top;
  s->count ++;
}

float pop(Stack * s) {
  if (s == NULL || s->top == NULL) {
    exit( EXIT_FAILURE);
  }
  if (s->count <= 0) {
    freeStack(s);
    exit(EXIT_FAILURE);
  }
  float retval = s->top->data;
  Node * old_top = s->top;
  Node * new_top = s->top->next;
  s->top = new_top;
  freeNode(old_top);
  s->count --;
  return retval;
}

void freeNode(Node * old) {
  free(old);
}

void freeStack(Stack * s) {
  Node * tmp = NULL;
  while (s->top != NULL) {
    tmp = s->top;
    s->top = s->top->next;
    freeNode(tmp);
  }
  free(s);
}

void testPrint(Stack * s){
  if (s == NULL){
    return;
  }
  Node * curr = s->top;
  int x = 0;
  while (curr != NULL) {
		printf("Value %d: %f\n", x, curr->data);
		x++;
		curr = curr->next;
	}
}
