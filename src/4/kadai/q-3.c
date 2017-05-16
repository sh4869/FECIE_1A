#include <stdio.h>
#include <stdlib.h>

void changeBoard(int size,int **board, int col, int row, int d)
{
  int k;
  for (k = 0; k < size; k++) { 
    board[col][k] += d;
    board[k][row] += d;
  }
  if (col > row) {
    for (k = 0; k < size-(col-row); k++) {
      board[k+(col-row)][k] += d;
    }
  } else {
    for (k = 0; k < size-(row-col); k++) {
      board[k][k+(row-col)] += d;
    }
  }
  if (col+row < size) {
    for (k = 0; k <= col+row; k++) {
      board[col+row-k][k] += d;
    }
  } else {
    for (k = col+row-size+1; k < size; k++) {
      board[col+row-k][k] += d;
    }
  }
}

void print_ban(int size,int *queen,int **ar){
  int i,j;
  printf("     ");
  for(i=0;i<size;i++) printf("%3d",i+1);
  printf("\n");
  printf("     ");
  for(i=0;i<size;i++) printf("  -");
  printf("\n");
  for(i=0;i<size;i++){
    printf("%2d | ",i+1);
    for(j=0;j<size;j++){
      if(j == queen[i]){
        printf("%3d",1);
      } else {
        printf("%3d",0);
      }
    }
    printf("\n");
  }
  printf("\n");
}

void setQueen(int size,int *queen,int **board,int col){
  int row;
  if(col == size){
    print_ban(size,queen,board);
    return;
  }
  for(row=0;row<size;row++){
    if(board[col][row]==0){
      queen[col] = row;
      changeBoard(size,board,col,row,+1);
      setQueen(size,queen,board,col+1);
      changeBoard(size,board,col,row,-1);
    }
  }
}

int main(void){
  int **ar;
  int *queen;
  int i,j,size;
  printf("盤面サイズを入力してください\n");
  scanf("%d",&size);
  // 盤面,Queenの初期化
  ar = malloc(sizeof(int *) * size);
  for(i=0;i<size;i++){
    ar[i]= calloc(0,sizeof(int) * size);
  }
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      ar[i][j]=0;
    }
  }
  // Queenの初期化
  queen = (int *)malloc(sizeof(int) * size);
  for(i=0;i<size;i++){
    queen[i] = 0;
  }
  // NULL チェック
  if(queen == NULL || ar == NULL){
    printf("メモリが確保できません\n");
    return -1;
  }
  setQueen(size,queen,ar,0);

  printf("終了します\n");
  for(i=0;i<size;i++){
    free(ar[i]);
  }
  free(ar);
  return 0;
}


