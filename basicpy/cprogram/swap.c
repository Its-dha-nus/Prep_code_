#include<stdio.h>
int main(){
  int a,b;
  printf("enter the number: ");
  scanf("%d",&a);
  printf("enter the number: ");
  scanf("%d",&b);
  a=a+b;
  b=a-b;
  a=a-b;
  printf("after swapping :%d,%d",a,b);

}