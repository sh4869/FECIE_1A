#include <stdio.h>
#define N 4

void max_section_slove(int *arr,int length){
  int i,j,sum=0,max,maxi,maxj;
  max = arr[0];
  maxi = 0;
  maxj = 0;
  for(i=0;i<length;i++){
    sum = 0;
    for(j=i;j<length;j++){
      sum += arr[j];
      if(sum > max){
        max = sum;
        maxi = i;
        maxj = j;
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
