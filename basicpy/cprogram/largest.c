#include<stdio.h>
int main(){
  int a,b,c,largest;
  printf("enter the number: ");
  scanf("%d",&a);
  printf("enter the second number");
  scanf("%d",&b);
  printf("enter the next number :");
  scanf("%d",&c);
  largest=(a>b)?((a>c)?a:c):((b>c)?b:c);
  printf("largest=%d",largest);
}