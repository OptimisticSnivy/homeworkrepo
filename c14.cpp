#include <iostream>
#include<string>
using namespace std;

const int MAX_CITIES = 100; // Maximum number of cities

struct flightname{
  int serialNumber;
  string cityName;
};


class Graph {
private:
    int adjacencyMatrix[MAX_CITIES][MAX_CITIES];
    int numCities;

public:
    Graph(int numCities) {
        this->numCities = numCities;

        // Initialize the adjacency matrix with zeros
        for (int i = 0; i < numCities; ++i) {
            for (int j = 0; j < numCities; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addFlight(int cityA, int cityB, int cost) {
        // Update the adjacency matrix with the cost of the flight
        adjacencyMatrix[cityA][cityB] = cost;
        adjacencyMatrix[cityB][cityA] = cost; // Assuming flights are bidirectional
    }

    bool isConnected() {
        bool visited[MAX_CITIES] = {false};

        // Perform a depth-first search (DFS) to check connectivity
        dfs(0, visited);

        // If any city is not visited, the graph is not connected
        for (int i = 0; i < numCities; ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    void dfs(int city, bool visited[]) {
        visited[city] = true;

        for (int neighbor = 0; neighbor < numCities; ++neighbor) {
            if (adjacencyMatrix[city][neighbor] > 0 && !visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
};

int main() {
    // Create a graph with 4 cities
    Graph graph(4);
    flightname a;
    a.cityName="PUNE";
    a.serialNumber=0;
    // Add flights between cities with their respective costs
    graph.addFlight(0, 1, 5);
    graph.addFlight(a.serialNumber, 2, 3);
    graph.addFlight(1, 2, 2);
    graph.addFlight(1, 3, 4);
    graph.addFlight(2, 3, 6);

    // Check if the graph is connected
    if (graph.isConnected()) {
        std::cout << "The graph is connected." << std::endl;
    } else {
        std::cout << "The graph is not connected." << std::endl;
    }

    return 0;
}
