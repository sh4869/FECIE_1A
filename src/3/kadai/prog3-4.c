#include <stdio.h>
#define N 6

int a[N] = {1,2,3,4,5,6};
int b[N] = {19,18,17,16,15,14};

void add(int *p,int *q,int *r){
  int i;
  for(i=0;i<N;i++){
    r[i] = p[i] + q[i];
  }
}

int *sub(int *p,int *q){
  int i;
  static int wk[N];
  for(i=0;i<N;i++){
    wk[i] = p[i] - q[i];
  }
  return wk;
}

int main(void){
  int i,w[N],*v;
  printf("/**** P3-4 ***\n");
  add(a,b,w);
  printf("a+b=");
  for(i=0;i<N;i++) printf("w[%d] = %d ",i,w[i]);
  printf("\n");
  v = sub(a,b);
  printf("a-b=");
  for(i=0;i<N;i++) printf("v[%d] = %d ",i,v[i]);

  printf("\n*/\n");
}

