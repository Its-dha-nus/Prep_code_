#include<stdio.h>
#include<time.h>

int partition(int* a,int low,int high){
    int pivot=a[high],i=low-1,temp;
    for(int j=low;j<high;j++){
        if(a[j]<=pivot){
            temp=a[j];
            a[j]=a[++i];
            a[i]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}

int quicksort(int* a,int low,int high){
    if(low<high){
        int pivot=partition(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}

int main(){
    int n;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    clock_t start=clock();
    quicksort(a,0,n-1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted array is:");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n Execution Time =%f seconds\n",time_taken);
}