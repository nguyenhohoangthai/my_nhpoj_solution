m, n = map(int, input().split())
m = 2 * m
n = 2 * n
a = [[0 for i in range(n)] for j in range(m)]
for i in range(m): a[i] = list(map(int, input().split()))
ans = [[] for j in range(m//2)]
cnt = 0
dem = 0
for cnt in range(0, m-1, 2):
    for j in range(0, n-1, 2):
        avg = (a[cnt][j] + a[cnt][j+1] + a[cnt+1][j] + a[cnt+1][j+1]) // 4
        ans[dem].append(avg)
    dem += 1
for x in ans:
    for y in x: print(y, end = " ")
    print()