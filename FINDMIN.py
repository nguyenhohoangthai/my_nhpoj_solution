n = int(input())
t = int(input())
for i in range(n-1):
    k = int(input())
    t = min(t, k)
print(t)