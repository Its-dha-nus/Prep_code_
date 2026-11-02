#include<stdio.h>
#define MAX_ITEMS 100

struct{
  int id;
  double value;
  double weight;
  double ratio;
};

int main(){
  int n;
  double capacity,total_value=0.0;
  struct Item items[MAX_ITEMS];
  struct Item temp;
  printf("enter the number of items: ");
  scanf("%d",%n);
  printf("enter the total capacity of the knapsack:");
  scanf("%lf",&capacity);
  printf("Entr the value and weight for each item:\n");
  for(int i=0;i<n;i++){
    items[i].id+=1;
    printf("Item %d (Value Weight):",i+1);
    scanf("%lf %lf",&items[i].value,&items[i].weight);
    items[i].ratio=items[i].value/items[i].weight;
  }
  for (int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(items[i].ratio<items[j].ratio){
        temp=items[i];
        items[i]=items[j];
        items[j]=temp;
      }
    }
  }
  for(int i=0;i<n;i++){
    if (capacity==0){
      break;
    }
    if(items[i].weight<=capacity){
      printf("Tacking all items of %d(Value: %.2f,weight: %.2f)\n",items[i].id,items[i].value,items[i].weight);
      total_value+=items.value;
      capacity -= items[i].weight;
    }
  }
  else{
    double fraction=capacity/items[i].weight;
    double fraction_value=fraction * items[i].value;
    printf("Taking %.2f of item %d (Value added:%.2f,Weight added: %.2f)\n",fraction * 100, items[i].id, fractional_value, capacity);
    total_value += fraction_value;
    capacity=0;
  }
  prinf("\nTotal value:%.2f",total_value);
  return 0;
}