a, b = map(int, input().split())
l = [i for i in range(a + ((a & 1) == 0), b + (b & 1), 2)]
print(l)