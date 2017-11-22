#include "graph.h"
#include "graphutil.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
using namespace std;

void dfsUtil(bool *visited, vector<int> *graph, int v) {
    // Aktuellen Knoten als besucht markieren
    visited[v] = true;

    // Ausgabe Knoten
    cout << v << " ";

    // Wiederholung für alle Eckpunkte für diesen Eckpunkt
    for (int i : graph[v]) {
        if (!visited[i]) {
            dfsUtil(visited, graph, i);
        }
    }
}

void dfs(vector<int>* graph, int numberOfNodes) {
    // Mark all the vertices as not visited
    auto *visited = new bool[numberOfNodes];

    for (int i = 0; i < numberOfNodes; i++) {
        visited[i] = false;
    }

    // Rekursivfunktion aufrufen
    dfsUtil(visited, graph, 0);
}

void bfs(vector<int> *graph, int numberOfNodes, int v) {

// Alle Knoten als nicht besucht markieren
    auto *visited = new bool[numberOfNodes];

    for (int i = 0; i < numberOfNodes; ++i) {
        visited[i] = false;
    }


    list<int> queue;

    //Jetzigen Node als visited markieren und diesen zur queue hinzufügen
    visited[v] = true;
    queue.push_back(v);

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        v = queue.front();
        cout << v << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (int i : graph[v]) {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

bool allNodeAreReachable(vector<int> *graph, int NUMBER_OF_NODES, int start, bool *visited) {
    // Aktuellen Knoten als besucht markieren
    visited[start] = true;

    // Ausgabe aktuellen Knoten
    cout << start << " ";

    // Wiederholung für alle Eckpunkte für diesen Eckpunkt
    for (int i : graph[start]) {
        if (!visited[i]) {
            allNodeAreReachable(graph, NUMBER_OF_NODES, i, visited);
        }
    }

    for (int j = 0; j < NUMBER_OF_NODES; ++j) {
        if (!visited[j]) {
            return false;
        }
    }
    return true;

}

bool allNodeAreReachable(vector<int>* graph, int NUMBER_OF_NODES, int start) {
    auto * visited = new bool [NUMBER_OF_NODES];

    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        visited[i] = false;
    }

    return allNodeAreReachable(graph, NUMBER_OF_NODES, start, visited);
}

int shortestReach(vector<int>* graph, int NUMBER_OF_NODES, int start, int end) {
//    Abbruchbedingung
    if (start == end) return 0;

    static int count(0);

    return -1;
}

int main(int argc, char **argv) {
    auto *g = new SampleGraph;
    g->randomInit(8, 15);

//    cout << *g << endl;

    vector<DijkstraEntry> disEn = GraphUtil::dijkstra(g, 0);

    const int NUMBER_OF_NODES = 6;
    const int NUMBER_OF_CONNECTIONS = 10;

//    SampleGraph::print(SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);

    vector<int>* Graph = SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);
    SampleGraph::print(Graph, NUMBER_OF_NODES);
    cout << endl;

    cout << "dfs: ";
    dfs(Graph, NUMBER_OF_NODES);
    cout << endl << "bfs: ";
    bfs(Graph, NUMBER_OF_NODES, 0);
    cout << endl;


    if (!allNodeAreReachable(Graph, NUMBER_OF_NODES, 0)) {
        cout << endl << "Not all Nodes are reachable" << endl;
    } else {
        cout << endl << "All Nodes are reachable" << endl;
    }

    shortestReach(Graph, NUMBER_OF_NODES, 0, 5);

    return 0;
}
