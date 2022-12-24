#include <iostream>
#include <string>
#include <map> // For the map container

using namespace std;

int main()
{
  // Create a map associative container to store the population of states in India
  map<string, int> statePopulations;

  // Add some state population data to the map
  statePopulations["Maharashtra"] = 12531549;
  statePopulations["Tamil Nadu"] = 72147030;
  statePopulations["Uttar Pradesh"] = 199812341;
  statePopulations["Bihar"] = 104099452;
  statePopulations["West Bengal"] = 91276115;

  // Prompt the user to enter the name of a state
  cout << "Enter the name of a state: ";
  string stateName;
  getline(cin, stateName);

  // Look up the population of the state in the map
  auto it = statePopulations.find(stateName);
  if (it != statePopulations.end())
  {
    // State was found in the map
    cout << "The population of " << stateName << " is " << it->second << "." << endl;
  }
  else
  {
    // State was not found in the map
    cout << "Sorry, I couldn't find the population of " << stateName << "." << endl;
  }

  return 0;
}
