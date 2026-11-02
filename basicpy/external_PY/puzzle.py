def calcu(legs,head):
  if legs%2 !=0:
    print("no solution")
  else:
    r=(legs-2*head)/2
    c=head-r
    if r<0 or c<0:
      print("NO VALID ANSWER!!")
    else:
      print(f"chickes:{c} rabbits:{r}")
legs=int(input("enter the number of legs :"))
heads=int(input("enter the nuber of heads:"))
calcu(legs,heads)