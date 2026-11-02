import pickle
from pickling import Food

with open('Pantry.calorie','rb') as file:
  Pantry=pickle.load(file)
cheese=Pantry['cheese']
egg=Pantry['egg']

print(cheese.carbs)
print(cheese.calorie_calc())

print(egg.carbs)
print(egg.calorie_calc())
