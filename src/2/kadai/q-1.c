#include <stdio.h>

#define QUEEN_ROW 1
#define QUEEN_COLUMN 2

int ar[6][6] = {{0}};

int check_queen(int row,int column){
  int i;
  for(i=0;i<6;i++){
    if(ar[row][i] == 1 || ar[i][column] == 1) return 0;
    if(column - (row - i) > -1 && column - (row - i) < 6){
      if(ar[i][column - (row - i)]==1) return 0;
    }
    if(column + (row - i) && column + (row - i) < 6){
      if(ar[i][column + (row - i)] == 1) return 0;
    }
  }
  return 1;
}

int main(void){
  int row,column;
  ar[QUEEN_ROW][QUEEN_COLUMN] = 1;
  while(1){
    printf("Queenのポジションを入力してください:");
    scanf("%d %d",&row,&column);
    if(check_queen(row-1,column-1)) printf("sucess\n");
    else printf("fail\n");
  }
  return 0;
}


