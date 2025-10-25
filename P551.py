n = int(input())
ans = 1
while n > 0:
    ans *= (n % 10)
    n //= 10
print(ans)