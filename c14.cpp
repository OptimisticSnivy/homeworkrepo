
#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

// Edge structure to represent a flight path
struct Edge {
    std::string destination;
    int cost;

    Edge(const std::string& dest, int c)
        : destination(dest), cost(c) {}
};

// Graph class using adjacency list representation
class Graph {
private:
    std::unordered_map<std::string, std::list<Edge>> adjacencyList;

public:
    // Function to add an edge between cities
    void addEdge(const std::string& source, const std::string& destination, int cost) {
        adjacencyList[source].push_back(Edge(destination, cost));
    }

    // Function to check if the graph is connected
    bool isConnected() {
        if (adjacencyList.empty()) {
            return true; // Empty graph is considered connected
        }

        std::unordered_map<std::string, bool> visited;
        dfs(adjacencyList.begin()->first, visited);

        // Check if all nodes were visited
        for (const auto& node : adjacencyList) {
            if (!visited[node.first]) {
                return false;
            }
        }

        return true;
    }

private:
    // Depth-first search (DFS) to visit all connected nodes
    void dfs(const std::string& node, std::unordered_map<std::string, bool>& visited) {
        visited[node] = true;

        for (const auto& edge : adjacencyList[node]) {
            if (!visited[edge.destination]) {
                dfs(edge.destination, visited);
            }
        }
    }
};

int main() {
    // Create a graph
    Graph flightGraph;

    // Add flight paths
    flightGraph.addEdge("City A", "City B", 2);
    flightGraph.addEdge("City B", "City C", 1);
    flightGraph.addEdge("City C", "City D", 3);
    flightGraph.addEdge("City D", "City E", 2);
    flightGraph.addEdge("City E", "City F", 1);

    // Check if the graph is connected
    if (flightGraph.isConnected()) {
        std::cout << "The graph is connected." << std::endl;
    } else {
        std::cout << "The graph is not connected." << std::endl;
    }

    return 0;
}
