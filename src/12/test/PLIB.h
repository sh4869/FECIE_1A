#include <stdio.h>
#include <stdlib.h>

typedef struct LIST {
  int data;
  struct LIST *next;
} LIST;

typedef struct BSTnode {
  int key;
  struct BSTnode *lson;
  struct BSTnode *rson;
} BSTnode;

BSTnode *node(int data){
  BSTnode *p;
  p = (BSTnode *)malloc(sizeof(BSTnode));
  if(p != NULL){
    p->key = data;
    p->lson = NULL;
    p->rson = NULL;
  }
  return p;
}

void tree(BSTnode *father,BSTnode *left,BSTnode *right){
  BSTnode *p;
  int l_key,r_key;
  p=father;
  p->lson = left;
  p->rson = right;
  if(left != NULL) {
    l_key = left->key;
  } else {
    l_key = 0;
  }
  if(right != NULL) {
    r_key = right->key;
  } else {
    r_key = 0;
  }
  printf("%2d (%p), (%2d (%p),%2d (%p))\n",p->key,p,l_key,left,r_key,right);
}

void printtree(BSTnode *p){
  if(p == NULL) return;
  printf("%2d(%p) ",p->key,p);
  if(p->lson != NULL){
    printf("(%2d(%p)) ",(p->lson)->key,p->lson);
  } else {
    printf("(0(%p)) ",p->lson);
  }
  if(p->rson != NULL){
    printf("(%2d(%p)) \n",(p->rson)->key,p->rson);
  } else {
    printf("(0(%p))\n ",p->rson);
  }
  if(p->lson != NULL){
    printtree(p->lson);
  }
  if(p->rson != NULL){
    printtree(p->rson);
  }
}

int search(BSTnode *root,int x){
  BSTnode *v;
  v = root;
  while(v != NULL){
    if(x == v->key){
      printf("v=%p (key=%d)\n",v,x);
      return 0;
    }
    if(x < v->key){
      v = v->lson;
    } else {
      v = v->rson;
    }
  }
  return 1;
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

#define STACKSIZE 10000
int stack[STACKSIZE];
int S_top = 0;
void push(int x){
  if(S_top == STACKSIZE){
    printf("Error Overflow\n");
    return;
  } else {
    stack[S_top++] = x;
  }
}

int pop(void){
  if(S_top == 0){
    printf("Error Underflow\n");
    return -1;
  }
  return stack[--S_top];
}

void printstack(int *stack){
  int i = 0;
  while(i<S_top){
    printf("stack[%d]=%d",i,stack[i]);
    i++;
  }
  printf("\n");
}
void printheap(int *heap,int n){
  int i;
  printf("heap(n = %02d) ",n);
  for(i=1;i<=n;i++){
    printf("%2d ",heap[i]);
  }
  printf("\n");
}

