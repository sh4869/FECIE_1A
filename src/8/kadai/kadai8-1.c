#include <stdio.h>
#include <malloc.h>
#define N 100
typedef struct LIST { 
  int data;
  struct LIST *next;
} LIST;

void AL3_1(void);
void AL3_2(void);
void printlist(LIST *);
int data[N];
int main(void){
  int i = 0,x;
  printf("/*** Program 3.1-3.2 **\n");
  printf("sizeof(LIST)=%d\n",sizeof(LIST));
  printf("input integers (example 10 20 30 -1( -1 end of input))\n");
  while(1){
    scanf("%d",&x);
    data[i++] = x;
    if(x<0) break;
  }
  printf("Program 3.1(insert to the top)\n");
  AL3_1();
  printf("Program 3.2(insert to the tail)\n");
  AL3_2();
  printf("*/\n");
}

void AL3_1(void){
  LIST *head,*new_r;
  int i = 0;head = NULL;
  while(data[i] >= 0){
    new_r = (LIST *)malloc(sizeof(LIST));
    new_r->data = data[i++];
    new_r->next = head;
    head = new_r;
  }
  printlist(head);
}

void AL3_2(void){
  LIST *head,*new_r,*tail;
  int i = 0;head = NULL,tail = NULL;
  while(data[i] >= 0){
    new_r = (LIST *)malloc(sizeof(LIST));
    if(tail==NULL) {
      head = new_r;
    } else {
      tail->next = new_r;
    }
    new_r->data = data[i++];
    new_r->next = NULL;
    tail = new_r;
  }
  printlist(head);
}

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
