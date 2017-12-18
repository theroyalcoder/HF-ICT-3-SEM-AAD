#include "graph.h"

#include "graphutil.h"

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

    auto *g = new Graph;
    g->randomInit(6, 80, true);
    cout << *g << endl;

    GraphUtil GU;
    if (GU.allNodeAreReachable(g, 0)) {
        cout << "true";
    } else {
        cout << "false";
    }

//  vector<DijkstraEntry> table = GraphUtil::dijkstra(&g, 0);

  return 0;
}
