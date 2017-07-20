#include <stdio.h>
#include <malloc.h>
#include "PLIB.h"

void push_list(int x,struct LIST **head){
  struct LIST *nr;
  nr = (struct LIST *)(malloc(sizeof(struct LIST)));
  if(nr == NULL){
    printf("** メモリ確保失敗 **\n");
    return;
  }
  if(*head == NULL) {
    nr->data = x;
    nr->next = NULL;
    *head = nr;
  } else {
    nr->data = x;
    nr->next=*head;
    *head = nr;
  }
  printf("p=%p,push x=%d\n",nr,x);
}

int pop_list(struct LIST **head){
  struct LIST *p;
  int t;
  if(*head == NULL){
    printf("POP-error: Underflow\n");
    return -1;
  }
  p = *head;
  t = p->data;
  *head = p->next;
  free(p);
  printf("p=%p, freed: ",p);
  return t;
}

int main(void){
  struct LIST *head = NULL;
  printf("/** 第三章 - 演習問題 問2(スタック)**\n");
  printf("sizeof(LIST)=%d\n",sizeof(LIST));
  push_list(100,&head);
  push_list(200,&head);
  push_list(300,&head);
  printlist(head);
  printf("pop_list(&head)=%d\n",pop_list(&head));
  printf("pop_list(&head)=%d\n",pop_list(&head));
  printlist(head);
  push_list(500,&head);
  printf("pop_list(&head)=%d\n",pop_list(&head));
  printf("pop_list(&head)=%d\n",pop_list(&head));
  printlist(head);
  printf("pop_list(&head)=%d\n",pop_list(&head));
  printf("*/\n");
}
