#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODES = 100;   // Maximum number of nodes in the graph
int adjMatrix[MAX_NODES][MAX_NODES];  // Adjacency matrix
bool visited[MAX_NODES];              // Array to track visited nodes

void dfs(int start, int n) {
    stack<int> s;

    // Start DFS from the given starting node
    s.push(start);
    visited[start] = true;

    cout << "DFS traversal starting from node " << start << ": ";

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        // Traverse all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                s.push(i);
                visited[i] = true;
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
            adjMatrix[i][j] = 0;
        }
        visited[i] = false;
    }

    cout << "Enter each edge as a pair of nodes (e.g., '0 1' for an edge between nodes 0 and 1):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Assuming an undirected graph
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    dfs(startNode, n);

    return 0;
}

