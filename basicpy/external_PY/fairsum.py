def Fairsum(a):
  l2=[]
  l3=[]
  l4=[]
  a.sort()
  a.reverse()
  for i in range(n):
    if (a[i]>0):
      l2.append(a[i])
    else:
      l3.append(a[i])
  if len(l2)>len(l3):
    d=len(l3)-len(l2)
    for i in range(d):
      l2.pop()
  else:
    d=len(l3)-len(l2)
    for i in range(d):
      l3.pop()
  for i in range (len(l2)):
    l4.append(l2[i])
    l4.append(l3[i])
  return l4
a=[]
print("enter  +ve and -ve numbers\n")
n=int(input("Enter size of list:"))
for i in range(n):
  print("enter  +ve and -ve numbers\n")
  e=int(input("entr the value:"))
  a.append(e)
print("fair sequence:")
result=Fairsum(a)
print(result)
s=0
for i in result:
  s=s+i
print("sum=",s)