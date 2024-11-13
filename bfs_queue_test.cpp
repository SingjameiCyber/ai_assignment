#include <iostream>
#include <queue>

using namespace std;

const int MAX_NODES = 100;  // Maximum number of nodes allowed in the graph
int adjList[MAX_NODES][MAX_NODES];  // Adjacency matrix
bool visited[MAX_NODES];            // Array to track visited nodes

void bfs(int start, int n) {
    queue<int> q;

    // Start BFS from the given starting node
    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Traverse all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adjList[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjList[i][j] = 0;
        }
        visited[i] = false;
    }

    cout << "Enter each edge as a pair of nodes (e.g., '0 1' for an edge between nodes 0 and 1):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
        adjList[v][u] = 1;  // Assuming an undirected graph
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    bfs(startNode, n);

    return 0;
}

