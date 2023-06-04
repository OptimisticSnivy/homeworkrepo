class client:
    def_init_(self,name,phone_number):
        self.name= name
        self.phone_number=phone_number

class hashTable:
    def_init_(self,size):
        self.size=size
        for i in range(size):
            inner=[]
            for j in range(2):
                inner.append(0)
            self.append(inner)   


    def insert(self,client):
        key=client.name
        index=self.hashfunction(key)
        self.table[index].append(client)

