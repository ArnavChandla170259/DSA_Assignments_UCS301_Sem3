#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Edges: 0-1, 0-2, 1-3, 1-4
    adj[0].push_back(8);
    adj[0].push_back(9);
    adj[1].push_back(57);
    adj[1].push_back(44);
    adj[1].push_back(42);
    adj[2].push_back(90);
    adj[3].push_back(100);
    adj[4].push_back(19);

    bfs(0, adj, V);

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
