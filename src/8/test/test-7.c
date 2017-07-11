#include <stdio.h>
#define N 15
#define m 23
int s1[N] = {2,5,6,10,12,14,16,19,22,23,25,28,33,36,43};
int s2[N] = {12,43,14,33,16,19,22,23,25,2,5,6,10,28,36};
int search1(int,int*,int);
int search2(int,int*);
int hash(int x) {
  return x % m;
}
void make_htb(int *s,int *htb){
  int i,j,x;
  for(i=0;i<m;i++) htb[i] = 0;
  for(i=0;i<N;i++){
    x = s[i];
    j = hash(x);
    while(htb[j] != 0) j = (j + 2) % m;
    htb[j] = x;
    printf("htb[%2d]=%2d\n",j,htb[j]);
  }
}

int main(void){
  int rc,x,htb[m];
  printf("/** 空欄を埋めなさい \n");
  printf("step-1 \n");
  printf("質問の数値xを入力してください (半角)\n");
  scanf("%d",&x);
  rc = search1(x,s1,N);
  if(rc < 0) printf("rc = %d (%d Not Found)",rc);
  else printf("rc = %d (x = %02d s1[%d] = %02d) ",rc,x,rc,s1[rc]);
  printf("\nstep1\n");

  make_htb(s2,htb);
  x = 28;
  printf("\nstep-2A: x=%dを探索\n",x);
  rc = search2(x,htb);
  if(rc < 0) printf("rc = %d (%d Not Found)",rc);
  else printf("rc = %d (x = %02d s1[%d] = %02d) ",x,rc,s1[rc]);
  x = 42;
  printf("\nstep-2B: x=%dを探索\n",x);
  rc = search2(x,htb);
  if(rc < 0) printf("rc = %d (%d Not Found)",rc);
  else printf("rc = %d (x = %02d s1[%d] = %02d) ",x,rc,s1[rc]);
  printf("\n*/\n");
  return 0;
}

int search1(int x,int *s,int n){
  int left,right,mid;
  if(x<s[0]||x>s[n-1]) return -1;
  left = 0;
  right = n - 1;
  do {
    mid = (left + right) / 2;
    printf("left = %02d, right = %02d, mid = %d\n",left,right,mid);
    if(x<s[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  } while(left <= right);
  printf("left=%02d,right=%02d,mid=%d\n",left,right,mid);
  if(x == s[right]) return right;
  else return -1;
}

int search2(int x,int *htb){
  int j;
  j = hash(x);
  while((htb[j]!=0)&&(htb[j]!=x)) j = (j+1)%m;
  if(htb[j] == x) return j;
  else return -1;
}
