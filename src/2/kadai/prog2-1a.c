#include <stdio.h>

void print_bitposition(int w){
  int i = 0;
  for(i=0;i<32;i++){
    if(w<0){
      printf("1");
    } else {
      printf("0");
    }
    w = w << 1;
  }
  printf("\n");
}

int main(void){
  int i;
  while(1){
    printf("10進数を入力してください:");
    scanf("%d",&i);
    print_bitposition(i);
    printf("終了しますか? はい:0,いいえ:1\n");
    scanf("%d",&i);
    if(!i){
     break;
    }
  }
}
