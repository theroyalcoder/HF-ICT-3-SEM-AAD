#include "graph.h"
#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

Graph::Graph() = default;

void Graph::randomInit(int nNodes, int nConnections, bool directed) {
  vector<int> v;
  for (int i=0; i<nNodes; i++) {
    neighbours.push_back(v);
  }
  int counter = 0;
  while (counter < nConnections) {
    int source = rand() % nNodes;
    int target = rand() % nNodes;
    if (source != target) {
      if (find(neighbours[source].begin(), neighbours[source].end(), target) == neighbours[source].end()) {
        neighbours[source].push_back(target);
        if (!directed) {
          neighbours[target].push_back(source);
        }
        counter++;
      }
    }
  }
  for (int i=0; i<nNodes; i++) {
    sort(neighbours[i].begin(), neighbours[i].end());
  }

  for (vector<int> v : neighbours) {
    vector<int> w;
    for (int i=0; i<v.size(); i++) {
//        Random Werte für normal zum Arbeiten
        int cost = rand() % 20 + 1;

//        Wert = 1 für Dijkstra Methode (ShortestReach)
//        int cost = 1;

        w.push_back(cost);
    }
    weights.push_back(w);
  }

  if (!directed) {
    for (int i=0; i<weights.size(); i++) {
      for (int j=0; j<weights.at(i).size(); j++) {
        int source = i;
        int target = neighbours.at(i).at(j);
        int weight = weights.at(i).at(j);
        int index = find(neighbours.at(target).begin(), neighbours.at(target).end(), source) - neighbours.at(target).begin();
        weights[target][index] = weight;
      }
    }
  }
}

int Graph::getNumberOfNodes() {
  return neighbours.size();
}

vector<int> Graph::getNeighbours(int node) {
  return neighbours.at(node);
}

vector<int> Graph::getWeights(int node) {
  return weights.at(node);
}

std::ostream& operator<<(std::ostream& s, const Graph & obj) {
  for (int i=0; i<obj.neighbours.size(); i++) {
    s << "Node " << i << "\t";
    for (int j : obj.neighbours[i]) {
//        s << obj.neighbours[i].at(j) << "(" << obj.weights[i].at(j) << "), ";
//        Ohne Gewicht
        s << j << "\t";

    }
    s << endl;
  }
  return s;
}

bool Graph::allNodeAreReachable(int start) {
    auto * visited = new bool[getNumberOfNodes()];

    for (int i = 0; i < getNumberOfNodes(); ++i) {
        visited[i] = false;
    }

    visited[start] = true;

    list<int> Q;
    Q.push_back(start);

    while (!Q.empty()) {
        start = Q.front();
        cout << start << "\t";

        Q.pop_front();

        for (auto i : neighbours[start]) {
            if (!visited[i]) {
                visited[i] = true;
                Q.push_back(i);
            }
        }
    }

    for (int j = 0; j < getNumberOfNodes(); ++j) {
        if (!visited[j]) return false;
    }

    return  true;
}
/*
//    Mit Oetti am Sonntag angeschaut, weiter arbeiten (shortestReach mit Dijkstra)
int Graph::shortestReach(int start, int end) {
//    Falls start und end gleich sind, liefert die Funktion 0.
    if (start == end) return 0;

    auto * visited = new bool[getNumberOfNodes()];

    for (int i = 0; i < getNumberOfNodes(); ++i) {
        visited[i] = false;
    }

    visited[start] = true;

//    todo: Funktion liefert die minimale Anzahl Knoten, welche von start nach end passiert werden muss.




//    Falls kein Weg zwischen start und end existiert, so liefert die Funktion den Wert -1.
    return -1;
}
*/

int Graph::shortestReach(int start, int target) {
//    Falls start und end gleich sind, liefert die Funktion 0.
    if (start == target) return 0;

    auto * visited = new bool[getNumberOfNodes()];
    auto * predessesor = new int[getNumberOfNodes()];
    int cost(0);

    for (int i = 0; i < getNumberOfNodes(); ++i) {
        visited[i] = false;
    }

    visited[start] = true;

//    todo: Funktion liefert die minimale Anzahl Knoten, welche von start nach end passiert werden muss.

    list<int> list_neighbour;
    list_neighbour.push_back(start);

    while(!list_neighbour.empty()) {
        start = list_neighbour.front();
        list_neighbour.pop_front();

        for (int i = 0; i < list_neighbour.size(); ++i) {
            if (!visited[neighbours[start].at(i)]) {

                visited[neighbours[start].at(i)] = true;

                int n = neighbours[start].at(i);
                list_neighbour.push_back(n);

                cost = weights[start].at(i) + 1;
            }

//            Wenn der Ziel-Node true ist, dann sind wir am Ziel und können abbrechen
            if (visited[target]) return i;
        }

        for (int i = 0; i < getNumberOfNodes(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                list_neighbour.push_back(i);
            }

            cout << "i: " << i << endl;
            if (visited[target]) return weights[target].at(i);

        }

//        for (auto i : neighbours[start]) {
//            if (!visited[i]) {
//                visited[i] = true;
//                list_neighbour.push_back(i);
//            }
//
//            cout << "i: " << i << endl;
//            if (visited[target]) return weights[target].at(i);
//        }
    }


//    Falls kein Weg zwischen start und end existiert, so liefert die Funktion den Wert -1.
    return -1;
}


bool Graph::connected(int start, int target) {
    auto *visited = new bool[getNumberOfNodes()];

    for (int i = 0; i < getNumberOfNodes(); ++i) {
        visited[i] = false;
    }

    visited[start] = true;
    list<int> search;

    search.push_back(start);

    while(!search.empty()) {
        start = search.front();
        cout << start << "\t";
        search.pop_front();

        for (auto i : neighbours[start]) {
            if (!visited[i]) {
                visited[i] = true;
                search.push_back(i);
            }
            if (visited[target]) return true;
        }
    }

    return false;
}

vector<int> Graph::getPath(int start, int end) {
    /*Diese Funktion liefert einen Vector, welche alle Knoten beinhaltet,
     * welche von start nach end passiert werden mu ̈ssen.
     * Verwenden Sie fu ̈r diese Aufgabe den DFS Algorithmus.*/


    return vector<int>();
}
