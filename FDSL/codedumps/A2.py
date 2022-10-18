def mxfreq(List):                                   
    counter = 0
    num = List[0]    
    for i in List:
        cfreq=List.count(i)
        if(cfreq>counter):
            counter=cfreq
            num=i
    return num

n=int(input("Enter the number of students="))
cnt1=0
ls1,ls2=[],[]

for i in range(0,n):
    ent1=input("Enter marks=")
    ls1.append(ent1)
    if(ent1 in "Aa"):
        cnt1=cnt1+1
    else:
        ls2.append(int(ent1))

print("The average score of the class is:-\n",(sum(ls2)/n))
print("Maximum:\n",max(ls2))
print("Minimum:\n",min(ls2))
print("Number of Absent Students:\n",cnt1)
print("Highest Frequency of marks\n",mxfreq(ls2))

