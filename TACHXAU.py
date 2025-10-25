s = input()
ans = 1
cnt = [s[0]]
for i in range(1, len(s)):
    if s[i] != s[i-1]:
        if s[i] not in cnt:
            if len(cnt) == 1 or len(cnt) == 0: cnt.append(s[i])
            else:
                ans += 1
                cnt.clear()
                cnt = [s[i]]
print(ans)