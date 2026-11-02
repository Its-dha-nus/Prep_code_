def phone(n):
    if 1>(n/(10**10)) and (n/(10**10))>=0.7:
        return True
    else:
        return False
n=int(input("enter the number : "))
if phone(n):
   print("valid number")
else:
   
   print("not valid")
   