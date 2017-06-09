#include <stdio.h>
#define N 4

void max_section_slove(int *arr,int length){
  int i,d,max,maxi=0,maxj=0;
  d = arr[0];
  max = arr[0];
  for(i=1;i<length;i++){
    if(d + arr[i] > arr[i]){
      d = d + arr[i];
      if(max < d){
        max = d;
        maxj = i;
      }
    } else {
      d = arr[i];
      if(max < d){
        max = d;
        maxi = i;
        maxj = i;
      }
    }
  }
  printf("区間 a[%d]~a[%d]の和が最大: 最大値=%d\n",maxi,maxj,max);
  return;
}

// TEST
int main(void){
  int a[N] = {-1,-10,-3,-5};
  int b[N] = {2,-3,3,-2};
  max_section_slove(a,N);
  max_section_slove(b,N);
  return 0;
}
