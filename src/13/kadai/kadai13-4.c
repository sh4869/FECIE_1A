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

int rotation2(BSTnode *up,BSTnode *v,int x,int rot){
  if(rot == 1) {
    if(v->lson == NULL) return 3;
    if(up==v){
      head = v->lson;
      v->lson = head->rson;
      head->rson =v;
    } else if(up->lson == v){
      up->lson = v->lson;
      v->lson = up->lson->rson;
      up->lson->rson = v;
    } else {
      up->rson = v->lson;
      v->lson = up->rson->rson;
      up->rson->rson = v;
    }
    return 0;
  }
  if(rot == 2) {
    if(v->rson == NULL) return 4;
    if(up==v){
      head = v->rson;
      v->rson = head->lson;
      head->lson = v;
    } else if(up->lson == v){
      up->lson = v->rson;
      v->rson = up->lson->lson;
      up->lson->lson = v;
    } else {
      up->rson = v->rson;
      v->rson = up->rson->lson;
      up->rson->lson = v;
    }
  }
  printf("up=%p,v=%p,x=%d,rot=%d\n",up,v,x,rot);
  return 5;
}

int rotation1(BSTnode **head,int x,int rot){
  BSTnode *v,*up;
  int rc;
  up = v = *head;
  if(head == NULL) {
    return 2;
  }
  while(v != NULL){
    if(x == v->key){
      rc = rotation2(up,v,x,rot);
      return rc;
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

int blanching(BSTnode *v,int ldepth,int rdepth){
  int d,lldepth,rrdepth;
  d = ldepth - rdepth;
  if(d*d < 2) return 0;
  if(ldepth > rdepth){
    depthcount = 0;
    lldepth = depth(v->lson->lson);
    depthcount = 0;
    rrdepth = depth(v->lson->rson);
    if(lldepth > rrdepth){
      rotation1(&head,v->key,1);
      printf("%dを中心に右回転しました\n",v->key);
      return 0;
    }
    if(lldepth < rrdepth){
      printf("%dを中心に左回転しました\n",v->lson->key);
      rotation1(&head,v->lson->key,2);
      printf("%dを中心に右回転しました\n",v->key);
      rotation1(&head,v->key,1);
      return 0;
    }
  }
  if(ldepth < rdepth){
    depthcount = 0;
    lldepth = depth(v->rson->lson);
    depthcount = 0;
    rrdepth = depth(v->rson->rson);
    if(lldepth < rrdepth){
      rotation1(&head,v->key,2);
      printf("%dを中心に左回転しました\n",v->key);
      return 0;
    }
    if(lldepth > rrdepth){
      printf("%dを中心に左回転しました\n",v->rson->key);
      rotation1(&head,v->rson->key,1);
      printf("%dを中心に右回転しました\n",v->key);
      rotation1(&head,v->key,2);
      return 0;
    }
  }
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


