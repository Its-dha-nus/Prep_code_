#include<stdio.h>
int main(){
  int a,i,j,c=1;
  printf("enter a number: ");
  scanf("%d",&a);
  for(i=1;i<=a;i++){
    for(j=1;j<=i;j++){
      printf("%d ",c);
      c++;
    }
    printf("\n");
  }
  return 0;
}