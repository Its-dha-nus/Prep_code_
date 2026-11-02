n=int(input("enter: "))
a=0
b=1
sum=0
while sum<n:
    print(a,end=" ")
    c=a+b
    a=b
    b=c
    sum+=1
    