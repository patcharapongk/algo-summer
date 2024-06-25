#ifndef MFGRAPH
#define MFGRAPH

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Graph {
   protected:
    int V, E;
    Matrix G;

   public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        G.resize(V, Vector(V, 0));
        printf("Graph constructed with V, E = %d, %d\n", V, E);
    }
    virtual void add_edge_wt(int u, int v, int wt) = 0;  // pure virtual, must be overriden
    void add_edge(int u, int v) { add_edge_wt(u, v, 1); };
    void print() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << G[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class UwUdGraph : public Graph {
   public:
    UwUdGraph(int V, int E) : Graph(V, E) {}

    void add_edge_wt(int u, int v, int wt) override {
        G[u][v] = wt;
        G[v][u] = wt;
    }
};
#endif