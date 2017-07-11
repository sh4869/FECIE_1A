#include <stdio.h>
#include <malloc.h>

typedef struct BSTnode {
  int key;
  struct BSTnode *lson;
  struct BSTnode *rson;
} BSTnode;

BSTnode *node(int);
void tree(BSTnode *,BSTnode *,BSTnode *);
int search(BSTnode *,int);

BSTnode *head;
int main(void){
  struct BSTnode *p50,*p9,*p81,*p5,*p21,*p62,*p92;
  int data,rc;
  printf("/*** Program 3.5 **\n");
  head = p50 = node(50);
  p9 = node(9);
  p81 = node(81);
  tree(p50,p9,p81);
  p5 = node(5);
  p21 = node(21);
  tree(p9,p5,p21);
  p62 = node(62);
  p92 = node(92);
  tree(p81,p62,p92);
  tree(p5,node(3),node(8));
  tree(p21,node(13),node(23));
  tree(p62,node(53),node(74));
  tree(p92,node(85),node(99));
  while(1){
    printf("Input a positive integer(0 indicates exit):");
    scanf("%d",&data);
    if(data<=0) break;
    rc = search(head,data);
    if(rc==0) {
      printf("find out key = %d\n",data);
    } else {
      printf("key=%d does not exist\n",data);
    }
  }
  printf("*/\n");
}

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


