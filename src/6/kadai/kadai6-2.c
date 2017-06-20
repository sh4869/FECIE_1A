#include <stdio.h>
#define N 18
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int search_2_2(int, int *,int);

int main(void){
  int rc;
  printf("/*** アルゴリズム2.2 **\n");
  rc = search_2_2(23,s,N);
  printf("rc=%d\n",rc);
  rc = search_2_2(16,s,N);
  printf("rc=%d\n",rc);
  printf("*/\n");
  return 0;
}

int search_2_2(int x,int *s,int n){
  int i;
  i = 0;
  do {
    if(x==s[i]) break;
    else i++;
  } while(i < n);
  if(i < n) return i;
  return -1;
}
