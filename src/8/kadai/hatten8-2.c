#include <stdlib.h>
#include <stdio.h>
#define BUCKET_SIZE 15
typedef struct cell {
  int key;
  struct cell *next;
} CELL;

CELL *table[BUCKET_SIZE];
#define N 10
int keylist[N] = {22,142,56,78,72,127,29,166,788,24};

int print_hush(){
  int i;
  CELL *p;
  for(i=0;i<BUCKET_SIZE;i++){
    if(table[i] != NULL){
      printf(" table[%d] = ",i);
      for(p=table[i];p!=NULL;p=p->next){
        printf(" %d ",p->key);
      }
      printf("\n");
    }
  }
  return 0;
}

int hash(int key){
  return key % BUCKET_SIZE;
}

int init_table(){
  for(int i = 0;i < BUCKET_SIZE; i++){
    table[i] = NULL;
  }
  return 0;
}

int find(int key){
  CELL *p;
  for(p = table[hash(key)];p!=NULL;p = p->next){
    if(key == p->key) {
      return p->key;
    }
  }
  return -1;
}

int insert(int key){
  CELL *p;
  int h;
  if(find(key) != -1) return 0;
  if((p = (CELL *)malloc(sizeof(CELL))) == NULL){
    fprintf(stderr,"out of memory\n");
    exit(-1);
  }
  h = hash(key);
  p->key = key;
  p->next = table[h];
  table[h] = p;
  return 1;
}

int delet(int key){
  int h;
  CELL *p,*q;
  h = hash(key);
  if(table[h] == NULL) return 0;
  if(key == table[h]->key){
    p = table[h];
    table[h] = p->next;
    free(p);
    return 1;
  }
  for(q=table[h],p=q->next;p!=NULL;q=p,p=p->next){
    if(key == p->key){
      q->next = p->next;
      free(p);
      return 1;
    }
  }
  return 0;
}

int main(void){
  int i;
  CELL *p;
  init_table();
  printf("/* Chain Hush Program \n");
  for(i=0;i<N;i++){
    if(insert(keylist[i]) == 0){
      printf("key %d insertion fail\n",keylist[i]);
    }
  }
  printf("Verify insertion results\n");
  print_hush();
  if(delet(788)==0){
    printf("Key does not exists!\n");
  } else {
    printf("Deletion of 788\n");
    print_hush();
  }

  printf("*/\n");
}

