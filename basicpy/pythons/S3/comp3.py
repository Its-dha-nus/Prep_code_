catagories=["Even" if x%2 ==0 else "Odd" for x in range(1,10)]
ls=[[[num for num in range(5)]for _ in range(5)]for _ in range(5)]

dict=[("num",1),("num2",2),("num3",3)]
dictcomp={key:value**2 for key,value in dict}
print(dictcomp)





