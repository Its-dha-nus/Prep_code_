#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
};
struct node*head=NULL;
void insert_beg(){
  struct node*newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the value:");
  scanf("%d",&newnode->data);
  newnode->next=head;
  head=newnode;
  printf("inserted at the beggining!!");
}
void insert_end(){
  struct node*temp;
  struct node*newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the value:");
  scanf("%d",&newnode->data);
  newnode node->next=NULL;
  if(head==NULL){
    head=newnode;
  }else{
  while(temp->next!=NULL){
    temp=temp->next;
    }
  temp->next=newnode;
  printf("inserted at end!!");
  }
}
void insert_pos(){
  struct node*newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the value to insert:");
  scanf("%d"&newnode->data);
  if(pos==1){
    newnode->next=head;
    head=newnode;
    printf("inserted at position%d",pos);
    return;
  }
  struct node*temp=head;
  for(int i=1;i<pos-1&&temp != NULL; i++){
    temp=temp->next;
  }
    if (temp==NULL){
      printf("Position out of range\n");
      free(newnode);
      return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("inserted at position!!");
  }
void display(){
  if (head==NULL){
    printf("Empty!!");
    return;
  }
  struct node*temp=head;
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
  }

}
void delete_by(){
  struct node*temp=head,prev=NULL;
  printf("enter the value to delete:");
  scanf("%d",&value);
  if(temp != NULL&& temp->data ==value){
    
  }
}