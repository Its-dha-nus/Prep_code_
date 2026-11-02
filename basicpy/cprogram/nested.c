#include<stdio.h>
int main(){
  int x;
  printf("entr the number :");
  scanf("%d",&x);
  if(x%2==0){
    if(x%3==0){
      printf("the number is divisible by both 2 & 3");
    }
  }
}