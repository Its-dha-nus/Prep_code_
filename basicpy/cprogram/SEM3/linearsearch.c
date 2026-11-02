#include<stdio.h>
int main() {
  int n,i,key,found=0;
  printf("enter the number of elements : ");
  scanf("%d",&n);
  int  arr[n];
  printf("enter the element:");
  for (i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("enter the element to search :");
  scanf("%d",&key);
  for (i=0;i<n;i++){
    if(arr[i]==key){
      found=1;
      break;

    }
  }
  if(found==1){
    printf("the element %d is in the array",key);
  }
  else{
    printf("the element is not in the array!!");
  }
  return 0;
}