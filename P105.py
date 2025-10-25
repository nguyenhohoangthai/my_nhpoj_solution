n = int(input())
a = list(map(int, input().split()))
x = int(input())

b = [[0,0]]*n
for i in range(n):
    b[i] = [a[i],i]
def cmp(x):
return x[0]*(10**5) + x[1]
b.sort(key = cmp)

def found(x):
global n
    low, high, pos = 0, n-1, n
    while low <= high:
        mid = (low+high) // 2
if b[mid][0] >= x:
            if b[mid][0] == x: pos = mid
            high = mid - 1
else:
            low = mid+1
return pos


for i in range(n-1):
    if x - a[i] < b[0][0] or x - a[i] >b[n-1][0]: continue
    p = found(x - a[i])
    if p == n: continue
    j = b[p][1]
    if i == j and p < n-1 and b[p][0] == b[p+1][0]: j = b[p+1][1]
    if i != j:
        print(i,j)
        break