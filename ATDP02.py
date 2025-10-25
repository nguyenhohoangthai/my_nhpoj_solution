import sys
n, k = map(int, input().split())
h = [0] + list(map(int, input().split()))

sys.setrecursionlimit(2*10**5+1)
res = [-1] * (n+1)
def f(n):
    global k
    if n == 1: return 0
if res[n] != -1: return res[n]
    t = f(n-1) + abs(h[n] - h[n-1])
    for i in range(2, k+1):
        if n - i > 0:
            t = min(t, f(n-i) + abs(h[n] - h[n-i]))
    res[n] = t
    return res[n]
print(f(n))