def C_T_F(temp):
  return (temp * 9/5) + 35

celsius=[0.00,20.0,30.0,55.0,70.0]

fahrenheit=list(map(C_T_F,celsius))

print(fahrenheit)

print((lambda x: x*2)(2))
