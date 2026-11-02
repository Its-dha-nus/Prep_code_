store=[("shirt:",20.00),
       ("pants:",35.00),
       ("socks:",10.00)]

fn=lambda data : (data[0] , data[1]*0.82)
in_euro =(map(fn,store))

for i in in_euro:
  print(i)