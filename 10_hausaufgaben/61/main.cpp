#include <iostream>
#include <vector>
#include <list>
#include "limits.h"
using namespace std;

struct Entry{
    int node;
    int distance;
    bool marked;
    int precessor;
    Entry(int node, int distance, bool marked, int precessor);
};

Entry::Entry(int node, int distance, bool marked, int precessor) {
    this->node = node;
    this->distance = distance;
    this->marked = marked;
    this->precessor = precessor;
}

class SampleGraph {
public:
    static vector<int> *create(int numberOfNodes, int numberOfConnections, bool directed = false);
    static void print(vector<int>* graph, int numberOfNodes);
};


vector<int> * SampleGraph::create(int numberOfNodes, int numberOfConnections, bool directed) {
    auto * result = new vector<int>[numberOfNodes];

    int counter = 0;
    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;
        if (source != target) {
            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(target);
//                Damit wir einen gerichteten Graph haben
                if (!directed) {
                    result[target].push_back(source);
                }
                counter++;
            }
        }
    }

    for (int i=0; i<numberOfNodes; i++) {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}

void SampleGraph::print(vector<int>* graph, int numberOfNodes) {
    for (int i=0; i<numberOfNodes; i++) {
        vector<int>::iterator it;
        cout << "Node " << i << "\t";
        for (it=graph[i].begin(); it!=graph[i].end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;
    }
}

void dfsUtil(int v, bool *visited, vector<int> *graph) {
    // Aktuellen Knoten als besucht markieren
    visited[v] = true;

    // Ausgabe Knoten
    cout << v << " ";

    // Wiederholung für alle Eckpunkte für diesen Eckpunkt
    for (int i : graph[v]) {
        if (!visited[i]) {
            dfsUtil(i, visited, graph);
        }
    }
}

//Tiefensuche: Geht zuerst zum letzten Node
void dfs(vector<int>* graph, int numberOfNodes) {
    // Mark all the vertices as not visited
    auto visited = new bool[numberOfNodes];

    for (int i = 0; i < numberOfNodes; i++) {
        visited[i] = false;
    }

    // Rekursivfunktion aufrufen
    dfsUtil(0, visited, graph);
}

//Breitensuche: Geht zuerst zum Nachbarn
void bfs(vector<int> *graph, int numberOfNodes, int v) {
// Alle Knoten als nicht besucht markieren
    auto *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; ++i) {
        visited[i] = false;
    }

    list<int> queue;

    // Den jetzigen Knoten als besucht markieren und in "queue" speichern
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

        for (auto i : graph[v]) {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

bool connected(vector<int>* graph, int numberOfNodes, int nodeA, int nodeB) {

    return false;
}

bool allNodeAreReachable(vector<int> *graph, int NUMBER_OF_NODES, int start) {
    // Alle Knoten als nicht besucht markieren
    auto *visited = new bool[NUMBER_OF_NODES];
    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        visited[i] = false;
    }

    list<int> queue;

    // Den jetzigen Knoten als besucht markieren und in "queue" speichern
    visited[start] = true;
    queue.push_back(start);

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        start = queue.front();
//        cout << start << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (auto i : graph[start]) {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }

    }

    for (int j = 0; j < graph->size(); ++j) {
        if (!visited[j]) return false;
    }

    return true;
}

int getNextNode(vector<Entry> &visited) {
    int nextNode = -1;
    int tmpDistance(INT_MAX);
    bool first = true;

    for (auto i : visited) {
        if(!i.marked && i.precessor != -1) {
        if (first) {
            tmpDistance = i.distance;
            nextNode = i.node;
            first = false;
        } else if (i.distance < tmpDistance) {
                tmpDistance = i.distance;
                nextNode = i.node;
            }
        }
    }

    return nextNode;
}

//Aufgabe 3: Graph - Get Path
vector<int> getPath(vector<int>* graph, int NUMBER_OF_NODES, int start, int end) {
    vector<Entry> visited;
    vector<int> result;
    int nextNode;

    if (start < 0 || start >= NUMBER_OF_NODES) return result;

    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        Entry tmp(i, INT_MAX, false, -1);
        visited.push_back(tmp);
    }

    visited[start].distance = 0;
    visited[start].precessor = start;

    nextNode = getNextNode(visited);

    while(nextNode != -1) {
        visited[nextNode].marked = true;

        for (auto i : graph[nextNode]) {
            if (!visited[i].marked) {
                if(visited[nextNode].distance+1 < visited[i].distance) {
                    visited[i].distance = visited[nextNode].distance+1;
                    visited[i].precessor = nextNode;
                }
            }
        }

        nextNode = getNextNode(visited);
    }

/*    for (auto i : visited) {
        cout << i.node << ", " << i.distance << ", " << i.precessor << endl;
    }*/

    //Abbruchbedingung wenn "end" nicht erreichbar war
    if (visited[end].precessor == -1) return result;

    //Weil while Schleife den ersten Wert nicht berücksichtigt
    result.push_back(end);

    while (visited[end].node != start) {
        end = visited[end].precessor;
        result.push_back(end);
    }

    reverse(result.begin(), result.end());

    return result;
}

//Aufgabe 2: Graph - Shortest Reach
int shortestReach (vector<int>* graph, int NUMBER_OF_NODES, int start, int end) {
    auto res = getPath(graph, NUMBER_OF_NODES, start, end);

    return static_cast<int>(res.size() - 1);
}

//Aufgabe 4:
vector<int> getMotherNodes(vector<int>* graph, int NUMBER_OF_NODES) {
    int count = 0;
    vector<int> vec;

    for (int i = 0; i < NUMBER_OF_NODES; ++i) {
        if (allNodeAreReachable(graph, NUMBER_OF_NODES, count)) {
            vec.push_back(count);
        }
            count++;
    }

    return vec;
}





int main(int argc, char **argv) {
    const int NUMBER_OF_NODES = 10;
    const int NUMBER_OF_CONNECTIONS = 16;
    vector<int>* notDirGraph = SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS, false);

    const int NUMBER_OF_NODES2 = 10;
    const int NUMBER_OF_CONNECTIONS2 = 16;
    vector<int>* dirGraph = SampleGraph::create(NUMBER_OF_NODES2, NUMBER_OF_CONNECTIONS2, true);


/*    SampleGraph SG;
    SG.print(SG.create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);
    SampleGraph::print(SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);
    SampleGraph::print(Graph, NUMBER_OF_NODES);*/
/*    cout << "DFS: ";
    dfs(Graph, NUMBER_OF_NODES);
    cout << endl << "BFS: ";
    bfs(Graph, NUMBER_OF_NODES, 0);*/

    SampleGraph::print(notDirGraph, NUMBER_OF_NODES);
    SampleGraph::print(dirGraph, NUMBER_OF_NODES2);


//    Aufgabe 3
    cout << "Aufgabe 3" << endl;
    auto pathGraph = getPath(dirGraph, NUMBER_OF_NODES2, 0, 6);

    if (!pathGraph.empty()) {
        for (auto i : pathGraph) {
            cout << i << "\t";
        }
    }

    cout << endl << "Aufgabe 2" << endl;

    cout << (shortestReach(notDirGraph, NUMBER_OF_NODES, 0, 9)) << endl;
    cout << (shortestReach(notDirGraph, NUMBER_OF_NODES, 0, 3)) << endl;
    cout << (shortestReach(notDirGraph, NUMBER_OF_NODES, 0, 4)) << endl;
    cout << (shortestReach(notDirGraph, NUMBER_OF_NODES, -1, 9)) << endl;
    cout << (shortestReach(notDirGraph, NUMBER_OF_NODES, 10, 9)) << endl;
    cout << (shortestReach(notDirGraph, NUMBER_OF_NODES, 9, 9)) << endl;

//    Aufgabe 4
    vector<int> vec = getMotherNodes(dirGraph, NUMBER_OF_NODES);

    cout << "Aufgabe 4" << endl;

    for (auto i : vec) {
        cout << i << "\t";
    }
/*    int start = 0;
    if (!allNodeAreReachable(Graph, NUMBER_OF_NODES, start)) {
        cout << "Not all Nodes are reachable" << endl;
    } else {
        cout << "All Nodes are reachable" << endl;
    }*/

    return 0;
}
