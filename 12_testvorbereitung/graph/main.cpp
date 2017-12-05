#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
public:
    static vector<int> *create(int numberOfNodes, int numberOfConnections, bool directed = false);
    static void print(vector<int>* graph, int numberOfNodes);
};

vector<int> *Graph::create(int numberOfNodes, int numberOfConnections, bool directed) {
    auto * result = new vector<int>[numberOfNodes];
    int counter = 0;

    while (counter < numberOfConnections) {
        int source = rand() % numberOfNodes;
        int target = rand() % numberOfNodes;

        if (source != target) {

            if (find(result[source].begin(), result[source].end(), target) == result[source].end()) {
                result[source].push_back(target);

                if (!directed) {
                    result[target].push_back(source);
                }
                counter++;
            }
        }
    }

    return result;
}

void Graph::print(vector<int> *graph, int numberOfNodes) {
    for (int i=0; i<numberOfNodes; i++) {
        vector<int>::iterator it;
        cout << "Node " << i << "\t";

        for (it=graph[i].begin(); it!=graph[i].end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;
    }
}

void dfsUtil(vector<int> *graph, bool * visited, int start) {
    visited[start] = true;

    cout << start << "\t";

    for (auto i : graph[start]) {
        if (!visited[i]) {
            dfsUtil(graph, visited, i);
        }
    }
}

void dfs(vector<int> *graph, int numberOfNodes) {
    auto *visited = new bool[numberOfNodes];

    for (int i = 0; i < numberOfNodes; ++i) {
        visited[i] = false;
    }

    dfsUtil(graph, visited, 0);
}

void bfs(vector<int> *graph, int numberOfNodes, int start) {
    auto *visited = new bool[numberOfNodes];

    for (int i = 0; i < numberOfNodes; ++i) {
        visited[i] = false;
    }

    visited[start] = true;

    list<int> neighbours;
    neighbours.push_back(start);

    while (!neighbours.empty()) {
        start = neighbours.front();

        cout << start << "\t";

        neighbours.pop_front();

        for (auto i : graph[start]) {
            if(!visited[i]) {
                visited[i] = true;
                neighbours.push_back(i);
            }
        }
    }

    for (int j = 0; j < numberOfNodes; ++j) {
        if (!visited[j]) return;
    }


}

int main() {
    int numberOfNodes(10), numberOfConnections(20);
    auto *vec = Graph::create(numberOfNodes, numberOfConnections);
    Graph::print(vec, numberOfNodes);

    cout << endl;
    dfs(vec, 10);
    cout << endl;
    bfs(vec, numberOfNodes, 0);

    return 0;
}