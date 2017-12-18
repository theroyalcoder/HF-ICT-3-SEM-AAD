#include "graph.h"

#include "graphutil.h"

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
  
  Graph g;
  g.randomInit(6, 12, true);
  cout << g << endl;

//  vector<DijkstraEntry> table = GraphUtil::dijkstra(&g, 0);

  return 0;
}
