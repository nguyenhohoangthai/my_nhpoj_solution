n = int(input())
a = list(map(int, input().split()))
cols = []
for x in a:
    low, high, pos = 0, len(cols) - 1, len(cols)
    while low <= high:
        mid = (low+high) // 2
if cols[mid] > x:
            pos = mid
            high = mid - 1
else: low = mid + 1
if pos == len(cols): cols.append(x)
    else: cols[pos] = x
print(len(cols))