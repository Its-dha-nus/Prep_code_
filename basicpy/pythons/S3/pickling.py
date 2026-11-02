import pickle
class Food():
  def __init__(self,protien,carbs,fat):
    self.protien = protien
    self.carbs = carbs
    self.fat = fat
  def calorie_calc(self):
    calories = self.protien*4 + self.carbs*4 + self.fat*9
    return calories
cheese=Food(9,1,9)
egg=Food(6,4,5)
Pantry={}
Pantry['cheese']=cheese
Pantry['egg']=egg
with open("Pantry.calorie","wb") as file:
  pickle.dump(Pantry,file)
