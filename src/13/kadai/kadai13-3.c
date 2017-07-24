#include <stdio.h>
#include "PLIB.h"
#define PSTACKSIZE 10000

BSTnode *node(int);
BSTnode *head;
static BSTnode * pstack[PSTACKSIZE];
static int pS_top;
static int depthcount;
void ppush(BSTnode *x){
  if(pS_top==PSTACKSIZE){
    printf("Error: Overflow\n");
    return;
  } else {
    pstack[pS_top++]  = x;
  }
}

BSTnode *ppop(void){
  if(pS_top == 0){
    printf("Error: Underflow\n");
    return NULL;
  }
  return pstack[--pS_top];
}

int depth(BSTnode *p){
  int ldepth = 0,rdepth = 0,savedepth;
  if(p==NULL) return depthcount;
  depthcount++;
  if((p->lson == NULL) && (p->rson == NULL)){
    return depthcount;
  }
  savedepth = depthcount;
  if(p->lson != NULL){
    ldepth = depth(p->lson);
  }
  if(p->rson != NULL){
    depthcount = savedepth;
    rdepth = depth(p->rson);
  }
  if(ldepth > rdepth) {
    return ldepth;
  } else {
    return rdepth;
  }
}

int blanching(BSTnode *v,int ldepth,int rdepth){
  return 0;
}
int check(){
  BSTnode *v;
  int ldepth,rdepth;
  while(1){
    if(pS_top == 0) break;
    v = ppop();
    depthcount = 0;
    ldepth = depth(v->lson);
    depthcount = 0;
    rdepth = depth(v->rson);
    printf("key=%d,ldepth=%d,rdepth=%d\n",v->key,ldepth,rdepth);
    blanching(v,ldepth,rdepth);
  }
  return 0;
}

int insert2(BSTnode **head,int x){
  BSTnode *v,*up,*nr;
  if(*head == NULL){
    *head = node(x);
    return 0;
  }
  v = *head;
  while(v != NULL){
    up = v;
    ppush(v);
    if(x < v->key) v = v->lson;
    else if (x > v->key) v = v->rson;
    else return 1;
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

int main(void){
  int data,rc;
  printf("/*** アルゴリズム4.1(挿入 head=NULLから開始可能) **\n");
  head = NULL;
  pS_top = 0;
  while(1){
    printf("正整数を入力してください(-1=>print,0=>終了):");
    scanf("%d",&data);
    if(data==0) break;
    if(data<0){
      printf("(headの内容=%p)\n",head);
      printtree(head);
      continue;
    }
    rc = insert2(&head,data);
    if(rc == 0){
      printf("key=%dを追加しました\n",data);
    } else {
      printf("key=%dは既に存在します\n",data);
    }
    check();
  }
  printf("*/\n");
}


