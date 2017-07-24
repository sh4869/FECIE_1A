#include <stdio.h>
#include "PLIB.h"
#define N 11
static int data[N] = {60,30,24,80,14,34,71,87,4,17,59};
int delete1(BSTnode **,int);
int delete2(BSTnode *,BSTnode *,int);

int main(void){
  BSTnode *head;
  int rc,data2;
  printf("/* (P.66) アルゴリズム 4.2 2分探索木への要素の削除 **\n");
  binary_tree(&head,data,N);

  while(1){
    printf("正整数を入力してください(0は終了):");
    scanf("%d",&data2);
    if(data2==0) break;
    if(data2<0) {
      if(head != NULL){
        printf("(headの内容=%p)\n",head);
        printtree(head);
      }
      continue;
    }
    rc = delete1(&head,data2);
    if(rc != 0){
      printf("削除対象(key=%d) 無し\n",data2);
    }
  }
  printf("\n*/\n");
}

int delete1(BSTnode **head,int x){
  BSTnode *up,*v;
  up = v = *head;
  if(*head == NULL) return 2;
  if(x== v->key){
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
  if((v->lson == NULL) && (v->rson==NULL)){
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
    if(up->lson == v){
      up->lson = v->lson;
    }
    if(up->rson == v){
      up->rson = v->lson;
    }
    free(v);
    return 0;
  } else if((v->lson == NULL) && (v->rson != NULL)){
    if(up->lson == v){
      up->lson = v->rson;
    }
    if(up->rson == v){
      up->rson = v->rson;
    }
    free(v);
    return 0;
  } else {
    if((v->lson)->rson != NULL){
      up2 = v;
      v2 = v->lson;
      while(1){
        if(v2->rson != NULL){
          up2 = v2;
          v2 = up2->lson;
        } else {
          v->key = v2->key;
          up2->rson = v2->lson;
          free(v2);
          break;
        }
      }
      return 0;
    } else {
      t = v->lson;
      v->key = t->key;
      v->lson = t->lson;
      free(t);
      return 0;
    }
  }
}
