import re
file=open("data.txt","r")
for line in file:
  x=re.search(r"\d{3}-\d{8}",line)
  if x:
    print(line.strip())
file.close()
