m=int(input("Enter the number of rows="))
n=int(input("Enter the number of columns="))

mult=0
mata,matb,matadd,matsubt,matmul,matat,matbtr=[],[],[],[],[],[],[]

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

for g in range(0,m):
    coladd=[]
    colsubt=[]
    for h in range(0,n):
        add=mata[g][h]+matb[g][h]
        subt=mata[g][h]-matb[g][h]
        coladd.append(add)
        colsubt.append(subt)
    matadd.append(coladd)
    matsubt.append(colsubt)    


print("For the Addition of the Matrices:-")
print(matadd)
print("For the Subtraction of the Matrices:-")
print(matsubt)

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
        colbtr.append(t2)
    matbtr.append(colbtr)

print(matbtr)

print("For the Multiplication of the both Matrices:-\n")

for u in range(0,m):
    colmul=[]
    for v in range(len(matb[0])):
        for w in range(len(matb)):
            mult+= mata[u][v] * matb[w][v]
        colmul.append(mult)
    matmul.append(colmul)

print(matmul)