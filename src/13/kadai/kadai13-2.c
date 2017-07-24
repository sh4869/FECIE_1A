#include <stdio.h>
#include "PLIB.h"
#define N 15
static int data[N] = {57,22,80,14,34,70,87,4,17,75,65,30,84,40,90};
int rotation1(BSTnode **,int ,int);
int rotation2(BSTnode *,BSTnode *,int,int);
BSTnode *head;

int main(void){
  int data2,rot,rc;
  printf("/*** 4.3章 1.バランスを保つための変形操作 **\n");
  binary_tree(&head,data,N);
  while(1){
    printf("ノード番号と回転向きを入力(例: 57 1 (1:右、2:左,0:終了)):");
    scanf("%d",&data2);
    if(data2<1){
      printf("*/\n");
      return 1;
    }
    scanf("%d",&rot);
    if((rot < 1) || (rot > 3)){
      printf("*/\n");
      return 1;
    }
    rc = rotation1(&head,data2,rot);
    if(rc == 0){
      if(rot == 1){
        printf("** %dを中心に、右1重回転しました **\n",data2);
      } else {
        printf("** %dを中心に、左1重回転しました **\n",data2);
      }
      printtree(head);
    } else {
      if(rot == 1){
        printf("右回転不可(左の子なし)\n");
      } else if(rot == 2){
        printf("左回転不可(右の子なし)\n");
      } else {
        printf("プログラムエラー(rc=%d)\n",rc);
      }
    }
  }
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
      v->lson = up->lson->rson;
      up->lson->lson = v;
    } else {
      up->rson = v->rson;
      v->lson = up->rson->lson;
      up->lson->lson = v;
    }
  }
  printf("up=%p,v=%p,x=%d,rot=%d\n",up,v,x,rot);
  return 5;
}

