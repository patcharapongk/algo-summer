#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;
typedef stack<int> Stack;

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
    Stack s;
    s.push(root);
    visited[root] = 1;

    while (s.size() != 0) {
        int current_node = s.top();
        cout << current_node << endl;
        s.pop();

        for (int i = 0; i <= V; ++i) {
            if (G[current_node][i] && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
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
    dfs(2);
    print_vec(visited);
    print_vec(previous);
    return 0;
}
