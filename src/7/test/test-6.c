#include <stdio.h>
#define N 21
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32,35,37,40};

int cellingP(double d){
  int k,r;
  k = (int)d;
  r = (d > (int)d) ? (int)d + 1 : (int)d;
  return r;
}

int search_a(int x,int m,int *s,int n){
  int i,j,k,t;
  double d;
  d = n / m;
  k = cellingP(d);
  printf("n=%d, m=%d,k=%d\n",n,m,k);
  j = 0;
  printf("trace: ");
  while(j<=m-2){
    printf("%d ",s[(j+1)*k-1]);
    if(x<=s[(j+1)*k-1]) break;
    else j++;
  }
  i = j*k;
  t = ((j+1)*k-1 <= n - 1) ? (j+1)*k-1 : n-1;
  while(i<t){
    printf("%d ",s[i]);
    if(x<=s[i]) break;
    else i++;
  }
  printf("\n");
  if(x==s[i]) return i;
  return -1;
}

int main(void){
  int m,rc,x;
  double y = 4.0001;
  printf("/** Test - 6 ** \n");
  printf("step1: cellingP(%f)=%d\n",y,(int)cellingP(y));
  printf("step2: \n");
  while(1){
    printf("please input: x,m\n");
    scanf("%d %d",&x,&m);
    if(x<0) break;
    rc = search_a(x,m,s,N);
    printf("rc = %d ",rc);
    if(rc >= 0) {
      printf("(s[%d]=%d)\n",rc,s[rc]);
    } else {
      printf("(%d Not Found)\n",x);
    }
  }
  printf("*/\n");
  return 0;
}

