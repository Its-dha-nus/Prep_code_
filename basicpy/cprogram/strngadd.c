#include<stdio.h>
#include<string.h>
int main(){
  char str1[100],str2[100];

  printf("enter the first string:");
  fgets(str1,sizeof(str1),stdin);
  str1[strcspn(str1,"\n")]='\0';

  printf("enter the second string:");
  fgets(str2,sizeof(str2),stdin);
  str2[strcspn(str2, "\n")]='\0';

  int len1=0;
  while(str1[len1] !='\0'){
    len1++;
  }
  int i,j=0;
  for(i=len1; str2[j] !='\0'; i++,j++){
    str1[i]=str2[j];
  }
  str1[i]='\0';
  printf("%s",str1);

  return 0;
}