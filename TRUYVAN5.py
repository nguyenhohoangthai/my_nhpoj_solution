n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
f = [0] * (n+1)
def _update(i, x):
    while i <= n:
        f[i] += x
        i += (i&-i)
def _sum(i):
    s = 0
while i > 0:
        s += f[i]
        i -= (i&-i)
    return s
for i in range(1, n+1): _update(i, a[i])
for im in range(m):
    t, i, j = map(int, input().split())
    if t == 1:
        _update(i, j - a[i])
        a[i] = j
    else:
        print(_sum(j) - _sum(i-1))