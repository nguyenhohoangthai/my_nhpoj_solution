n = int(input())
temp_list_x=[]
temp_list_y=[]
for i in range(n):
    x, y = map(int, input().split())
    temp_list_x.append(x)
    temp_list_y.append(y)
print(min(temp_list_x),max(temp_list_y))
print(max(temp_list_x),min(temp_list_y))