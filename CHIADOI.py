a, b, x, y, k = map(int, input().split())
divided = min(a//x, b//y)
nam_rest = a - x * divided
nu_rest = b - y * divided
s = nam_rest + nu_rest
k -= s
low, high = 0, k
ans = 0
while low <= high:
    mid = (low + high) // 2
if mid * (x+y) >= k:
        ans = mid
        high = mid - 1
else: low = mid + 1
print(divided - ans)