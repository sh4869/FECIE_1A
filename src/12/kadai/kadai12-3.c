#include <stdio.h>
#include "PLIB.h"

#define N 12
static int data[N]={57,60,70,65,90,62,80,98,75,84,88,86};
// #define N 8
// static int data[N]={57,22,60,14,34,30,45,4};
#define PATH_MAXN 10
int front1(BSTnode *,int,int *);
int front2(BSTnode *,int,int *);
BSTnode *path[PATH_MAXN];
int depth;
int main(void){
  BSTnode *head;
  int data2,rc,frontkey;
  printf("/*** 4章 4.2-6 直前キーの探索(P.69) **\n");
  binary_tree(&head,data,N);
  while(1){
    printf("正整数を入力してください(0は資料) ");
    scanf("%d",&data2);
    if(data2==0) break;
    if(data2<0){
      printtree(head);
      continue;
    }
    rc = front1(head,data2,&frontkey);
    if(rc==0){
      printf("キー%dの直前のキーは%dです\n",data2,frontkey);
    } else {
      printf("\nキー(key=%d)の直前キー無し(またはキー%dは存在しない)\n",data2,data2);
    }
  }
}

int front1(BSTnode *head,int in_key,int *frontkey){
  int answer,rc;
  BSTnode * v;
  depth = -1;
  v = head;
  if(head == NULL) return 2;
  while(v != NULL){
    path[++depth] = v;
    printf("path[%d]=%p ",depth,path[depth]);
    if(in_key == v->key){
      rc = front2(v,in_key,&answer);
      if(rc == 0){
        *frontkey = answer;
        return 0;
      } else {
        return -1;
      }
    }
    if(in_key < v->key) {
      v = v->lson;
    } else {
      v = v->rson;
    }
  }
}

int front2(BSTnode *v,int in_key,int *answer){
  BSTnode *p,*up2,*v2;
  if((v->lson == NULL) && (depth == 0)){
    printf("\n(case-1) key=%d(%p) ",v->key,v);
    return 1;
  }
  if((v->lson == NULL) && (depth > 0)){
    if(path[depth - 1]->rson == path[depth]){
      p = path[depth - 1];
      *answer = p->key;
      printf("\n(case-2-1) key=%d(%p) ",p->key,p);
      return 0;
    } else {
      depth--;
      p = path[depth];
      while(p->rson != path[depth+1]){
        if(depth>0) {
          depth--;
        } else {
          return 1;
        }
        p = path[depth];
      }
      *answer = p->key;
      printf("\n(case-2-2)key=%d(%p) ",p->key,p);
      return 0;
    }
  }
  if((v->lson!=NULL) && (v->lson->rson == NULL)){
    p = path[depth]->lson;
    *answer = p->key;
    printf("\n(case-3),key=%d(%p) ",p->key,p);
    return 0;
  }
  if((v->lson != NULL) && (v->lson->rson != NULL)){
    up2 = path[depth];
    v2 = up2->lson;
    while(1){
      if(v2->lson != NULL){
        up2 = v2;
        v2 = up2->lson;
      } else {
        break;
      }
    }
    *answer = v2->key;
    printf("\n(case-4) key=%d(%p) ",v2->key,v2);
    return 0;
  }
  return 1;
}
