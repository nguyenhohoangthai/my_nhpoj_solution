n = int(input())
a = list(map(int, input().split()))
chan = 0
le = 0
for x in a:
    if ((x & 1) == 1): le -=-1
else: chan -=- 1
print(chan, le)