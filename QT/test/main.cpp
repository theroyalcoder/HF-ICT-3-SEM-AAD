#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;

int main()
{
    //Vector
/*
    //Initialisierung
    vector<int> zahlen(10);

    //Werte in Vector einfüllen
    for(int i = 0; i < zahlen.size(); i++)    {
        zahlen[i] = i;
    }

    //Nach letzten Wert den nachfolgenden Wert einfüllen
    zahlen.push_back(1111);

    //Vector ausgeben
    for(int i = 0; i < zahlen.size(); i++)    {
        cout << zahlen[i] << endl;
    }
*/

    //Map
/*
   //Initialisierung
    map<int, string> namensliste;

    //Abfüllen mit Werten
    namensliste.insert(pair<int, string>(1, "hans"));
    namensliste.insert(pair<int, string>(6, "jefferson"));

    //Ausgabe
    cout << namensliste.find(6)->first << endl;
    cout << namensliste.find(6)->second << endl;
*/
    //Set
/**/
    //Initialisierung, Werte aufsteigend
    set<int, greater<int>> zahlen_sortiert;
    //Initialisierung, Werte absteigend
    //set<int> zahlen_sortiert;

    //Wert eingeben, diese werdem im Set autmatisch sortiert
    zahlen_sortiert.insert(1);
    zahlen_sortiert.insert(67);
    zahlen_sortiert.insert(145);
    zahlen_sortiert.insert(71);
    zahlen_sortiert.insert(16);
    zahlen_sortiert.insert(561);
    zahlen_sortiert.insert(14);
    zahlen_sortiert.insert(1);
    zahlen_sortiert.insert(46);

    //Ausgabe
    for (auto i = zahlen_sortiert.begin(); i != zahlen_sortiert.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}
