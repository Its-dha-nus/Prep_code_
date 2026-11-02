import re
x= input("enter the phone number: ")
if(re.search(r"^[789]\d{9}$",x)):
  print("valid phone number!!")
else:
  print("Not valid")
