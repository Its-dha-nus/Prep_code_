#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push()
{
  int x;
  printf("enter data :");
  scanf("%d",&x);
  if(top==MAX-1){
    printf("Overflow\n");
  }else{
    top++;
    stack[top]=x;
  }
}
void pop(){
  int item;
  if(top==-1){
    printf("underflow\n");
  }
  else{
    item=stack[top];
    top--;
    printf("%d is poped!\n",item);
  }
}
void peek(){
  if(top==-1){
    printf("stack is empty!!");
  }
  else{
    printf("%d \n",stack[top]);
  }
}
void display(){
  int i;
  for(i=top;i>=0;i--){
    printf("%d ",stack[i]);
  }
}
int main(){
  int choice;
  while(1){
    printf("enter yout choice for operation :\n 1-push,2-pop,3-peek,4-display,5-exit :");
    scanf("%d",&choice);
    switch(choice){
      case 1:push();
        break;
      case 2:pop();
        break;
      case 3:peek();
        break;
      case 4:display();
        break;
      case 5:exit(0);
        break;
      default:
        printf("Enter valid choice!!");
    }
  }
  return 0;
}