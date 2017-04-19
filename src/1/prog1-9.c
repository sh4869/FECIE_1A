#include <stdio.h>

int print_array(int *arr){
  int i;
  printf("arr[]={");
  for(i=0;i<3;i++){
    printf("%d ",arr[i]);
  }
  printf("}\n");
  return 0;
}

int main(void){
  int i,k1,k2,k3,arr[3],sum;
  sum = 0;
  for(k1=5;k1>=0;k1--){
    arr[0] = k1;
    sum = sum+k1;
    for(k2=5;k2 >= 0;k2--){
      arr[1] = k2;
      sum+=k2;
      if(sum>5){
        sum -= k2;
        continue;
      }
      if(arr[0] < arr[1]) {
        sum-=k2;
        continue;
      }
      for(k3=5;k3 >=0;k3--){
        arr[2] = k3;
        sum = sum + k3;
        if(sum>5){
          sum -= k3;
          continue;
        }
        if(arr[1]<arr[2]) {
          sum -= k3;
          continue;
        }
        if(sum==5){
          print_array(arr);
        }
        sum -= k3;
      }
      sum -= k2;
    }
    sum -= k1;
  }
}
