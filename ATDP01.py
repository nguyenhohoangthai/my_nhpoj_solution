import sys
n = int(input())
h = [0]+list(map(int, input().split()))

sys.setrecursionlimit(2*10**5+1)
res = [-1] * (n+1)
def f(n):
    if n == 1: return 0
if n == 2: return abs(h[2] - h[1])
    if res[n] != -1: return res[n]
    res[n] = min(f(n-1) + abs(h[n] - h[n-1]), f(n-2) + abs(h[n] - h[n-2]))
    return res[n]
print(f(n))