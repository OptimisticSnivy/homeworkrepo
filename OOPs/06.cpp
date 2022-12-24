#include <iostream>
#include <algorithm> // For the sort function
#include <vector> // For the vector container

using namespace std;

// Define the item record structure
struct Item
{
  string name;
  int quantity;
  double price;
};



// Function to compare two item records based on their name
bool compareByName(const Item &a, const Item &b)
{
  return a.price < b.price;
}

int main()
{
  int n;    
  // Create a vector of item records
  vector<Item> items;

  // Add some item records to the vector
  items.push_back({"Apple", 10, 0.99});
  items.push_back({"Banana", 5, 0.59});
  items.push_back({"Carrot", 15, 0.79});
  items.push_back({"Durian", 7, 1.29});
  items.push_back({"Eggplant", 8, 0.89});

  // Sort the item records by name using the sort function
  sort(items.begin(), items.end(), compareByName);

  cout << "Sorted item records:" << endl;
  n=items.size();
  for (i=0;i<n;i++)
  {
    cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
  }

  // Print the sorted item records
  /*
  cout << "Sorted item records:" << endl;
  for (const auto &item : items)
  {
    cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << endl;
  }

  // Search for an item record with a specific name using the find function
  auto it = find_if(items.begin(), items.end(), [](const Item &item) { return item.name == "Carrot"; });
  if (it != items.end())
  {
    cout << "Item record found: " << endl;
    cout << "Name: " << it->name << ", Quantity: " << it->quantity << ", Price: $" << it->price << endl;
  }
  else
  {
    cout << "Item record not found." << endl;
  }
  */
  return 0;
}
