n = int(input())
ans = 0
x = list(map(int, input().split()))
for i in x:
    if i%2 != 0: ans+=i
print(ans)