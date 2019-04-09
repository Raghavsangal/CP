n=int(input())
a=list(map(int,input().split(" ")))
a=list(set(a))
t=max(a)
a.remove(t)
if(len(a)==0):
    print(0)
else:
    y=max(a)
    print(y%t)