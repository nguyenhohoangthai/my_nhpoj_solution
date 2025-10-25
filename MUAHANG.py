n = int(input())
temp = []
ans=0
for i in range(n):
    a = int(input())
    temp.append(a)
temp.sort()
temp.reverse()
for i in range(n%3):
    ans+=temp[-1]
    temp.remove(temp[-1])
for i in range(n//3):
    ans+=temp[0]
    ans+=temp[1]
    temp.remove(temp[0])
    temp.remove(temp[0])
    temp.remove(temp[0])

print(ans)