#include "graphutil.h"

#include "graph.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int graphutil::getNextNode(vector<DijkstraEntry> &data){
    int id(-1),distance;
    bool first(true);
    for (DijkstraEntry e:data){
        if(e.marked != true){
            if(first){
                id = e.node;
                distance = e.distance;
                first = false;
            } else {
                if(e.distance < distance){
                    id = e.node;
                    distance = e.distance;
                }
            }
        }
    }
return id;
}


vector<DijkstraEntry> graphutil::dijkstra(Graph *g, int start){

    vector<DijkstraEntry> tabelle;

    for (int i = 0 ; i < g->getNumberOfNodes() ; i++){
        DijkstraEntry entry;
        entry.node = i;
        entry.distance = INT_MAX;
        entry.marked = false;
        entry.predecessor = -1;
        tabelle.push_back(entry);
    }

    //Startbedingung
    tabelle[start].distance=0;
    tabelle[start].predecessor=start;

    int id = getNextNode(tabelle);

    while(id != -1){

    vector<int> nachbarn=g->getNeighbours(id);
    vector<int> kosten=g->getWeights(id);
    int currentcost = tabelle[id].distance;

    for(int i = 0 ; i < nachbarn.size() ; i++){
        int nachbar = nachbarn[i];
        int cost = kosten[i];
        int totalcost = currentcost + cost;
        if(tabelle[nachbar].distance > totalcost){
            tabelle[nachbar].distance = totalcost;
            tabelle[nachbar].predecessor = id;
        }
    }
    tabelle[id].marked = true;
    id = getNextNode(tabelle);
    }

return tabelle;
}
