def bubsort(arr):
    n=len(arr)
    for i in range(n):
        for j in range(0,n-i-1):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]
    

ls1=[]
entr1=0

while(entr1==0):        
    per1=float(input("Enter your marks here="))
    ls1.append(per1)
    chc=input("Do you want to continue entering marks?[Y/N]")
    if(chc=="n" or chc=="N" or chc=="NO" or chc=="no" or chc=="No"):
        entr1=entr1+1

bubsort(ls1)
print(ls1)