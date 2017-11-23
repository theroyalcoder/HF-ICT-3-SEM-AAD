#include <iostream>
#include <utility>
#include <vector>
#include <list>

using namespace std;

class Node {
public:
    Node(int node, vector<int> neighbours, bool marked, int weight, int predecessor);
    int getNode() const {
        return node;
    }
    void setNode(int node) {
        Node::node = node;
    }
    const vector<int> &getNeighbours() const {
        return neighbours;
    }
    void setNeighbours(const vector<int> &neighbours) {
        Node::neighbours = neighbours;
    }
    bool isMarked() const {
        return marked;
    }
    void setMarked(bool marked) {
        Node::marked = marked;
    }
    int getWeight() const {
        return weight;
    }
    void setWeight(int weight) {
        Node::weight = weight;
    }
    int getPredecessor() const {
        return predecessor;
    }
    void setPredecessor(int predecessor) {
        Node::predecessor = predecessor;
    }
private:
    int node;
    vector<int> neighbours;
    bool marked;
    int weight = 1;
    int predecessor;
};

Node::Node(int node, vector<int> neighbours, bool marked, int weight, int predecessor) : node(node),
                                                                                                neighbours(std::move(
                                                                                                        neighbours)),
                                                                                                marked(marked),
                                                                                                weight(weight),
                                                                                                predecessor(
                                                                                                        predecessor) {}

class realGraph {
public:
    realGraph(int NUMBER_OF_NODES, int NUMBER_OF_CONNECTIONS);
    static vector<Node>* create(int numberOfNodes, int numberOfConnections);
    static void print(vector<int>* graph, int numberOfNodes);
private:
    int NUMBER_OF_NODES;
    int NUMBER_OF_CONNECTIONS;
};

realGraph::realGraph(int NUMBER_OF_NODES, int NUMBER_OF_CONNECTIONS) : NUMBER_OF_NODES(NUMBER_OF_NODES),
                                                                       NUMBER_OF_CONNECTIONS(NUMBER_OF_CONNECTIONS) {
    this->create(NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);
}
/*    int node;
    vector<int> neighbours;
    bool marked;
    int weight = 1;
    int predecessor;*/
vector<Node> *realGraph::create(int numberOfNodes, int numberOfConnections) {
    auto * result = new vector<Node>[numberOfNodes];


    int counter = 0;
    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;
        auto * n = new Node(source, NULL, false, 1, target);
        

        if (source != target) {
            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(n->getPredecessor());

                result[source].push_back(target);
                result[target].push_back(source); //Auskommentieren, damit wir einen gerichteten Graph haben
                counter++;
            }
        }
    }

    for (int i=0; i<numberOfNodes; i++) {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}

void realGraph::print(vector<int> *graph, int numberOfNodes) {
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

int shortestReach(vector<int>* graph, int NUMBER_OF_NODES, int start, int end) {
    /*
    todo: Diese Funktion liefert die minimale Anzahl Knoten, welche von start nach end passiert werden muss.
    todo: Falls kein Weg zwischen start und end existiert, so liefert die Funktion den Wert -1.
    */
//    Falls start und end gleich sind, liefert die Funktion 0
    if (start == end) return 0;

    int path(0);

    return -1;
}

int main(int argc, char **argv) {
    const int NUMBER_OF_NODES = 10;
    const int NUMBER_OF_CONNECTIONS = 16;

/*    cout << "DFS: ";
    dfs(Graph, NUMBER_OF_NODES);
    cout << endl << "BFS: ";
    bfs(Graph, NUMBER_OF_NODES, 0);*/

    vector<int> neighbours;

    realGraph RG(0, neighbours, false, 1, -1, NUMBER_OF_NODES, NUMBER_OF_CONNECTIONS);

    return 0;
}
