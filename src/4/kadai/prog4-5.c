#include <stdio.h>

enum animal {
  dog,
  cat,
  cow,
  pig
};

int main(void){
  enum animal an;
  int sw,num,i;
  double x = 12.345,y; float z=12.34f;
  printf("/*** P4-5 switch enum ***\n");
  printf("switch:\n 数0~3を入力してください\n");
  scanf("%d",&sw);
  switch(sw){
    case 0:
      printf("0を入力した\n");
      break;
    case 1:
      printf("1を入力した\n");
      break;
    case 2:
      printf("2を入力した\n");
      break;
    case 3:
      printf("3を入力した\n");
      break;
    default:
      printf("指定外の入力です\n");
      break;
  }
  printf("enum:\n動物の番号を選んでください\n");
  while(1){
    printf("0=dog,1=cat,2=cow,3=pig,他:終了\n");
    scanf("%d",&num);
    if(num < 0 || 3 < num){
      printf("enum 終了\n");
      break;
    } else {
      an = (enum animal) num;
      if(an == pig) printf("**ブー**\n"); 
      else if(an == cat) printf("**ニャーン**\n");
      else if(an == cow) printf("**モー**\n");
      else if(an == dog) printf("**ワン**\n"); 
    }
  }
  i = (int)x;
  x = (double)z;
  y = (float)2000;
  printf("cast演算子\ni=%d,x=%2.12f,x=%e,y=%3.4f\n",i,x,x,y);
  printf("(int): (int)2.8=%d (int)(-0.8)=%d (int)(-2.8)=%d\n",(int)2.8,(int)(-0.8),(int)(-2.8));
  printf("*/\n");
}
