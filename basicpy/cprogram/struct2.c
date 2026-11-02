#include<stdio.h>
struct Student{
  char name[20];
  int age;
};
void update(struct Student *s){
  (*s).age += 1;
}
int main(){
  struct Student s1={"Alice",21};
  printf("before update: Age=%d\n",s1.age);
  update(&s1);
  printf("After the update: Age=%d\n",s1.age);
  return 0;
  
}