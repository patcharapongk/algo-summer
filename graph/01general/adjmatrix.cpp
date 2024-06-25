#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

Matrix G;
int V, E;

void add_edge(int u, int v) {
    G[u][v] = 1;
    G[v][u] = 1;
}

int main() {
    cin >> V >> E;
}