#include "graph.h"

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv) {
  
  Graph g;
  g.randomInit(10, 32);
  cout << g << endl;

  return 0;
}