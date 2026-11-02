#include<stdio.h>
void swap(int *x,int *y){
  int temp=*x;
  *x=*y;
  *y=temp;
}
int partition(int a[],int lb,int ub){
  int pivot=a[lb];
  int start=lb;
  int end=ub;
  while(start<end){
    while(start <=ub && a[start]<=pivot){
      start++;
    while(a[end]>pivot){
      end--;
    }
    if (start < end) {
      swap(&a[start], &a[end]);
    }
  swap(&a[lb],&a[end]);
  return end;}
}
}
void quick(int a[],int lb,int ub){
  if(lb<ub){
    int loc=partition(a,lb,ub);
    quick(a,lb,loc-1);
    quick(a,loc+1,ub);
  }
}
int main(){
  int a[100],n;
  int ub,lb;
  printf("enter the limit:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("enter the value:");
    scanf("%d",&a[i]);
  }
  lb=0;
  ub=n-1;
  quick(a,lb,ub);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
  return 0;   
}