#include<iostream>
#include<algorithm>
#include<fstream>
#include<time.h>
using namespace std;
void WriteDataToFile(int i, double avgTime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << "," << avgTime << endl;
        fout.close();
    }
    else {
        cout << "Unable to open file for writing data. " << endl;
    }
}
bool compareEdges(const int a[], const int b[]) {
    return a[2] > b[2]; // Min-heap comparator based on weights
}

int find(int p[], int i) {
    if (p[i] == -1)
        return i;
    return find(p, p[i]);
}

void unionSets(int p[], int x, int y) {
    int xset = find(p, x);
    int yset = find(p, y);
    p[xset] = yset;
}

void heapify(int edges[][3], int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n && compareEdges(edges[left], edges[smallest]))
        smallest = left;
    if (right < n && compareEdges(edges[right], edges[smallest]))
        smallest = right;
    if (smallest != i) {
        swap(edges[i], edges[smallest]);
        heapify(edges, smallest, n);
    }
}

void buildHeap(int edges[][3], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(edges, i, n);
    }
}

void kruskal(int edges[][3], int n, int numVertices, int result[][3]) {
    buildHeap(edges, n); // Build min-heap
    int p[numVertices];
    for(int i=0;i<numVertices;i++){
        p[i]=-1;
    }
    int edgeCount = 0;
    while (edgeCount < numVertices - 1 && n > 0) {
        int edge[3];
        for (int i = 0; i < 3; i++) {
            edge[i] = edges[0][i]; // Get minimum weight edge
        }
        swap(edges[0], edges[n - 1]); // Move last edge to root
        n--; // Reduce heap size
        heapify(edges, 0, n); // Restore min-heap property
        int srcp = find(p, edge[0]);
        int destp = find(p, edge[1]);
        if (srcp != destp) {
            for (int i = 0; i < 3; i++) {
                result[edgeCount][i] = edge[i]; // Store edge in result
            }
            edgeCount++;
            unionSets(p, srcp, destp);
        }
    }
}

int main() {
    srand(time(NULL));
    double time1, time2, avgtime;
    int numVertices = 6;
    int numEdges = 10; // Adjust this based on the number of edges you have
     // Corrected type declaration
    for(int k=10;k<1000;k+=10){
        int edges[k][3];
        int j= k-4;
    // Assign values to each edge
    for (int i = 0; i < k; i++) {
        edges[i][0] = rand() % j; // Random source vertex between 0 and 5
        edges[i][1] = rand() % j; // Random destination vertex between 0 and 5
        edges[i][2] = rand() % 100 + 1; // Random weight between 1 and 100
    }
    
    int result[(j) - 1][3] = {};
    time1=(double)clock();
    kruskal(edges, k, (j), result);
    cout << "Minimum Spanning Tree Edges:" << endl;
    int minCost = 0;
    for (int i = 0; i < (j) - 1; i++) {
        cout << result[i][0] << " - " << result[i][1] << " (Cost: " << result[i][2] << ")" << endl;
        minCost += result[i][2];
    }
    cout << "Total Minimum Cost: " << minCost << endl;
    time2=(double)clock();
    avgtime=(double)(time2-time1)/10;
    cout<<k<<" - "<<avgtime<<endl;
    WriteDataToFile(k,avgtime);
    }
    return 0;
}
