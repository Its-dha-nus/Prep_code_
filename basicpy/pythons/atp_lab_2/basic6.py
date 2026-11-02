a=int(input("enter a year"))
if a%4==0:
 print(f"{a} is a leap year.")
elif a%100==0:
 print(f"{a} is not a leap year.")
elif a%400==0:
 print(f"{a} is a leap year.")
else:
 print(f"{a} is not a leap year.")
 