#include<stdio.h>
int main(){
  int rows,cols,i,j;
  printf("enter the number of rows and columns : ");
  scanf("%d %d", &rows, &cols);
  int matrix[rows][cols], transpose[cols][rows];
    for(i=0; i<rows; i++){
      for(j=0; j<cols; j++){
        printf("enter the element");
        scanf("%d",&matrix[i][j]);
      }
    }
  for(i=0; i<rows; i++){
    for(j=0; j<cols;j++){
      transpose[j][i]=matrix[i][j];
    }
  }
  for(i=0; i<cols; i++){
    for(j=0;j<rows; j++){
      printf("%d\t",transpose[i][j]);
    }
    printf("\n");
  }
  return 0;
}