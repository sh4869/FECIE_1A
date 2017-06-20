#include <stdio.h>
#define N 18
#define m 27
static int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int hash(int);
int main(void){
  int htb[m],i,j,x;
  printf("/*** アルゴリズム2.8 **\n");
  for(i=0;i<m;i++) htb[i] = 0;
  for(i=0;i<N;i++){
    x = s[i];
    j = hash(x);
    while(htb[j] != 0) j++;
    htb[j] = x;
  }
  printf("(教科書32頁 図2.7参照\n");
  for(i=0;i<m;i++){
    printf("htb[%2d]=%2d ",i,htb[i]);
    if(((i+1)/7)*7==(i+1)) printf("\n");
  }
  printf("\n*/\n");
}

int hash(int x){
  return (x%m);
}


