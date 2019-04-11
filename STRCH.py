t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(str,input().split(" ")))
    s=a[0]
    x=a[1]
    total=int((n*(n+1))/2)
    q=s.split(x)
    not_sub_string=0
    for i in range (len(q)):
        not_sub_string+=int((len(q[i])*(len(q[i])+1))/2)
    print(total-not_sub_string)