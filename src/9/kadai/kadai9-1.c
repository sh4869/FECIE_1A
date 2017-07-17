#include <stdio.h>
#define STACKSIZE 10000
int stack[STACKSIZE];
int S_top = 0;
void push(int x){
  if(S_top == STACKSIZE){
    printf("Error Overflow\n");
    return;
  } else {
    stack[S_top++] = x;
  }
}

int pop(void){
  if(S_top == 0){
    printf("Error Underflow\n");
    return -1;
  }
  return stack[--S_top];
}

void printstack(int *stack){
  int i = 0;
  while(i<S_top){
    printf("stack[%d]=%d",i,stack[i]);
    i++;
  }
  printf("\n");
}

int main(void){
  int data,i;
  printf("/*** プログラム3.8 **\n");
  push(13);
  push(25);
  push(41);
  printstack(stack);
  for(i=0;i<4;i++){
    data = pop();
    if(data>0){
      printf("stack[%d]=%d\n",S_top,data);
 }
 }
  printf("*/\n");
}
