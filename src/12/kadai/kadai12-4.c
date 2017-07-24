#include <stdio.h>
#include "PLIB.h"
#define N 10
static int data[N] = {57,22,80,14,34,71,87,4,17,59};
void infix1(BSTnode *);
void infix2(BSTnode *);

int main(void){
  BSTnode *head;
  printf("/*** (P.69) 4章 4.2-7 最大値/最小値の探索 **\n");
  binary_tree(&head,data,N);

  printf("\n 昇順走査(最小値から)\n ");
  infix1(head);
  printf("\n 昇順走査(最大値から)\n ");
  infix2(head);
  printf("\n*/\n");
}

void infix1(BSTnode *p){
  if(p->lson != 0) infix1(p->lson);
  printf("%d ",p->key);
  if(p->rson != 0) infix1(p->rson);
}

void infix2(BSTnode *p){
  if(p->rson != 0) infix2(p->rson);
  printf("%d ",p->key);
  if(p->lson != 0) infix2(p->lson);
}


