def get_age():
  age=int(input("enter the age:"))
  if age<=0:
    error=ValueError("{0} is not a valid age!",format(age))
    raise error
  return age
get_age()