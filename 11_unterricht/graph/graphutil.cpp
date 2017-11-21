#include "graphutil.h"
#include "graph.h"


DijkstraEntry::DijkstraEntry(int node, int distance, bool marked, int predecessor) : node(node), distance(distance),
                                                                                     marked(marked),
                                                                                     predecessor(predecessor) {}

vector<DijkstraEntry> GraphUtil::dijkstra(Graph *g, int start) {
  // init node, marked, distance von jedem DijkstraEntry Objekt
  // perform algorithm
    int counter(0);
    vector<DijkstraEntry> result ;



    return result;

}
