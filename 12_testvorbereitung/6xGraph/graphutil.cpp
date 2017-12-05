#include "graphutil.h"

#include "graph.h"

int GraphUtil::getNextDijkstraNode(vector<DijkstraEntry> result) {
    int id = -1;
    int weight(0);





    return id;
}

vector<DijkstraEntry> GraphUtil::dijkstra(Graph *g, int start) {

//   Result Vector erstellen (#nodes DijkstraEntry Objekte)
    vector<DijkstraEntry> result;
    result.reserve(static_cast<unsigned long>(g->getNumberOfNodes()));

//   init node, marked, disstance von jedem DijkstraEntry Objekt
    for (int i = 0; i < g->getNumberOfNodes(); ++i) {
        auto *EntryObj = new DijkstraEntry();

        EntryObj->node = i;
        EntryObj->distance = INT_MAX;
        EntryObj->marked = false;
        EntryObj->predecessor = -1;

        result.push_back(*EntryObj);
    }

//   perform algorithm

    result[start].marked = true;
    result[start].predecessor = start;

    int id = getNextDijkstraNode(result);



//   return result vector
    return result;
}
