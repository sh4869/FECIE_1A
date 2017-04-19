#include <stdio.h>

int count,num;

void print_array(int *array,int length){
  int i;
  printf("arr[]={");
  for(i=0;i<length;i++){
    printf("%d ",array[i]);
  }
  printf("}\n");
}

int calc_array_sum(int *array,int length){
  int i;
  int sum = 0;
  for(i=0;i<length;i++){
    sum += array[i];
  }
  return sum;
}

int func(int *arr,int n,int sum){
  int k;
  if(n==num+1){
    if(sum==count){
      print_array(arr,num);
    }
    return 0;
  }
  for(k=count;k>=0;k--){
    arr[n-1] = k;
    if(n==1){
      func(arr,n+1,arr[n-1]);
    } else {
      if(sum+k>count) continue;
      if(arr[n-2]<arr[n-1]) {
        continue;
      } else {
        func(arr,n+1,calc_array_sum(arr,num));
      }
    }
  }
}

int main(void){
  printf("kagoに5つのballを入れるプログラム\n");
  printf("ballの個数を入力してください:");
  scanf("%d",&count);
  printf("かごの個数を入力してください:");
  scanf("%d",&num);
  int kago[num];
  func(kago,1,0);
  return 0;
}
