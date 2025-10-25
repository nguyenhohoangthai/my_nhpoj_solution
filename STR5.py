s = input()
t = int(input())
if (t == 0): print(s)
elif (t == 1): print(s.upper())
elif (t == 2): print(s.lower())
else:
    s = s.split()
    for i in range(len(s)): s[i] = s[i].lower()
    for i in range(len(s) - 1):
        tmp = ""
        tmp += s[i][0];
        print(tmp.upper(), end = "")
        print((s[i][1:]), end = " ")
    tmp = ""
    tmp += s[len(s)-1][0];
    print(tmp.upper(), end = "")
    print((s[len(s)-1][1:]), end = " ")