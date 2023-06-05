class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]  # Separate chaining

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))

    def separate_chaining_search(self, key):
        index = self.hash_function(key)
        for item in self.table[index]:
            if item[0] == key:
                return item[1]
        return None

    def linear_probing_search(self, key):
        index = self.hash_function(key)
        i = 0
        while i < self.size:
            curr_index = (index + i) % self.size
            item = self.table[curr_index]
            if item and item[0] == key:
                return item[1]
            i += 1
        return None


# Create a sample telephone book
telephone_book = {
    "John Doe": 1234567890,
    "Jane Smith": 9876543210,
    "Alice Johnson": 5678901234,
    "Bob Williams": 4567890123,
    "Eve Davis": 8901234567,
}

# Build the hash table using separate chaining
hash_table_separate_chaining = HashTable(10)
for name, number in telephone_book.items():
    hash_table_separate_chaining.insert(number, name)

# Build the hash table using linear probing
hash_table_linear_probing = HashTable(10)
for name, number in telephone_book.items():
    hash_table_linear_probing.insert(number, name)

# Test the search operations
set_of_numbers = [1234567890, 4567890123, 5555555555]  # Numbers to search

# Separate chaining search
separate_chaining_comparisons = 0
for number in set_of_numbers:
    result = hash_table_separate_chaining.separate_chaining_search(number)
    separate_chaining_comparisons += 1 if result else 0

# Linear probing search
linear_probing_comparisons = 0
for number in set_of_numbers:
    result = hash_table_linear_probing.linear_probing_search(number)
    linear_probing_comparisons += 1 if result else 0

# Compare the number of comparisons required
print("Separate Chaining Comparisons:", separate_chaining_comparisons)
print("Linear Probing Comparisons:", linear_probing_comparisons)
