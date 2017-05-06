#ifndef _CALC_H_
#define _CALC_H_

typedef enum OpType {
  ADD = '+',
  SUB = '-',
  MLT = '*',
  DIV = '/'
} OpType;

// calculates the value of two poped items and the RPN operator
float calc(float a, float b, char op);

// calculator for Reverse Polish Notation, returns result
float rpn(Stack * s, char * file_name);


#endif
