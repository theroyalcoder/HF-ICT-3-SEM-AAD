#include "graph.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int NUMBER_OF_NODES = 12;
    int NUMBER_OF_CONNECTIONS = 20;
    auto * g = new Graph();

    g->randomInit(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);
    cout << *g << endl;

    /*cout << "allNodeAreReachable" << endl;
    if (g->allNodeAreReachable(0)) {
        cout << "All Nodes are reachable" << endl;
    } else {
        cout << "NOT all Nodes are reachable" << endl;
    }

    cout << endl << "connected" << endl;
    if (g->connected(3, 5)) {
        cout << "Target Node is reachable" << endl;
    } else {
        cout << "Target Node is NOT reachable" << endl;
    }

    cout << endl << "shortestReach" << endl;
    cout << g->shortestReach(0, 10);
*/

    return 0;

}
