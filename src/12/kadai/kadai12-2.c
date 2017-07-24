#include <stdio.h>
#include "PLIB.h"

#define N 16
static int data[N] = {57,22,80,14,34,71,87,4,17,59,74,72,78,76,75,77};

// #define N 10
// static int data[N] = {57,22,80,14,34,71,87,4,17,59};

int delete1(BSTnode **,int);
int delete2(BSTnode *,BSTnode *,int);
int main(void){
  BSTnode * head;
  int rc,data2;
  printf("/** アルゴリズム4.2--準備--1(2分探索木の削除)**\n");
  binary_tree(&head,data,N);
  while(1){
    printf("Please input positive intger (0 end)");
    scanf("%d",&data2);
    if(data2 == 0){
      break;
    }
    if(data2<0){
      if(head != NULL){
        printf("(head = %p)\n",head);
        printtree(head);
        continue;
      }
    }
    rc = delete1(&head,data2);
    if(rc != 0){
      printf("No delete object(key = %d)\n",data2);
    }
  }
  printf("*/\n");
}

int delete1(BSTnode **head,int x){
  BSTnode *up,*v;
  up = v = *head;
  if(*head == NULL) return 2;
  if(x == v->key){
    if((v->lson == NULL) && (v->rson == NULL)){
      printf("%d(%p) : deleted\n",x,v);
      *head = NULL;
      free(v);
      return 0;
    } else if((v->lson == NULL) && (v->rson != NULL)){
      printf("%d(%p) : deleted\n",x,v);
      *head = v->rson;
      free(v);
      return 0;
    } else if((v->lson != NULL) && (v->rson == NULL)){
      printf("%d(%p) : deleted\n",x,v);
      *head = v->lson;
      free(v);
      return 0;
    }
  }
  while(v != NULL){
    if(x == v->key){
      printf("%d(%p): deleted\n",x,v);
      delete2(up,v,x);
      return 0;
    }
    up = v;
    if(x < v->key){
      v = v->lson;
    } else {
      v = v->rson;
    }
  }
  return 1;
}

int delete2(BSTnode *up,BSTnode *v,int x){
  BSTnode *v2,*up2,*t;
  if((v->lson == NULL) && (v->rson == NULL)){
    printf("@1\n");
    if(up->lson == v){
      up->lson = NULL;
      free(v);
      return 0;
    } else {
      up->rson = NULL;
      free(v);
      return 0;
    }
  } else if((v->lson != NULL) && (v->rson == NULL)){
    printf("@2\n");
    if(up->lson == v) {
      up->lson = v->lson;
    }
    if(up->rson == v){
      up->rson = v->rson;
    }
    free(v);
    return 0;
  } else if((v->lson == NULL) && (v->rson != NULL)){
    printf("@3\n");
    if(up->lson == v) {
      up->lson = v->lson;
    }
    if(up->rson == v){
      up->rson = v->rson;
    }
    free(v);
    return 0;
  } else {
    printf("@4\n");
    if((v->lson)->rson != NULL){
      up2 = v;
      v2 = v->lson;
      while(1){
        if(v2->rson != NULL){
          up2 = v2;
          v2 = v2->rson;
        } else {
          v->key = v2->key;
          up2->rson = NULL;
          free(v2);
          break;
        }
      }
    } else {
      printf("@5\n");
      t = v->lson;
      v->key = t->key;
      v->lson = (v->lson)->lson;
      free(t);
      return 0;
    }
  }
}
