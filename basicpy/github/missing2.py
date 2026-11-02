a1=[]
flag=1
n=int(input("enter the limit:"))
if n==0:
  print("invalid limit!!")
  exit()
for i in range(n):
  a=int(input("enter the element:"))
  a1.append(a)
a1=list(set(a1))
a1.sort()
n=len(a1)
if n==1:
  print("no missing!!")
else:
  for i in range(n-1):
    if a1[i]>=0:
      if a1[i+1] != a1[i]+1:
        print((a1[i]+1),"is missing!!")
        flag=0
        break
  if flag:
    print("The arr has been sorted.")
    print("No missing number:) ")