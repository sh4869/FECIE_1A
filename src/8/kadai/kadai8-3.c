#include <stdio.h>
#include <malloc.h>

typedef struct BSTnode {
  int key;
  struct BSTnode *lson;
  struct BSTnode *rson;
} BSTnode;

BSTnode *node(int data){
  BSTnode *p;
  p = (BSTnode *)malloc(sizeof(BSTnode));
  if(p != NULL){
    p->key = data;
    p->lson = NULL;
    p->rson = NULL;
  }
  return p;
}

int main(void){
  BSTnode *v,*p1,*p2,*p3;
  printf("/** Prepartion for Program 3.5 **\n");
  p1 = node(100);
  p2 = node(200);
  p3 = node(300);
  p1->lson = p2;
  p1->rson = p3;
  v=p1;
  printf("node-1 v=%p (key=%d,lson=%p,rson=%p\n",v,v->key,v->lson,v->rson);
  v=p2;
  printf("node-2 v=%p (key=%d,lson=%p,rson=%p\n",v,v->key,v->lson,v->rson);
  v=p3;
  printf("node-3 v=%p (key=%d,lson=%p,rson=%p\n",v,v->key,v->lson,v->rson);
  printf("*/\n");
}
