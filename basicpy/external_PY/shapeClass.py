class Shape:
  def __init__(self,color):
    self.color=color
  def get_details(self):
    return "Color:",self.color
class Rectangle(Shape):
  def __init__(self,color,width,height):
    super().__init__(color)
    self.width=width
    self.height=height
  def get_details(self):
    base_details=super().get_details()
    return base_details,"width:",self.width,"height:",self.height
  def area(self):
    return self.width*self.height
if __name__=="__main__":
  color=input("Enter the color of rectangle:")
  width=int(input("Enter the width:"))
  height=int(input("Enter the height:"))
  rect1=Rectangle(color,width,height)
  details=rect1.get_details()
  print("details:",details)
  area=rect1.area()
  print("area",area)

