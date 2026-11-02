#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
};
struct node*top=NULL;
void push(){
  int value;
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the Vlue to push:");
  scanf("%d",&value);
  newnode->data=value;
  newnode->next=top;
  top=newnode;
  printf("pushed!\n");
}
void display(){
  struct node*temp=top;
  if (top==NULL){
    printf("Underflow!!\n");
  }else{
    while(temp!=NULL){
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("\n");
  }
}
void peek(){
  if(top==NULL){
    printf("Empty!!");
  }else{
    printf("%d",top->data);
  }
}
void pop(){
  struct node*temp=top;
  if (top==NULL){
    printf("Empty");
  }else{
    printf("deleting %d .",top->data);
    top=top->next;
    free(temp);
  }
}
int main(){
  int choice;
  while(1){
    printf("1-push\n2-display\n3-peek\n4-pop\n5-exit.");
    printf("enter the choice:");
    scanf("%d",&choice);
    switch (choice){
      case 1:
        push();
        break;
        case 2:
      display();
        break;
        case 3:
      peek();
        break;
        case 4:
      pop();
        break;
        case 5:
      exit(0);
        break;
      default:
        printf("Enter a valid choice1!!");
        break;
    }
  }
  return 0;
}