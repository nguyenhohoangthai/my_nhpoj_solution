a = [0]*15
for i in range(1, 10): a[i] = int(input())

np = [0]*10
ans = [0]*10
while True:
    s = cnt =0
for i in range(1, 10):
        if np[i] == 1:
            s += a[i]
            cnt += 1
if cnt == 7 and s == 100:
        for i in range(1, 10):
            ans[i] = np[i]
        break

    p = 9
while p > 0 and np[p] == 1: p -= 1
if p == 0: break
    np[p] = 1
for i in range(p+1, 10):
        np[i] = 0
for i in range(1, 10):
    if ans[i] == 1: print(a[i])