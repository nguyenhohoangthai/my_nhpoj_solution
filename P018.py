m, n, k = map(int, input().split())
cnt = min(m // 2, n)
res = m+n - 3*cnt
k -= res
if k > 0:
    x = k // 3
if (x*3 >= k): print(cnt - x)
    else: print(cnt - x - 1)
else: print(cnt)