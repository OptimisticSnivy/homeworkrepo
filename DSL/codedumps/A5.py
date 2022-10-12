str1=input("Enter your string here=")
char1=input("Enter the desired subtring to search=")
flag=0
ls1=str1.split()

n=len(ls1)
larg=ls1[0]
 
 
#For longest string;-

#for i in range(0,n):
#    if(len(ls1[i])>len(larg)):
#        larg=ls1[i]
#
#print(larg)

#For the most frequent character;-
#for i in str1:
#    if(char1==i):
#        flag=flag+1
#
#print("The character appears for",flag,"times!")

#For Palindrome check;-

#if(str1==str1[::-1]):
#    print("Your string is a Palindrome!")    
#else:
#    print("Your string isn't a Palindrome!")


#For substring 1st time w/ index;-

#for i in range(0,n):
#    if(ls1[i]==char1):
#        print("Character found at",i,"index")
#        break

#For no. of times of a word;-

for i in range(0,n):
   if(ls1[i]==char1):
        flag=flag+1

print("Word found",flag,"times!")

