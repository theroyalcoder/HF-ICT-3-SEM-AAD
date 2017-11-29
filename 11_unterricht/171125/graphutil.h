#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H

#include <vector>
#include "graph.h"
#include <sstream>
using namespace std;

struct DijkstraEntry {
  int node;
  int distance;
  bool marked;
  int predecessor;
};

class graphutil{
public:
  static vector<DijkstraEntry> dijkstra(Graph *g, int start);
private:
  static int getNextNode(vector<DijkstraEntry> &data);
};

#endif // GRAPHUTIL_H





