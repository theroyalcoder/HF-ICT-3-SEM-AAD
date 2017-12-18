#include "graphutil.h"

#include "graph.h"

#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

int getNextNode(vector<DijkstraEntry> table) {
  int minDistance = INT_MAX;
  int minIndex = -1;
  for (DijkstraEntry e : table) {
    if (e.distance < minDistance && !e.marked) {
      minDistance = e.distance;
      minIndex = e.node;
    }
  }
  return minIndex;
}

vector<DijkstraEntry> GraphUtil::dijkstra(Graph *g, int start) {
  vector<DijkstraEntry> table;
  for (int i=0; i<g->getNumberOfNodes(); i++) {
    DijkstraEntry e;
    e.node = i;
    e.distance = INT_MAX;
    e.marked = false;
    e.predecessor = -1;
    table.push_back(e);
  }

  table[start].distance = 0;
  table[start].predecessor = start;

  int nextNode = getNextNode(table);
  while (nextNode != -1) {
    vector<int> neighbours = g->getNeighbours(nextNode);
    vector<int> weights = g->getWeights(nextNode);
    int d = table[nextNode].distance;
    for (int i=0; i<neighbours.size(); i++) {
      int n = neighbours[i];
      int w = weights[i];
      if (!table[n].marked && table[n].distance > d+w) {
        table[n].distance = d+w;
        table[n].predecessor = nextNode;
      }
    }
    table[nextNode].marked = true;
    nextNode = getNextNode(table);
  }
  return table;
}

bool GraphUtil::hasCycle(Graph *g) {
  vector<int> path;
  vector<bool> visited(g->getNumberOfNodes());
  bool allNodesAreVisited = false;
  while (!allNodesAreVisited && visited.size() > 0) {
    int node = -1;
    for (int i=0; i<visited.size(); i++) {
      if (!visited[i]) {
        node = i;
        break;
      }
    }
    if (node == -1) {
      allNodesAreVisited = true;
    } else {
      bool result = hasCycle(g, node, visited, path);
      if (result) {
        return true;
      }
    }
  }
  return false;
}

bool GraphUtil::hasCycle(Graph *g, int node, vector<bool> & visited, vector<int> & path) {
  visited[node] = true;
  if (find(path.begin(), path.end(), node) != path.end()) {
    return true;
  }
  path.push_back(node);

  for (int n : g->getNeighbours(node)) {
    bool result = hasCycle(g, n, visited, path);
    if (result) {
      return true;
    }
  }

  path.pop_back();
  return false;
}
