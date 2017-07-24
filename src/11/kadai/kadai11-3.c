#include <stdio.h>
#include "PLIB.h"

BSTnode *node(int);
BSTnode *head;
int insert1(BSTnode *,int );

int main(void){
  BSTnode *p57,*p22,*p80,*p14,*p34,*p71;
  int data,rc;
  printf("/*** アルゴリズム4.1 **\n");
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
  while(1){
    printf("正の整数を入力してください(-1=>print,0=>終了)");
    scanf("%d",&data);
    if(data == 0){
      break;
    } else if(data < 0){
      printf("(headの内容=%p)\n",head);
      printtree(head);
    } else {
      rc = insert1(head,data);
      if(rc == 0){
        printf("key=%dを追加しました\n",data);
      } else {
        printf("key = %d は既に存在します\n",data);
      }
    }
  }
}

int insert1(BSTnode *head,int x){
  BSTnode *v,*up,*nr;
  v = head;
  printf("Trace:");
  while(v != NULL){
    up = v;
    printf(" %d,",v->key);
    if(x < v->key){
      v = v->lson;
    } else if(x > v->key){
      v = v->rson;
    } else {
      return 1;
    }
  }
  printf("\n");
  nr = node(x);
  printf("%2d(%p) ",x,nr);
  if(x < up->key){
    up->lson = nr;
  } else {
    up->rson = nr;
  }
  return 0;
}
