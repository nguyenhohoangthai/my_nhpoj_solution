n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
b = [0] + list(map(int, input().split()))
a.sort()
for i in range(1, m+1):
    p = 0
    low, high = 1, n
    while low <= high:
        mid = (low+high)//2
if a[mid] < b[i]:
            p = mid
            low = mid + 1
else:
            high = mid - 1
    print(p, end = " ")
print()