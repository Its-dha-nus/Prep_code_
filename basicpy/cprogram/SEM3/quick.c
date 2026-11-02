#include<stdio.h>
void swap(int *x,int *y){
  int temp= *x;
  *x = *y;
  *y = temp;
}
int partition(int a[],int lb,int ub){
  int pivot=a[lb];
  int start=lb;
  int end=ub;
  while(start<end){
    while(a[start]<=pivot){
      start++;
    }
    while(a[end]>pivot){
      end--;
    }
    if(start<end){
      swap(&a[start],&a[end]);
    }
  }
  swap(&a[lb],&a[end]);
  return end;
}
void quick_sort(int a[],int lb,int ub){
  if(lb<ub){
    int loc=partition(a,lb,ub);
    quick_sort(a,lb,loc-1);
    quick_sort(a,loc+1,ub);
    }
  }
int main(){
  int n,a[100];
  int ub,lb;
  printf("enter the limit:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("enter the %dth element:",i);
    scanf("%d",&a[i]);
  }
  lb=0;
  ub=n-1;
  quick_sort(a,lb,ub);
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}