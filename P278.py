n = int(input())
a = list(map(int, input().split()))
ans = 0
for x in a:
    if ((x & 1) == 1): ans += x
print(ans)