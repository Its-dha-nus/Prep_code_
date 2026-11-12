#include<stdio.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))
int main(){
  int n,capacity;
  printf("entr the number of the items:");
  scanf("%d",&n);
  printf("Enter the max cpacity:");
  scanf("%d",&capacity);
  int values[n];
  int weights[n];

  printf("Enter the value and weight for each item(Integers only):\n");
  for(int i=0;i<n;i++){
    printf("Item %d (value weight): ",i+1);
    scanf("%d %d",&values[i],&weights[i]);
  }

  int dp[n+1][capacity+1];
  for(int i=0;i<=n;i++){
    for(int w=0;w<=capacity;w++){
      if(i==0 || w==0){
        dp[i][w]=0;
      }
      else if(weights[i-1]<=w){
        int include_value=values[i-1]+dp[i-1][w-weights[i-1]];
        int exclude_value=dp[i-1][w];
        dp[i][w]=MAX(include_value,exclude_value);
      }
      else{
        dp[i][w]=dp[i-1][w];
      }
    }
  }
  printf("Slouthon hereeee!!\n");
  printf("max total value:%d\n\n",dp[n][capacity]);
  int remaining_capacity = capacity;
  printf("items  included in the knapsack\n");

  for(int i=n;i>0 && dp[i][remaining_capacity]>0;i--){
    if(dp[i][remaining_capacity]==dp[i-1][remaining_capacity]){
      continue;
    }
    else{
      printf("-Item %d(Value:%d,Weight:%d)\n",i,values[i-1],weights[i-1]);
      remaining_capacity -= weights[i-1];
    }
  }
  return 0;
}