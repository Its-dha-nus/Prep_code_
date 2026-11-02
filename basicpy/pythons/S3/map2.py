def map_fn(fn,iter):
  result=[]
  for i in iter :
    new_i=fn(i)
    result.append(new_i)
  return (result)

values=[1,2,3,4,5,6,7,8,9]

sqr=map_fn(lambda x: x**2,values)
print(sqr)
