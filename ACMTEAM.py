a = list(map(int, input().split()))
np = [0]*6
def sinhnp(i):
    global ans
    if i == 6:
        cnt, s0, s1 = 0, 0, 0
        for j in range(6):
            if np[j] == 0:
                cnt += 1
                s0 += a[j]
            else:
                cnt -= 1
                s1 += a[j]
        if cnt == 0:
            ans = min(ans, abs(s1-s0))
        return
    for j in range(2):
        np[i] = j
        sinhnp(i+1)
ans = 1000
sinhnp(0)
print(ans)
