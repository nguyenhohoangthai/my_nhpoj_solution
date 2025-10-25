a, b = map(int, input().split())
if (a <= b):
    for i in range(a, b): print(i, end = " ")
    print(b)
else:
    for i in range(-a, -b): print(-i, end = " ")
    print(b)