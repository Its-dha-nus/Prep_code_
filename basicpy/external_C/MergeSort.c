#include<stdio.h>
void merge(int a[],int lb,int mid,int ub){
  int i=lb;
  int j=mid+1;
  int k=lb;
  int b[100];
  while(i<=mid && j<=ub){
    if(a[i]<=a[j]){
      b[k]=a[i];
      i++;
      k++;
    }else{
      b[k]=a[j];
      j++;
      k++;
    }
  }
  if(i>mid){
    while(j<=ub){
      b[k]=a[j];
      j++;
      k++;
    }
  }
  else{
      while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
      }
    }
  for(k=lb;k<=ub;k++){
    a[k]=b[k];
  }
}
void merge_sort(int a[],int lb,int ub){
  int mid;
  if(lb<ub){
    mid=(lb+ub)/2;
    merge_sort(a,lb,mid);
    merge_sort(a,mid+1,ub);
    merge(a,lb,mid,ub);
  }
}
int main(){
  int a[100],n;
  int lb=0;
  printf("enter the limit:");
  scanf("%d",&n);
  int ub=n-1;
  for(int i=0;i<n;i++){
    printf("enter the value:");
    scanf("%d",&a[i]);
  }
  merge_sort(a,lb,ub);
  for (int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  return 0;
}