n, m, p, q = map(int, input().split())
if q % 2 == 0:
    if p % 2 == 0: print("W")
    else: print("B")
else:
    if p % 2 == 0: print("B")
    else: print("W")