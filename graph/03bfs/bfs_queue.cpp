#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> Vector;
typedef vector<Vector> Graph;
typedef queue<int> Queue;

Graph G;
int V, E;

/*
5 6
1 2
1 4
2 3
2 4
3 5
4 5
*/

void bfs(int root) {
  Vector visited(V + 1, 0);
  Vector previous(V + 1, -1);

  Queue q;
  q.push(root);
  visited[root] = 1;

  while (!q.empty()) {
    int curr_node = q.front();
    q.pop();

    cout << curr_node << endl;

    for (int i = 0; i <= V; ++i) {
      if (G[curr_node][i] && !visited[i]) {
        visited[i] = 1;
        q.push(i);
      }
    }
  }
}
int main() {
  cin >> V >> E;
  G.resize(V + 1, Vector(V + 1, 0));
  int u, v;
  for (int i = 0; i < E; ++i) {
    cin >> u >> v;
    G[u][v] = 1;
    G[v][u] = 1;
  }
  bfs(2);
}