#include <iostream>
#include <list>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

void print_vec(Vector &v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}
void print_matrix(Matrix &m) {
    for (int i = 0; i < m.size(); ++i) {
        print_vec(m[i]);
    }
}

Matrix G;
int V, E;

Vector visited;
Vector previous;

void dfs(int root) {
    cout << root << endl;
    visited[root] = 1;
    for (int i = 0; i <= V; ++i) {
        if (G[root][i] == 1 && !visited[i]) {
            previous[i] = root;
            dfs(i);
        }
    }
}

void add_edge(int u, int v) {
    G[u][v] = 1;
    G[v][u] = 1;
}

int main() {
    cin >> V >> E;
    int u, v;
    G.resize(V + 1, Vector(V + 1, 0));
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        add_edge(u, v);
    }
    print_matrix(G);
    visited.resize(V + 1, 0);
    previous.resize(V + 1, -1);
    dfs(5);
    print_vec(visited);
    print_vec(previous);
    return 0;
}
