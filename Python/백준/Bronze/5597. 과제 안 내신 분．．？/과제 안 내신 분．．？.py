a = []
for i in range(0, 31): 
    a.append(0)
for i in range(0, 28):
    num = int(input())
    a[num] = 1
for i in range(1,31):
    if a[i] == 0:
        print(i)