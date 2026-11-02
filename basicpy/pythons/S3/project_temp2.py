import pickle

class InavlidInputError(Exception):
  pass

Factors={
  "car":0.21,
  "bus":0.10,
  "electricity":0.85,
  "meat":2.5
}

def Carbon_calculator(items,value):
  return value*Factors[items]

def Saving_file(name,value):
  records={'Name':name,'Total_co2':value}
  with open('Save.records','ab') as f:
    pickle.dump(records)

def display_file():
  try:
    with open('Save.records','rb') as f:
      print("recors  showning!!")
      while True:
        try:
          record=pickle.load(f)
          print(record)
        except EOFError:
          break
  except FileNotFoundError:
    print("No preious ")
def main():
  print("Carbon foot printinf tracker!!!")
  print("-------------------------------")
  name=input("enter your name:")
  activity=['car','bus','electricity','meat']

  values=[]
  for act in activity:
    try:
      value=float(input(f"enter your {act} usage (in/k/kwh/servings)"))
      if value<0:
        raise InavlidInputError
      values.append(value)
    except ValueError:
      print("INvalid input!!")
    except InavlidInputError:
      print("Enter the value greater than ZERO!!")
  total=0
  for i in range(len(activity)):
    total += Carbon_calculator(values[i],activity[i])
  Saving_file(name,total)
  display_file()

if __name__=="__main__":
  main()