def is_amstrong(n):
    digits=str(n)
    amstrong_sum=0
    for digit in digits:
       amstrong_sum += int(digit) ** len(digits)
    return amstrong_sum==n
n=int(input("enter the number: "))
if is_amstrong(n):
   print("number is amstrong ")
else :
   print("the number is not amstrong ")
