#include<stdio.h>
#include<time.h>
void swap(int *x,int *y){
  int temp= *x;
  *x = *y;
  *y = temp;
}
void sort(int n,int arr[]){
    int j;
    for(int i=0; i<n-1; i++){
      int min=i;
      for(j=i+1; j<n ;j++){
        if(arr[j]<arr[min]){
          min=j;
        }
     }
      if(min != i){
        swap(&arr[i],&arr[min]);
        }
    }
  }
int main(){
  clock_t start, end;
  double cpu_time_used;
  start=clock();
  int arr[100];
  int n;
  printf("enter the limit:");
  scanf("%d",&n);
  for (int i=0; i<n; i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
  }  
  sort(n,arr);
  cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
  for(int i=0; i<n; i++){
     printf("%d",arr[i]);
     printf("\n");
    } 
  end=clock();
  cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
  printf("proseccing time:%.10f",cpu_time_used);
}