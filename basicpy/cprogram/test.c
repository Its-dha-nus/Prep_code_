#include<stdio.h>
int main(){
  char str[100];
  printf("enter");
  scanf("%[^\n]",str);
  printf("this is what you've entered: %s\n",str);
  return 0;

}