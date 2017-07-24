#include <stdio.h>
#include "PLIB.h"

BSTnode *node(int);
BSTnode *head;
int insert2(BSTnode **,int);
int main(void){
  int data,rc;
  printf("/*** アルゴリズム4.1(挿入:head==NULLから開始可能) **\n");
  head = NULL;
  while(1){

    printf("正の整数を入力してください(-1=>print,0=>終了)");
    scanf("%d",&data);
    if(data == 0){
      break;
    } else if(data < 0){
      printf("(headの内容=%p)\n",head);
      printtree(head);
    } else {
      rc = insert2(&head,data);
      if(rc == 0){
        printf("key=%dを追加しました\n",data);
      } else {
        printf("key = %d は既に存在します\n",data);
      }
    }
  }
}

int insert2(BSTnode **head,int x){
  BSTnode *v,*up,*nr;
  if(*head==NULL){
    *head = node(x);
    return 0;
  }
  v = *head;
  while(v != NULL){
    up = v;
    if(x < v->key){
      v = v->lson;
    } else if(x > v->key){
      v = v->rson;
    } else {
      return 1;
    }
  }
  nr = node(x);
  printf("%2d(%p) ",x,nr);
  if(x < up->key){
    up->lson = nr;
  } else {
    up->rson = nr;
  }
  return 0;
}
