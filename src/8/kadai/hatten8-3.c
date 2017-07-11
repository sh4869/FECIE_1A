#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUCKET_SIZE 50

typedef struct cell {
  int key;
  struct cell *next;
} CELL;

CELL *table[BUCKET_SIZE];
#define N 50

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

int find(int key,int *count){
  CELL *p;
  *count = 0;
  for(p = table[hash(key)];p!=NULL;p = p->next){
    *count += 1;
    if(key == p->key) {
      return p->key;
    }
  }
  return -1;
}

int insert(int key,int * c){
  CELL *p;
  int h,count;
  if(find(key,&count) != -1) {
    if(c != NULL){
      *c = count;
    }
    return 0;
  }
  if((p = (CELL *)malloc(sizeof(CELL))) == NULL){
    fprintf(stderr,"out of memory\n");
    exit(-1);
  }
  h = hash(key);
  p->key = key;
  p->next = table[h];
  table[h] = p;
  if(c != NULL){
    *c = count;
  }
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
  int i,rnd,cnt,sum = 0;
  CELL *p;
  srand((unsigned)time(NULL));
  init_table();
  printf("/* Chain Hush Program \n");
  for(i=0;i<N/2;i++){
    insert(rand()%500,NULL);
  }
  for(i=0;i<20;i++){
    rnd = rand()%500;
    if(insert(rnd,&cnt) == 1){
      delet(rnd);
    }
    sum += cnt;
  }
  printf("N/2登録されている状態での新規登録時のポインタ操作回数平均: %f\n",(double)sum / (double)20.0);
  print_hush();

  sum = 0;
  for(i=0;i<N/2;i++){
    insert(rand()%500,NULL);
  }
  for(i=0;i<20;i++){
    rnd = rand()%500;
    if(insert(rnd,&cnt) == 1){
      delet(rnd);
    }
    sum += cnt;
  }
  printf("N登録されている状態での新規登録時のポインタ操作回数平均: %f\n",(double)sum / (double)20.0);
  print_hush();

  sum = 0;
  for(i=0;i<N;i++){
    insert(rand()%500,NULL);
  }
  for(i=0;i<20;i++){
    rnd = rand()%500;
    if(insert(rnd,&cnt) == 1){
      delet(rnd);
    }
    sum += cnt;
  }
  printf("2N登録されている状態での新規登録時のポインタ操作回数平均: %f\n",(double)sum / (double)20.0);
  print_hush();

  sum = 0;
  for(i=0;i<N;i++){
    insert(rand()%500,NULL);
  }
  for(i=0;i<20;i++){
    rnd = rand()%500;
    if(insert(rnd,&cnt) == 1){
      delet(rnd);
    }
    sum += cnt;
  }
  printf("3N登録されている状態での新規登録時のポインタ操作回数平均: %f\n",(double)sum / (double)20.0);
  print_hush();
  printf("*/\n");
}

