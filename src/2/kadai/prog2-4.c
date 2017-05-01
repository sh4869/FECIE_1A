#include <stdio.h>
#include "PLIB.h"

int main(void){
  int a,b,n;
  double y;
  printf("/*** P2-4(int) ***\n");

  a = 12345;
  printf("sizeof(a) = %d,&a = %p,(&a = aのアドレス) *(&a) = %d(アドレス&aの中身 = aの値)\n",sizeof(a),&a,*(&a));
  y = 12.34;
  printf("sizeof(y) = &d,&y = &p\n",sizeof(y),&y);
  printf("補足:アドレスはパソコン毎に異なります\n");

  a = 64;
  printf("a = %08x, a = ",a);
  print_bitposition(a);
  printf("a = %08x, a = ",a);
  print_bitposition(a);
  b = -a;
  printf("b = %08x, b = ",b);
  print_bitposition(b);

  // -64は64ビット表現を反転させてから+1
  a = 15*256*256 + 15*256 + 15;
  printf("a = %08x, a = ",a);
  print_bitposition(a);
  b = -a;
  printf("b = %08x, b = ",b);
  print_bitposition(b);

  n = 2745;
  printf("10進数 n = %06d,%d\n",n,n);
  printf("16進数: n= %06x,%06X,%x,%X",n,n,n,n);
  printf("*/\n");
  return 0;
}

/***
# 考察
KISSの法則からして，同じ処理が繰り返されるのであれば関数にまとめるべきだと考えられる．
たとえば変数にある値を代入してそれを16進数とbitとして表示する処理はプログラム中で繰り返されている．
その処理を引数にintの値一つを取る関数にまとめて呼び出すようにすると，プログラムも可読性があがる．
これは御存知の通りだと思う．

また，この講義は情報工学科の二年生を対象に行われている講義である．
そのため，受講者の多くはまだプログラミングに慣れていない．
よいプログラムとは何か，ということを問題を通して理解させることができるとよいのではないか．
 ***/
