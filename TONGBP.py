n = int(input())
a=0
while n>=1:
    a += (n%10)*(n%10)
    n = n//10
print(a)