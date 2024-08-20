n = int(input())
li = []
mx = 0
for _ in range(n):
    a, b, c = map(int, input().split())
    cnt = 0
    if a==b:
        if b==c:
            cnt = 10000 + a*1000
        else:
            cnt = 1000 + a*100
    elif b==c:
        cnt = 1000 + b*100
    elif c==a: 
        cnt = 1000 + c*100
    else:
        cnt = max(a, max(b, c)) * 100
    mx = max(mx, cnt)
print(mx)