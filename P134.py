n = int(input())
a = [0] + list(map(int,input().split()))
chan = [0] * (n+1)
le = [0] * (n+1)
ans = 0
for i in range(1,n+1):
    chan[i] = chan[i-1]
    le[i] = le[i-1]
    if a[i] % 2 == 0: chan[i] += 1
else: le[i] += 1
for i in range(1,n+1):
    for j in range(i+1,n+1):
        if chan[j] - chan[i-1] == le[j]-le[i-1]:
            ans = max(ans, j-i+1)
print(ans)