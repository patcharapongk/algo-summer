#include <iostream>
#include <vector>

#include "mfgraph.h"

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

UwUdGraph* G;
int V, E;

int main() {
    cin >> V >> E;
    G = new UwUdGraph(V, E);

    int u, v;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        G->add_edge(u, v);
    }

    G->print();
    delete G;
}