#include <stdio.h>
#include "PLIB.h"
#define N 7
static int data[N] = {57,22,80,14,34,70,87};
int rotation1(BSTnode **,int ,int);
int rotation2x(BSTnode *,BSTnode *,int,int);
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
      printf("Judgement(rc = %d) ",rc);
      switch(rc){
        case 2:
          printf("Empty tree\n");
          break;
        case 3:
          printf("右回転不可\n");
          break;
        case 4:
          printf("左回転不可\n");
          break;
        case 5:
          printf("正常 (処理系未作成)\n");
          break;
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
      rc = rotation2x(up,v,x,rot);
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

int rotation2x(BSTnode *up,BSTnode *v,int x,int rot){
  if((rot == 1) && (v->lson == NULL)) return 3;
  if((rot == 2) && (v->rson == NULL)) return 4;
  printf("up=%p,v=%p,x=%d,rot=%d\n",up,v,x,rot);
  return 5;
}

