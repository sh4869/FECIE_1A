#include <stdio.h>
#include "PLIB.h"


LIST *head,*tail;
void add_to_top(int);
int take_from_top();
void add_to_bottom(int);
int take_from_bottom();

int main(void){
  printf("/*** 第三章 演習問題 問1**\n");
  printf("(case-1) 先頭に追加(push),先頭から取り出し(pop)\n");
  head = tail = NULL;
  add_to_top(100);
  add_to_top(200);
  add_to_top(300);
  add_to_top(400);
  printlist(head);

  take_from_top();
  take_from_top();
  printlist(head);
  take_from_top();
  take_from_top();
  printlist(head);

  printf("\n(case-2) 先頭に追加 末尾から取り出し\n");
  head = tail = NULL;
  add_to_top(100);
  add_to_top(200);
  add_to_top(300);
  add_to_top(400);
  printlist(head);
  take_from_bottom();
  take_from_bottom();
  printlist(head);

  printf("\n(case-3) 末尾に追加(Enqueue), 先頭から取り出し(Dequeue)\n");
  head = tail = NULL;
  add_to_bottom(100);
  add_to_bottom(200);
  add_to_bottom(300);
  printlist(head);
  take_from_top();
  take_from_top();
  printlist(head);
  take_from_top();
  printlist(head);
  printf("*/\n");
}

void add_to_top(int x){
  LIST *p;
  p = (LIST *)(malloc(sizeof(LIST)));
  p->data = x;
  p->next = head;
  head = p;
}

int take_from_top(){
  LIST *p;
  int x;
  if(head == NULL){
    printf("Error: Underflow(take top)\n");
    return -1;
  }
  p= head;
  x = p->data;
  head = p->next;
  free(p);
  return x;
}

int take_from_bottom(){
  LIST *p,*p_up;
  int x;
  if(head==NULL){
    printf("Error: Underflow(take bottom)\n");
    return -1;
  }
  p = head;
  p_up = NULL;
  while(p->next != NULL){
    p_up = p;
    p = p->next;
  }
  p_up->next = NULL;
  x = p->data;
  printf("x=%d (head =%p) (freed %p)\n",x,head,p);
  free(p);
  return x;
}

void add_to_bottom(int x){
  LIST *p,*p2;
  p2 = (LIST *)(malloc(sizeof(LIST)));
  p2->data = x;
  p2->next = NULL;
  if(head == NULL) head = p2;
  else {
    p = head;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = p2;
  }
}

