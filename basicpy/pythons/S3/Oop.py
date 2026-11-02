class Car:
  def __init__(self,make,model,year,color):
    self.make=make
    self.model=model
    self.year=year
    self.color=color
  def drive(self):
    print("this "+self.make+" is driving!")
  def stop(slef):
    print("this "+slef.make+" has been stopped!")
Car_1=Car("BMW","M4",2018,"black")
Car_2=Car("Pagani","Huayra",2015,"White")
print(Car_1.make)
Car_1.drive()
Car_2.stop()