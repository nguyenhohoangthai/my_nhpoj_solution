n, m = map(int, input().split())
ans = n*(n+1)*(2*n+1)//6
print(ans%m)