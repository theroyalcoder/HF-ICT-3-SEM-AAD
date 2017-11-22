#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H

#include <vector>
using namespace std;

class SampleGraph;

class DijkstraEntry {
public:
  int node;
  int distance;
  bool marked;
  int predecessor;

    DijkstraEntry(int node, int distance, bool marked, int predecessor);
};

class GraphUtil {
public:
  static vector<DijkstraEntry> dijkstra(SampleGraph *g, int start);

};

#endif

