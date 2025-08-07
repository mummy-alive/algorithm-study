n = int(input())
li = []
for i in range(n):
    li.append(int(input())) # 주어진 원소 입력

for i in range(1,n):
    key = li[i]
    j = i-1
    while  j >= 0 and li[j] > key:
        li[j+1] = li[j]	
        j = j-1 # 다음 칸으로 이동
    li[j+1] = key

for i in li:    
    print(i)  # 출력

