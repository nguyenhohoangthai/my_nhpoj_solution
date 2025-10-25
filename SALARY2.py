h = float(input())
r = float(input())
du = h-40
if du>0:
    ruoi = 3/2
    tien_luong = 40*r+du*r*ruoi
    print(int(tien_luong))
else:
    print(h*r)