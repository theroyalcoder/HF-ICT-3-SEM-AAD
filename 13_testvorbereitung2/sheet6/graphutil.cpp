#include "graphutil.h"

#include "graph.h"

#include <climits>
#include <algorithm>
#include <iostream>
#include <queue>
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

bool GraphUtil::allNodeAreReachable(Graph *g, int start) {
  /*Diese Funktion erhält als Parameter einen Graphen, die Anzahl Knoten und den Start Knoten.
   * Die Funktion liefert true falls alle anderen Knoten im Graphen von start erreichbar sind.
   * Falls ein oder mehrere Knoten nicht erreichbar sind, so liefert die Funktion false.*/

  auto *visited = new bool[g->getNumberOfNodes()]{};

  for (int i = 0; i < g->getNumberOfNodes(); ++i) {
    visited[i] = false;
  }

  visited[start] = true;

  queue<int> neighbours;
  neighbours.push(start);

  while (!neighbours.empty()) {
    start = neighbours.front();
    neighbours.pop();

    for (int i = 0; i < g->getNeighbours(start).size(); ++i) {
      if (!visited[g->getNeighbours(start)[i]]) {
        visited[g->getNeighbours(start)[i]] = true;
        neighbours.push(g->getNeighbours(start)[i]);
      }
    }
  }

  for (int j = 0; j < g->getNumberOfNodes(); ++j) {
    if (!visited[j]) return false;
  }

  return true;
}
