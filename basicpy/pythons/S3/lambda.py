double= lambda x: x * 2
add= lambda x, y: x + y
max_value = lambda x, y: x if x > y else y
print(add(2,1))
print(max_value(5,6))
full_name=lambda firstname,lastname: firstname + " " + lastname
print(full_name("Aroomal","shekhavar"))
age=lambda num: True if num >= 18 else False
print(age(19))
even=lambda x: x%2==0 
print(even(2))