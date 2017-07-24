#include <stdio.h>
typedef struct LIST {
  int data;
  float x;
} LIST;

void swap_err(int,int);
void swap(int*,int*);
void swap_ptr(LIST**,LIST**);
int main(void){
  int aa=100,bb=200;
  LIST *h1,*h2,block1,block2;
  printf("/** 準備(ポインタの引数とSWAP)**\n");

  printf("(case-1) swap_err aa=%d bb=%d\n",aa,bb);
  swap_err(aa,bb);
  printf("after  swap_err aa=%d bb=%d\n",aa,bb);

  printf("(case-2) swap aa=%d bb=%d\n",aa,bb);
  swap(&aa,&bb);
  printf("after  swap aa=%d bb=%d\n",aa,bb);
  h1 = &block1;
  block1.data = 1111;
  block1.x = 11.1f;
  h2 = &block2;
  block2.data = 2222;
  block2.x = 22.2f;

  printf("(case-3)\n");
  printf("h1=%p,h1->data=%d,h1->x=%0.2f\n",h1,h1->data,h1->x);
  printf("h2=%p,h2->data=%d,h2->x=%0.2f\n",h2,h2->data,h2->x);
  swap_ptr(&h1,&h2);
  printf("after swap_ptr\n");
  printf("h1=%p,h1->data=%d,h1->x=%0.2f\n",h1,h1->data,h1->x);
  printf("h2=%p,h2->data=%d,h2->x=%0.2f\n",h2,h2->data,h2->x);
  printf("*/\n");
}

void swap_err(int a,int b){
  int t;
  t = a;
  a = b;
  b = t;
  printf("\n Inside swap_err a=%d,b=%d",a,b);
}

void swap(int *a,int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void swap_ptr(LIST **a,LIST **b){
  LIST *t;
  t = *a;
  *a = *b;
  *b = t;
}

