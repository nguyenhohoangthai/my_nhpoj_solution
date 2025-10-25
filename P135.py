#import sys
#sys.stdin = open("DUDOAN.INP","r")
#sys.stdout = open("DUDOAN.OUT","w")
n, v = map(int,input().split())
a = list(map(int,input().split()))
mx = v+a[0]
for i in range(n):
    v += a[i]
    if v > mx: mx = v
print(mx)