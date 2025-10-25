from math import sqrt
n = int(input())
ans = 0
for i in range(1, int(sqrt(n))+1):
    if n % i == 0:
        temp = n//i
if i%2 == 1: ans += 1
if temp != i and temp % 2 == 1: ans += 1
print(ans)