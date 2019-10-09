x=int(input(" 1 - repeat until n. 2 - repeat x times. 3 - repeat infinitely. choose a numbero:".replace(".", "\n")))
a= 0
b= 1
c=0
print("/\  "*10)
print("  \/"*10)

if x == 1:
  n=int(input("enter the maximum value of the fibonacci sequence:"))
  print("/\  "*10)
  print("  \/"*10)
  print(a)
  print(b)
  while(1):
    c = a + b
    if c > n:
      break
    a = b
    b = c
    print (c) 
elif x == 2:
  n=int(input("Enter the number of fibonacci sequence numbers you want:"))
  i=3
  print("/\  "*10)
  print("  \/"*10)
  print("1 -",a)
  print("2 -",b)
  for l in range(n-2):
    c = a + b
    a = b
    b = c
    print (i, "-", c)
    i=i+1
elif x == 3:
    print("/\  "*10)
    print("  \/"*10)
    print (a)
    print(b)
    for l in range(n):
     c = a + b
     a = b
     b = c
     print (c)
     n=n+1