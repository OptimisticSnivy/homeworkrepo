def bucsort(marks):
    n = len(marks)
    
    for i in range(n-1):
        for j in range(0,n-i-1):
            if marks[j]>marks[j+1]:
                marks[j],marks[j+1]=marks[j+1],marks[j]

    print("Marks of students after performing Bubble Sort on the list :")
    for i in range(len(marks)):
        print(marks[i])

ls1=[]
entr1=0

while(entr1==0):        
    per1=float(input("Enter your marks here="))
    ls1.append(per1)
    chc=input("Do you want to continue entering marks?[Y/N]")
    if(chc=="n" or chc=="N" or chc=="NO" or chc=="no" or chc=="No"):
        entr1=entr1+1

bucsort(ls1)
print(ls1)