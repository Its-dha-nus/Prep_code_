#include<stdio.h>

void calc(int a[], int n, int *s, float *avg){
  *s=0;
  for (int i=0; i<n ;i++){
    *s += a[i];
  }
  *avg=(float)(*s) / n;
}
int main(){
  int n;
  printf("enter count: ");
  scanf("%d",&n);
  int a[n];
  printf("enter %d numbers:\n",n);
  for (int i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  int s;
  float avg;
  calc(a, n, &s ,&avg);

  printf("sum=%d\n",s);
  printf("avg=%0.2f\n",avg);

  return 0;
}