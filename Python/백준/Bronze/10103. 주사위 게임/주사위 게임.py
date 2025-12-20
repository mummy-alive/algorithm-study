n = int(input())
p1 = 100
p2 = 100
while n:
    n-=1
    a, b= map(int, input().split())
    if a < b:
        p1 -= b
    elif a > b:
        p2 -= a
print(p1, p2, sep='\n')