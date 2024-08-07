n = int(input())

sl = '%.300f' %2 ** - n
ed = len(sl)
for i in range(ed-1, 1 ,-1):
    if sl[i] != '0':
        ed = i
        break
print(sl[:ed+1])