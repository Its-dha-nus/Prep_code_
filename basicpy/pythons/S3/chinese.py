def solve(legs,heads):
  if(legs%2 !=0):
    print("no solution!!")
  else:
    rabbits=(legs - 2*heads)/2
    chickens=heads-rabbits
    if rabbits <0 or chickens<0:
      print("Solution no available!!")
    else:
      print("Chickens=",chickens,"rabbits=",rabbits)
heads=int(input("enter the number of heads:"))
legs=int(input("enter the number of legs:"))
solve(legs,heads)