#include <stdio.h>
#include "PLIB.h"

LIST *head1 = NULL;

BSTnode *head2;

int main(void){
  LIST *nr,*p;
  int data,rc,i = 1,n = 1,m = 23456;
  BSTnode *p1,*p2,*p3,*p4,*p5,*p6,*p7,*px,*py;
  printf("/** Test-08\n");
  head1 = inputdata(head1);
  if(head1==NULL){
    printf("exit (no data)\n");
    return 1;
  }
  printf("\n%d番目(または末尾)の次の%dを追加指定\n",n,m);
  p = head1;
  nr = (LIST *)malloc(sizeof(LIST));
  nr->next = NULL;
  nr->data = m;
  while(i<n){
    if(p->next==NULL){ 
      break;
    } else {
      p=p->next;
    }
    i++;
  }
  nr->next = p->next;
  p->next = nr;
  printlist(head1);

  printf("\n** 問2 空欄を埋めなさい**\n");
  p1=node(100);
  p2=node(200);
  p3=node(300);
  p4=node(400);
  p5=node(500);
  p6=node(600);
  p7=node(700);
  head2 = p4;
  tree(p4,p2,p6);
  tree(p2,p1,p3);
  tree(p6,p5,p7);

  px=node(250);
  py=node(380);
  tree(p3,px,py);
  printf("\nhead2=%p\n",head2);
  while(1){
    printf("正の整数を入力:");
    scanf("%d",&data);
    if(data<=0) break;
    rc = search(head2,data);
    if(rc==0){
      printf("key=%d:あり\n",data);
    } else {
      printf("key=%d:なし\n",data);
    }
  }
  printf("\n**問3 上の問題の2分探索木を図示しなさい(簡略図) **\n");
  printf("*/\n");
  return 0;
}
