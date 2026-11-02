#include<stdio.h>
int main(){
  int a,d=0;
  float i,c,b=0;
  printf("enter a number: ");
  scanf("%d",&a);
  for (i=1;i<=a;i++){
    d++;
    printf("1/%d ",d);
    c=(float)(1/i);
    b+=c;
  }
  printf("\n");
  printf("sum is=%.2f",b);
  return 0;
}