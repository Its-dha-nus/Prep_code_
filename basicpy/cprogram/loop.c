#include<stdio.h>
int main(){
  FILE *fp;
  char ch;

  fp=fopen("sample.txt","w");
  if(fp==NULL){
    printf("error!!");
    return 1;
  }
  printf("writing....\n");
  putc('h',fp);
  putc('e',fp);
  putc('y',fp);
  
  fclose(fp);
  fp=fopen("sample.txt","r");
  if(fp==NULL){
    printf("error on reading!!");
    return 1;
  }
  printf("reading the file....\n");
  while((ch=getc(fp))!=EOF){
    printf("%c",ch);
  }
  fclose(fp);
  return 0;
}