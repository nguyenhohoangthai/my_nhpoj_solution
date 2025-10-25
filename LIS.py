n = int(input())
a = [0] + list(map(int, input().split()))
L = [0]
for i in range(1, n+1):
    if a[i] > L[-1]: L.append(a[i])
    else:
        low, high = 0, len(L) - 1
        p = 0
while low <= high:
            mid = (low + high) // 2
if L[mid] >= a[i]:
                high = mid - 1
else:
                p = mid
                low = mid + 1
        L[p+1] = a[i]
print(len(L)-1)