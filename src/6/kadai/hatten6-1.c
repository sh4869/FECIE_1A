#include <stdio.h>
#define N 18
#define m 27
static int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int hash(int,int);
int search(int, int*);
void make_htb(int *,int *);
int main(void){
  int htb[m],i,x,rc;
  printf("/*** アルゴリズム2.9 (ハッシュ法) **\n");
  make_htb(s,htb);
  printf("(教科書32頁 図2.7参照)\n");
  for(i=0;i<m;i++){
    printf("htb[%2d]=%2d ",i,htb[i]);
    if(((i+1)/7)*7==(i+1)) printf("\n");
  }
  printf("\n探索するデータxを入力して下さい(半角正整数)\n");
  scanf("%d",&x);
  rc = search(x,htb);
  if(rc >= 0) {
    printf("rc = %d (x=%d,htb[%d]=%d",rc,x,rc,htb[rc]);
  } else {
    printf("rc=%d ( ** %d not found **)",rc,x);
  }
  printf("\n*/\n");
  return 0;
}

int search(int x,int *htb){
  int k = 1;
  int j = hash(x,k);
  while(htb[j] != x) {
    k++;
    j = hash(x,k);
  }
  if(htb[j] == x) return j;
  else return -1;
}

void make_htb(int *s,int *htb) {
  int i,j,x,k;
  for(i=0;i<m;i++) htb[i] = 0;
  for(i=0;i<N;i++){
    k = 1;
    x = s[i];
    j = hash(x,k);
    while(htb[j] != 0) {
      k++;
      j = hash(x,k);
    }
    htb[j] = x;
  }
}

int hash(int x,int k){
  return (x  + (3 * (k-1) * x)) % m;
}

