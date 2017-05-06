#ifndef _STACK_H_
#define _STACK_H_


typedef struct Node {
  float data;
  struct Node * next;
} Node;

typedef struct Stack {
  int count;
  Node * top;
} Stack;

// push things onto stack Last In First Out
void push(Stack * s, float val);

// pop things off stack
float pop(Stack * s);

//Deallocate a pathNode
void freeNode(Node * s);

//Remove all nodes from a linked list, deallocate the PathLL structure
void freeStack(Stack * s);

// prints the stack to the command window
void testPrint(Stack * s);
#endif
