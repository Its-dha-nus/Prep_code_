#include<stdio.h>
int main(){
  int a,b,c=0;
  printf("enter a number: ");
  scanf("%d",&a);
  for(b=1;b<a;b++){
    if(a%b==0){
      c+=b;
    }
  }
  if(c==a){
    printf("%d is perfect",a);
  }
  else{
    printf("%d is not perfect",a);
  }
  return 0;
}