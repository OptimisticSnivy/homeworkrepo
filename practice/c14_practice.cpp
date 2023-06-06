#include<iostream>
#include<string>
using namespace std;

const int MAX_CITIES=100;

struct flightName{
  string cityName;
  int cityNumber;
};

class graph{
private:
  int adjMatrix[MAX_CITIES][MAX_CITIES];
  int numCities;
public:
  graph(int numCities){
    this-> numCities=numCities;
    for(int i=0;i<numCities;i++){
      for(int j=0;j<numCities;j++){
        adjMatrix[i][j]=0;
      }
    }
  }
  
  void addFlight(int cityA,int cityB, int cost){
    adjMatrix[cityA][cityB]=cost;  
  }
  
  void dfs(int city,bool visited[]){
    visited[city]=true;

    for(int ngb=0;ngb<numCities;ngb++){
      if(adjMatrix[city][ngb]>0 && !visited[ngb]){
        dfs(ngb,visited);
      }
    }
  }

  bool isConnected(){
    bool visited[MAX_CITIES]={false};

    dfs(0,visited);
    for(int i=0;i<numCities;i++){
      if(!visited[i]){
        return false;
      }
    }

    return true;
  }

};

int main(){
    // Create a graph with 4 cities
    graph graph1(4);
    flightName a;
    a.cityName="PUNE";
    a.cityNumber=0;
    // Add flights between cities with their respective costs
    graph1.addFlight(0, 1, 5);
    graph1.addFlight(a.cityNumber,1, 3);
    graph1.addFlight(1, 3, 4);
    graph1.addFlight(2, 3, 6);

    // Check if the graph is connected
    if (graph1.isConnected()) {
        std::cout << "The graph is connected." << std::endl;
    } else {
        std::cout << "The graph is not connected." << std::endl;
    }

    return 0;
}
