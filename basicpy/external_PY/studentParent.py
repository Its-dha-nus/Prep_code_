class Person:
  def __init__(self,name,age):
    self.name=name
    self.age=age
  def display(self):
    print("------- Person info ------")
    print("Name:",self.name,"Age:",self.age)
class Student(Person):
  def __init__(self, name, age,id):
    super().__init__(name,age)
    self.id=id
  def display(self):
    print("----Student details-------")
    print("name:",self.name)
    print("age:",self.age)
    print("ID:",self.id)
def main():
  name=input("Enter the person name :")
  age=int(input("Enter the person age:"))
  p1=Person(name,age)
  id=int(input("enter the student id:"))
  s_name=input("student name:")
  s_age=int(input("enter the student age:"))
  s1=Student(s_name,s_age,id)
  p1.display()
  s1.display()
if __name__=="__main__":
  main()