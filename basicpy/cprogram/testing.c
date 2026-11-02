#include<stdio.h>
int main(){
  int a,b,c=0,d=1;
  int temp;
  printf("enter a number: ");
  scanf("%d",&a);
  for (b=1;b<=a;b++){
    printf("%d ",c);
    temp=c;
    c=d;
    d=temp;
    d+=c;
  }
  return 0;
}