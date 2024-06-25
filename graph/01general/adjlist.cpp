#include <iostream>
#include <list>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef list<int> List;
typedef vector<List> Graph;

Graph G;
int V, E;

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int main() {
    cin >> V >> E;
}