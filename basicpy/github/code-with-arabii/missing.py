a1=[]
b=0
check=0
n=int(input("number of elements: "))
if n<=0:
  print("invalid input!!")
else:
  for i in range (n):
    a=int(input("enter the element: "))
    a1.append(a)
  for i in range(n-1):
    if a1[i]>=0:
      if (a1[i]) - (a1[i+1]) == 0:
        print("Invalid input!!,BUG AVOOLLAA HEHE!!")
        break
      if (a1[i]) - (a1[i+1]) != -1:
        b=a1[i]
        check=1
  if check!=0:
    print(b+1,"is missing!!")
  else:
    print("no missing number!!")