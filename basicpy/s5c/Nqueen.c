#include<stdio.h>
#include<stdbool.h>
#include<time.h>

#define MAX_N 20
bool isSafe(int board[MAX_N][MAX_N],int row,int col,int N){
  int i,j;
  for(i=0;i<row;i++){
    if(board[row][i]) return false;
  }
  for(i=row,j=col; i>=0 && j>=0;j--,i--){
    if(board[i][j]) return false;
  }
  for(i=row,j=col;i<N && j>=0; i++,j--){
    if(board[i][j]) return false;
  }
  return true;
}
bool solveNQ(int board[MAX_N][MAX_N],int col,int N){
  if(col>=N){
    return true;
  }
  for(int row=0;row<N;row++){
    if(isSafe(board,row,col,N)){
      board[row][col]=1;
      if(solveNQ(board,col+1,N)){
        return true;
      }
      board[row][col]=0;
    }
  }
}
int main(){
  int N;
  int board[MAX_N][MAX_N]={0};
  clock_t start_time, end_time;
  double cpu_time_used;
  printf("Enter the number of queens (N): ");
  scanf("%d", &N);
  if(N<=3 && N!=1){
    printf("No soltn");
    return 1;
  }
  start_time=clock();
  if(solveNQ(board,0,N)){
    printf("\n--- Valid N-Queens Positions ---\n");
    for(int col=0;col<N;col++){
      for(int row=0;row<N;row++){
        if(board[row][col]==1){
          printf("Queen%d -> [Col:%d,Row:%d]\n",col+1,col,row);
        }
      }
    }
  }else{
    printf("Solution does not exist!!");
  }
  end_time=clock();
  cpu_time_used=((double)(end_time-start_time)/CLOCKS_PER_SEC);
  printf("\nxecutn time: %f seconds\n", cpu_time_used);
  return 0;
}
