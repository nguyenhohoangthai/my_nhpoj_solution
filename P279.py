m, n = map(int, input().split())
a = [[0 for i in range(n+5)] for j in range(m+5)]
for i in range(m): a[i] = list(map(int, input().split()))
k = int(input())
for i in range(k):
    x, y = map(int, input().split())
    print(a[x-1][y-1])