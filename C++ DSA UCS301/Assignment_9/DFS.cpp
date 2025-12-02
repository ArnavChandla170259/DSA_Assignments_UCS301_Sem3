#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfsUtil(start, adj, visited);
    cout << "\n";
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(1);

    dfs(0, adj, V);

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
