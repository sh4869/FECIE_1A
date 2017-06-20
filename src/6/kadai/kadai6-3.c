#include <stdio.h>
#include <math.h>
#include "PLIB.h"
#define N 18
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int search_2_3(int,int,int *,int);

int main(void){
  int x,n,m,m1,m2,rc;
  double y=2.001,z=2.7;
  printf("/*** アルゴリズム2.3 **\n");
  printf("case-0: cellingP(%f)=%d,cellingP(%f)=%d\n",y,(int)cellingP(y),z,(int)cellingP(z));
  n = 18;
  m1 = 6;
  m2 = 7;
  printf("n=%d;m1=%d;m2=%d\n",n,m1,m2);
  printf("case-1:(int)cellingP(n/m1)=%d,(int)cellingP(n/m2)=%d\n",(int)cellingP(n/m1),(int)cellingP(n/m2));
  printf("case-1:(int)cellingP((double)n/m1)=%d,(int)cellingP((double)n/m2)=%d\n",(int)cellingP((double)n/m1),(int)cellingP((double)n/m2));
  printf("\n質問の数値xとブロック数mを入力(例: 18 5 (終了は 0 0))\n");
  while(1){
    scanf("%d %d",&x,&m);
    if((m>N)||(m<=0)||(x==0)) break;
    rc = search_2_3(x,m,s,N);
    printf("rc=%d ",rc);
    if(rc>=0) printf("(s[%d]=%d)",rc,s[rc]);
    else printf("(%d: Not Found)",x);
    printf("\n質問の数値xとブロック数mを入力(例: 18 5 (終了は 0 0))\n");
  }
  printf("*/\n");
}

int search_2_3(int x,int m,int *s,int n){
  int i,j,k,t;
  k = (int)cellingP((double)n/m);
  j = 0;
  while(j<=m-2){
    if(x <= s[(j+1)*k - 1]) break;
    else j++;
  }
  i = j*k;
  t = ((j+1)*k - 1 <= n-1) ? (j+1)*k-1 : n-1;
  while(i<t){
    if(x<=s[i]) break;
    else i++;
  }
  if(x==s[i]) return i;
  return -1;
}
