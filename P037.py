n, d = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
ans = 0
left = 0
right = 1
size = len(a)
while size > 1:
    try:
        prev = a[right] - a[left]
        if prev <= d:
            ans += 1
            left += 2
            right = left + 1
            size -= 2
else:
            left += 1
            right = left + 1
            size -= 1
    except: break
print(ans)