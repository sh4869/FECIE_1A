#include <stdio.h>
#define N 3
#define M 6
static int a[N] = {4,6,9};
static int b[M] = {2,5,8,12,16,18};

int c[N+M];
int main(void){
  int i,numa,numb;
  numa = 0;
  numb = 0;
  for(i=0;i<N+M;i++){
    if(numa >= N) {
      c[i] = b[numb];
      numb++;
    } else if(numb >= M){
      c[i] = a[numa];
      numa++;
    } else {
      if(a[numa] < b[numb]){
        c[i] = a[numa];
        numa++;
      } else {
        c[i] = b[numb];
        numb++;
      }
    }
  }
  printf("c = {");
  for(i=0;i<N+M;i++){
    printf("%d ",c[i]);
  }
  printf(" }\n");
}
