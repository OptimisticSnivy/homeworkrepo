def recbs(arr,l,h,key):
    if(h>=l):
        mid=(h+l)//2
        
        if(arr[mid]==key):
            print(mid)
            return mid
        elif(arr[mid]>key):
            print(mid)
            return recbs(arr,l,mid-1,key)
        elif(arr[mid]<key):
            print(mid)
            return recbs(arr,mid+1,h,key)
    else:
        return -1

def iterbs(arr,key):
    l=0
    mid=0
    h=len(arr)-1
    while(l<=h):
        mid=int((l+h)/2)
        if(arr[mid]<key):
            l=mid+1
        elif(arr[mid]>key):
            h=mid-1
        else:
            return mid
    return -1

def binary_s(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
 
    while low <= high:
 
        mid = (high + low) // 2
 
        # If x is greater, ignore left half
        if arr[mid] < x:
            low = mid + 1
 
        # If x is smaller, ignore right half
        elif arr[mid] > x:
            high = mid - 1
 
        # means x is present at mid
        else:
            return mid
 
    # If we reach here, then the element was not present
    return -1

ls1=[]
n=int(input("Enter the Number of Entries you want;-"))
for i in range(0,n):
    col1=[]
    name1=input("Enter your name=")
    col1.append(name1)
    num1=input("Enter your Phone Number=")
    col1.append(num1)
    ls1.append(col1)
    
templs1=[i[0] for i in ls1]
print("<---------------------------------------------------------->")
srch=input("Enter the name to be searched=")

result1=iterbs(templs1,srch)
print("<---------------------------------------------------------->")
if(result1==-1):
    col1=[]
    name1=input("Enter your Name=")
    col1.append(name1)
    num1=input("Enter your Phone Number=")
    col1.append(num1)
    ls1.append(col1)
    print(ls1)
else:
    print("Element found at index",result1,"!")