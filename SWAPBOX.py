s = input()
pos = 1
for x in s:
    if x == "A":
        if pos == 1: pos = 2
elif pos == 2: pos = 1
elif x == "B":
        if pos == 2: pos = 3
elif pos == 3: pos = 2
elif x == "C":
        if pos == 1: pos = 3
elif pos == 3: pos = 1
print(pos)