try:
  n1=int(input("Enter the numerator:"))
  n2=int(input("Enter the denominator:"))
  r=n1/n2
  print("Result:",r)
  my_list=[4,5,6,7]
  index=int(input("enter the index from the list(0-3):"))
  print("Showing the value....",my_list[index])
except ZeroDivisionError:
  print("Divisio with zero is not allowed!")
except ValueError:
  print("Please only enter integers!")
except IndexError:
  print("Error:Plese keep the index in the range(0-3)")
finally:
  print("thank you for using the program....")
