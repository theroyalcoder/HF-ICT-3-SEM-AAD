#include <iostream>
#include <deque>
#include "graph.h"
#include "graphutil.h"
#include "graphgen.h"

using namespace std;

bool hasCycle(Graph *g, int node, bool *visited, deque<int> myDeque) {
    // Aktuellen Knoten als b esucht markieren
    visited[node] = true;
    myDeque.push_back(node);

    // Ausgabe Knoten
    cout << node << " ";

    // Wiederholung für alle Eckpunkte für diesen Eckpunkt
    for (int i : g->getNeighbours(node)) {
        if (!visited[i]) {
//            find(myDeque.begin(), myDeque.end(), node);
            hasCycle(g, i, visited, myDeque);
        }
    }

    sort(myDeque.begin(), myDeque.end());

    for (int j = 0; j < myDeque.size()-1; ++j) {
        if (myDeque[j] == myDeque[j+1]) return false;
    }

    return true;
}

bool hasCycle(Graph *g) {
    deque<int> myDeque;

    // Mark all the vertices as not visited
    auto visited = new bool[g->getNumberOfNodes()];

    for (int i = 0; i < g->getNumberOfNodes(); i++) {
        visited[i] = false;
    }

    // Rekursivfunktion aufrufen
    return hasCycle(g, 0, visited, myDeque);
}

int main() {
    auto *g = new Graph;
    g->randomInit(6,10);

    cout << *g << endl;

//    if (hasCycle(g)) {
//        cout << "has a Cycle" << endl;
//    } else {
//        cout << "has not a Cycle" << endl;
//    }

//    auto *createGraph1 = new Graph;
//    auto *createGraph2 = new Graph;
//    auto *createGraph3 = new Graph;
//    auto *createGraph4 = new Graph;
//    auto *createGraph5 = new Graph;

    cout << hasCycle(GraphGenerator::createGraph1());
//    cout << hasCycle(GraphGenerator::createGraph2());
//    cout << hasCycle(GraphGenerator::createGraph3());
//    cout << hasCycle(GraphGenerator::createGraph4());
//    cout << hasCycle(GraphGenerator::createGraph5());


    return 0;
}
