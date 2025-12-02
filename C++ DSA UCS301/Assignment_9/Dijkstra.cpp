#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define R 9

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int q = 0; q < R; q++)
        if (sptSet[q] == false && dist[q] <= min)
            min = dist[q], min_index = q;

    return min_index;
}

void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < R; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[R][R], int src) {
    int dist[R];
    bool sptSet[R];

    for (int i = 0; i < R; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < R - 1; count++) {

        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int q = 0; q < R; q++) {
            if (!sptSet[q] && graph[u][q] && dist[u] != INT_MAX
                && dist[u] + graph[u][q] < dist[q])
                dist[q] = dist[u] + graph[u][q];
        }
    }

    printSolution(dist);
}

int main() {
    int graph[R][R] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
