#include<stdio.h>
struct Student{
  char name[20];
  int age;
};
void display(struct Student s){
  printf("name:%s\n",s.name);
  printf("age:%d\n",s.age);
}
int main(){
  struct Student s1={"Alice",21};
  display(s1);
  return 0;
}