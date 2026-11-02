#include<stdio.h>
#include<stdlib.h>
struct node{
  int coef;
  int pow;
  struct node *next;
};
int main(){
  struct node*start=NULL,*current,*newnode;
  int terms,i;
  printf("For 1st polynomial!\n");
  printf("enter the number of terms:");
  scanf("%d",&terms);
  printf("Enter %d terms starting from the highest power:",terms);
  for(i=0;i<terms;i++){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("Enter the Coefficient:");
    scanf("%d",&newnode->coef);
    printf("Enter the power:");
    scanf("%d",&newnode->pow);
    if(start==NULL){
      start=newnode;
      current=newnode;
    }else{
      current->next=newnode;
      current=newnode;
    }
  }
  for(current=start;current!=NULL;current=current->next){
    if(current->pow==1){
      printf("%dx ",current->coef);
    }else if(current->pow==0){
      printf("%d",current->coef);
    }else{
      printf("%dx^%d ",current->coef,current->pow);
    }
    if(current->next){
      printf("+ ");
    }
  }
  return 0;
}