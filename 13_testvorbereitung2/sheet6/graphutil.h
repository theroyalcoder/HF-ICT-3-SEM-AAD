#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H

#include <vector>
using namespace std;

class Graph;

class DijkstraEntry {
public:
  int node;
  int distance;
  bool marked;
  int predecessor;
};

class GraphUtil {
private:
  static bool hasCycle(Graph *g, int node, vector<bool> & visited, vector<int> & path);
public:
  static vector<DijkstraEntry> dijkstra(Graph *g, int start);
  static bool hasCycle(Graph *g);
    bool allNodeAreReachable(Graph *g, int start);
};

#endif
