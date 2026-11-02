import re
x=input("enter the password:")
if((re.search(r"[a-z]",x)) and
  (re.search(r"[A-Z]",x)) and
  (re.search(r"[0-9]",x)) and
  (len(x)>=6) and
  (re.search(r"\w",x))):
  print("Password is valid!!!")
else:
  print("NOT VALID!!")
