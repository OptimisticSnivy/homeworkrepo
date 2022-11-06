def recbs(arr,l,h,key):
    storarr=[i[0] for i in arr]
    while(h-l>1):
        print('1')
        mid=int((l+h)/2)
        if(key==storarr[mid]):
            return mid
        elif(storarr[mid]<key):
            l=mid+1
        elif(storarr[mid]<key):
            h=mid-1

 
ls1=[]
n=int(input("No of students="))
for i in range(n):
    col1=[]
    name1=input("Enter your name=")
    col1.append(name1)
    num1=input("Enter your Phone Number=")
    col1.append(num1)
    ls1.append(col1)
    
print("<---------------------------------------------------------->")
srch=input("Enter the name to be searched=")

result1=recbs(ls1,0,n,srch)
print("<---------------------------------------------------------->")
if(result1==False):
    col1=[]
    name1=input("Enter your name=")
    col1.append(name1)
    num1=input("Enter your Phone Number=")
    col1.append(num1)
    ls1.append(col1)
    print(ls1)
else:
    print("Element found at index",result1,"!")