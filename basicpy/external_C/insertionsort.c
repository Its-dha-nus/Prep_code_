#include<stdio.h>
int main(){
  int i,j,temp;
  int n,a[100];
  printf("enter the limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("enter the value:");
    scanf("%d",&a[i]);
  }
  for(i=1;i<n;i++){
    temp=a[i];
    j=i-1;
    while(j>=0 && a[j]>temp){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }
    printf("THe array is sorted!!\n");
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  return 0;
}