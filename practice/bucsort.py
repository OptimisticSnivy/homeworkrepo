l=[10.1,0.1,8.2,12.5,24.5,24.1,26.8,89.2,99.1,99.9,45,2,45.2,5.3,4.2,0.3,5.4,10.5]
bucket=[]
rangemin=0
rangemax=10
for i in range(0,10):
    temp=[]
    for i in l:
        if(i>=rangemin and i<=rangemax):
            temp.append(i)
    bucket.append(temp)
    rangemin+=10
    rangemax+=10
for i in range(len(bucket)):
    bucket[i].sort()
for i in bucket:
    for j in i:
        print(j,end=" ")