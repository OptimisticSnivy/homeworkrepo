def selecsort(arr):
    n=len(arr)
    for i in range(n):
        minind=i
        for j in range(i+1,n):
            if(arr[j]<arr[minind]):
                minind=j
        arr[i],arr[minind]=arr[minind],arr[i]
    
ls1=[]
entr1=0

while(entr1==0):        
    per1=float(input("Enter your marks here="))
    ls1.append(per1)
    chc=input("Do you want to continue entering marks?[Y/N]")
    if(chc=="n" or chc=="N" or chc=="NO" or chc=="no" or chc=="No"):
        entr1=entr1+1

selecsort(ls1)
print(ls1)