#include <stdio.h>
#include "PLIB.h"

#define N 4
static int data[N] = {57,80,71,87};

int delete1_x(BSTnode **,int);
int main(void){
  BSTnode * head;
  int data2;
  printf("/** アルゴリズム4.2--準備--1(2分探索木の削除)**\n");
  binary_tree(&head,data,N);
  data2 = 57;
  if(delete1_x(&head,data2) == 0){
    printf("%d delete\n",data2);
  }
  if(head != NULL){
    printtree(head);
  }
  printf("*/\n");
}

int delete1_x(BSTnode **head,int x){
  BSTnode *up,*v;
  up = v = *head;
  if(*head == NULL) return 2;
  if(x == v->key){
    if((v->lson == NULL) && (v->rson == NULL)){
      *head = NULL;
      free(v);
      return 0;
    } else if((v->lson == NULL) && (v->rson != NULL)){
      *head = v->rson;
      free(v);
      return 0;
    } else if((v->lson != NULL) && (v->rson == NULL)){
      *head = v->lson;
      free(v);
      return 0;
    }
  }
  return 1;
}
