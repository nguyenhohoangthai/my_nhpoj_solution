h = list(map(int, input().split()))
h_1 = h[0]*60
h_2 = h[2]*60
sum_1 = h_1+h[1]
sum_2 = h_2+h[3]
time = sum_2-sum_1
print(time)