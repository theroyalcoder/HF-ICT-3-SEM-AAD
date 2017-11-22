#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

SampleGraph::SampleGraph() = default;

void SampleGraph::randomInit(int nNodes, int nConnections, bool directed) {
  vector<int> v;
  for (int i=0; i<nNodes; i++) {
    neighbours.push_back(v);
  }
  int counter = 0;
  while (counter < nConnections) {
    int source = rand() % nNodes;
    int target = rand() % nNodes;
    if (source != target) {
      if (find(neighbours[source].begin(), neighbours[source].end(), target) == neighbours[source].end()) {
        neighbours[source].push_back(target);
        if (!directed) {
          neighbours[target].push_back(source);
        }
        counter++;
      }
    }
  }
  for (int i=0; i<nNodes; i++) {
    sort(neighbours[i].begin(), neighbours[i].end());
  }

  for (vector<int> v : neighbours) {
    vector<int> w;
    for (int i=0; i<v.size(); i++) {
      int cost = rand() % 20 + 1;
      w.push_back(cost);
    }
    weights.push_back(w);
  }

  if (!directed) {
    for (int i=0; i<weights.size(); i++) {
      for (int j=0; j<weights.at(i).size(); j++) {
        int source = i;
        int target = neighbours.at(i).at(j);
        int weight = weights.at(i).at(j);
        int index = static_cast<int>(find(neighbours.at(static_cast<unsigned long>(target)).begin(), neighbours.at(
                static_cast<unsigned long>(target)).end(), source) - neighbours.at(static_cast<unsigned long>(target)).begin());
        weights[target][index] = weight;
      }
    }
  }
}

int SampleGraph::getNumberOfNodes() {
  return neighbours.size();
}

vector<int> SampleGraph::getNeighbours(int node) {
  return neighbours.at(static_cast<unsigned long>(node));
}

vector<int> SampleGraph::getWeights(int node) {
  return weights.at(node);
}

std::ostream& operator<<(std::ostream& s, const SampleGraph & obj) {
  for (int i=0; i<obj.neighbours.size(); i++) {
    vector<int>::iterator it;
    s << "Node " << i << "\t";
    for (int j=0; j<obj.neighbours[i].size(); j++) {
      s << obj.neighbours[i].at(j) << "(" << obj.weights[i].at(j) << "), ";
    }
    s << endl;
  }
  return s;
}


