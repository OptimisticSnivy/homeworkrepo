def recbs(arr,l,h,key):
    if(l==h):
        if(arr[l]==key):
            return l
        else:
            return 0
    else:
        mid =int((l+h)/2)
        if(arr[mid]==key):
            return mid
        elif(arr[mid]>key):
            return recbs(arr,l,mid-1,key)
        else:
            return recbs(arr,mid+1,h,key)

ls1=[1,5,7,22,111,121]

result1=recbs(ls1,1,4,121)

print(result1)