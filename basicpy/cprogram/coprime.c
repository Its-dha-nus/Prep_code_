#include<stdio.h>
int prime(int a){
  int i,f=0;
  for(i=2;i<a;i++){
    if (a%i==0){
      f=1;
    break;
    }
  }
  if (f==1){
    return 0;
  }
  else{
    return 1;
  }
}
void main(){
  int a,b;
  printf("enter 2 numbers: ");
  scanf("%d%d",&a,&b);
  if(prime(a)==prime(b)){
    if(prime(a)==0){
      printf("not prime");
    }
    else{
      printf("co prime");
    }
  }
  else{
    printf("not co prime");
  }
}