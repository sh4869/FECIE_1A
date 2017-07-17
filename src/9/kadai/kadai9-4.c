#include <stdio.h>
#include <malloc.h>
typedef struct LIST {
  int data;
  struct LIST *next;
} LIST;

void Enqueue_list(int x,LIST**,LIST**);
int Dequeue_list(LIST**,LIST**);
LIST *head,*tail;
void printlist(LIST *);

int main(void){
  printf("/** 第三章-演習問題 問4(キュー) **\n");
  head = tail = NULL;
  Enqueue_list(100,&head,&tail);
  Enqueue_list(200,&head,&tail);
  Enqueue_list(300,&head,&tail);
  printlist(head);
  printf("Dequeue_list()=%d\n",Dequeue_list(&head,&tail));
  printf("Dequeue_list()=%d\n",Dequeue_list(&head,&tail));
  printlist(head);
  Enqueue_list(5000,&head,&tail);
  printf("Dequeue_list()=%d\n",Dequeue_list(&head,&tail));
  printf("Dequeue_list()=%d\n",Dequeue_list(&head,&tail));
  printlist(head);
  printf("Dequeue_list()=%d\n",Dequeue_list(&head,&tail));
  printf("*/\n");
}

void printlist(LIST *head){
  LIST *p;
  p = head;
  if(p==NULL){
    printf("printlist: list end (head = %p)\n",p);
  }
  printf("print out from the head (head = %p)\n",head);
  while(p!=NULL){
    printf("p=%p,(p->data=%d,p->next=%p)\n",p,p->data,p->next);
    if(p->next != NULL) {
      p = p->next;
    } else {
      break;
    }
  }
}

void Enqueue_list(int x,LIST **head,LIST **tail){
  LIST *nr;
  nr = (LIST *)(malloc(sizeof(LIST)));
  if(nr == NULL) {
    printf("** ERROR: No Memory **\n");
    return;
  }
  if(*tail == NULL){
    nr->data = x;
    nr->next = NULL;
    *tail = nr;
    *head = nr;
  } else {
    (*tail)->next = nr;
    nr->data = x;
    nr->next = NULL;
    *tail = nr;
  }
  printf("p=%p Enqueue x = %d\n",nr,x);
}

int Dequeue_list(LIST **head,LIST **tail){
  LIST *p1;
  int t;
  if(*tail == NULL){
    printf("Dequeue-error: Underflow\n");
    return -1;
  } else if(*head==*tail){
    p1 = *head;
    t = p1->data;
    *head = NULL;
    *tail = NULL;
    printf("p1=%p freed: ",p1);
    free(p1);
    return t;
  } else {
    p1 = *head;
    t = (*head)->data;
    (*head) = (*head)->next;
    printf("p1=%p freed: ",p1);
    free(p1);
    return t;
  }
}
