#include<stdio.h>
#include<time.h>

void merge(int *arr,int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int b[high];
    while((i<mid+1)&&(j<high+1)){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }
        else{
            b[k++]=arr[j++];
        }
    }
    while(i<mid+1){
        b[k++]=arr[i++];
    }
    while(j<high+1){
        b[k++]=arr[j++];
    }
    for(int l=low;l<=high;l++){
        arr[l]=b[l];
    }
}

void mergesort(int *arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergesort(a,0,n-1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The sorted array is:");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n Execution Time =%f seconds\n",time_taken);
}