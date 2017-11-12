#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class SampleGraph {
public:
  static vector<int>* create(int numberOfNodes, int numberOfConnections);
  static void print(vector<int>* graph, int numberOfNodes);
};

vector<int>* SampleGraph::create(int numberOfNodes, int numberOfConnections) {
  vector<int>* result = new vector<int>[numberOfNodes];
  
  int counter = 0;
  while (counter < numberOfConnections) {
    int source = rand() % numberOfNodes;
    int target = rand() % numberOfNodes;
    if (source != target) {
      if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
        result[source].push_back(target);
        result[target].push_back(source);
        counter++;
      }
    }
  }
  for (int i=0; i<numberOfNodes; i++) {
    sort(result[i].begin(), result[i].end());
  }
  
  return result;
}

void SampleGraph::print(vector<int>* graph, int numberOfNodes) {
  for (int i=0; i<numberOfNodes; i++) {
    vector<int>::iterator it;
    cout << "Node " << i << "\t";
    for (it=graph[i].begin(); it!=graph[i].end(); it++) {
      cout << *it << ", ";
    }
    cout << endl;
  }
}

void dfs(vector<int>* graph, int numberOfNodes) {
  
}

void bfs(vector<int>* graph, int numberOfNodes) {
  
}

bool connected(vector<int>* graph, int numberOfNodes, int nodeA, int nodeB) {
  
}


int main(int argc, char **argv) {
  
  const int NUMBER_OF_NODES = 10;
  const int NUMBER_OF_CONNECTIONS = 16;
  SampleGraph::print(
    SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);
  
  return 0;
}
