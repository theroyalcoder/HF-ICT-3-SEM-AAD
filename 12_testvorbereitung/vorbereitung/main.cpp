#include<iostream>
#include<vector>
#include<set>
#include <cmath>

using namespace std;

int getSumOfLevel(vector<int> &input, int level){
    int firstOfLevel = pow(2, level-1)-1;
    int nodesOfThisLevel = pow(2, (level-1));
    //cout << nodesOfThisLevel << endl;
    int result = 0;
    //cout << firstOfLevel << endl;
    for(int i = firstOfLevel; i < firstOfLevel+nodesOfThisLevel; i++){
        result += input[i];
    }
    return result;
}

/* Aufgabe 3 */
bool validate(vector<int>&tree, int index) {

    // Get index
    int leftnodeindex = 2 * index + 1;
    int rightnodeindex = 2 * index + 2;

    bool leftnodecorrect = true, rightnodecorrect = true;

    int size = tree.size();

    // If we have no childnode, return true
    if (leftnodeindex >= tree.size() && rightnodeindex >= tree.size()) {
        return true;
    }

    if (leftnodeindex < tree.size()) {
        if (tree.at(leftnodeindex) > tree.at(index)) {
            // If left node is bigger, search deeper
            leftnodecorrect = validate(tree, leftnodeindex);
        }
        else {
            return false;
        }
    }

    if (rightnodeindex < tree.size()) {
        if (tree.at(rightnodeindex) > tree.at(index)) {
            // If right node is bigger, search deeper
            rightnodecorrect = validate(tree, rightnodeindex);
        }
        else {
            return false;
        }
    }

    if (leftnodecorrect == true && rightnodecorrect == true) {
        return true;
    }
    else {
        return false;
    }
}
bool validate(vector<int>tree) {

    return validate(tree, 0);
}

/* Aufgabe 4 */
void sum(vector<int> tree, unsigned int currentlevel, int currentindex, vector<int> &vectorsum) {

    // Get index
    int leftnodeindex = 2 * currentindex + 1;
    int rightnodeindex = 2 * currentindex + 2;

    bool leftnodecorrect = true, rightnodecorrect = true;


    int size = tree.size();

    // Check if the vectorsum has enough levels
    if (vectorsum.size() < currentlevel + 1) {
        vectorsum.push_back(0);
    }

    // Add the value of the parent node
    vectorsum.at(currentlevel) += tree.at(currentindex);

    // If we have no childnode, return true
    if (leftnodeindex >= tree.size() && rightnodeindex >= tree.size()) {
        return;
    }

    if (leftnodeindex < tree.size()) {
        sum(tree, currentlevel + 1, leftnodeindex, vectorsum);
    }

    if (rightnodeindex < tree.size()) {
        sum(tree, currentlevel + 1, rightnodeindex, vectorsum);
    }
    return;
}
int sum(vector<int> tree, unsigned int level) {

    vector<int> vectorsum;

    sum(tree, 0, 0, vectorsum);

    if (level >= vectorsum.size()) {
        return -1;
    }
    else {
        return vectorsum.at(level);
    }
}

/* Aufgabe 5 */
void reachableNodes(vector< vector<int> > *graph, int CurrentNode, int HopsRemaining, set<int> &ReachedNodes) {

    for (int i = 0; i < graph->at(CurrentNode).size(); i++) {
        // Check if HopsRemaining is 0
        if (HopsRemaining == 0) {
            ReachedNodes.insert(CurrentNode);
            return;
        }
        else {
            reachableNodes(graph, graph->at(CurrentNode).at(i), HopsRemaining - 1, ReachedNodes);
        }
    }
    return;
}
set<int> reachableNodes(vector< vector<int> > graph, int startNode, int nHops) {

    set<int> ReachedNodes;
    if (startNode >= graph.size()) {
        return ReachedNodes;
    }

    reachableNodes(&graph, startNode, nHops, ReachedNodes);
    return ReachedNodes;
}

int main(int argc, char **argv) {

    vector<int> test {1,6,3,2,7,9,6,4,3,5,8,2,23,1,8,123,34};

    cout << getSumOfLevel(test, 3) << endl;


//     Aufgabe 3
    vector<int> v1 = { 1,2,3,4,5,6,7,8 };
    vector<int> v2 = { 8,7,6,5,4,3,2,1 };

    cout << validate(v2) << endl;

//     Aufgabe 4
//    vector<int> v1 = { 1,2,3,4,5,6,7,8 };
//    int level = 0;
//    cout << "Level(" << level << "): " << sum(v1, level) << endl;

    /* Aufgabe 5

    vector< vector<int> > myGraph;
    vector<int> neightbours;

    neightbours.push_back(5);
    myGraph.push_back(neightbours);
    neightbours.clear();

    neightbours.push_back(2);
    neightbours.push_back(3);
    neightbours.push_back(4);
    myGraph.push_back(neightbours);
    neightbours.clear();

    neightbours.push_back(0);
    neightbours.push_back(1);
    neightbours.push_back(4);
    neightbours.push_back(5);
    neightbours.push_back(6);
    myGraph.push_back(neightbours);
    neightbours.clear();

    neightbours.push_back(0);
    neightbours.push_back(4);
    neightbours.push_back(6);
    myGraph.push_back(neightbours);
    neightbours.clear();

    neightbours.push_back(1);
    neightbours.push_back(6);
    myGraph.push_back(neightbours);
    neightbours.clear();

    neightbours.push_back(1);
    neightbours.push_back(6);
    myGraph.push_back(neightbours);
    neightbours.clear();

    neightbours.push_back(1);
    neightbours.push_back(2);
    neightbours.push_back(3);
    neightbours.push_back(4);
    myGraph.push_back(neightbours);
    neightbours.clear();

    set<int> mySet;

    mySet = reachableNodes(myGraph,3, 0);
    */

    return 0;
}
