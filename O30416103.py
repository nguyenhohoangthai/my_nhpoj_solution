up = [-1] * 505
down_1_1 = [-1] * 505
down_1_0 = [-1] * 505
down_2 = [-1] * 505
def dp_up(x):
if (x == 0): return 1
if (x < 0): return 0
if (up[x] != -1): return up[x]
    up[x] = dp_up(x-1) + dp_up(x-2) + dp_up(x-3)
    return up[x]

def dp_down_1(x, flag):
if (x == 0 and flag == 1): return 1
if (x == 0 and flag == 0): return 0
if (x < 0): return 0
if flag == 0:
        if (down_1_0[x] != -1): return down_1_0[x]
        down_1_0[x] = dp_down_1(x-1, 0) + dp_down_1(x-2, 0) + dp_down_1(x-3, 1)
        return down_1_0[x]
    else:
        if (down_1_1[x] != -1): return down_1_1[x]
        down_1_1[x] = dp_down_1(x-1, 1) + dp_down_1(x-2, 1)
        return down_1_1[x]
def dp_down_2(x) :
if (x == 0): return 1;
    if (x < 0): return 0;
    if (down_2[x] != -1): return down_2[x];
    down_2[x] = dp_down_2(x-1) + dp_down_2(x-2);
    return down_2[x]
while True:
    try:
        a, b = map(int, input().split())
        up_a = dp_up(a);
        up_b = dp_up(b);
        down_a = dp_down_2(a);
        down_b = dp_down_1(b, 0)
        print(up_a * up_b * down_a * down_b)
    except EOFError: break