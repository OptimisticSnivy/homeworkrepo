m=int(input("Enter the number of rows="))
n=int(input("Enter the number of columns="))

mata,matb,matadd,matat,matbtr=[],[],[],[],[]

print("For the 1st Matrix:-")

for i in range(0,m):
    cola=[]
    for j in range(0,n):
        a=int(input("Enter="))
        cola.append(a)
    mata.append(cola)

print("For the 2nd Matrix:-")

for k in range(0,m):
    colb=[]
    for l in range(0,n):
        b=int(input("Enter="))
        colb.append(b)
    matb.append(colb)

print("For the Addition of the Matrices:-")

for g in range(0,m):
    coladd=[]
    for h in range(0,n):
        add=mata[g][h]+matb[g][h]
        coladd.append(add)
    matadd.append(coladd)

print(matadd)

print("For the Transpose of the both Matrices:-")

for d in range(0,m):
    colat=[]
    for e in range(0,n):
        t1=mata[e][d]
        colat.append(t1)
    matat.append(colat)

print(matat)

for p in range(0,m):
    colbtr=[]
    for q in range(0,n):
        t2=matb[q][p]
        colat.append(t2)
    matbtr.append(colbtr)

print(matbtr)
