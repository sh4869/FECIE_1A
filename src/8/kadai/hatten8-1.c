#include <stdio.h>
#include "PLIB.h"
#include <stdlib.h>

struct LIST *head;
void insert(void){
  struct LIST *new_r,*temp;
  int data,i;
  printf("please input new data\n");
  scanf("%d",&data);
  if(data < 0) return;
  new_r =  (LIST *) malloc(sizeof(LIST));
  new_r->data = data;
  new_r->next = NULL;
  printf("input for - head: 0,tail: 1");
  scanf("%d",&i);
  switch(i){
    case 0:
      new_r->next = head;
      head = new_r;
      break;
    case 1:
      temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = new_r;
      break;
  }
  printlist(head);
  return;
}
void delete(void){
  struct LIST *p1,*p2;
  int n,i;
  printf("Please input number of data's number:");
  scanf("%d",&n);
  i = 1;
  p1 = head;
  p2 = p1->next;
  while((i+1<n) && (p2 != NULL)) {
    i++;
    p1 = p2;
    p2 = p1->next;
  }
  printlist(head);
  if((i+1 != n) && (i != 1)) printf("Deletion Error\n");
  else {
    p1->data = p2->data;
    p1->next = p2->next;
  }
  if(n == 1) head = p2;
  printlist(head);
}

int main(void){
  int i;
  printf("/*** Advance 8-1 **\n");
  head = NULL;
  head = inputdata(head);
  while(1){
    printf("insert: 0,delete: 1,exit: 2\n");
    scanf("%d",&i);
    switch(i){
      case 0:
        insert();
        break;
      case 1:
        delete();
        break;
      case 2:
        exit(0);
        break;
    }
  }
  printf("*/\n");
}
