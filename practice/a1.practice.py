class hashTable:
    def __init__(self,size):
        self.size=size
        self.table=[[]for _ in range(size)]

    def hashFunction(self,key):
        return key % self.size 

    def insert_linear_probing(self,key,value):
        index=self.hashFunction(key)
        for i in range(0,self.size):
           if(self.table[(index+i)%self.size]==[]):
            self.table[(index+i)%self.size].append((key,value)) 
            break
           else:                    
            print("Inserting...")

    def insert_quadratic_probing(self,key,value):
        index=self.hashFunction(key)
        for i in range(0,self.size):
           if(self.table[(index+(i*i))%self.size]==[]):
            self.table[(index+(i*i))%self.size].append((key,value)) 
            break
           else:                    
            print("Inserting...")
    
    def search_linear_probing(self, key):
        index = self.hashFunction(key)
        for i in range(0, self.size):
            if self.table[(index+i) % self.size] != [] and self.table[(index+i) % self.size][0][0] == key:
                print("Entry Found! ", self.table[(index+i) % self.size])
                break
            else:
                print("Searching...")

telephone_book = {
    "John Doe": 1234567899,
    "Jane Smith": 9876543210,
    "Alice Johnson": 5678901230,
    "Bob Williams": 4567890121,
    "Eve Davis": 8901234569,
}

hashTable1 = hashTable(10)

for name, number in telephone_book.items():
    hashTable1.insert_quadratic_probing(number,name)

hashTable1.search_linear_probing(1234567899)
print(hashTable1.table)
