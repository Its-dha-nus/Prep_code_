n=int(input("enter the num : "))
ones=n%10
x=n//10
tens=x%10
y=x//10
hundreds=y%10
reverse_num=(ones*100)+(tens*10)+(hundreds)
print(reverse_num)

