#include<stdio.h>
void swap(int *a,int *b){
   int temp=*a;
    *a=*b;
    *b=temp;}
void selection(int n,int a[]){
  int j;
  for(int i=0;i<n-1;i++){
    int min=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[min]){
        min=j;
      }}
    if(min!=i){
      swap(&a[i],&a[min]);
    }
  }
}
int main(){
  int n,a[100];
  printf("enter the limit:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("enter the value:");
    scanf("%d",&a[i]);}
  selection(n,a);
  printf("sorted!");
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}