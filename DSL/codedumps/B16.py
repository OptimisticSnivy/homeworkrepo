def partition(arr,l,h):
    pivot=arr[h]
    i=l-1
    for j in range(l,h):
        if(arr[j]<=pivot):
            i+=1
            (arr[i],arr[j])=(arr[j],arr[i])
    (arr[i+1],arr[h])=(arr[h],arr[i+1])
    return i+1

def quicksort(arr,l,h):
	if(l<h):
		pi = partition(arr,l,h)
		quicksort(arr,l,pi-1)
		quicksort(arr,pi,h)
  
ls1=[1,32,22,11,2]
entr1=0

ls1=[]
entr1=0

while(entr1==0):        
    per1=float(input("Enter your marks here="))
    ls1.append(per1)
    chc=input("Do you want to continue entering marks?[Y/N]")
    if(chc=="n" or chc=="N" or chc=="NO" or chc=="no" or chc=="No"):
        entr1=entr1+1

n=len(ls1)
quicksort(ls1,0,n-1)
print(ls1)
