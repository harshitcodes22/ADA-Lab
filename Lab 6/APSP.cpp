#include <iostream>
using namespace std;

#define V 4
#define INF 99999

void printPath(int pred[][V], int start, int end) {
    if (start == end) {
        cout << start;
        return;
    }
    if (pred[start][end] == -1) {
        cout << "No path exists from " << start << " to " << end;
        return;
    }
    printPath(pred, start, pred[start][end]);
    cout << " -> " << end;
}

void APSP(int graph[V][V]) {
    int dist[V][V];
    int pred[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
                pred[i][j] = i;
            else
                pred[i][j] = -1;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    cout << "Shortest distances and paths between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << "Shortest distance from " << i << " to " << j << ": " << dist[i][j] << ", Path: ";
                printPath(pred, i, j);
                cout << endl;
            }
        }
    }
}

int main() {
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0} };

    APSP(graph);
    return 0;
}