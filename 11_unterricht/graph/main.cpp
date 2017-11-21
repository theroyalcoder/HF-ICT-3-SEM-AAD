#include "graph.h"
#include "graphutil.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    auto *g = new Graph;
    g->randomInit(8, 15);

//    cout << *g << endl;

    vector<DijkstraEntry> disEn = graphutil::dijkstra(g, 0);

  return 0;
}
