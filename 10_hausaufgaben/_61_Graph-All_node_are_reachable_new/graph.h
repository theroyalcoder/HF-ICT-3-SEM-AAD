#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class SampleGraph {
private:
  vector< vector<int> > neighbours;
  vector< vector<int> > weights;
public:
  SampleGraph();
  void randomInit(int nNodes=10, int nConnections=15, bool directed=false);
  int getNumberOfNodes();
  vector<int> getNeighbours(int node);
  vector<int> getWeights(int node);
    static vector<int>* create(int numberOfNodes, int numberOfConnections);
    static void print(vector<int>* graph, int numberOfNodes);

  friend std::ostream& operator<<(std::ostream& s, const SampleGraph & obj);
};

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

vector<int> *SampleGraph::create(int numberOfNodes, int numberOfConnections) {
    auto * result = new vector<int>[numberOfNodes];

    int counter = 0;
    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;
        if (source != target) {
            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(target);
                //result[target].push_back(source); //Auskommentieren, damit wir einen gerichteten SampleGraph haben
                counter++;
            }
        }
    }

    for (int i=0; i<numberOfNodes; i++) {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}


std::ostream& operator<<(std::ostream& s, const SampleGraph & obj);

#endif
