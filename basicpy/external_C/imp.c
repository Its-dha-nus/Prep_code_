#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node*next;
};
struct node* head=NULL;
void at_beg(){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("entr the vlue to input at the beg:");
  scanf("%d",&newnode->data);
  newnode->next=head;
  head=newnode;
  printf("inserted at the begg!\n");
}
void printing(){
  if(head==NULL){
    printf("List is EMPTY!!\n");
  }
  else{
    struct node* temp=head;
    while(temp!=NULL){
      printf("%d ->",temp->data);
      temp=temp->next;
    }
    printf("NULL\n");
  }
}
void at_pos(){
  int pos;
  struct node*newnode;
  struct node* temp=head;
  printf("enter the postion to enter:");
  scanf("%d",&pos);
  if (pos < 1) {
    printf("Invalid position! Position must be 1 or greater.\n");
    return;
  }
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the value to input:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(pos==1){
    newnode->next=head;
    head=newnode;
    printf("Inserted %d at first position..\n",newnode->data);
  }else{
  for(int i=1;i<pos-1;i++){
    if (temp == NULL) {
      printf("Position out of range (list is too short)!\n");
      free(newnode);
      return;
    }
    temp = temp->next;
  }
  if(temp==NULL){
    printf("List is  empty or is too short!\n");
    free(newnode);
    return;
  }
  newnode->next=temp->next;
  temp->next=newnode;
  printf("Inserted %d at position %d.\n", newnode->data, pos);
  }
}

void ending(){
  struct node* newnode;
  struct node*temp;

  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter the value to input: ");
  scanf("%d",&newnode->data);
  newnode->next=NULL;

  if(head==NULL){
    head=newnode;
  }
  else{
    temp=head;
    while(temp->next !=NULL){
      temp=temp->next;
    }
    temp->next=newnode;
  }
   printf("Inserted at the end.\n");
}

void del_beg(){
  struct node* temp=head;
  if(head==NULL){
    printf("List is empty.Nothing to delete!\n");
  }else{
    head=head->next;
    free(temp);
    printf("deleted the first node!!\n");
  }
}

void del_end(){
  struct node*temp=head;
  if(head==NULL){
    printf("List is empty.First insert some values!!\n");
  }
  else if(head->next==NULL){
    free(head);
    head=NULL;
    printf("Deleted the last node!\n");
  }else{
    while(temp->next->next!=NULL){
      temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
  }
}
void del_pos(){
  struct node*temp=head;
  struct node*nextnode;
  int value;
  int pos,i=1;
  printf("enter the position of the value to delete:");
  scanf("%d",&pos);
  if (pos < 1){
    printf("Invalid position! Position must be 1 or greater.\n");
    return;
  }
  if (head == NULL) {
    printf("List is empty. Nothing to delete.\n");
    return;
  }
  if (pos==1){
    nextnode=head;
    value=nextnode->data;
    head=head->next;
    free(nextnode);
    printf("%d deleted from 1st position!!",value);
    return;
  }
  temp=temp->next;
  i++;
}
while(i<pos-1&&temp !=NULL){
  if (temp == NULL || temp->next == NULL) {
    printf("Position %d is out of range!\n", pos);
    return;
  }
  nextnode=temp->next;
  temp->next=nextnode->next;
  value=nextnode->data;
  free(nextnode);
  printf("Deleted %d from the %d position!!\n",value,pos);
}

int main(){
  int choice;
  while(1){
    printf("Decide your choise...\n1-insert at begg\n2-insert at pos\n3-insert at end\n4-display\n5-del from end\n6-del from beg\n");
    printf("7-del from position\n8-exit\nEnter:");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        at_beg();
        break;
      case 2:
        at_pos();
        break;
      case 3:
        ending();
        break;
      case 4:
        printing();
        break;
      case 5:
        del_end();
        break;
      case 6:
        del_beg();
        break;
      case 7:
        del_pos();
        break;
      case 8:
        printf("exiting the program....");
        exit(0);
      default:
        printf("invalid choice! please provide a valid input!\n");
    }
  }
  return 0;
}