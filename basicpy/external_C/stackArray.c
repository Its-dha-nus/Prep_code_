#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N];
int top=-1;
void push(){
  int x;
  printf("enter the number to insert:");
  scanf("%d",&x);
  if (top==N-1){
    printf("OverFlow!!!\n");
  }else{
    top++;
    stack[top]=x;
    printf("inserted!\n");
  }
}
void pop(){
  int item;
  if (top==-1){
    printf("underFlow!!\n");
  }else{
    item=stack[top];
    top--;
    printf("%d is deleted!\n",item);
  }
}
void peek(){
  if(top==-1){
    printf("Empty!!\n");
  }else{
    printf("%d is the top element!\n",stack[top]);
  }
}
void display(){
  if (top==-1){
    printf("Empty!,Nothing to display!\n");
  }else{
    for(int i=top; i>=0; i--){
      printf("%d \n",stack[i]);
    }
  }
}
int main(){
  int choice;
  while(1){
    printf("1-push\n2-pop\n3-peek\n4-display\n5-Exit\n");
    printf("Enter the Choice :");
    scanf("%d",&choice);
    switch (choice){
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        display();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Enter a valid choice!");
        break;
    }
  }
  return 0;
}