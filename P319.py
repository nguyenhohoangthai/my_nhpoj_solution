n = int(input())
a = list(map(int, input().split()))
x, y = map(int, input().split())
print(sum(a[x:y]))