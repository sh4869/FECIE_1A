#include <stdio.h>
#include "PLIB.h"

BSTnode *head;

void printtree(BSTnode *p){
  if(p == NULL) return;
  printf("%2d(%p) ",p->key,p);
  if(p->lson != NULL){
    printf("(%2d(%p)) ",(p->lson)->key,p->lson);
  } else {
    printf("(0(%p)) ",p->lson);
  }
  if(p->rson != NULL){
    printf("(%2d(%p)) \n",(p->rson)->key,p->rson);
  } else {
    printf("(0(%p))\n ",p->rson);
  }
  if(p->lson != NULL){
    printtree(p->lson);
  }
  if(p->rson != NULL){
    printtree(p->rson);
  }
}
int main(void){
  BSTnode *p57,*p22,*p80,*p14,*p34,*p71;
  printf("/**(Binary search tree: Page63 Figure1) **\n");
  head = p57 = node(57);
  p22 = node(22);
  p80 = node(80);
  tree(p57,p22,p80);
  p14 = node(14);
  p34 = node(34);
  tree(p22,p14,p34);
  p71 = node(71);
  tree(p80,p71,node(87));
  tree(p14,node(4),node(17));
  tree(p71,node(59),NULL);
  printf("**** printtree *** \n");
  printtree(head);
  printf("*/\n");
}
