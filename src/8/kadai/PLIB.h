#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
  int data;
  struct LIST *next;
} LIST;

void printlist(LIST *head){
  LIST *p;
  p = head;
  if(p==NULL) {
    printf("printlist : list end(head = %p)\n",p);
  }
  printf("print out from the head(head = %p)\n",head);
  while(p!=NULL){
    printf("p=%p(p->data=%d,p->next=%p)\n",p,p->data,p->next);
    if(p->next != NULL) {
      p = p->next;
    } else {
      break;
    }
  }
}

LIST *inputdata(LIST *head){
  LIST *new_r,*tail;
  int x;
  head = NULL,tail = NULL;
  while(1){
    scanf("%d",&x);
    if(x<0) break;
    new_r = (LIST *)malloc(sizeof(LIST));
    if(tail==NULL) {
      head = new_r;
    } else {
      tail->next = new_r;
    }
    new_r->data = x;
    new_r->next = NULL;
    tail = new_r;
  }
  printlist(head);
  return head;
}


void print_bitposition(int w){
  int i = 0;
  for(i=0;i<32;i++){
    if(w<0){
      printf("1");
    } else {
      printf("0");
    }
    w = w << 1;
  }
  printf("\n");
}

int cellingP(double num){
  if(num > (int)num) return (int)num + 1;
  else return (int)num;
}

int floorP(double num){
  return (int)num;
}
