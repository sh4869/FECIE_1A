#include <stdio.h>
#define N 8
int s[N] = {13,30,42,87,10,60,50,25};
int search_2_1(int,int *,int);

int main(void){
  int rc;
  printf("/*** アルゴリズム 2.1**\n");
  rc = search_2_1(60,s,N);
  printf("(1) rc=%d\n",rc);

  rc = search_2_1(55,s,N);
  printf("(2) rc=%d\n",rc);

  printf("*/\n");
  return 0;
}

int search_2_1(int x,int *s,int n){
  int i;
  i = 0;
  do {
    if(x==s[i]) return i;
    else i++;
  } while(i<n);
  return -1;
}
