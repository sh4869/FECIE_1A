#include <stdio.h>
double x = 3.0;

#define N1 10
double a[N1] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
#define N2 18
int d[N2] = {8,-4,-7,4,5,-3,6,7,8,-4,9,-5,18,-6,-7,8,-9,3};

int main(void){
  double y;
  int i,j,temp,low,high,min;
  int sum,max,lowtemp;
  // 問題1
  printf("問題1\n");
  y = a[N1 - 1];
  for(i=N1-2;i>=0;i--){
    y = y * x + a[i];
    printf("i=%d,y=%0.2f(x=%0.2f)\n",i,y,x);
  }
  printf("answer : x=%0.2f y=%0.2f\n",x,y);
  // 問題2
  printf("\n問題2\n");
  min = d[0];
  for(i=0;i<N2;i++){
    temp = 0;
    for(j=i;j<N2;j++){
      temp += d[j];
      if(temp < min){
        min = temp;
        low = i;
        high = j;
      }
    }
  }
  printf("最小区間 d[%d]~d[%d] 最小値=%d\n*/\n",low,high,min);
  return 0;
}
