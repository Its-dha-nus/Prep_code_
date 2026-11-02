#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
};
struct node* front = 0;
struct node* rear = 0;
void enqueue(int x){
  struct node*newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = x;
  newnode->next = 0;
  if(rear == 0){
    front = rear = newnode;
    rear->next = front;
  }
  else{
    rear->next = newnode;
    rear = newnode;
    rear->next = front;
  }
}
void dequeue(){
  struct node*temp;
  temp=front;
  if (front == NULL && rear == NULL){
    printf("queue is empty!!");
  }
  else if(front == rear){
  front = rear = NULL;
  free(temp);
  }
  else{
    temp = front;
    front = front->next;
    rear->next = front;
    free(temp);
  }
}
void peek(){
  if(front == NULL && rear == NULL){
    printf("Queue is empty!!");
  }
  else{
    printf("Font element :%d",front->data);
  }
}
void display(){
  struct node* temp = front;
  if(front == NULL && rear == NULL){
    printf("Queue is empty!!\n");
  }
  else{
    printf("Queue element is: ");
    while(temp->next != front){
      printf(" %d ",temp->data);
      temp = temp->next;
    }
    printf(" %d",temp->data);
  }
}

int main(){
  int choice, value;
  while(1){
      printf("\n--- Circular Queue Menu ---\n");
      printf("1. Enqueue\n");
      printf("2. Dequeue\n");
      printf("3. Peek\n");
      printf("4. Display\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice){
        case 1:      
          printf("enter teh value to add:");
          scanf("%d",&value);
          enqueue(value);
          break;
        case 2:
          dequeue();
          break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
          printf("INvalid input !!!");
      }

  }
  return 0;
}