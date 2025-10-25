n, s = map(int, input().split())
x = list(map(int, input().split()))
if s>sum(x): print(0)
else:
    print(sum(x)-s)