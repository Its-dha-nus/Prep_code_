#include<stdio.h>
void sort(int n,int arr[]){
  int j,temp;
  for(int i=1;i<n;i++){
    temp=arr[i];
    j=i-1;
    while(j>=0 &&arr[j]>temp){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=temp;
    for(int i=0;i<n;i++){
      printf("%d ",arr[i]);
      
    }
    printf("\n");
  }
}
int main(){
  int n,arr[100];
  printf("enter the limit:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("enter the %dth element:",i);
    scanf("%d",&arr[i]);
  }
  sort(n,arr);
  printf("the array is sorted!!\n");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}