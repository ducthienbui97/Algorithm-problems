def fib(n):
 a,b = 1,1
 for i in range(n):
  a,b = b,a+b
 return a
t = int(input())
for i in range(t):
    n = int(input())
    print(fib(n))
