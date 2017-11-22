#include <iostream>
#include <vector>
#include <list>

using namespace std;

class SampleGraph {
public:
    static vector<int>* create(int numberOfNodes, int numberOfConnections);
    static void print(vector<int>* graph, int numberOfNodes);
};


vector<int>* SampleGraph::create(int numberOfNodes, int numberOfConnections) {
    auto * result = new vector<int>[numberOfNodes];

    int counter = 0;
    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;
        if (source != target) {
            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(target);
                //result[target].push_back(source); //Auskommentieren, damit wir einen gerichteten Graph haben
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

bool allNodeAreReachable(vector<int> *graph, int NUMBER_OF_NODES, int start) {
    // Alle Knote als nicht besucht markieren
//    auto *visited = new bool[v];

    /*for (int i = 0; i < v; ++i) {
        visited[i] = false;
    }*/

    return false;
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

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[v] = true;
    queue.push_back(v);

    while(!queue.empty())
    {
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

bool connected(vector<int>* graph, int numberOfNodes, int nodeA, int nodeB) {

    return false;
}


int main(int argc, char **argv) {

    const int NUMBER_OF_NODES = 4;
    const int NUMBER_OF_CONNECTIONS = 10;

//    SampleGraph SG;
//    SG.print(SG.create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);
//    SampleGraph::print(SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS), NUMBER_OF_NODES);

    vector<int>* Graph = SampleGraph::create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);

//    SampleGraph::print(Graph, NUMBER_OF_NODES);
    dfs(Graph, NUMBER_OF_NODES);
    bfs(Graph, NUMBER_OF_NODES, 0);

    return 0;
}
