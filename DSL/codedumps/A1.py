numcr=int(input("Enter the number of students who play Cricket="))
numbd=int(input("Enter the number of students who play Badminton="))
numft=int(input("Enter the number of students who play Football="))

print("<----------------------------------------------------------->")
print("For students who play Cricket;-")

for i in range(0,numcr):
    lscr=[]
    cr=input("\nEnter the Name=")
    lscr.append(cr)
    

print("<----------------------------------------------------------->")
print("For students who play Badminton;-")

for i in range(0,numbd):
    lsbd=[]
    bd=input("\nEnter the Name=")
    lsbd.append(bd)


print("<----------------------------------------------------------->")
print("For students who play Football;-")

for i in range(0,numft):
    lsft=[]
    ft=input("\nEnter the Name=")
    lsft.append(ft)

print("<----------------------------------------------------------->")

setcr=set(lscr)
setbd=set(lsbd)
setft=set(lsft)

print("a.)Students who play Both Cricket and Badminton;-",list(setcr.intersection(setbd)))
print("b.)Students who play Cricket and Badminton, but not both;-",list(setcr.symmetric_difference(setbd)))
print("c.)Students who play niether Cricket not Football:-",list(setbd-(setcr.union(setft))))
print("d.)Students who play Cricket & Football but not Badminton;-",list(setft.intersection(setbd)-setbd))