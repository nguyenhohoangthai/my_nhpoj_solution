T = int(input())
for i in range(T):
    ans = 0
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    r = 0
for i in range(m):
        while r < n and a[r] - k <= b[i]:
            if a[r] + k >= b[i]:
                ans += 1
                r += 1
break
else: r += 1
    print(ans)