l1=[] 
l2=[]
n=int(input("enter the number on item needed to add in the l1 : "))
for i in range (n):
    a=int(input("enter the item : "))
    l1.append(a)
x=int(input("enter the number of items in the l2 : "))
for k in range (x):
    b=int(input("enter the numbr : "))
    l2.append(b)
l3=l1+l2
l3.sort()
odd=[]
even=[]
for i in range(len(l3)):
    if l3[i]%2==0:
        even.append(l3[i])
    else:
        odd.append(l3[i])
l4=odd+even
print(l4)


